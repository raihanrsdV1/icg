#include "2105046_SymbolTable.hpp"



string randomStructOrUnionDetails() {
    const string fieldTypes[] = {"INT", "FLOAT", "STRING", "BOOL"};
    int fieldCount = 1 + rand() % 4; // number of fields

    string result;
    for (int i = 0; i < fieldCount; i++) {
        result += " " + fieldTypes[rand() % 4];

        // Generate a random variable name
        int len = 4 + rand() % 4;
        string varName = "";
        for (int j = 0; j < len; j++) {
            varName += (char)('a' + rand() % 26);
        }

        result += " " + varName;
    }

    return result;
}

string randomInsertGenerator(){
    ui word_len = 2 + rand() % 50;
    string str = "I ";

    for (ui i = 0; i < word_len; i++) {
        str += (char)('a' + rand() % 26);
    }

    str += " ";
    const string types[] = {"INT", "FLOAT", "STRING", "FOO", "STRUCT", "UNION", "FUNCTION"};
    string type = types[rand() % 7];

    str += type;

    if (type == "STRUCT" || type == "UNION") {
        str += " ";
        str += randomStructOrUnionDetails();
    }

    else if (type == "FUNCTION") {
        int paramCount = rand() % 4; // 0 to 3 params
        const string paramTypes[] = {"INT", "FLOAT", "STRING"};
        for (int i = 0; i < paramCount; i++) {
            str += " " + paramTypes[rand() % 3];
        }
    }

    return str;
}

string randomDeleteGenerator(const string & name){
    return  "D " + name;
}

string randomLookUpGenerator(const string & name){
    return "L " + name;
}

string randomInstructionGenerator(const string& name) {
    const ui TOTALINS = 100;
    ui instruction = rand() % TOTALINS;
    if(instruction < TOTALINS / 2){
        return randomInsertGenerator();
    }
    else if(instruction >= TOTALINS / 2 && instruction < TOTALINS * 3 / 4){
        return randomDeleteGenerator(name);
    }
    else if(instruction >= TOTALINS * 3 / 4 && instruction < TOTALINS - 2){
        return randomLookUpGenerator(name);
    }
    else if(instruction == TOTALINS - 2) return "E";
    else if(instruction == TOTALINS - 1) return "S";
    return randomInsertGenerator();
}


int main(int argc, char* argv[]){
    if (argc < 3 || argc > 4) {
        cerr << "Usage: " << argv[0] << " <input-file> <output-file>\n";
        return 1;
    }
    HashFn hashFunctions[] = { SDBMHash, MURMURhash, JENKINSHash };
    for(int sample = 1; sample <= SAMPLES; sample++){
        ofstream fout(argv[1]);
        if (!fout) {
            cerr << "Can't open input file for writing\n";
            return 1;
        }

        fout << DEFAULT_BUCKETS << endl;
        ui numSamples = INSERT_SAMPLES / SAMPLES * sample;
        string names[numSamples];
        ui nameCount = 0;
        for(ui i = 0; i < numSamples; i++){
            string randomName = (nameCount == 0)? "": names[rand() % nameCount];
            string instruction = randomInstructionGenerator(randomName);
            string cmd = getToken(instruction, 0);
            if(cmd == "I"){
                names[nameCount++] = getToken(instruction, 1);
            }
            fout << instruction << endl;
            if(i % 100 == 0){
                fout << "P A" << endl;
            }
        }
        fout << "P A" << endl;
        fout << "Q" << endl;
        fout.close();

        // freopen(argv[1], "r", stdin);
        ifstream fin(argv[1]);
        if (!fin) {
            cerr << "Failed to open input file.\n";
            return 1;
        }
        freopen(argv[2], "a", stdout);

        
        
        cout << "This is for samples size: " << numSamples << endl << endl;
        for(int i = 0; i < NUM_HASHES; i++){
            HashFn hashFunction = hashFunctions[i];
            ui bucketSize;
            if (!(fin >> bucketSize)) {
                cerr << "Failed to read bucket size\n";
                return 1;
            }

            fin.ignore(numeric_limits<streamsize>::max(), '\n');


            ui commandNum = 1;
            SymbolTable symbolTable(hashFunction, bucketSize);

            while(true){
                string line;
                if(!getline(fin, line)) break;
                if(line.empty()) continue;
                line = trimLine(line);
                if(PRINT_OUTPUT) cout << "Cmd " << commandNum++ << ": " << line << endl;
                string cmd = getToken(line, 0);
                string secondToken = getToken(line, 1);
                ui tokenCount = countTokens(line);
                if(!symbolTable.inputValidation(cmd, tokenCount, secondToken, line)){
                    continue;
                }

                if(cmd == "I"){
                    string name = secondToken;
                    ui pos = line.find(name);
                    string type = line.substr(pos + name.length() + 1);
                    symbolTable.insert(name, type);
                }
                else if(cmd == "L"){
                    
                    string name = secondToken;
                    symbolTable.lookUp(name);
                }
                else if(cmd == "D"){
                    
                    string name = secondToken;
                    symbolTable.remove(name);
                }
                else if(cmd == "S"){
                    
                    symbolTable.enterScope();
                }
                else if(cmd == "E"){
                    
                    symbolTable.exitScope();
                }
                else if(cmd == "P"){
                    string cmd2 = secondToken;
                    (cmd2 == "A") ? symbolTable.printAll() : symbolTable.printCurrent();

                }
                else if(cmd == "Q"){
                    symbolTable.quit();
                    break;
                }
            }

            if(hashFunction == SDBMHash){
                cout << "Performace for SDBM hash: " << endl;
            } else if(hashFunction == JENKINSHash){
                cout << "Performace for JENKINS hash: " << endl;
            } else{
                cout << "Performace for MURMUR hash: " << endl;
            }
            cout << "Collision Count: " << symbolTable.getCollisionCount() << endl;
            cout << "Total Bucket Size: " << symbolTable.getTotalBucketSize() << endl;
            cout << "Actually Inserted: " << symbolTable.getInsertions() << endl;
            cout << "Performance Ratio: " << (float) symbolTable.getCollisionCount() / (float) symbolTable.getTotalBucketSize() << endl << endl;
            fin.clear();                 // Clear any error flags (like EOF)
            fin.seekg(0, ios::beg);      
        } 
        cout << endl;


    }
    

}