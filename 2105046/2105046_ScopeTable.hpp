#ifndef SCOPETABLE_HPP
#define SCOPETABLE_HPP

#include "2105046_SymbolInfo.hpp"
#include "2105046_helperHash.hpp"


class ScopeTable{
    private:
    SymbolInfo ** chainingTable;
    ui numBuckets;
    HashFn hash;
    ui currSize;
    ui maxChainLength;
    // ui numInsertions;
    ui currMaxChainLength;
    ui tableID;
    ScopeTable* parent;
    // ui numDeletions;
    ui collisionCount;
    ui numChildren;

    public:
    ScopeTable(ui tableID = 0, ScopeTable* parent = nullptr, ui numBuckets = DEFAULT_BUCKETS, HashFn hash = SDBMHash, ui maxChainLength = MAX_CHAIN_LENGTH){
        this->hash = hash;
        this->numBuckets = numBuckets;
        chainingTable = new SymbolInfo*[numBuckets]();
        this->currSize = 0;
        this->maxChainLength = maxChainLength;
        // this->numInsertions = 0;
        // this->numDeletions = 0;
        this->currMaxChainLength = 0;
        this->parent = parent;
        this->tableID = tableID;
        if(PRINT_OUTPUT) cout << "\tScopeTable# " << tableID << " created" << endl;
        this->collisionCount = 0;
        this->numChildren = 0;
    }

