#include <iostream>
#include <string>
#include <cstdio>   
#include <sstream>


using namespace std;


#define DEFAULT_BUCKETS 7
#define MAX_CHAIN_LENGTH 3
#define REHASH_INTERVAL 100
#define MurmurSeed 5113
#define JENKINS_A 0x9e3779b9U
#define JENKINS_B 0x9e3779b9U
#define JENKINS_C 0U
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef ui (*HashFn)(const string&, const ui &);


#include "2105046_SymbolInfo.hpp"

// helping hash functions
// Hash functions sources:  
//   - SDBM: (https://www.programmingalgorithms.com/algorithm/ sdbm-hash/cpp/)
//   - MurmurHash2: Austin Appleby, https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp (slightly modified MurmurHash2A)
//   - Bob Jenkins' one-at-a-time hash adapted from http://burtleburtle.net/bob/hash/doobs.html

static ui SDBMHash(const string& str, const ui & numBuckets) {
	ui hash = 0;
	unsigned int i = 0;
	unsigned int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % numBuckets;
	}

	return hash;
}

static ui MURMURhash(const string & key, const ui & numBuckets)
{
    int seed = MurmurSeed;
    const uint32_t m = 0x5bd1e995;
    const ui r = 24;
    const uint8_t *data = reinterpret_cast<const uint8_t *>(key.c_str());
    size_t length = key.length();
    uint32_t h = seed ^ (length * m); 

    while (length >= 4)
    {
        uint32_t k = *reinterpret_cast<const uint32_t *>(data);
        k *= m;
        k ^= k >> r;
        k *= m;
        h ^= k;
        h *= m;
        data += 4;
        length -= 4;
    }

    switch (length)
    {
    case 3:
        h ^= data[2] << 16;
        break;
    case 2:
        h ^= data[1] << 8;
        break;
    case 1:
        h ^= data[0];
        h *= m;
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    // Ensure the hash is non-zero
    return h % numBuckets;
}

static ui JENKINSHash(const string& key, const ui & numBuckets) {
    typedef uint32_t ub4;
    typedef uint8_t  ub1;
    const ub1* k = reinterpret_cast<const ub1*>(key.c_str());
    ub4 length = static_cast<ub4>(key.length());
    ub4 a = JENKINS_A, b = JENKINS_B, c = JENKINS_C;

    // mix function (macro) as per Jenkins' original
    #define mix(a,b,c)                          \
        a -= b; a -= c; a ^= (c >> 13);        \
        b -= c; b -= a; b ^= (a << 8);         \
        c -= a; c -= b; c ^= (b >> 13);        \
        a -= b; a -= c; a ^= (c >> 12);        \
        b -= c; b -= a; b ^= (a << 16);        \
        c -= a; c -= b; c ^= (b >> 5);         \
        a -= b; a -= c; a ^= (c >> 3);         \
        b -= c; b -= a; b ^= (a << 10);        \
        c -= a; c -= b; c ^= (b >> 15);

    ub4 len = length;
    while (len >= 12) {
        a += (k[0]  | (ub4)k[1]  << 8 | (ub4)k[2]  << 16 | (ub4)k[3]  << 24);
        b += (k[4]  | (ub4)k[5]  << 8 | (ub4)k[6]  << 16 | (ub4)k[7]  << 24);
        c += (k[8]  | (ub4)k[9]  << 8 | (ub4)k[10] << 16 | (ub4)k[11] << 24);
        mix(a, b, c);
        k += 12;
        len -= 12;
    }
    c += length;
    switch (len) {
        case 11: c += (ub4)k[10] << 24;
        case 10: c += (ub4)k[9]  << 16;
        case 9:  c += (ub4)k[8]  << 8;
        case 8:  b += (ub4)k[7]  << 24;
        case 7:  b += (ub4)k[6]  << 16;
        case 6:  b += (ub4)k[5]  << 8;
        case 5:  b += (ub4)k[4];
        case 4:  a += (ub4)k[3]  << 24;
        case 3:  a += (ub4)k[2]  << 16;
        case 2:  a += (ub4)k[1]  << 8;
        case 1:  a += (ub4)k[0];
        case 0:  break;
    }
    mix(a, b, c);
    #undef mix
    return c % numBuckets;
}


int nextPrime(int n)
{
    if (n <= 1)
    {
        n = 2;
        return n;
    }
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            n++;
            i = 2;
        }
        else
        {
            i++;
        }
    }
    return n;
}


class ScopeTable{
    private:
    SymbolInfo ** chainingTable;
    ui numBuckets;
    HashFn hash;
    ui currSize;
    ui maxChainLength;
    ui numInsertions;
    ui currMaxChainLength;
    ui tableID;
    ScopeTable* parent;
    ui numDeletions;
    ui collisionCount;

