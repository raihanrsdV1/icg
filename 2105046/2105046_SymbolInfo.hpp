#ifndef SYMBOLINFO_HPP
#define SYMBOLINFO_HPP

#include "2105046_helperFunctions.hpp"



class SymbolInfo{
    private:
        string name;
        string type;
        string dataType;
        string returnType;
        vector<string> parameters;
        bool isDeclaredOnly;
        bool isArray;
        int offset;
        bool isGlobal;
        int arrSize;
        


    public:
        SymbolInfo* next;
        SymbolInfo(){
            this->name = "";
            this->type = "";
            this->dataType = "";
            this->returnType = "";            
            isDeclaredOnly = false;
            isArray = false;
            this->offset = 0;
            this->isGlobal = false;
            this->arrSize = 0;
        }
        SymbolInfo(string name = "", string type = "", SymbolInfo* next = nullptr, string data_type = "", bool isArray = false){
            this->name = name;
            string tmp = getTokens(type, 0);
            if(tmp == "STRUCT" || tmp == "UNION"){
                int i = 1;
                tmp += ",{";
                while(getTokens(type, i) != ""){
                    string tmp2 = getTokens(type, i);
                    string name2 = getTokens(type, i + 1);
                    // if(name2 == "" || tmp2 == ""){
                    //     // throw some error 
                    //     // didn't need to handle it because i wasn't even 
                    //     // letting the invalid inputs to pass
                    // }
                    tmp+= ("(" + tmp2 + "," + name2 + ")");
                    i += 2;
                    if(getTokens(type, i) != ""){
                        tmp+= ",";
                    }
                }
                tmp+= "}";
                this->type = tmp;
            }else if(tmp == "FUNCTION"){
                string returnType = getTokens(type, 1);
                tmp += "," + returnType + "<==(";
                int i = 2;
                while(getTokens(type, i) != ""){
                    tmp+=getTokens(type, i++);
                    if(getTokens(type, i) != ""){
                        tmp+= ",";
                    }
                }
                tmp+=")";
                this->type = tmp;
            }
            else{
                this->type = type;
            }
            
            this->next = next;
            this->dataType = data_type;
            this->isDeclaredOnly = false;
            this->returnType = "";
            this->isArray = isArray;
        }

        string getName(){
            return name;
        }

        string getType(){
            return type;
        }

        // inline string getDataType(){
        //     return this->dataType;
        // }

        void setName(string name){
            this->name = name;
        }

        bool getIsDeclaredOnly(){
            return this->isDeclaredOnly;
        }

        void print(){
            if(PRINT_OUTPUT) cout << "<" << name << " : " << type << ">";
        }

        void printFile(FILE* fileptr){
            if(fileptr){
                fprintf(fileptr, "< %s : %s >", name.c_str(), type.c_str());
            }
            else {
                cout << "< " << name << " : " << type << " >";
            }
            
        }

        void setParameters(vector<string> parameters, string returnType){
            this->parameters = parameters;
            this->returnType = returnType;
        }

        void setIsDeclaredOnly(bool flag){
            this->isDeclaredOnly = flag;
        }
        void setIsArray(){
            this->isArray = true;
        }

        bool getIsArray(){
            return this->isArray;
        }

        string getDataType() {
            return this->dataType;
        }

        string getReturnType() {
            return this->returnType;
        }

        int getOffset(){
            return this->offset;
        }

        int getArrSize(){
            return this->arrSize;
        }

        bool getIsGlobal(){
            return this->isGlobal;
        }

        vector<string> getParameters(){
            return parameters;
        }

        void setAsmData(int offset, bool isGlobal){
            this->offset = offset;
            this->isGlobal  = isGlobal;
        }

        void setArrSize(int arrSize){
            this->arrSize = arrSize;
        }

        


        ~SymbolInfo(){
            
        }
};

#endif 