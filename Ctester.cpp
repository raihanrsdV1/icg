#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "antlr4-runtime.h"
#include "C2105046Lexer.h"
#include "C2105046Parser.h"
#include "2105046/2105046_SymbolTable.hpp"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream
ofstream codeFile;
ofstream tmpFile;
ofstream optimizedCodeFile;
ifstream inputCodeFile;


vector<SymbolInfo *> globalVariables;

int syntaxErrorCount;
SymbolTable symbolTable;
bool scoped = false;
bool inDeclaration = false;
vector<int> scopeOffset;
bool pop_flag = true;

string current_return_label = "";

#include <algorithm> 
#include <cctype>
#include <locale>

// Trim from the start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Trim from the end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}



void optimize(){
    vector<string> codes;

    string line;
    while(getline(inputCodeFile, line)){
        codes.push_back(line);
    }

    // Removing Comments
    vector<string> tmpCode;
    for(auto line: codes){
        int position = line.find(';');
        line = line.substr(0, position);
        tmpCode.push_back(line);
    }
    codes = tmpCode;
    tmpCode.clear();

    int first_case = 0;
    int second_case = 0;
    int third_case = 0;
    int fourth_case = 0;

    // removing push pop same stuff same line
    string push_reg = "";
    for(auto line: codes){
        if(line == "" || line == "\t") continue;
        // transform(line.begin(), line.end(),line.begin(), toupper);
        auto position = line.find("PUSH");
        auto pop_position = line.find("POP");
        if(pop_position != string::npos){
           string pop_reg = line.substr(pop_position + 4);
            ltrim(pop_reg);
            rtrim(pop_reg);
            ltrim(push_reg);
            rtrim(push_reg);
           // cout << pop_reg << endl;
           if(pop_reg != push_reg){
                if(push_reg != ""){
                    tmpCode.push_back("\tPUSH "+ push_reg);
                }
                tmpCode.push_back("\tPOP "+ pop_reg);
           } else {
            // cout << "found1" << endl;
            first_case++;
           }
            push_reg = "";
        } else if(position != string::npos){
            if(push_reg != ""){
                tmpCode.push_back("\tPUSH " + push_reg);
                push_reg = "";
            }
            push_reg = line.substr(position + 5);
        } else{
            if(push_reg != ""){
                tmpCode.push_back("\tPUSH " + push_reg);
                push_reg = "";
            }
            tmpCode.push_back(line);
        }
    }
    codes = tmpCode;
    tmpCode.clear();

    // handling ADD AX, 0
    for(auto line: codes){
        auto position = line.find("ADD");
        if(position != string::npos){
            auto position_0 = line.find(", ");
            // cout << line << endl;
            string second_oper = line.substr(position_0 + 2);
            if(second_oper != "0"){
                tmpCode.push_back(line);
            } else {
                second_case++;
            }
            // cout << second_oper << endl;
        } else {
            tmpCode.push_back(line);
        }
    }



    codes = tmpCode;
    tmpCode.clear();

    string prev_source = "";
    string prev_dest = "";
    for(auto line: codes){
        auto position = line.find("MOV");
        // cout << line << endl;
        if(position != string::npos){
            auto delim_pos = line.find(", ");
            string current_dest = line.substr(position + 4, delim_pos - (position + 4));
            string current_source = line.substr(delim_pos + 2);
            // cout << line << endl;
            // cout << current_dest << " " << current_source << endl;
            if(!(current_source == prev_dest && prev_source == current_dest)){
                tmpCode.push_back(line);
                prev_source = current_source;
                prev_dest = current_dest;
            } else {
                // cout << "found3" << endl;
                third_case++;
            }
        } else {
            tmpCode.push_back(line);
            prev_source = "";
            prev_dest = "";
        }
        
    }

    codes = tmpCode;
    tmpCode.clear();

    // handling redundant labels
    unordered_map<string, string> label_map;

    string prev_label = "";
    for(auto line: codes){
        auto position = line.find(":");
        if(position != string::npos){
            string label = line.substr(0, position);
            ltrim(label);
            rtrim(label);
            if(prev_label != ""){
                label_map.insert({label, prev_label});
                // cout << "found4" << endl;
                fourth_case++;
            } else{
                label_map.insert({label, label});
                prev_label = label;
                tmpCode.push_back(line);
            }
        } else {
            prev_label = "";
            tmpCode.push_back(line);
        }
    }

    codes = tmpCode;
    tmpCode.clear();

    for(auto line: codes){
        string first_word = getTokens(line, 0);
        // cout << first_word << endl;
        if(first_word == "JMP" || first_word == "JL" || first_word == "JE" ||first_word == "JNE" ||first_word == "JG" ||first_word == "JLE" ||first_word == "JGE"){
            string label = getTokens(line, 1);
            if(label_map[label] != label){
                // cout << "replaced " << label << endl;
                tmpCode.push_back("\t" + first_word + " " + label_map[label]);
            } else {
                tmpCode.push_back(line);
            }
        } else {
            tmpCode.push_back(line);
        }
    }

    codes = tmpCode;
    tmpCode.clear();

    


    for(auto line: codes){
        optimizedCodeFile << line << endl;
    }

    cout << "Case 1 optimization: " << first_case << endl;
    cout << "Case 2 optimization: " << second_case << endl;
    cout << "Case 3 optimization: " << third_case << endl;
    cout << "Case 4 optimization: " << fourth_case << endl;
}