    void rehash(bool increase = true){
        
        if(!REHASH){
            return;
        }
        ui newBuckets = increase? this->numBuckets * 2: this->numBuckets / 2;
        
        // never go below DEFAULT_BUCKETS
        if (newBuckets < DEFAULT_BUCKETS){
            return;
        }
        
        SymbolInfo** newTable = new SymbolInfo*[newBuckets]();

        for(ui i = 0; i < this->numBuckets; i++){
            SymbolInfo* current = this->chainingTable[i];
            while(current){
                SymbolInfo* next = current->next;
                ui index = this->hash(current->getName(), newBuckets);
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

    bool insert(string& name, string type, FILE * fileptr = nullptr, string data_type="", bool isArray = false){
        if(name == "" || type == ""){
            if(PRINT_OUTPUT) cout << "\tInvalid Operation (name or type can't be empty)" << endl;
        }

        SymbolInfo* symbol = new SymbolInfo(name, type, nullptr, data_type, isArray);
        ui index = this->hash(name, this->numBuckets);
        // if(PRINT_OUTPUT) cout << index << endl;
        SymbolInfo * node = chainingTable[index];
        // creating a dummy for easier linked list operation
        SymbolInfo * dummy = new SymbolInfo("", "", node);
        SymbolInfo * prev = dummy;
        ui chainLength = 0;
        while(node){
            if(node->getName() == symbol->getName()){
                if(PRINT_OUTPUT) cout << "\t'"<< name <<"' already exists in the current ScopeTable" << endl;
                if(fileptr){
                    fprintf(fileptr, "< %s : %s > already exists in ScopeTable# ", name.c_str(), symbol->getType().c_str());
                    this->recursiveIDPrintFile(fileptr, true);
                    fprintf(fileptr, " at position %d, %d\n", index, chainLength);
                }
                delete symbol;
                delete dummy;
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

        // if(PRINT_OUTPUT) cout << "\tInserted in ScopeTable# " << tableID << " at position " << index + 1 << ", " << chainLength << endl;

        if(chainLength > this->currMaxChainLength){
            this->currMaxChainLength = chainLength;
        }

        // checking if rehasing is necessary or not;
        if(this->currSize > AVG_CHAIN_LENGTH * this->numBuckets ||this->currMaxChainLength > this->maxChainLength){
            rehash(true);
        }
        this->currSize++;
        // this->numInsertions++;
        return true;
    }

    SymbolInfo* lookUp(string& name, FILE* fileptr = nullptr){
        // getting the hash
        ui index = hash(name, numBuckets);

        SymbolInfo* symbol = chainingTable[index];
        ui chainLength = 1;
        if(PRINT_OUTPUT) cout << "Debug: Comes here" << endl;
        if(PRINT_OUTPUT) cout << symbol->getName() << ", " << name << endl;
        while(symbol && symbol->getName() != name){
            symbol = symbol->next;
            chainLength++;
        }

        if(symbol == nullptr){
            if(parent){
                return parent->lookUp(name, fileptr);
            }
            return nullptr;
        }
        else{
            if(PRINT_OUTPUT) cout << "\t'" << name << "' found in ScopeTable# " << tableID << " at position " << index + 1 << ", " << chainLength << endl;
            if(fileptr){
                fprintf(fileptr, "< %s : %s > already exists in ScopeTable# ", name.c_str(), symbol->getType().c_str());
                this->recursiveIDPrintFile(fileptr, true);
                fprintf(fileptr, " at position %d, %d\n", index, chainLength - 1);
            }
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
            if(PRINT_OUTPUT) cout << "\tNot found in the current ScopeTable" << endl;
            delete dummy;
            return false;
        }
        prev->next = symbol->next;
        delete symbol;
        if(prev == dummy){
            chainingTable[index] = prev->next;
        }
        delete dummy;
        // if(PRINT_OUTPUT) cout << "\tDeleted '" << name << "' from ScopeTable# " << tableID <<  " at position " << index + 1 << ", " << chainingLength << endl;
        this->currSize--;

        if(currSize / 2 < numBuckets){
            rehash(false);
        }
        return true;
    }

    void recursiveIDPrint(bool flag){
        if(parent == nullptr){
            cout << tableID;
            if(!flag){
                cout << ".";
            }
            return;
        }
        parent->recursiveIDPrint(false);
        cout << tableID;
        if(!flag){
            cout << ".";
        }
    }

    void recursiveIDPrintFile(FILE* fileptr, bool flag){
        if(parent == nullptr){
            if(fileptr){
                fprintf(fileptr, "%d", tableID);
            } else {
                cout << tableID;
            }
            
            if(!flag){
                if(fileptr){
                    fprintf(fileptr, ".");
                } else {
                    cout << ".";
                }
            }
            return;
        }
        parent->recursiveIDPrintFile(fileptr, false);
        fprintf(fileptr, "%d", tableID);
        if(!flag){
            fprintf(fileptr, ".");
        }
    }

    void print(string indent = ""){
        indent = "";
        if(PRINT_OUTPUT) cout <<  "ScopeTable # ";
        this->recursiveIDPrint(true);

        for(ui i = 0; i < numBuckets; i++){
            SymbolInfo* symbol = chainingTable[i];
            if(symbol == nullptr) continue;
            if(PRINT_OUTPUT) cout << i + 1 << "--> ";
            while(symbol){
                symbol->print();
                if(symbol->next){
                    if(PRINT_OUTPUT) cout << "";
                }
                symbol = symbol->next;
            }
            if(PRINT_OUTPUT) cout << endl;
            
        }
        // if(this->parent != nullptr){
        //     parent->print("     " + indent);
        // }
    }

    void printFile(FILE* fileptr){
        fprintf(fileptr, "ScopeTable # ");
        this->recursiveIDPrintFile(fileptr, true);
        fprintf(fileptr, "\n");
        for(ui i = 0; i < numBuckets; i++){
            SymbolInfo* symbol = chainingTable[i];
            if(symbol == nullptr) continue;
            // if(PRINT_OUTPUT) cout << i + 1 << "--> ";
            fprintf(fileptr, "%d --> ", i);
            while(symbol){
                symbol->printFile(fileptr);
                symbol = symbol->next;
            }
            fprintf(fileptr, "\n");
        }
        if(parent){
            parent->printFile(fileptr);
        }
        
    }


    void printForParser(){
        // fprintf(fileptr, "ScopeTable # ");
        cout << "ScopeTable # ";
        this->recursiveIDPrint(true);
        cout << endl;
        for(ui i = 0; i < numBuckets; i++){
            SymbolInfo* symbol = chainingTable[i];
            if(symbol == nullptr) continue;
            // if(PRINT_OUTPUT) cout << i + 1 << "--> ";
            cout << i << " --> ";
            // fprintf(fileptr, "%d --> ", i);
            while(symbol){
                symbol->printFile(nullptr);
                symbol = symbol->next;
            }
             //fprintf(fileptr, "\n");
            cout << endl;
        }
        if(parent){
            parent->printForParser();
        }
        
    }

    ScopeTable* getParent(){
        return parent;
    }

    ui getNumBuckets(){
        return this->numBuckets;
    }

    // string getNameAtIndex(ui bucket){
    //     while(this->chainingTable[bucket] == nullptr){
    //         bucket = (bucket + 1) % this->numBuckets;
    //     }
    //     return chainingTable[bucket]->getName();
    // }

    ui getCollisionCount(){
        return this->collisionCount;
    }

    // ui getNoInsertions(){
    //     return this->numInsertions;
    // }

    ui getNumChildren(){
        return numChildren;
    }

    void incChildren(){
        this->numChildren++;
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
        if(PRINT_OUTPUT) cout << "\tScopeTable# " << tableID << " removed" << endl;
    }

};


#endif