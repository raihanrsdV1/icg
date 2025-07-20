
#include "2105046_SymbolTable.hpp"




int main(int argc, char* argv[]){
    if (argc < 3 || argc > 4) {
        cerr << "Usage: " << argv[0] << " <input-file> <output-file> [SDBM|MURMUR|JENKINS]\n";
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    HashFn hashFunction = SDBMHash; // default
    if (argc == 4) {
        if      (strcmp(argv[3], "SDBM")    == 0) hashFunction = SDBMHash;
        else if (strcmp(argv[3], "MURMUR")  == 0) hashFunction = MURMURhash;
        else if (strcmp(argv[3], "JENKINS") == 0) hashFunction = JENKINSHash;
        else {
            cerr << "Unknown hash “" << argv[3] << "”, using default SDBM\n";
        }
    }

    ui bucketSize;
    if (!(cin >> bucketSize)) {
        cerr << "Failed to read bucket size\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    ui commandNum = 1;
    SymbolTable symbolTable(hashFunction, bucketSize);

    while(true){
        string line;
        if(!getline(cin, line)) break;
        if(line.empty()) continue;
        line = trimLine(line);
        cout << "Cmd " << commandNum++ << ": " << line << endl;
        string cmd = getToken(line, 0);
        string secondToken = getToken(line, 1);
        ui tokenCount = countTokens(line);
        

        if(!symbolTable.inputValidation(cmd, tokenCount, secondToken, line)){
            continue;
        }

        if(cmd == "I"){
            string name = secondToken;
            ui pos = line.find(name);
            string type = trimLine(line.substr(pos + name.length() + 1));
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
    // cout << symbolTable.getCollisionCount() << endl;
}