    public:
    ScopeTable(ui tableID = 0, ScopeTable* parent = nullptr, ui numBuckets = DEFAULT_BUCKETS, HashFn hash = SDBMHash, ui maxChainLength = MAX_CHAIN_LENGTH){
        this->hash = hash;
        this->numBuckets = numBuckets;
        chainingTable = new SymbolInfo*[numBuckets]();
        this->currSize = 0;
        this->maxChainLength = maxChainLength;
        this->numInsertions = 0;
        this->numDeletions = 0;
        this->currMaxChainLength = 0;
        this->parent = parent;
        this->tableID = tableID;
        cout << "\tScopeTable# " << tableID << " created" << endl;
        this->collisionCount = 0;
    }

    void rehash(bool increase = true){
        // TODO: COMPLETE THE REHASHING
        ui newBuckets = increase? this->numBuckets * 2: this->numBuckets / 2;

        // never go below DEFAULT_BUCKETS
        if (newBuckets < DEFAULT_BUCKETS)
            newBuckets = DEFAULT_BUCKETS;
        
        SymbolInfo** newTable = (SymbolInfo**) calloc(newBuckets, sizeof(SymbolInfo*));

        for(ui i = 0; i < this->numBuckets; i++){
            SymbolInfo* current = this->chainingTable[i];
            while(current){
                SymbolInfo* next = current->next;
                ui index = this->hash(current->getName(), this->numBuckets);
                current->next = newTable[index];
                newTable[index] = current;
                current = next;
            }
        }

        // free(this->chainingTable);
        delete[] this->chainingTable;

        this->chainingTable = newTable;
        this->numBuckets = newBuckets;

        this->currMaxChainLength = 0;
        for(ui i = 0; i < this->numBuckets; i++){
            SymbolInfo * current = chainingTable[i];
            ui chainLength = 0;
            while(current){
                chainLength++;
                current = current->next;
            }
            this->currMaxChainLength = max(this->currMaxChainLength, chainLength);
        }
    }

    bool insert(string& name, string type){
        if(name == "" || type == ""){
            cout << "\tInvalid Operation (name or type can't be empty)" << endl;
        }

        SymbolInfo* symbol = new SymbolInfo(name, type);
        ui index = this->hash(name, this->numBuckets);
        // cout << index << endl;
        SymbolInfo * node = chainingTable[index];
        // creating a dummy for easier linked list operation
        SymbolInfo * dummy = new SymbolInfo("", "", node);
        SymbolInfo * prev = dummy;
        ui chainLength = 0;
        while(node){
            if(node->getName() == symbol->getName()){
                cout << "\t'"<< name <<"' already exists in the current ScopeTable" << endl;
                return false;
            }
            prev = node;
            node = node->next;
            chainLength++;
        }
        chainLength++;
        prev->next = symbol;
        if(dummy->next == symbol){
            chainingTable[index] = symbol;
        } else{
            collisionCount++;
        }
        delete dummy;

        cout << "\tInserted in ScopeTable# " << tableID << " at position " << index + 1 << ", " << chainLength << endl;

        if(chainLength > this->currMaxChainLength){
            this->currMaxChainLength = chainLength;
        }

        // checking if rehasing is necessary or not;
        if((this->numInsertions != 0 && this->numInsertions % REHASH_INTERVAL == 0 and this->currMaxChainLength > this->maxChainLength)){
            rehash(true);
        }
        this->currSize++;
        this->numInsertions++;
        return true;
    }

    SymbolInfo* lookUp(string& name){
        // getting the hash
        ui index = hash(name, numBuckets);

        SymbolInfo* symbol = chainingTable[index];
        ui chainLength = 1;
        // cout << "Debug: Comes here" << endl;
        // cout << symbol->getName() << ", " << name << endl;
        while(symbol && symbol->getName() != name){
            symbol = symbol->next;
            chainLength++;
        }

        if(symbol == nullptr){
            if(parent){
                return parent->lookUp(name);
            }
            return nullptr;
        }
        else{
            cout << "\t'" << name << "' found in ScopeTable# " << tableID << " at position " << index + 1 << ", " << chainLength << endl;
        }
        return symbol;
    }

    bool Delete(string & name){
        ui index = this->hash(name, this->numBuckets);
        SymbolInfo* symbol = this->chainingTable[index];
        SymbolInfo* dummy = new SymbolInfo("", "", symbol);
        SymbolInfo* prev = dummy;
        ui chainingLength = 1;
        while(symbol){
            if(symbol->getName() == name){
                break;
            }
            prev = symbol;
            symbol = symbol->next;
            chainingLength++;
        }
        
        if(symbol == nullptr){
            cout << "\tNot found in the current ScopeTable" << endl;
            return false;
        }
        prev->next = symbol->next;
        delete symbol;
        if(prev == dummy){
            chainingTable[index] = prev->next;
        }
        delete dummy;
        cout << "\tDeleted '" << name << "' from ScopeTable# " << tableID <<  " at position " << index + 1 << ", " << chainingLength << endl;
        this->currSize--;
        this->numDeletions++;
        if(numDeletions != 0 && numDeletions % REHASH_INTERVAL == 0 && currSize / 2 < numBuckets){
            rehash(false);
        }
        return true;
    }

