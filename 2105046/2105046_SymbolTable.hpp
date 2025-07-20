#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include "2105046_ScopeTable.hpp"

class SymbolTable{
    private:
    ScopeTable* currentScopeTable;
    ui scopeCount;
    ScopeTable* mainScopeTable;
    HashFn hash;
    ui collisionCount;
    ui totalBucketSize;
    ui numBuckets;
    ui numInsertion;

    public:
    SymbolTable(HashFn hashFn = SDBMHash, ui numBuckets = DEFAULT_BUCKETS){
        this->scopeCount = 1;
        this->mainScopeTable = new ScopeTable(scopeCount++, nullptr, numBuckets, hashFn);
        this->currentScopeTable = mainScopeTable;
        this->hash = hashFn;
        this->collisionCount = 0;
        this->totalBucketSize = 0;
        this->numBuckets = numBuckets;
        this->numInsertion = 0;
    }

    void enterScope(){
        ScopeTable* prevCurrScopeTable = this->currentScopeTable;
        prevCurrScopeTable->incChildren();
        this->currentScopeTable = new ScopeTable(prevCurrScopeTable->getNumChildren(), prevCurrScopeTable, numBuckets, hash);
    }

    void exitScope(){
        if(this->currentScopeTable == this->mainScopeTable){
            if(PRINT_OUTPUT) cout << "\tCan't Remove the Main Scope Table" << endl;
            return;
        }
        ScopeTable* scopeTable = this->currentScopeTable;
        this->collisionCount += scopeTable->getCollisionCount();
        this->totalBucketSize += scopeTable->getNumBuckets();
        this->currentScopeTable = this->currentScopeTable->getParent();
        delete scopeTable;
    }

    bool insert(string& name, string type, FILE* fileptr = nullptr, string data_type = "", bool isArray = false){
        bool result = currentScopeTable->insert(name, type, fileptr, data_type, isArray);
        if(result) numInsertion++;
        return result;
    }

    bool remove(string& name){
        return currentScopeTable->Delete(name);
    }

    SymbolInfo * lookUp(string& name, FILE * fileptr = nullptr){
        SymbolInfo * symbol = currentScopeTable->lookUp(name, fileptr);
        if(symbol == nullptr){
            if(PRINT_OUTPUT) cout << "\t'"<< name <<"' not found in any of the ScopeTables" << endl;
        }
        return symbol;
    }

    void printCurrent(){
        currentScopeTable->print("\t");
    }

    void quit(){
        while(currentScopeTable){
            ScopeTable * tmp = currentScopeTable->getParent();
            this->collisionCount += currentScopeTable->getCollisionCount();
            this->totalBucketSize += currentScopeTable->getNumBuckets();
            delete currentScopeTable;
            currentScopeTable = tmp;
        }
    }

    void printAll(){
        ScopeTable * scopeTable = this->currentScopeTable;
        string indent = "";
        while(scopeTable){
            scopeTable->print(indent);
            scopeTable = scopeTable->getParent();
            // indent += "\t";
        }
        
    }

    void printAllFile(FILE* fileptr){
        this->currentScopeTable->printFile(fileptr);
    }

    void printForParser(){
        this->currentScopeTable->printForParser();
    }

    ui getCollisionCount(){
        return this->collisionCount;
    }

    ui getTotalBucketSize(){
        return this->totalBucketSize;
    }

    bool inputValidation(const string& cmd, const ui & toks, const string & secondToken = "", const string & line = ""){

        if (cmd == "I") {
            // number of tokens should be greater than 3
            string typeToken = getTokens(line, 2);
            bool stOrUni = (typeToken == "STRUCT" || typeToken == "UNION");
            bool condition1 = toks < 3;
            // structs and unions must be or add lenth parameters and must have more than 4 parameters
            bool condition2 = (stOrUni && (toks % 2 == 0 || toks < 5));
            // other stuffs except funcs, structs and union must have only 3 parameters
            bool condition3 = !(typeToken == "FUNCTION" || stOrUni) && toks > 3;

            bool condition4 = false;

            // checking for same variable name in struct
            if(stOrUni && !condition2){
                ui structTokens = (toks - 3) / 2;
                string structVars[structTokens];
                ui i = 0;
                while(i < structTokens){
                    structVars[i] = getTokens(line, i * 2 + 4);
                    for(ui j = 0; j < i; j++){
                    
                        if(structVars[i] == structVars[j]){
                            condition4 = true;
                            break;
                        }
                    }
                    if(condition4) break;
                    i++;
                }
            }
            

            if (condition1 || condition2 || condition3) { 
                if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command I\n";
                return false;
            }

            if(condition4){
                if(PRINT_OUTPUT) cout << "\tDuplicate Parameters are not allowed\n";
                return false;
            }

            
            
            return true;
        }
        else if (cmd == "L") {
            if (toks == 2) return true;
            if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command L\n";
            return false;
        }
        else if (cmd == "D") {
            if (toks == 2) return true;
            if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command D\n";
            return false;
        }
        else if (cmd == "P") {
            if (toks == 2) {
                
                if (secondToken == "A" || secondToken == "C") return true;
                else {
                    if(PRINT_OUTPUT) cout << "\tP command must be “P A” or “P C”\n";
                    return false;
                }
            }
            if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command P\n";
            return false;
        }
        else if (cmd == "S" || cmd == "E") {
            if (toks == 1) return true;
            if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command " << cmd << "\n";
            return false;
        }
        else if (cmd == "Q") {
            if (toks == 1) return true;
            if(PRINT_OUTPUT) cout << "\tNumber of parameters mismatch for the command Q\n";
            return false;
        }

        if(PRINT_OUTPUT) cout << "\tUnknown command " << cmd << "\n";
        return false;
    }

    // string getRandomName(){
    //     ui size = currentScopeTable->getNumBuckets();
    //     return currentScopeTable->getNameAtIndex(rand() % size);
    // }


    ui getInsertions(){
        return this->numInsertion;
    }

    bool isMainScope(){
        return mainScopeTable == currentScopeTable;
    }

    ~SymbolTable(){
        while(currentScopeTable){
            ScopeTable * tmp = currentScopeTable->getParent();
            delete currentScopeTable;
            currentScopeTable = tmp;
        }
    }

};

#endif