int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string outputDirectory = "output/";
    string parserLogFileName = outputDirectory + "parserLog.txt";
    string errorFileName = outputDirectory + "errorLog.txt";
    string lexLogFileName = outputDirectory + "lexerLog.txt";
    string codeFileName = outputDirectory + "code.asm";
    string tmpFileName = outputDirectory + "tmp.asm";
    string optimizedCodeFileName = outputDirectory + "optimized.asm";


    // create output directory if it doesn't exist
    system(("mkdir -p " + outputDirectory).c_str());

    // ---- Output Files ----
    parserLogFile.open(parserLogFileName);
    if (!parserLogFile.is_open()) {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }

    codeFile.open(codeFileName);
    if (!codeFile.is_open()) {
        cerr << "Error opening code log file: " << codeFileName << endl;
        return 1;
    }

    tmpFile.open(tmpFileName);
    if (!tmpFile.is_open()) {
        cerr << "Error opening tmp file: " << tmpFileName << endl;
        return 1;
    }

    // ADD THESE 5 LINES
    // ofstream parserFile(parserLogFileName);
    streambuf* originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(parserLogFile.rdbuf());
   
    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C2105046Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C2105046Parser parser(&tokens);

    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();

    // start parsing at the 'start' rule
    parser.start();

    // ADD THIS LINE BEFORE CLEANUP
    cout.rdbuf(originalCoutBuffer);

    tmpFile.close();

    ifstream dumpTmpFile;
    dumpTmpFile.open(tmpFileName);
    if (!dumpTmpFile.is_open()) {
        cerr << "Error opening tmp file: " << tmpFileName << endl;
        return 1;
    }

    string line;
    while(getline(dumpTmpFile, line)){
        codeFile << line << endl;
    }

    // clean up
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    codeFile.close();
    dumpTmpFile.close();

    inputCodeFile.open(codeFileName);
    if (!inputCodeFile.is_open()) {
        cerr << "Error opening input code log file: " << codeFileName << endl;
        return 1;
    }

    optimizedCodeFile.open(optimizedCodeFileName);
    if(!optimizedCodeFile.is_open()){
        cerr << "Error opening optimized code file: " << codeFileName << endl;
        return 1;
    }

    optimize();
    

    // parserFile.close();  // ADD THIS LINE
    optimizedCodeFile.close();
    inputCodeFile.close();
    cout << "Parsing completed. Check the output files for details." << endl;
    return 0;
}