    void print(string indent = ""){
        cout << indent <<  "ScopeTable# " << tableID << endl;

        for(ui i = 0; i < numBuckets; i++){
            cout << indent << i + 1 << "--> ";
            SymbolInfo* symbol = chainingTable[i];
            while(symbol){
                symbol->print();
                if(symbol->next){
                    cout << "";
                }
                symbol = symbol->next;
            }
            cout << endl;
        }
        // if(this->parent != nullptr){
        //     parent->print("     " + indent);
        // }
    }

    ScopeTable* getParent(){
        return parent;
    }

    ~ScopeTable(){
        for(ui i = 0; i < this->numBuckets; i++){
            SymbolInfo* cur = chainingTable[i];
            while(cur){
                SymbolInfo* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
        delete[] chainingTable;
        cout << "\tScopeTable# " << tableID << " removed" << endl;
    }

};


class SymbolTable{
    private:
    ScopeTable* currentScopeTable;
    ui scopeCount;
    ScopeTable* mainScopeTable;
    HashFn hash;

    public:
    SymbolTable(HashFn hashFn = SDBMHash, ui numBuckets = DEFAULT_BUCKETS){
        scopeCount = 1;
        mainScopeTable = new ScopeTable(scopeCount++, nullptr, numBuckets, hashFn);
        currentScopeTable = mainScopeTable;
        hash = hashFn;
    }

    void enterScope(){
        this->currentScopeTable = new ScopeTable(scopeCount++, this->currentScopeTable, DEFAULT_BUCKETS, hash);
    }

    void exitScope(){
        if(this->currentScopeTable == this->mainScopeTable){
            cout << "\tCan't Remove the Main Scope Table" << endl;
            return;
        }
        ScopeTable* scopeTable = this->currentScopeTable;
        this->currentScopeTable = this->currentScopeTable->getParent();
        delete scopeTable;
    }

    bool insert(string& name, string type){
        return currentScopeTable->insert(name, type);
    }

    bool remove(string& name){
        return currentScopeTable->Delete(name);
    }

    SymbolInfo * lookUp(string& name){
        SymbolInfo * symbol = currentScopeTable->lookUp(name);
        if(symbol == nullptr){
            cout << "\t'"<< name <<"' not found in any of the ScopeTables" << endl;
        }
        return symbol;
    }

    void printCurrent(){
        currentScopeTable->print("\t");
    }

    void quit(){
        while(currentScopeTable){
            ScopeTable * tmp = currentScopeTable->getParent();
            delete currentScopeTable;
            currentScopeTable = tmp;
        }
    }

    void printAll(){
        ScopeTable * scopeTable = currentScopeTable;
        string indent = "\t";
        while(scopeTable){
            scopeTable->print(indent);
            scopeTable = scopeTable->getParent();
            indent += "\t";
        }
    }

    bool inputValidation(const string& cmd, const ui & toks, const string & secondToken = ""){

        if (cmd == "I") {
            if (toks < 3 || ((secondToken == "STRUCT" || secondToken == "UNION") && toks % 2 == 0)) { 
                cout << "\tNumber of parameters mismatch for I\n";
                return false;
            }
            
            return true;
        }
        else if (cmd == "L") {
            if (toks == 2) return true;
            cout << "\tNumber of parameters mismatch for the command L\n";
            return false;
        }
        else if (cmd == "D") {
            if (toks == 2) return true;
            cout << "\tNumber of parameters mismatch for the command D\n";
            return false;
        }
        else if (cmd == "P") {
            if (toks == 2) {
                
                if (secondToken == "A" || secondToken == "C") return true;
                else {
                    cout << "\tP command must be “P A” or “P C”\n";
                    return false;
                }
            }
            cout << "\tNumber of parameters mismatch for the command P\n";
            return false;
        }
        else if (cmd == "S" || cmd == "E") {
            if (toks == 1) return true;
            cout << "\tNo extra parameters allowed for " << cmd << "\n";
            return false;
        }
        else if (cmd == "Q") {
            if (toks == 1) return true;
            cout << "\tNo extra parameters allowed for Q\n";
            return false;
        }

        cout << "\tUnknown command “" << cmd << "”\n";
        return false;
    }

    ~SymbolTable(){
        while(currentScopeTable){
            ScopeTable * tmp = currentScopeTable->getParent();
            delete currentScopeTable;
            currentScopeTable = tmp;
        }
    }

};



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
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        string secondToken = "";
        ui tokenCount = countTokens(line);
        ss >> secondToken;
        
        // validating input
        if(!symbolTable.inputValidation(cmd, tokenCount, secondToken)){
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
}
