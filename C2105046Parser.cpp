
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
	#include <vector>
    #include "C2105046Lexer.h"
	#include "2105046/2105046_SymbolTable.hpp"
	using namespace std;

    extern ofstream parserLogFile;
    extern ofstream errorFile;
	extern ofstream codeFile;
	extern ofstream tmpFile;

    extern int syntaxErrorCount;
	
	extern SymbolTable symbolTable;

	extern bool scoped;

	extern bool inDeclaration;

	extern vector<int> scopeOffset;

	extern bool pop_flag;

	extern string current_return_label;



// Generated from C2105046Parser.g4 by ANTLR 4.13.2


#include "C2105046ParserListener.h"
#include "C2105046ParserVisitor.h"

#include "C2105046Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105046ParserStaticData final {
  C2105046ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105046ParserStaticData(const C2105046ParserStaticData&) = delete;
  C2105046ParserStaticData(C2105046ParserStaticData&&) = delete;
  C2105046ParserStaticData& operator=(const C2105046ParserStaticData&) = delete;
  C2105046ParserStaticData& operator=(C2105046ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105046parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105046ParserStaticData> c2105046parserParserStaticData = nullptr;

void c2105046parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105046parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105046parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105046ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
      "type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'printf'", "'return'", "'int'", "'float'", "'void'", "'('", "')'", 
      "'{'", "'}'", "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", 
      "'!'", "", "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "PRINTF", "RETURN", "INT", "FLOAT", "VOID", 
      "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", 
      "COMMA", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", 
      "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "INVALID_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,35,468,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,5,1,61,8,1,10,1,12,1,64,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,
  	75,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,3,3,93,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,3,4,113,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,134,8,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,5,5,165,8,5,10,5,12,5,168,9,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,3,6,179,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	3,7,191,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,201,8,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,3,10,211,8,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,228,8,10,10,10,12,10,
  	231,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,241,8,11,10,11,
  	12,11,244,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,309,8,12,1,13,
  	1,13,1,13,1,13,1,13,1,13,3,13,317,8,13,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,327,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,346,8,15,1,15,1,15,1,15,
  	5,15,351,8,15,10,15,12,15,354,9,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,3,16,367,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,3,17,377,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,
  	388,8,18,10,18,12,18,391,9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,5,19,402,8,19,10,19,12,19,405,9,19,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,3,20,418,8,20,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,3,21,446,8,21,1,22,1,22,1,22,1,22,3,22,
  	452,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,463,8,23,10,
  	23,12,23,466,9,23,1,23,0,8,2,10,20,22,30,36,38,46,24,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,0,492,0,48,1,0,0,
  	0,2,52,1,0,0,0,4,74,1,0,0,0,6,92,1,0,0,0,8,112,1,0,0,0,10,133,1,0,0,0,
  	12,178,1,0,0,0,14,190,1,0,0,0,16,192,1,0,0,0,18,200,1,0,0,0,20,210,1,
  	0,0,0,22,232,1,0,0,0,24,308,1,0,0,0,26,316,1,0,0,0,28,326,1,0,0,0,30,
  	345,1,0,0,0,32,366,1,0,0,0,34,376,1,0,0,0,36,378,1,0,0,0,38,392,1,0,0,
  	0,40,417,1,0,0,0,42,445,1,0,0,0,44,451,1,0,0,0,46,453,1,0,0,0,48,49,6,
  	0,-1,0,49,50,3,2,1,0,50,51,6,0,-1,0,51,1,1,0,0,0,52,53,6,1,-1,0,53,54,
  	3,4,2,0,54,55,6,1,-1,0,55,62,1,0,0,0,56,57,10,2,0,0,57,58,3,4,2,0,58,
  	59,6,1,-1,0,59,61,1,0,0,0,60,56,1,0,0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,
  	63,1,0,0,0,63,3,1,0,0,0,64,62,1,0,0,0,65,66,3,14,7,0,66,67,6,2,-1,0,67,
  	75,1,0,0,0,68,69,3,6,3,0,69,70,6,2,-1,0,70,75,1,0,0,0,71,72,3,8,4,0,72,
  	73,6,2,-1,0,73,75,1,0,0,0,74,65,1,0,0,0,74,68,1,0,0,0,74,71,1,0,0,0,75,
  	5,1,0,0,0,76,77,3,18,9,0,77,78,5,32,0,0,78,79,5,15,0,0,79,80,6,3,-1,0,
  	80,81,3,10,5,0,81,82,5,16,0,0,82,83,5,21,0,0,83,84,6,3,-1,0,84,93,1,0,
  	0,0,85,86,3,18,9,0,86,87,5,32,0,0,87,88,5,15,0,0,88,89,5,16,0,0,89,90,
  	5,21,0,0,90,91,6,3,-1,0,91,93,1,0,0,0,92,76,1,0,0,0,92,85,1,0,0,0,93,
  	7,1,0,0,0,94,95,3,18,9,0,95,96,5,32,0,0,96,97,6,4,-1,0,97,98,5,15,0,0,
  	98,99,3,10,5,0,99,100,6,4,-1,0,100,101,5,16,0,0,101,102,3,12,6,0,102,
  	103,6,4,-1,0,103,113,1,0,0,0,104,105,3,18,9,0,105,106,5,32,0,0,106,107,
  	6,4,-1,0,107,108,5,15,0,0,108,109,5,16,0,0,109,110,3,12,6,0,110,111,6,
  	4,-1,0,111,113,1,0,0,0,112,94,1,0,0,0,112,104,1,0,0,0,113,9,1,0,0,0,114,
  	115,6,5,-1,0,115,116,3,18,9,0,116,117,5,32,0,0,117,118,6,5,-1,0,118,134,
  	1,0,0,0,119,120,3,18,9,0,120,121,6,5,-1,0,121,134,1,0,0,0,122,123,3,18,
  	9,0,123,124,5,32,0,0,124,125,5,19,0,0,125,126,5,20,0,0,126,127,6,5,-1,
  	0,127,134,1,0,0,0,128,129,3,18,9,0,129,130,5,19,0,0,130,131,5,20,0,0,
  	131,132,6,5,-1,0,132,134,1,0,0,0,133,114,1,0,0,0,133,119,1,0,0,0,133,
  	122,1,0,0,0,133,128,1,0,0,0,134,166,1,0,0,0,135,136,10,9,0,0,136,137,
  	5,22,0,0,137,138,3,18,9,0,138,139,5,32,0,0,139,140,6,5,-1,0,140,165,1,
  	0,0,0,141,142,10,8,0,0,142,143,5,22,0,0,143,144,3,18,9,0,144,145,6,5,
  	-1,0,145,165,1,0,0,0,146,147,10,7,0,0,147,148,5,23,0,0,148,165,6,5,-1,
  	0,149,150,10,4,0,0,150,151,5,22,0,0,151,152,3,18,9,0,152,153,5,32,0,0,
  	153,154,5,19,0,0,154,155,5,20,0,0,155,156,6,5,-1,0,156,165,1,0,0,0,157,
  	158,10,3,0,0,158,159,5,22,0,0,159,160,3,18,9,0,160,161,5,19,0,0,161,162,
  	5,20,0,0,162,163,6,5,-1,0,163,165,1,0,0,0,164,135,1,0,0,0,164,141,1,0,
  	0,0,164,146,1,0,0,0,164,149,1,0,0,0,164,157,1,0,0,0,165,168,1,0,0,0,166,
  	164,1,0,0,0,166,167,1,0,0,0,167,11,1,0,0,0,168,166,1,0,0,0,169,170,5,
  	17,0,0,170,171,6,6,-1,0,171,172,3,22,11,0,172,173,5,18,0,0,173,174,6,
  	6,-1,0,174,179,1,0,0,0,175,176,5,17,0,0,176,177,5,18,0,0,177,179,6,6,
  	-1,0,178,169,1,0,0,0,178,175,1,0,0,0,179,13,1,0,0,0,180,181,3,18,9,0,
  	181,182,3,20,10,0,182,183,5,21,0,0,183,184,6,7,-1,0,184,191,1,0,0,0,185,
  	186,3,18,9,0,186,187,3,16,8,0,187,188,5,21,0,0,188,189,6,7,-1,0,189,191,
  	1,0,0,0,190,180,1,0,0,0,190,185,1,0,0,0,191,15,1,0,0,0,192,193,6,8,-1,
  	0,193,17,1,0,0,0,194,195,5,12,0,0,195,201,6,9,-1,0,196,197,5,13,0,0,197,
  	201,6,9,-1,0,198,199,5,14,0,0,199,201,6,9,-1,0,200,194,1,0,0,0,200,196,
  	1,0,0,0,200,198,1,0,0,0,201,19,1,0,0,0,202,203,6,10,-1,0,203,204,5,32,
  	0,0,204,211,6,10,-1,0,205,206,5,32,0,0,206,207,5,19,0,0,207,208,5,33,
  	0,0,208,209,5,20,0,0,209,211,6,10,-1,0,210,202,1,0,0,0,210,205,1,0,0,
  	0,211,229,1,0,0,0,212,213,10,5,0,0,213,214,5,22,0,0,214,215,5,32,0,0,
  	215,228,6,10,-1,0,216,217,10,4,0,0,217,218,5,22,0,0,218,219,5,32,0,0,
  	219,220,5,19,0,0,220,221,5,33,0,0,221,222,5,20,0,0,222,228,6,10,-1,0,
  	223,224,10,1,0,0,224,225,5,23,0,0,225,226,5,32,0,0,226,228,6,10,-1,0,
  	227,212,1,0,0,0,227,216,1,0,0,0,227,223,1,0,0,0,228,231,1,0,0,0,229,227,
  	1,0,0,0,229,230,1,0,0,0,230,21,1,0,0,0,231,229,1,0,0,0,232,233,6,11,-1,
  	0,233,234,3,24,12,0,234,235,6,11,-1,0,235,242,1,0,0,0,236,237,10,1,0,
  	0,237,238,3,24,12,0,238,239,6,11,-1,0,239,241,1,0,0,0,240,236,1,0,0,0,
  	241,244,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,23,1,0,0,0,244,242,
  	1,0,0,0,245,246,3,14,7,0,246,247,6,12,-1,0,247,309,1,0,0,0,248,249,3,
  	26,13,0,249,250,6,12,-1,0,250,309,1,0,0,0,251,252,3,12,6,0,252,253,6,
  	12,-1,0,253,309,1,0,0,0,254,255,5,7,0,0,255,256,6,12,-1,0,256,257,5,15,
  	0,0,257,258,3,26,13,0,258,259,6,12,-1,0,259,260,3,26,13,0,260,261,6,12,
  	-1,0,261,262,3,30,15,0,262,263,6,12,-1,0,263,264,5,16,0,0,264,265,3,24,
  	12,0,265,266,6,12,-1,0,266,309,1,0,0,0,267,268,5,5,0,0,268,269,6,12,-1,
  	0,269,270,5,15,0,0,270,271,3,30,15,0,271,272,5,16,0,0,272,273,6,12,-1,
  	0,273,274,3,24,12,0,274,275,6,12,-1,0,275,309,1,0,0,0,276,277,5,5,0,0,
  	277,278,5,15,0,0,278,279,3,30,15,0,279,280,5,16,0,0,280,281,6,12,-1,0,
  	281,282,3,24,12,0,282,283,6,12,-1,0,283,284,5,6,0,0,284,285,6,12,-1,0,
  	285,286,3,24,12,0,286,287,6,12,-1,0,287,309,1,0,0,0,288,289,5,8,0,0,289,
  	290,6,12,-1,0,290,291,5,15,0,0,291,292,3,30,15,0,292,293,5,16,0,0,293,
  	294,6,12,-1,0,294,295,3,24,12,0,295,296,6,12,-1,0,296,309,1,0,0,0,297,
  	298,5,9,0,0,298,299,5,15,0,0,299,300,5,32,0,0,300,301,5,16,0,0,301,302,
  	5,21,0,0,302,309,6,12,-1,0,303,304,5,11,0,0,304,305,3,30,15,0,305,306,
  	5,21,0,0,306,307,6,12,-1,0,307,309,1,0,0,0,308,245,1,0,0,0,308,248,1,
  	0,0,0,308,251,1,0,0,0,308,254,1,0,0,0,308,267,1,0,0,0,308,276,1,0,0,0,
  	308,288,1,0,0,0,308,297,1,0,0,0,308,303,1,0,0,0,309,25,1,0,0,0,310,311,
  	5,21,0,0,311,317,6,13,-1,0,312,313,3,30,15,0,313,314,5,21,0,0,314,315,
  	6,13,-1,0,315,317,1,0,0,0,316,310,1,0,0,0,316,312,1,0,0,0,317,27,1,0,
  	0,0,318,319,5,32,0,0,319,327,6,14,-1,0,320,321,5,32,0,0,321,322,5,19,
  	0,0,322,323,3,30,15,0,323,324,5,20,0,0,324,325,6,14,-1,0,325,327,1,0,
  	0,0,326,318,1,0,0,0,326,320,1,0,0,0,327,29,1,0,0,0,328,329,6,15,-1,0,
  	329,330,3,28,14,0,330,331,5,31,0,0,331,332,3,32,16,0,332,333,5,23,0,0,
  	333,334,5,31,0,0,334,335,3,32,16,0,335,336,6,15,-1,0,336,346,1,0,0,0,
  	337,338,3,32,16,0,338,339,6,15,-1,0,339,346,1,0,0,0,340,341,3,28,14,0,
  	341,342,5,31,0,0,342,343,3,32,16,0,343,344,6,15,-1,0,344,346,1,0,0,0,
  	345,328,1,0,0,0,345,337,1,0,0,0,345,340,1,0,0,0,346,352,1,0,0,0,347,348,
  	10,1,0,0,348,349,5,35,0,0,349,351,6,15,-1,0,350,347,1,0,0,0,351,354,1,
  	0,0,0,352,350,1,0,0,0,352,353,1,0,0,0,353,31,1,0,0,0,354,352,1,0,0,0,
  	355,356,3,34,17,0,356,357,6,16,-1,0,357,367,1,0,0,0,358,359,6,16,-1,0,
  	359,360,3,34,17,0,360,361,6,16,-1,0,361,362,5,30,0,0,362,363,6,16,-1,
  	0,363,364,3,34,17,0,364,365,6,16,-1,0,365,367,1,0,0,0,366,355,1,0,0,0,
  	366,358,1,0,0,0,367,33,1,0,0,0,368,369,3,36,18,0,369,370,6,17,-1,0,370,
  	377,1,0,0,0,371,372,3,36,18,0,372,373,5,29,0,0,373,374,3,36,18,0,374,
  	375,6,17,-1,0,375,377,1,0,0,0,376,368,1,0,0,0,376,371,1,0,0,0,377,35,
  	1,0,0,0,378,379,6,18,-1,0,379,380,3,38,19,0,380,381,6,18,-1,0,381,389,
  	1,0,0,0,382,383,10,1,0,0,383,384,5,23,0,0,384,385,3,38,19,0,385,386,6,
  	18,-1,0,386,388,1,0,0,0,387,382,1,0,0,0,388,391,1,0,0,0,389,387,1,0,0,
  	0,389,390,1,0,0,0,390,37,1,0,0,0,391,389,1,0,0,0,392,393,6,19,-1,0,393,
  	394,3,40,20,0,394,395,6,19,-1,0,395,403,1,0,0,0,396,397,10,1,0,0,397,
  	398,5,25,0,0,398,399,3,40,20,0,399,400,6,19,-1,0,400,402,1,0,0,0,401,
  	396,1,0,0,0,402,405,1,0,0,0,403,401,1,0,0,0,403,404,1,0,0,0,404,39,1,
  	0,0,0,405,403,1,0,0,0,406,407,5,23,0,0,407,408,3,40,20,0,408,409,6,20,
  	-1,0,409,418,1,0,0,0,410,411,5,28,0,0,411,412,3,40,20,0,412,413,6,20,
  	-1,0,413,418,1,0,0,0,414,415,3,42,21,0,415,416,6,20,-1,0,416,418,1,0,
  	0,0,417,406,1,0,0,0,417,410,1,0,0,0,417,414,1,0,0,0,418,41,1,0,0,0,419,
  	420,3,28,14,0,420,421,6,21,-1,0,421,446,1,0,0,0,422,423,5,32,0,0,423,
  	424,5,15,0,0,424,425,3,44,22,0,425,426,5,16,0,0,426,427,6,21,-1,0,427,
  	446,1,0,0,0,428,429,5,15,0,0,429,430,3,30,15,0,430,431,5,16,0,0,431,432,
  	6,21,-1,0,432,446,1,0,0,0,433,434,5,33,0,0,434,446,6,21,-1,0,435,436,
  	5,34,0,0,436,446,6,21,-1,0,437,438,3,28,14,0,438,439,5,26,0,0,439,440,
  	6,21,-1,0,440,446,1,0,0,0,441,442,3,28,14,0,442,443,5,27,0,0,443,444,
  	6,21,-1,0,444,446,1,0,0,0,445,419,1,0,0,0,445,422,1,0,0,0,445,428,1,0,
  	0,0,445,433,1,0,0,0,445,435,1,0,0,0,445,437,1,0,0,0,445,441,1,0,0,0,446,
  	43,1,0,0,0,447,448,3,46,23,0,448,449,6,22,-1,0,449,452,1,0,0,0,450,452,
  	6,22,-1,0,451,447,1,0,0,0,451,450,1,0,0,0,452,45,1,0,0,0,453,454,6,23,
  	-1,0,454,455,3,32,16,0,455,456,6,23,-1,0,456,464,1,0,0,0,457,458,10,2,
  	0,0,458,459,5,22,0,0,459,460,3,32,16,0,460,461,6,23,-1,0,461,463,1,0,
  	0,0,462,457,1,0,0,0,463,466,1,0,0,0,464,462,1,0,0,0,464,465,1,0,0,0,465,
  	47,1,0,0,0,466,464,1,0,0,0,27,62,74,92,112,133,164,166,178,190,200,210,
  	227,229,242,308,316,326,345,352,366,376,389,403,417,445,451,464
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105046parserParserStaticData = std::move(staticData);
}

}

C2105046Parser::C2105046Parser(TokenStream *input) : C2105046Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105046Parser::C2105046Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105046Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105046parserParserStaticData->atn, c2105046parserParserStaticData->decisionToDFA, c2105046parserParserStaticData->sharedContextCache, options);
}

C2105046Parser::~C2105046Parser() {
  delete _interpreter;
}

const atn::ATN& C2105046Parser::getATN() const {
  return *c2105046parserParserStaticData->atn;
}

std::string C2105046Parser::getGrammarFileName() const {
  return "C2105046Parser.g4";
}

const std::vector<std::string>& C2105046Parser::getRuleNames() const {
  return c2105046parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105046Parser::getVocabulary() const {
  return c2105046parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105046Parser::getSerializedATN() const {
  return c2105046parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105046Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::ProgramContext* C2105046Parser::StartContext::program() {
  return getRuleContext<C2105046Parser::ProgramContext>(0);
}


size_t C2105046Parser::StartContext::getRuleIndex() const {
  return C2105046Parser::RuleStart;
}

void C2105046Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105046Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


std::any C2105046Parser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::StartContext* C2105046Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105046Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

    		writeIntoCodeFile(
    			string("; c to assembly conversion by Raihan RSD\n.MODEL SMALL\n.STACK 100H\n.CODE\n")
    		);
    		writeIntoTmpFile(
    			string(".DATA\n\tCR EQU 0dh\n\tLF EQU 0ah \n\tnumber DB \"00000$\"")
    		);
    	
    setState(49);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            writeIntoparserLogFile(
    			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": start : program\n")
    		);

    		symbolTable.printForParser();

    		writeIntoparserLogFile(
    			string("\n") + string("Total number of lines: ") + to_string(_input->LT(-1)->getLine()) + string("\n")
    			+ string("Total number of errors: ") + to_string(syntaxErrorCount) 
    			
    		);

    // Assembly code
    writeIntoCodeFile(
    string("\n\
    new_line proc\n\
    	push ax\n\
    	push dx\n\
    	mov ah,2\n\
    	mov dl,0Dh\n\
    	int 21h\n\
    	mov ah,2\n\
    	mov dl,0Ah\n\
    	int 21h\n\
    	pop dx\n\
    	pop ax\n\
    	ret\n\
    	new_line endp \n \
    print_output proc  ;print what is in ax  \n\
    	push ax\n\
    	push bx\n\
    	push cx\n\
    	push dx\n\
    	push si\n\
    	lea si,number\n\
    	mov bx,10\n\
    	add si,4\n\
    	cmp ax,0\n\
    	jnge negate\n\
    	print:\n\
    	xor dx,dx\n\
    	div bx\n\
    	mov [si],dl\n\
    	add [si],'0'\n\
    	dec si\n\
    	cmp ax,0\n\
    	jne print\n\
    	inc si\n\
    	lea dx,si\n\
    	mov ah,9\n\
    	int 21h\n\
    	pop si\n\
    	pop dx\n\
    	pop cx\n\
    	pop bx\n\
    	pop ax\n\
    	ret\n\
    	negate:\n\
    	push ax\n\
    	mov ah,2\n\
    	mov dl,'-'\n\
    	int 21h\n\
    	pop ax\n\
    	neg ax\n\
    	jmp print\n\
    	print_output endp\n\n\n") 
    );





    		writeIntoTmpFile(
    			string("\nEND MAIN\n ;; ggwp loved this offline no cap fr")
    		);
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105046Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::UnitContext* C2105046Parser::ProgramContext::unit() {
  return getRuleContext<C2105046Parser::UnitContext>(0);
}

C2105046Parser::ProgramContext* C2105046Parser::ProgramContext::program() {
  return getRuleContext<C2105046Parser::ProgramContext>(0);
}


size_t C2105046Parser::ProgramContext::getRuleIndex() const {
  return C2105046Parser::RuleProgram;
}

void C2105046Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105046Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any C2105046Parser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::ProgramContext* C2105046Parser::program() {
   return program(0);
}

C2105046Parser::ProgramContext* C2105046Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105046Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105046Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(53);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

    		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : unit\n")
      		);
    		  writeIntoparserLogFile(
    	 		string(antlrcpp::downCast<ProgramContext *>(_localctx)->u->print_text) + string("\n")
    		);

    		antlrcpp::downCast<ProgramContext *>(_localctx)->print_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->print_text;
    		
    	
    _ctx->stop = _input->LT(-1);
    setState(62);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(56);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(57);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                  		writeIntoparserLogFile(
                  			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : program unit\n")
                  		);
                  		writeIntoparserLogFile(
                  			string(antlrcpp::downCast<ProgramContext *>(_localctx)->p->print_text) + string("\n") + string(antlrcpp::downCast<ProgramContext *>(_localctx)->u->print_text) + string("\n")
                  		);

                  		antlrcpp::downCast<ProgramContext *>(_localctx)->print_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->print_text + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->print_text;
                  	 
      }
      setState(64);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105046Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Var_declarationContext* C2105046Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105046Parser::Var_declarationContext>(0);
}

C2105046Parser::Func_declarationContext* C2105046Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105046Parser::Func_declarationContext>(0);
}

C2105046Parser::Func_definitionContext* C2105046Parser::UnitContext::func_definition() {
  return getRuleContext<C2105046Parser::Func_definitionContext>(0);
}


size_t C2105046Parser::UnitContext::getRuleIndex() const {
  return C2105046Parser::RuleUnit;
}

void C2105046Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105046Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}


std::any C2105046Parser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::UnitContext* C2105046Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105046Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();

      		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : var_declaration\n")
        	  	);	
      		writeIntoparserLogFile(
      			string(antlrcpp::downCast<UnitContext *>(_localctx)->vd->print_text) + string("\n")
      		);
      		antlrcpp::downCast<UnitContext *>(_localctx)->print_text =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->print_text;
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      antlrcpp::downCast<UnitContext *>(_localctx)->f_dl = func_declaration();

      		  writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_declaration\n")
      		  );

      		  writeIntoparserLogFile(
      			string(antlrcpp::downCast<UnitContext *>(_localctx)->f_dl->print_text) + string("\n")
      		  );

      		antlrcpp::downCast<UnitContext *>(_localctx)->print_text =  antlrcpp::downCast<UnitContext *>(_localctx)->f_dl->print_text;
      	 
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(71);
      antlrcpp::downCast<UnitContext *>(_localctx)->f_def = func_definition();

      		writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_definition\n")
      			);
      			antlrcpp::downCast<UnitContext *>(_localctx)->print_text =  antlrcpp::downCast<UnitContext *>(_localctx)->f_def->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      	 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105046Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105046Parser::LPAREN, 0);
}

tree::TerminalNode* C2105046Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105046Parser::RPAREN, 0);
}

C2105046Parser::Type_specifierContext* C2105046Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105046Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105046Parser::Func_declarationContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

C2105046Parser::Parameter_listContext* C2105046Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105046Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105046Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105046Parser::SEMICOLON, 0);
}


size_t C2105046Parser::Func_declarationContext::getRuleIndex() const {
  return C2105046Parser::RuleFunc_declaration;
}

void C2105046Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105046Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}


std::any C2105046Parser::Func_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Func_declarationContext* C2105046Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105046Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(78);
      match(C2105046Parser::LPAREN);

      			inDeclaration = true;
      		
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(81);
      match(C2105046Parser::RPAREN);
      setState(82);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

      			inDeclaration = false;
      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n")
      			);

      			writeIntoparserLogFile(
      				string((antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts != nullptr ? _input->getText(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->start, antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->stop) : nullptr)) + string(" ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText()) + string("(") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->print_text) + string(");\n")
      			);

      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->print_text =  string((antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts != nullptr ? _input->getText(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->start, antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->stop) : nullptr)) + string(" ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText()) + string("(") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->print_text) + string(");");
      			string name = string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText());

      			if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			} 
      			SymbolInfo* symbol = symbolTable.lookUp(name);
      			symbol->setIsDeclaredOnly(true);
      			
      			//SymbolInfo* symbol = symbolTable.lookUp(name);
      			symbol->setParameters(antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->args, antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->print_text);
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->l_p = match(C2105046Parser::LPAREN);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->r_p = match(C2105046Parser::RPAREN);
      setState(89);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n")
      			);

      			writeIntoparserLogFile(
      				string((antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts != nullptr ? _input->getText(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->start, antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->stop) : nullptr)) + string(" ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText()) + string("();\n")
      			);

      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->print_text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + "()" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getText();
      			string name = string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText());
      			if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText()) + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			} 
      			SymbolInfo* symbol = symbolTable.lookUp(name);
      			symbol->setIsDeclaredOnly(true);
      			symbol->setParameters(vector<string>(), antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->print_text);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105046Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Type_specifierContext* C2105046Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105046Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105046Parser::Func_definitionContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105046Parser::LPAREN, 0);
}

C2105046Parser::Parameter_listContext* C2105046Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105046Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105046Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105046Parser::RPAREN, 0);
}

C2105046Parser::Compound_statementContext* C2105046Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105046Parser::Compound_statementContext>(0);
}


size_t C2105046Parser::Func_definitionContext::getRuleIndex() const {
  return C2105046Parser::RuleFunc_definition;
}

void C2105046Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105046Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}


std::any C2105046Parser::Func_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitFunc_definition(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Func_definitionContext* C2105046Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105046Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105046Parser::ID);

      		string name = string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
      		bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
      		bool wasDeclared = false;
      		SymbolInfo* symbol = symbolTable.lookUp(name);
      		wasDeclared = symbol->getIsDeclaredOnly();
      		if(!canInsert && !wasDeclared){
      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      			);
      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      			);
      			syntaxErrorCount++;
      		}
      		else {
      			// SymbolInfo* symbol = symbolTable.lookUp(name);
      			if(wasDeclared){
      				if(symbol->getReturnType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      					);
      					syntaxErrorCount++;
      				}
      			}
      			symbol->setIsDeclaredOnly(false);

      		}
                
      		// Enter new scope for function body and parameters
      		symbolTable.enterScope();
      		scoped = true;
      		// Assembly code 
      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main"){
      			writeIntoCodeFile(
      			string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
      			);
      		} else {
      			writeIntoCodeFile(
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + 
      			string(" PROC")
      			);
      		}

      		writeIntoCodeFile(
      			string("\tPUSH BP\n\tMOV BP, SP") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
      		);

      		string return_label = getLabel();

      		current_return_label = return_label;

      		scopeOffset.push_back(0);
            
      setState(97);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);

      		writeIntoCodeFile(
      			string("; sotring parameter information in scope table")
      		);
      		scopeOffset.back() = -2;
      		for(int i = antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->vars.size() - 1; i >= 0; i--){ 
      			scopeOffset.back() -= 2;
      			SymbolInfo* symbol = symbolTable.lookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->vars[i]);
      			symbol->setAsmData(scopeOffset.back(), false);
      		}

      		scopeOffset.back() = 0;

      	 
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);
      setState(101);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm = compound_statement();

      		
      		
              int param_count = antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->vars.size();
      		if(wasDeclared){
      			if(symbol->getParameters().size() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->args.size()){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			}

      		}
      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type != antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text){
      			if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text == "void" && !((antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "") || (antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "void"))){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string(" with void return type \n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string(" with void return type \n")
      				);
      				syntaxErrorCount++;
      			}
      			else if(!(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text == "void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "")){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Return type mismatch in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Return type mismatch in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			}
      		}

      		writeIntoparserLogFile(
                  string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n")
              );
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->print_text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text + string(" ") + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->print_text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->print_text;
              writeIntoparserLogFile(
                  _localctx->print_text + string("\n")
              );
      		symbol->setParameters(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->args, antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text);

      		// Assembly Code 
      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main"){ 
      			writeIntoCodeFile(
      				current_return_label + string(":\n") + 
      				string("\tMOV SP, BP\n") +
      				string("\tMOV AX, 4C00H\n\tINT 21H")
      			);
      		} else {
      			writeIntoCodeFile(
      				current_return_label + string(":\n") + 
      				string("\tMOV SP, BP\n") +
      				string("\tPOP BP\n\tRET ") + to_string(param_count * 2)
      			);
      		}
      		writeIntoCodeFile(
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + string(" ENDP")
      		);
      		scopeOffset.pop_back();
      		
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105046Parser::ID);

      		string name = string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
      		bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
      		bool wasDeclared = false;
      		SymbolInfo* symbol = symbolTable.lookUp(name);
      		wasDeclared = symbol->getIsDeclaredOnly();
      		if(!canInsert && !wasDeclared){
      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      			);
      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      			);
      			syntaxErrorCount++;
      		}
      		else {
      			// SymbolInfo* symbol = symbolTable.lookUp(name);
      			if(wasDeclared){
      				if(symbol->getReturnType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      					);
      					syntaxErrorCount++;
      				}
      			}
      			symbol->setIsDeclaredOnly(false);
      		}
                
      		// Enter new scope for function body and parameters
      		symbolTable.enterScope();
      		scoped = true;
      		// Assembly code 
      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main"){
      			writeIntoCodeFile(
      			string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
      			);
      		} else {
      			writeIntoCodeFile(
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + 
      			string(" PROC")
      			);
      		}

      		writeIntoCodeFile(
      			string("\tPUSH BP\n\tMOV BP, SP") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
      		);

      		scopeOffset.push_back(0);

      		string return_label = getLabel();

      		current_return_label = return_label;

            
      setState(107);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm = compound_statement();

              

      		if(wasDeclared){
      			if(symbol->getParameters().size() > 0){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			}
      		}

      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type != antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text){
      			if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text == "void" && !((antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "") || (antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "void"))){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Cannot return value from function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string(" with void return type\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Cannot return value from function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string(" with void return type\n")
      				);
      				syntaxErrorCount++;
      			}
      			else if(!(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text == "void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->return_type == "")){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Return type mismatch in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()) + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + string(": Return type mismatch in function ") + string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText())+ string("\n")
      				);
      				syntaxErrorCount++;
      			}
      		}

      		writeIntoparserLogFile(
                  string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n")
              );
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->print_text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text + string(" ") + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->csm->print_text;

              writeIntoparserLogFile(
                  _localctx->print_text + string("\n")
              );

      		symbol->setParameters(vector<string>(), antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->print_text);
      		// Assembly Code 
      		if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main"){ 
      			writeIntoCodeFile(
      				current_return_label + string(":\n") + 
      				string("\tMOV SP, BP\n") +
      				string("\tMOV AX, 4C00H\n\tINT 21H")
      			);
      		} else {
      			writeIntoCodeFile(
      				current_return_label + string(":\n") + 
      				string("\tMOV SP, BP\n") +
      				string("\tPOP BP\n\tRET ")
      			);
      		}
      		writeIntoCodeFile(
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + string(" ENDP")
      		);

      		scopeOffset.pop_back();

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105046Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Type_specifierContext* C2105046Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105046Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105046Parser::Parameter_listContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::Parameter_listContext::LTHIRD() {
  return getToken(C2105046Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105046Parser::Parameter_listContext::RTHIRD() {
  return getToken(C2105046Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105046Parser::Parameter_listContext::COMMA() {
  return getToken(C2105046Parser::COMMA, 0);
}

C2105046Parser::Parameter_listContext* C2105046Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105046Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105046Parser::Parameter_listContext::ADDOP() {
  return getToken(C2105046Parser::ADDOP, 0);
}


size_t C2105046Parser::Parameter_listContext::getRuleIndex() const {
  return C2105046Parser::RuleParameter_list;
}

void C2105046Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105046Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


std::any C2105046Parser::Parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitParameter_list(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::Parameter_listContext* C2105046Parser::parameter_list() {
   return parameter_list(0);
}

C2105046Parser::Parameter_listContext* C2105046Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105046Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105046Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(115);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(116);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105046Parser::ID);

      			
      			string name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
      			if(!inDeclaration){
      				if(!symbolTable.insert(name, "ID", nullptr, antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text)){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string(" in parameter\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string(" in parameter\n")
      					);
      					syntaxErrorCount++;
      				} else {
      					_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
      				}
      			} else {
      				
      				_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
      			}

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
         		   );

      		   writeIntoparserLogFile(
      	  			string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text) + string(" ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText()) + string("\n")
      	 		);

      			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
      			// symbolTable.enterScope();
      			scoped = true;

      			// first parameter which is being read
      			// Assembly Code
      			// writeIntoCodeFile(
      			// 	string("\t; defining first paramter into stack offset -2")
      			// );

      			// SymbolInfo* symbol = symbolTable.lookUp(name);
      			// scopeOffset.back() -= 2;

      			// symbol->setAsmData(-2, false);
      			_localctx->vars.push_back(name);

      		
      break;
    }

    case 2: {
      setState(119);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
      			);
      			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
      		
      break;
    }

    case 3: {
      setState(122);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(123);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(124);
      match(C2105046Parser::LTHIRD);
      setState(125);
      match(C2105046Parser::RTHIRD);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
         		   );

      		   writeIntoparserLogFile(
      	  			string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text) + string(" ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText()) + string("\n")
      	 		);

      			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
      			// symbolTable.enterScope();
      			scoped = true;
      			string name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
      			if(!inDeclaration){
      				if(!symbolTable.insert(name, "ID", nullptr, antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text)){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string("\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string("\n")
      					);
      					syntaxErrorCount++;
      				} else {
      					_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + "[]");
      					SymbolInfo* symbol = symbolTable.lookUp(name);
      					symbol->setIsArray();
      				}
      			}

      		
      break;
    }

    case 4: {
      setState(128);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(129);
      match(C2105046Parser::LTHIRD);
      setState(130);
      match(C2105046Parser::RTHIRD);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
      			);
      			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);

      			_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + "[]");
      		
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(164);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(135);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(136);
          match(C2105046Parser::COMMA);
          setState(137);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(138);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105046Parser::ID);

                    			string name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
                    			if(!inDeclaration){
                    				if(!symbolTable.insert(name, "ID", nullptr, antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text)){
                    					writeIntoErrorFile(
                    						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string(" in parameter\n")
                    					);
                    					writeIntoparserLogFile(
                    						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string(" in parameter\n")
                    					);
                    					syntaxErrorCount++;
                    				}	else{
                    					antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    					_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
                    				}
                    			} else {
                    				antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    				_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
                    			}

                    			writeIntoparserLogFile(
                    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
                    			);

                    			writeIntoparserLogFile(
                    				string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text) + string(",") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text) + string(" ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText()) + string("\n")
                    			);


                    			// writeIntoCodeFile(
                    			// 	string("\t; defining paramter into stack offset")
                    			// );

                    			// SymbolInfo* symbol = symbolTable.lookUp(name);
                    			// scopeOffset.back() -= 2;

                    			// symbol->setAsmData(scopeOffset.back(), false);

                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->vars =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->vars;
                    			_localctx->vars.push_back(name);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();

                    		
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(141);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(142);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm = match(C2105046Parser::COMMA);
          setState(143);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

                    			writeIntoparserLogFile(
                    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
                    			);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text;
                    			writeIntoparserLogFile(
                    				_localctx->print_text + string("\n")
                    			);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    			_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text);
                    		
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(146);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(147);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->add_op = match(C2105046Parser::ADDOP);

                    			// syntax error handle rule
                    			writeIntoparserLogFile(
                    				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
                    			);
                    			writeIntoErrorFile(
                    				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
                    			);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text;
                    			syntaxErrorCount++;
                    		
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(149);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(150);
          match(C2105046Parser::COMMA);
          setState(151);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(152);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105046Parser::ID);
          setState(153);
          match(C2105046Parser::LTHIRD);
          setState(154);
          match(C2105046Parser::RTHIRD);

                    			writeIntoparserLogFile(
                    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
                    			);

                    			writeIntoparserLogFile(
                    				string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text) + string(",") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text) + string(" ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText()) + string("\n")
                    			);

                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
                    			string name = antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
                    			if(!inDeclaration){
                    				if(!symbolTable.insert(name, "ID", nullptr, antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text)){
                    					writeIntoErrorFile(
                    						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string("\n")
                    					);
                    					writeIntoparserLogFile(
                    						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText())+ string("\n")
                    					);
                    					syntaxErrorCount++;
                    				}	else {
                    					antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    					_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + "[]");
                    					SymbolInfo* symbol = symbolTable.lookUp(name);
                    					symbol->setIsArray();
                    				}
                    			}

                    		
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(157);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(158);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm = match(C2105046Parser::COMMA);
          setState(159);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(160);
          match(C2105046Parser::LTHIRD);
          setState(161);
          match(C2105046Parser::RTHIRD);

                    			writeIntoparserLogFile(
                    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
                    			);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->print_text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text;
                    			writeIntoparserLogFile(
                    				_localctx->print_text + string("\n")
                    			);
                    			antlrcpp::downCast<Parameter_listContext *>(_localctx)->args =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->args;
                    			_localctx->args.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->print_text + "[]");
                    		
          break;
        }

        default:
          break;
        } 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105046Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Compound_statementContext::LCURL() {
  return getToken(C2105046Parser::LCURL, 0);
}

C2105046Parser::StatementsContext* C2105046Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105046Parser::StatementsContext>(0);
}

tree::TerminalNode* C2105046Parser::Compound_statementContext::RCURL() {
  return getToken(C2105046Parser::RCURL, 0);
}


size_t C2105046Parser::Compound_statementContext::getRuleIndex() const {
  return C2105046Parser::RuleCompound_statement;
}

void C2105046Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105046Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}


std::any C2105046Parser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Compound_statementContext* C2105046Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105046Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(169);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcl = match(C2105046Parser::LCURL);

      			if(!scoped){
      				symbolTable.enterScope();
      				// scopeOffset.push_back(0);
      			}
      			scoped = false;

      		
      setState(171);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->stms = statements(0);
      setState(172);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcl = match(C2105046Parser::RCURL);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL statements RCURL\n")
      			);
      			antlrcpp::downCast<Compound_statementContext *>(_localctx)->print_text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcl->getText() + string("\n") + antlrcpp::downCast<Compound_statementContext *>(_localctx)->stms->print_text + string("\n") + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcl->getText();
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			symbolTable.printForParser();
      			writeIntoparserLogFile(
      				string("")
      			);
      			symbolTable.exitScope();
      			antlrcpp::downCast<Compound_statementContext *>(_localctx)->return_type =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->stms->return_type;
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      match(C2105046Parser::LCURL);
      setState(176);
      match(C2105046Parser::RCURL);

      				writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL RCURL\n")
      			);
      			antlrcpp::downCast<Compound_statementContext *>(_localctx)->print_text =  string("{}");

      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);

      			symbolTable.printForParser();
      			writeIntoparserLogFile(
      				string("")
      			);
      			symbolTable.exitScope();
      			// scopeOffset.pop_back();
      			antlrcpp::downCast<Compound_statementContext *>(_localctx)->return_type =  "void";
      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105046Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Type_specifierContext* C2105046Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105046Parser::Type_specifierContext>(0);
}

C2105046Parser::Declaration_listContext* C2105046Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105046Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105046Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105046Parser::SEMICOLON, 0);
}

C2105046Parser::Declaration_list_errContext* C2105046Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105046Parser::Declaration_list_errContext>(0);
}


size_t C2105046Parser::Var_declarationContext::getRuleIndex() const {
  return C2105046Parser::RuleVar_declaration;
}

void C2105046Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105046Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}


std::any C2105046Parser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Var_declarationContext* C2105046Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105046Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(180);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->ts = type_specifier();
      setState(181);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(182);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

              writeIntoparserLogFile(
      			string("Line ") + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + string(": var_declaration : type_specifier declaration_list SEMICOLON\n")
      		);

      		

      		if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->ts->print_text == "void"){
      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void")  + string("\n")
      			);
      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void") + string("\n")
      			);

      			syntaxErrorCount++;
      		}

      		writeIntoparserLogFile(
      			string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->ts->print_text)+ string(" ") + string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->print_text) + string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText()) + string("\n")
      		);
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->print_text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->ts->print_text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->print_text  + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();

      		for(int i = 0; i < antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->ids.size(); i++){
      			
      			string str = antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->ids[i];
      			string actual_name = str;
      			string length = antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->id_size[i];
      			bool isArray = false;

      			
      			// Check if the last 2 characters are "[]"
      			if (str.length() >= 2 && str.substr(str.length() - 2) == "[]") {
      				// It's an array - remove the "[]" to get actual name
      				actual_name = str.substr(0, str.length() - 2);
      				isArray = true;
      			}
      			
      			// if(!symbolTable.insert(actual_name, "ID", nullptr, antlrcpp::downCast<Var_declarationContext *>(_localctx)->ts->print_text, isArray)){
      			// 	writeIntoErrorFile(
      			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + actual_name + string("\n")
      			// 	);
      			// 	writeIntoparserLogFile(
      			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + actual_name + string("\n")
      			// 	);

      			// 	syntaxErrorCount++;
      			// }

      			// Assembly instructions
      			// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
      			// if(symbolTable.isMainScope()){
      			// 	globalVariables.push_back(symbol);
      			// 	symbol->setAsmData(0, true);
      			// 	symbol->setArrSize(stoi(length));
      			// } else {
      			// 	// local variables 
      				
      			// 	if(isArray){

      			// 		scopeOffset.back() += stoi(length) * 2;
      			// 		symbol->setAsmData(scopeOffset.back(), false);
      			// 		symbol->setArrSize(stoi(length));
      			// 		string codeOffset = to_string(stoi(length) * 2);
      			// 		writeIntoCodeFile(
      			// 			string("\tSUB SP, ") + codeOffset
      			// 		);
      			// 	} else {
      			// 		scopeOffset.back() += 2;
      			// 		symbol->setAsmData(scopeOffset.back(), false);
      			// 		writeIntoCodeFile(
      			// 			string("\tSUB SP, 2")
      			// 		);
      			// 	}
      				
      			// }

      		}

      		

            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(185);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(186);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(187);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

              writeIntoErrorFile(
                  string("Line# ") + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );

              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105046Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105046Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105046Parser::RuleDeclaration_list_err;
}

void C2105046Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105046Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}


std::any C2105046Parser::Declaration_list_errContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_list_err(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Declaration_list_errContext* C2105046Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105046Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105046Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Type_specifierContext::INT() {
  return getToken(C2105046Parser::INT, 0);
}

tree::TerminalNode* C2105046Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105046Parser::FLOAT, 0);
}

tree::TerminalNode* C2105046Parser::Type_specifierContext::VOID() {
  return getToken(C2105046Parser::VOID, 0);
}


size_t C2105046Parser::Type_specifierContext::getRuleIndex() const {
  return C2105046Parser::RuleType_specifier;
}

void C2105046Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105046Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}


std::any C2105046Parser::Type_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitType_specifier(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Type_specifierContext* C2105046Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105046Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105046Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->i = match(C2105046Parser::INT);

                    writeIntoparserLogFile(
        				string("Line ") + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->i->getLine()) + string(": type_specifier : INT\n")
        			);

        			writeIntoparserLogFile(
        					string("int\n")
        			);
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->print_text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->i->getText();
        			

                
        break;
      }

      case C2105046Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(196);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->f = match(C2105046Parser::FLOAT);

                    writeIntoparserLogFile(
        				string("Line ") + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->f->getLine()) + string(": type_specifier : FLOAT\n")
        			);

        			writeIntoparserLogFile(
        				string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->f->getText()) + string("\n")
        			);

        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->print_text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->f->getText();
                
        break;
      }

      case C2105046Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(198);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->v = match(C2105046Parser::VOID);

                    writeIntoparserLogFile(
        				string("Line ") + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->v->getLine()) + string(": type_specifier : VOID\n")
        			);

        			writeIntoparserLogFile(
        				string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->v->getText()) + string("\n")
        			);

        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->print_text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->v->getText();
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105046Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105046Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105046Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105046Parser::RTHIRD, 0);
}

C2105046Parser::Declaration_listContext* C2105046Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105046Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::COMMA() {
  return getToken(C2105046Parser::COMMA, 0);
}

tree::TerminalNode* C2105046Parser::Declaration_listContext::ADDOP() {
  return getToken(C2105046Parser::ADDOP, 0);
}


size_t C2105046Parser::Declaration_listContext::getRuleIndex() const {
  return C2105046Parser::RuleDeclaration_list;
}

void C2105046Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105046Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


std::any C2105046Parser::Declaration_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_list(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::Declaration_listContext* C2105046Parser::declaration_list() {
   return declaration_list(0);
}

C2105046Parser::Declaration_listContext* C2105046Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105046Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105046Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(203);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->i = match(C2105046Parser::ID);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getLine()) + string(": declaration_list : ID\n")
      			);
      			antlrcpp::downCast<Declaration_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText();
      			writeIntoparserLogFile(
      				string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText()) + string("\n")
      			);

      			_localctx->ids.push_back(_localctx->print_text);
      			// _localctx->ids.push_back(make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), false));
      			_localctx->id_size.push_back("1");

      			string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText();
      			symbolTable.insert(name, "ID", nullptr, "int", false);
      			SymbolInfo* symbol = symbolTable.lookUp(name);
      			if(symbolTable.isMainScope()){
      				symbol->setAsmData(0, true);
      				symbol->setArrSize(1);
      				writeIntoTmpFile(
      					string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
      				);
      			} else {
      				// local variables 
      				scopeOffset.back() += 2;
      				symbol->setAsmData(scopeOffset.back(), false);
      				writeIntoCodeFile(
      					string("\tSUB SP, 2")
      				);
      			}
      		  
      break;
    }

    case 2: {
      setState(205);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->i = match(C2105046Parser::ID);
      setState(206);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->l_t = match(C2105046Parser::LTHIRD);
      setState(207);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i = match(C2105046Parser::CONST_INT);
      setState(208);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_t = match(C2105046Parser::RTHIRD);

      				writeIntoparserLogFile(
      					string("Line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getLine()) + string(": declaration_list : ID LTHIRD CONST_INT RTHIRD\n")
      				);

      				antlrcpp::downCast<Declaration_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->l_t->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_t->getText();
      				writeIntoparserLogFile(
      					string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->l_t->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_t->getText()) + string("\n")
      				);

      				_localctx->ids.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText() + "[]");
      				// _localctx->ids.push_back(make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), true));
      				_localctx->id_size.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText());

      				string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText();
      				symbolTable.insert(name, "ID", nullptr, "int", true);
      				SymbolInfo* symbol = symbolTable.lookUp(name);
      				// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
      				if(symbolTable.isMainScope()){
      					symbol->setAsmData(0, true);
      					symbol->setArrSize(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()));
      					writeIntoTmpFile(
      						string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
      					);
      				} else {
      					// local variables 
      					scopeOffset.back() += stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()) * 2;
      					symbol->setAsmData(scopeOffset.back(), false);
      					symbol->setArrSize(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()));
      					string codeOffset = to_string(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()) * 2);
      					writeIntoCodeFile(
      						string("\tSUB SP, ") + codeOffset
      					);
      				}
      		  
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(227);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->d = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(212);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(213);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->c = match(C2105046Parser::COMMA);
          setState(214);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105046Parser::ID);

                    			writeIntoparserLogFile(
                    				string("Line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + string(": declaration_list : declaration_list COMMA ID\n")
                    			);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->print_text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->c->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                    			writeIntoparserLogFile(
                    				_localctx->print_text + string("\n")
                    			);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->ids;
                    			_localctx->ids.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText());
                    			// _localctx->ids.push_back(make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), false));
                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->id_size =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->id_size;
                    			_localctx->id_size.push_back("1");
                    			string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                    			symbolTable.insert(name, "ID", nullptr, "int", false);
                    			SymbolInfo* symbol = symbolTable.lookUp(name);
                    			if(symbolTable.isMainScope()){
                    				
                    				symbol->setAsmData(0, true);
                    				symbol->setArrSize(1);
                    				writeIntoTmpFile(
                    					string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
                    				);
                    			} else {
                    				// local variables 
                    				scopeOffset.back() += 2;
                    				symbol->setAsmData(scopeOffset.back(), false);
                    				writeIntoCodeFile(
                    					string("\tSUB SP, 2")
                    				);
                    				
                    			}

                    			
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->d = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(216);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(217);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->c = match(C2105046Parser::COMMA);
          setState(218);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105046Parser::ID);
          setState(219);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->third_brac = match(C2105046Parser::LTHIRD);
          setState(220);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int = match(C2105046Parser::CONST_INT);
          setState(221);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_third = match(C2105046Parser::RTHIRD);

                    			writeIntoparserLogFile(
                    	 			string("Line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + string(": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n")
                    	   		);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->print_text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->c->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->third_brac->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_third->getText();
                    			writeIntoparserLogFile(
                    				_localctx->print_text + string("\n")
                    			);
                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->ids;
                    			_localctx->ids.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + "[]");
                    			// _localctx->ids.push_back(make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), true));
                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->id_size =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d->id_size;
                    			_localctx->id_size.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText());
                    			
                    			string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                    			symbolTable.insert(name, "ID", nullptr, "int", true);
                    			SymbolInfo* symbol = symbolTable.lookUp(name);
                    			// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
                    			if(symbolTable.isMainScope()){
                    				symbol->setAsmData(0, true);
                    				symbol->setArrSize(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText()));
                    				writeIntoTmpFile(
                    					string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
                    				);
                    			} else {
                    				// local variables 
                    				scopeOffset.back() += stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText()) * 2;
                    				symbol->setAsmData(scopeOffset.back(), false);
                    				symbol->setArrSize(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText()));
                    				string codeOffset = to_string(stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_int->getText()) * 2);
                    				writeIntoCodeFile(
                    					string("\tSUB SP, ") + codeOffset
                    				);
                    			}
                    		  
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(223);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(224);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->add_op = match(C2105046Parser::ADDOP);
          setState(225);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105046Parser::ID);

                    				// syntax error handle
                    				writeIntoErrorFile(
                    					string("Error at line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
                    				);

                    				writeIntoparserLogFile(
                    					string("Error at line ") + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
                    				);
                    				syntaxErrorCount++;

                    				antlrcpp::downCast<Declaration_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->print_text;
                    				antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->ids;
                    				// writeIntoparserLogFile(
                    				// 	string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->l_t->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->c_i->getText()) + string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->r_t->getText()) + string("\n")
                    				// );

                    				// _localctx->ids.push_back(antlrcpp::downCast<Declaration_listContext *>(_localctx)->i->getText() + "[]");
                    		  
          break;
        }

        default:
          break;
        } 
      }
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105046Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::StatementContext* C2105046Parser::StatementsContext::statement() {
  return getRuleContext<C2105046Parser::StatementContext>(0);
}

C2105046Parser::StatementsContext* C2105046Parser::StatementsContext::statements() {
  return getRuleContext<C2105046Parser::StatementsContext>(0);
}


size_t C2105046Parser::StatementsContext::getRuleIndex() const {
  return C2105046Parser::RuleStatements;
}

void C2105046Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105046Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


std::any C2105046Parser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::StatementsContext* C2105046Parser::statements() {
   return statements(0);
}

C2105046Parser::StatementsContext* C2105046Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105046Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105046Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(233);
    antlrcpp::downCast<StatementsContext *>(_localctx)->stm = statement();

    			writeIntoparserLogFile(
    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statement\n")
    			);
    			antlrcpp::downCast<StatementsContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->stm->print_text;
    			writeIntoparserLogFile(
    				_localctx->print_text + string("\n")
    			);
    			antlrcpp::downCast<StatementsContext *>(_localctx)->return_type =  antlrcpp::downCast<StatementsContext *>(_localctx)->stm->return_type;
    	
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->stms = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(236);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(237);
        antlrcpp::downCast<StatementsContext *>(_localctx)->stm = statement();

                  			if(antlrcpp::downCast<StatementsContext *>(_localctx)->stm->print_text != ""){
                  			writeIntoparserLogFile(
                  				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statements statement\n")
                  			);
                  			antlrcpp::downCast<StatementsContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->stms->print_text + string("\n") + antlrcpp::downCast<StatementsContext *>(_localctx)->stm->print_text;
                  			writeIntoparserLogFile(
                  				_localctx->print_text + string("\n")
                  			);
                  			antlrcpp::downCast<StatementsContext *>(_localctx)->return_type =  antlrcpp::downCast<StatementsContext *>(_localctx)->stm->return_type;
                  			}
                  			else {
                  				antlrcpp::downCast<StatementsContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->stms->print_text;
                  			}
                  	    
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105046Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Var_declarationContext* C2105046Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105046Parser::Var_declarationContext>(0);
}

std::vector<C2105046Parser::Expression_statementContext *> C2105046Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105046Parser::Expression_statementContext>();
}

C2105046Parser::Expression_statementContext* C2105046Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105046Parser::Expression_statementContext>(i);
}

C2105046Parser::Compound_statementContext* C2105046Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105046Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105046Parser::StatementContext::FOR() {
  return getToken(C2105046Parser::FOR, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::LPAREN() {
  return getToken(C2105046Parser::LPAREN, 0);
}

C2105046Parser::ExpressionContext* C2105046Parser::StatementContext::expression() {
  return getRuleContext<C2105046Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105046Parser::StatementContext::RPAREN() {
  return getToken(C2105046Parser::RPAREN, 0);
}

std::vector<C2105046Parser::StatementContext *> C2105046Parser::StatementContext::statement() {
  return getRuleContexts<C2105046Parser::StatementContext>();
}

C2105046Parser::StatementContext* C2105046Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105046Parser::StatementContext>(i);
}

tree::TerminalNode* C2105046Parser::StatementContext::IF() {
  return getToken(C2105046Parser::IF, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::ELSE() {
  return getToken(C2105046Parser::ELSE, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::WHILE() {
  return getToken(C2105046Parser::WHILE, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::PRINTLN() {
  return getToken(C2105046Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::SEMICOLON() {
  return getToken(C2105046Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105046Parser::StatementContext::RETURN() {
  return getToken(C2105046Parser::RETURN, 0);
}


size_t C2105046Parser::StatementContext::getRuleIndex() const {
  return C2105046Parser::RuleStatement;
}

void C2105046Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105046Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any C2105046Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::StatementContext* C2105046Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105046Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(245);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : var_declaration\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr_stm = expression_statement();

      			if(antlrcpp::downCast<StatementContext *>(_localctx)->expr_stm->print_text != ""){
      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : expression_statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->expr_stm->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";
      			}
      			else {
      				antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  "";
      			}
      	  
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->csm = compound_statement();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : compound_statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->csm->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";
      	  
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(254);
      antlrcpp::downCast<StatementContext *>(_localctx)->fr = match(C2105046Parser::FOR);

      		symbolTable.enterScope();
      		scoped = true;
      		string start_label = getLabel();
      		string out_label = getLabel();
      		string increment_step = getLabel();
      		string inside_step = getLabel();
      	  
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr_st1 = expression_statement();

      		// pre comparison steps
      		writeIntoCodeFile(
      			start_label + string(":") + string("; Line ") + to_string(_input->LT(-1)->getLine())
      		);
      		pop_flag = false;
      	  
      setState(259);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr_st2 = expression_statement();

      		// post comparison happens here
      		writeIntoCodeFile(
      			string("\tPOP AX; comparision happens here (for loop starts up)\n\tCMP AX, 0\n\tJE ") + out_label +
      			string("\n\tJMP ") + inside_step + string("\n") +
      			increment_step + string(":") 
      		);
      	  
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression(0);

      		writeIntoCodeFile(
      			string("\tPOP AX; incrementing starts here\n\tJMP ") + start_label + string("\n") +
      			inside_step + string(":; inside forloop step\n")
      		);

      	  
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->stm = statement();

      			// inside step for for
      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->fr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->expr_st1->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->expr_st2->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->stm->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";

      			writeIntoCodeFile(
      				string("\tJMP ") + increment_step +
      				string("\n") + out_label + string(": ; for loop ends here")
      			);
      	   
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(267);
      antlrcpp::downCast<StatementContext *>(_localctx)->if_ = match(C2105046Parser::IF);


      		string done_label = getLabel();
      	  
      setState(269);
      antlrcpp::downCast<StatementContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression(0);
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);


      		// string done_label = getLabel();
      		writeIntoCodeFile(
      			string("\tPOP AX; only if condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
      			+ string("\n\tCMP AX, 0\n\tJE ") + done_label
      		);

      	  
      setState(273);
      antlrcpp::downCast<StatementContext *>(_localctx)->stm = statement();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->if_->getLine()) + string(": statement : IF LPAREN expression RPAREN statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->if_->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->stm->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";

      			writeIntoCodeFile(
      				done_label + string(":")
      			);

      	  
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(276);
      antlrcpp::downCast<StatementContext *>(_localctx)->if_ = match(C2105046Parser::IF);
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(278);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression(0);
      setState(279);
      antlrcpp::downCast<StatementContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);


      		string else_label = getLabel();
      		string done_label = getLabel();
      		writeIntoCodeFile(
      			string("\tPOP AX; if else condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
      			+ string("\n\tCMP AX, 0\n\tJE ") + else_label 
      		);

      	  
      setState(281);
      antlrcpp::downCast<StatementContext *>(_localctx)->stm1 = statement();


      		writeIntoCodeFile(
      			string("\tJMP ") + done_label
      		);

      	  
      setState(283);
      antlrcpp::downCast<StatementContext *>(_localctx)->else_ = match(C2105046Parser::ELSE);

      		writeIntoCodeFile(
      			else_label + string(":")
      		);
      	  
      setState(285);
      antlrcpp::downCast<StatementContext *>(_localctx)->stm2 = statement();
       
      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : IF LPAREN expression RPAREN statement ELSE statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->if_->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->stm1->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->else_->getText() + string(" ") + antlrcpp::downCast<StatementContext *>(_localctx)->stm2->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";
      			
      			writeIntoCodeFile(
      				done_label + string(":")
      			);
      	  
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(288);
      antlrcpp::downCast<StatementContext *>(_localctx)->while_ = match(C2105046Parser::WHILE);

      		string start_label = getLabel();
      		string out_label = getLabel();
      		writeIntoCodeFile(
      			start_label + string(": ; while loop starts") + string("Line ") + to_string(_input->LT(-1)->getLine())
      		);
      	  
      setState(290);
      antlrcpp::downCast<StatementContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(291);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression(0);
      setState(292);
      antlrcpp::downCast<StatementContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);

      		writeIntoCodeFile(
      			string("\tPOP AX\n\tCMP AX, 0\n\tJE ") + out_label
      		);
      	  
      setState(294);
      antlrcpp::downCast<StatementContext *>(_localctx)->stm = statement();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : WHILE LPAREN expression RPAREN statement\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->while_->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->stm->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";

      			writeIntoCodeFile(
      				string("\tJMP ") + start_label 
      				+ string("\n") + out_label + string(": ; while loop ends\n")
      			);
      	  
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(297);
      antlrcpp::downCast<StatementContext *>(_localctx)->pln = match(C2105046Parser::PRINTLN);
      setState(298);
      antlrcpp::downCast<StatementContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(299);
      antlrcpp::downCast<StatementContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(300);
      antlrcpp::downCast<StatementContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);
      setState(301);
      antlrcpp::downCast<StatementContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->pln->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->rpr->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->sm->getText();
      			string name = antlrcpp::downCast<StatementContext *>(_localctx)->id->getText();
      			SymbolInfo* symbol = symbolTable.lookUp(name);
      			if(symbol == nullptr){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
      				);
      				syntaxErrorCount++;
      			}
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  "void";

      			if(symbol){
      				if(symbol->getIsGlobal()){
      					writeIntoCodeFile(
      						string("\tMOV AX, ") + symbol->getName() + string(" ; print function call from here")
      					);
      				} else{
      					string offset = to_string(symbol->getOffset());
      					writeIntoCodeFile(
      						string("\tMOV AX, [BP - ") + offset + string("] ; print function call from here")
      					);
      				}
      				writeIntoCodeFile(
      					string("\tCALL print_output\n\tCALL new_line")
      				);
      				
      			}
      	  
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(303);
      antlrcpp::downCast<StatementContext *>(_localctx)->ret = match(C2105046Parser::RETURN);
      setState(304);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression(0);
      setState(305);
      antlrcpp::downCast<StatementContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : RETURN expression SEMICOLON\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->print_text =  antlrcpp::downCast<StatementContext *>(_localctx)->ret->getText() + string(" ") + antlrcpp::downCast<StatementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<StatementContext *>(_localctx)->sm->getText();
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<StatementContext *>(_localctx)->return_type =  antlrcpp::downCast<StatementContext *>(_localctx)->expr->dataType;
      			writeIntoCodeFile(
      				string("\tPOP AX; return statement written here") + string("; Line ") + to_string(_input->LT(-1)->getLine())
      				+ string("\n\tJMP ") + current_return_label
      			);
      	  
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105046Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105046Parser::SEMICOLON, 0);
}

C2105046Parser::ExpressionContext* C2105046Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105046Parser::ExpressionContext>(0);
}


size_t C2105046Parser::Expression_statementContext::getRuleIndex() const {
  return C2105046Parser::RuleExpression_statement;
}

void C2105046Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105046Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}


std::any C2105046Parser::Expression_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitExpression_statement(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Expression_statementContext* C2105046Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105046Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(316);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105046Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(310);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

        			writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : SEMICOLON\n")
        			);
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->print_text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm->getText();
        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        			);
        	 
        break;
      }

      case C2105046Parser::LPAREN:
      case C2105046Parser::ADDOP:
      case C2105046Parser::NOT:
      case C2105046Parser::ID:
      case C2105046Parser::CONST_INT:
      case C2105046Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(312);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->expr = expression(0);
        setState(313);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm = match(C2105046Parser::SEMICOLON);

        			if(antlrcpp::downCast<Expression_statementContext *>(_localctx)->expr->print_text != ""){
        			writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : expression SEMICOLON\n")
        			);
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->print_text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expr->print_text + antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm->getText();
        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        			);
        			}
        			else {
        				antlrcpp::downCast<Expression_statementContext *>(_localctx)->print_text =  "";
        			}

        			writeIntoCodeFile(
        				string("\t; comes to expression_statement")
        			);
        			if(pop_flag){
        				writeIntoCodeFile(
        					string("\tPOP AX; expression_statement pop")
        				);
        				
        			}

        			pop_flag = true;

        			
        	
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105046Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::VariableContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::VariableContext::LTHIRD() {
  return getToken(C2105046Parser::LTHIRD, 0);
}

C2105046Parser::ExpressionContext* C2105046Parser::VariableContext::expression() {
  return getRuleContext<C2105046Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105046Parser::VariableContext::RTHIRD() {
  return getToken(C2105046Parser::RTHIRD, 0);
}


size_t C2105046Parser::VariableContext::getRuleIndex() const {
  return C2105046Parser::RuleVariable;
}

void C2105046Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105046Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}


std::any C2105046Parser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::VariableContext* C2105046Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105046Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(318);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105046Parser::ID);

      		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID\n")
      		);
      		string name = antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
      		SymbolInfo* symbol = symbolTable.lookUp(name);
      		antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  false;
      		if(symbol == nullptr){
      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
      			);

      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
      			);
      			antlrcpp::downCast<VariableContext *>(_localctx)->dataType =  "invalid";
      			antlrcpp::downCast<VariableContext *>(_localctx)->symbol =  nullptr;
      			syntaxErrorCount++;
      		} else {
      			antlrcpp::downCast<VariableContext *>(_localctx)->dataType =  symbol->getDataType();
      			antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  symbol->getIsArray();
      			antlrcpp::downCast<VariableContext *>(_localctx)->symbol =  symbol;
      			// string msg = "false";
      			// if(_localctx->isArray){
      			// 	msg = "true";
      			// }
      			// writeIntoparserLogFile(
      			// 	string("DEBUG var condition check true: ") + msg
      			// );
      			
      		}

      		antlrcpp::downCast<VariableContext *>(_localctx)->print_text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
      		//antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  symbol->getIsArray();
      		
      		writeIntoparserLogFile(
         			string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText()) + string("\n")
        		);
      		
      	

      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(320);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(321);
      antlrcpp::downCast<VariableContext *>(_localctx)->lthr = match(C2105046Parser::LTHIRD);
      setState(322);
      antlrcpp::downCast<VariableContext *>(_localctx)->expr = expression(0);
      setState(323);
      antlrcpp::downCast<VariableContext *>(_localctx)->rthr = match(C2105046Parser::RTHIRD);

      		writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID LTHIRD expression RTHIRD\n")
      			);
      			antlrcpp::downCast<VariableContext *>(_localctx)->print_text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->lthr->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->expr->print_text + antlrcpp::downCast<VariableContext *>(_localctx)->rthr->getText();
      			antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  false;
      			if(antlrcpp::downCast<VariableContext *>(_localctx)->expr->dataType == "float"){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
      				);

      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
      				);
      				syntaxErrorCount++;
      			}
      			

      			string name = antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
      			SymbolInfo* symbol = symbolTable.lookUp(name);

      			if(symbol == nullptr){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
      				);

      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
      				);
      				// antlrcpp::downCast<VariableContext *>(_localctx)->dataType =  "invalid";
      				antlrcpp::downCast<VariableContext *>(_localctx)->symbol =  nullptr;
      				syntaxErrorCount++;
      			} else {
      				if(!symbol->getIsArray()){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
      					);

      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
      					);
      					antlrcpp::downCast<VariableContext *>(_localctx)->symbol =  nullptr;
      					syntaxErrorCount++;
      				}
      				antlrcpp::downCast<VariableContext *>(_localctx)->dataType =  symbol->getDataType();
      				antlrcpp::downCast<VariableContext *>(_localctx)->symbol =  symbol;
      				antlrcpp::downCast<VariableContext *>(_localctx)->arr_ind =  antlrcpp::downCast<VariableContext *>(_localctx)->expr->print_text;

      				// if(symbol->getIsGlobal()){

      				// 	writeIntoCodeFile(
      				// 		string("\tPOP BX ; arr offset\n") +
      				// 		string("\tMOV AX, ") + symbol->getName() + string("[BX]") + 
      				// 		string("\n\tPUSH AX; var push")
      				// 	);
      				// } else {
      				// 	string offset = to_string(symbol->getOffset());
      				// 	writeIntoCodeFile(	
      				// 		string("\tPOP BX ; arr offset\n") +
      				// 		string("\tSHL BX, 1\n") +
      				// 		string("\tMOV AX, ") + offset + string("\n") +
      				// 		string("\tSUB AX, BX\n") +
      				// 		string("\tMOV BX, AX\n") +
      				// 		string("\tMOV SI, BX\n") +
      				// 		string("\tNEG SI\n") +
      				// 		string("\tMOV AX, [BP + SI]\n") + 
      				// 		string("\tPUSH AX; var push")
      				// 	);
      				// }
      			}

      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);





      			// antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  symbol->getIsArray();
      				
      			
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105046Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::VariableContext* C2105046Parser::ExpressionContext::variable() {
  return getRuleContext<C2105046Parser::VariableContext>(0);
}

std::vector<tree::TerminalNode *> C2105046Parser::ExpressionContext::ASSIGNOP() {
  return getTokens(C2105046Parser::ASSIGNOP);
}

tree::TerminalNode* C2105046Parser::ExpressionContext::ASSIGNOP(size_t i) {
  return getToken(C2105046Parser::ASSIGNOP, i);
}

std::vector<C2105046Parser::Logic_expressionContext *> C2105046Parser::ExpressionContext::logic_expression() {
  return getRuleContexts<C2105046Parser::Logic_expressionContext>();
}

C2105046Parser::Logic_expressionContext* C2105046Parser::ExpressionContext::logic_expression(size_t i) {
  return getRuleContext<C2105046Parser::Logic_expressionContext>(i);
}

tree::TerminalNode* C2105046Parser::ExpressionContext::ADDOP() {
  return getToken(C2105046Parser::ADDOP, 0);
}

C2105046Parser::ExpressionContext* C2105046Parser::ExpressionContext::expression() {
  return getRuleContext<C2105046Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105046Parser::ExpressionContext::INVALID_CHAR() {
  return getToken(C2105046Parser::INVALID_CHAR, 0);
}


size_t C2105046Parser::ExpressionContext::getRuleIndex() const {
  return C2105046Parser::RuleExpression;
}

void C2105046Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105046Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any C2105046Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::ExpressionContext* C2105046Parser::expression() {
   return expression(0);
}

C2105046Parser::ExpressionContext* C2105046Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  C2105046Parser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, C2105046Parser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(329);
      variable();
      setState(330);
      match(C2105046Parser::ASSIGNOP);
      setState(331);
      logic_expression();
      setState(332);
      match(C2105046Parser::ADDOP);
      setState(333);
      match(C2105046Parser::ASSIGNOP);
      setState(334);
      logic_expression();

      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
      			);
      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
      			);
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->print_text =  "";
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->dataType = "";
      			syntaxErrorCount++;
      	   
      break;
    }

    case 2: {
      setState(337);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : logic_expression\n")
      			);
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->print_text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->dataType =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType;
       		
      break;
    }

    case 3: {
      setState(340);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(341);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assop = match(C2105046Parser::ASSIGNOP);
      setState(342);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : variable ASSIGNOP logic_expression\n")
      			);
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->print_text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->print_text + antlrcpp::downCast<ExpressionContext *>(_localctx)->assop->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->print_text;

      			bool is_func = false;

      			if(antlrcpp::downCast<ExpressionContext *>(_localctx)->le->symbol != nullptr && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->symbol->getDataType() == "FUNCTION"){
      				is_func = true;
      				// writeIntoparserLogFile(
      				// 	string("DEBUG comes here ") 
      				// );
      			}
      			
      			if(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType != antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType && antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType != "invalid" && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType != "invalid" && !is_func && !(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType == "float" && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType == "int")){
      				// writeIntoparserLogFile(
      				// 	string("DEBUG Variable datatype: ") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType)+ string(" le dataType") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType) + string("\n")
      				// );
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      				);
      				syntaxErrorCount++;
      			}
      			else if(is_func && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->symbol->getReturnType() != antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType ){
      				// writeIntoparserLogFile(
      				// 	string("DEBUG Variable FUNC: ") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType)+ string(" le dataType") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->le->dataType) + string("\n")
      				// );
      				if(antlrcpp::downCast<ExpressionContext *>(_localctx)->le->symbol->getReturnType() == "void"){
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
      					);
      					syntaxErrorCount++;
      				} else {
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      					);
      					syntaxErrorCount++;
      				}
      			}

      			// writeIntoparserLogFile(
      			// 	string("cums\n")
      			// );
      			

      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->dataType =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->dataType;

      			if(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->isArray && !antlrcpp::downCast<ExpressionContext *>(_localctx)->le->isArray){
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ antlrcpp::downCast<ExpressionContext *>(_localctx)->v->print_text + string(" is an array\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ antlrcpp::downCast<ExpressionContext *>(_localctx)->v->print_text + string(" is an array\n")
      				);
      				syntaxErrorCount++;
      			}

      			
      			// Assembly Code 
      			SymbolInfo* symbol = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->symbol;
      			if(symbol != nullptr){
      				if(!symbol->getIsGlobal()){
      					if(symbol->getIsArray()){

      						string str_ind = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->arr_ind;
      						int actual_offset = symbol->getOffset() - stoi(str_ind) * 2;

      						writeIntoCodeFile(
      							string("\tPOP AX\n") + 
      							string("\tMOV [BP - ") + to_string(actual_offset) + string("], AX")
      						);
      					} else {
      						writeIntoCodeFile(
      							string("\tPOP AX\n") + 
      							string("\tMOV [BP - ") + to_string(symbol->getOffset()) + string("], AX")
      						);
      					}
      					
      				} else {
      					
      					if(symbol->getIsArray()){

      						writeIntoparserLogFile(
      							string("cums\n")
      						);
      						string str_ind = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->arr_ind;
      						string actual_offset = to_string(stoi(str_ind) * 2);

      						writeIntoparserLogFile(
      							string("cums\n")
      						);
      						writeIntoCodeFile(
      							string("\tPOP AX\n") + 
      							string("\tMOV ") + symbol->getName() + string("[") + str_ind + string("], AX")
      						);
      					} else {
      						writeIntoCodeFile(
      							string("\tPOP AX\n") + 
      							string("\tMOV ") + symbol->getName() + string(", AX")
      						);
      					}
      					
      				}
      				
      			}

      			writeIntoCodeFile(
      				string("\tPUSH AX; expression push")
      			);

      			

      			
      	   
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(352);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(347);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(348);
        antlrcpp::downCast<ExpressionContext *>(_localctx)->ic = match(C2105046Parser::INVALID_CHAR);

                  		writeIntoparserLogFile(
                  			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ic->getText()) + string("\n")
                  		);
                  		writeIntoErrorFile(
                  			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ic->getText()) + string("\n")
                  		);
                  		// antlrcpp::downCast<ExpressionContext *>(_localctx)->print_text =  "";
                  		syntaxErrorCount++;
                  	   
      }
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105046Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105046Parser::Rel_expressionContext *> C2105046Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105046Parser::Rel_expressionContext>();
}

C2105046Parser::Rel_expressionContext* C2105046Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105046Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105046Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105046Parser::LOGICOP, 0);
}


size_t C2105046Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105046Parser::RuleLogic_expression;
}

void C2105046Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105046Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}


std::any C2105046Parser::Logic_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitLogic_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Logic_expressionContext* C2105046Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105046Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(355);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re = rel_expression();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression\n")
      			);
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);

      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->dataType;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->isArray;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->symbol =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->symbol;
      			// string msg = "false";
      			// if(_localctx->isArray){
      			// 	msg = "true";
      			// }

      			// writeIntoparserLogFile(
      			// 	string("DEBUG logic lexpr condition check: ") + msg
      			// );
       		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      			string check_label = getLabel();
      			string done_label = getLabel();
      		 
      setState(359);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();



      			writeIntoCodeFile(
      				string("\tPOP AX; logic_expression : rel_expression LOGICOP rel_expression") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
      			);


      		 
      setState(361);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lop = match(C2105046Parser::LOGICOP);

      			if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lop->getText() == "||"){
      				writeIntoCodeFile(
      					string("\tCMP AX, 0\n\tJE ") + check_label + 
      					string("\n\tPUSH 1\n\tJMP ") + done_label + string("\n") +
      					check_label + string(": ; logical check label")
      				);
      			} else if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lop->getText() == "&&"){
      				writeIntoCodeFile(
      					string("\tCMP AX, 0\n\tJNE ") + check_label + 
      					string("\n\tPUSH 0\n\tJMP ") + done_label + string("\n") +
      					check_label + string(":; logical check label")
      				);
      			}
      		 
      setState(363);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression LOGICOP rel_expression\n")
      			);
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->print_text + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lop->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->dataType;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->symbol =  nullptr;

      			// Assembly codes


      			writeIntoCodeFile(
      				string("\tPOP BX; logic_expression : rel_expression LOGICOP rel_expression")
      			);
      			
      			string false_label = getLabel();

      			writeIntoCodeFile(
      				string("\tCMP BX, 0\n\tJE ") + false_label + string("\n") +
      				string("\tPUSH 1\n\tJMP ") + done_label + string("\n") +
      				false_label  + string(": ; this is the false label\n") + 
      				string("\tPUSH 0")
      			);

      			writeIntoCodeFile(
      				done_label + string(":; logical operation done label")
      			);
      		 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105046Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105046Parser::Simple_expressionContext *> C2105046Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105046Parser::Simple_expressionContext>();
}

C2105046Parser::Simple_expressionContext* C2105046Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105046Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105046Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105046Parser::RELOP, 0);
}


size_t C2105046Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105046Parser::RuleRel_expression;
}

void C2105046Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105046Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}


std::any C2105046Parser::Rel_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitRel_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Rel_expressionContext* C2105046Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105046Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se = simple_expression(0);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression\n")
      			);
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->dataType;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->isArray;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->symbol =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->symbol;
      			// string msg = "false";
      			// if(_localctx->isArray){
      			// 	msg = "true";
      			// }

      			// writeIntoparserLogFile(
      			// 	string("DEBUG rel lexpr condition check: ") + msg
      			// );
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1 = simple_expression(0);
      setState(372);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop = match(C2105046Parser::RELOP);
      setState(373);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2 = simple_expression(0);

      			writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression RELOP simple_expression\n")
      			);
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->print_text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2->print_text;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);

      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->dataType =  "int";
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->symbol =  nullptr;

      			// Assembly codes
      			string true_label = getLabel();
      			string done_label = getLabel();


      			writeIntoCodeFile(
      				string("\tPOP BX; rel_expr: simple_expr relop simple_expr") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
      			); 



      			writeIntoCodeFile(
      				string("\tPOP AX")
      			); 




      			writeIntoCodeFile(
      				string("\tCMP AX, BX") 
      			);
      			if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == ">"){
      				writeIntoCodeFile(
      					string("\tJG ") + true_label
      				);
      			} else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == ">="){
      				writeIntoCodeFile(
      					string("\tJGE ") + true_label
      				);
      			} else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == "<="){
      				writeIntoCodeFile(
      					string("\tJLE ") + true_label
      				);
      			} else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == "<"){
      				writeIntoCodeFile(
      					string("\tJL ") + true_label
      				);
      			} else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == "!="){
      				writeIntoCodeFile(
      					string("\tJNE ") + true_label
      				);
      			} else if(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relop->getText() == "=="){
      				writeIntoCodeFile(
      					string("\tJE ") + true_label
      				);
      			}

      			writeIntoCodeFile(
      				string("\tPUSH 0\n\tJMP ") + done_label
      				+ string("\n") + true_label + string(":\n") +
      				string("\tPUSH 1\n") + done_label + string (":\n") 
      			);


      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105046Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::TermContext* C2105046Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105046Parser::TermContext>(0);
}

C2105046Parser::Simple_expressionContext* C2105046Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105046Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105046Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105046Parser::ADDOP, 0);
}


size_t C2105046Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105046Parser::RuleSimple_expression;
}

void C2105046Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105046Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


std::any C2105046Parser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::Simple_expressionContext* C2105046Parser::simple_expression() {
   return simple_expression(0);
}

C2105046Parser::Simple_expressionContext* C2105046Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105046Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105046Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(379);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

    				writeIntoparserLogFile(
    					string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : term\n")
    				);
    				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->print_text;
    				writeIntoparserLogFile(
    					_localctx->print_text + string("\n")
    				);

    				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->dataType;
    				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->isArray;
    				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->symbol =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->symbol;
    				// string msg = "false";
    				// if(_localctx->isArray){
    				// 	msg = "true";
    				// }

    				// writeIntoparserLogFile(
    				// 	string("DEBUG simple lexpr condition check: ") + msg
    				// );
    			
    _ctx->stop = _input->LT(-1);
    setState(389);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(382);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(383);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao = match(C2105046Parser::ADDOP);
        setState(384);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                  				writeIntoparserLogFile(
                  					string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : simple_expression ADDOP term\n")
                  				);

                  				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->print_text + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->print_text;
                  				writeIntoparserLogFile(
                  					_localctx->print_text + string("\n")
                  				);
                  				
                  				if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->dataType == "int" && antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->dataType == "float"){
                  					writeIntoErrorFile(
                  						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
                  					);
                  					writeIntoparserLogFile(
                  						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
                  					);
                  					antlrcpp::downCast<Simple_expressionContext *>(_localctx)->dataType =  "invalid";
                  					syntaxErrorCount++;
                  				}
                  				else if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->dataType == "float" && antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->dataType == "int"){
                  					antlrcpp::downCast<Simple_expressionContext *>(_localctx)->dataType =  "float";
                  				}
                  				else {
                  					antlrcpp::downCast<Simple_expressionContext *>(_localctx)->dataType =  "int";
                  				}

                  				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->symbol =  nullptr;

                  				// Assembly codes

                  				writeIntoCodeFile(
                  					string("\tPOP BX ; simple expression: simple expression add op term") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
                  				);

                  				writeIntoCodeFile(
                  					string("\tPOP AX")
                  				);


                  				if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText() == "+"){
                  					writeIntoCodeFile(
                  						string("\tADD AX, BX\n\tPUSH AX")
                  					);
                  				} else if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText() == "-"){
                  					writeIntoCodeFile(
                  						string("\tSUB AX, BX\n\tPUSH AX")
                  					);
                  				}

                  				
                  		   
      }
      setState(391);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105046Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Unary_expressionContext* C2105046Parser::TermContext::unary_expression() {
  return getRuleContext<C2105046Parser::Unary_expressionContext>(0);
}

C2105046Parser::TermContext* C2105046Parser::TermContext::term() {
  return getRuleContext<C2105046Parser::TermContext>(0);
}

tree::TerminalNode* C2105046Parser::TermContext::MULOP() {
  return getToken(C2105046Parser::MULOP, 0);
}


size_t C2105046Parser::TermContext::getRuleIndex() const {
  return C2105046Parser::RuleTerm;
}

void C2105046Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105046Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any C2105046Parser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::TermContext* C2105046Parser::term() {
   return term(0);
}

C2105046Parser::TermContext* C2105046Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105046Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105046Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(393);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

    		writeIntoparserLogFile(
    			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : unary_expression\n")
    		);

    		writeIntoparserLogFile(
    			antlrcpp::downCast<TermContext *>(_localctx)->u->print_text + string("\n")
    		);

    		antlrcpp::downCast<TermContext *>(_localctx)->print_text =  antlrcpp::downCast<TermContext *>(_localctx)->u->print_text;
    		antlrcpp::downCast<TermContext *>(_localctx)->dataType =  antlrcpp::downCast<TermContext *>(_localctx)->u->dataType;
    		antlrcpp::downCast<TermContext *>(_localctx)->isArray =  antlrcpp::downCast<TermContext *>(_localctx)->u->isArray;
    		antlrcpp::downCast<TermContext *>(_localctx)->symbol =  antlrcpp::downCast<TermContext *>(_localctx)->u->symbol;

    		// string msg = "false";
    		// if(_localctx->isArray){
    		// 	msg = "true";
    		// }

    		// writeIntoparserLogFile(
    		// 	string("DEBUG term lexpr condition check: ") + msg
    		// );

    	
    _ctx->stop = _input->LT(-1);
    setState(403);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(396);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(397);
        antlrcpp::downCast<TermContext *>(_localctx)->mul = match(C2105046Parser::MULOP);
        setState(398);
        antlrcpp::downCast<TermContext *>(_localctx)->una = unary_expression();

                  		writeIntoparserLogFile(
                  				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
                  			);
                  			// bool invalid = false;
                  			antlrcpp::downCast<TermContext *>(_localctx)->print_text =  antlrcpp::downCast<TermContext *>(_localctx)->t->print_text + antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() + antlrcpp::downCast<TermContext *>(_localctx)->una->print_text;
                  			if(antlrcpp::downCast<TermContext *>(_localctx)->t->dataType == "float" || antlrcpp::downCast<TermContext *>(_localctx)->una->dataType == "float"){
                  				antlrcpp::downCast<TermContext *>(_localctx)->dataType =  "float";
                  			} else {
                  				antlrcpp::downCast<TermContext *>(_localctx)->dataType =  "int";
                  			}

                  			// // test
                  			// writeIntoparserLogFile(
                  			// 	string("test1 ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
                  			// );

                  			if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() == "%" && antlrcpp::downCast<TermContext *>(_localctx)->una->dataType != "int"){
                  				antlrcpp::downCast<TermContext *>(_localctx)->dataType =  "int";
                  				writeIntoErrorFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Non-Integer operand on modulus operator\n")
                  				);

                  				writeIntoparserLogFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Non-Integer operand on modulus operator\n")
                  				);
                  				syntaxErrorCount++;
                  			}

                  			// // test
                  			// writeIntoparserLogFile(
                  			// 	string("test2 ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
                  			// );


                  			if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() == "%" && antlrcpp::downCast<TermContext *>(_localctx)->una->print_text == "0"){
                  				antlrcpp::downCast<TermContext *>(_localctx)->dataType =  "int";
                  				writeIntoErrorFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Modulus by Zero\n")
                  				);

                  				writeIntoparserLogFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Modulus by Zero\n")
                  				);
                  				syntaxErrorCount++;
                  			}

                  			// // test
                  			// writeIntoparserLogFile(
                  			// 	string("test3 ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
                  			// );


                  			if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() == "/" && antlrcpp::downCast<TermContext *>(_localctx)->una->print_text == "0"){
                  				antlrcpp::downCast<TermContext *>(_localctx)->dataType =  "int";
                  				writeIntoErrorFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
                  				);

                  				writeIntoparserLogFile(
                  					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
                  				);
                  				syntaxErrorCount++;
                  			}

                  			

                  			// if(antlrcpp::downCast<TermContext *>(_localctx)->una->dataType == "FUNCTION" &&  antlrcpp::downCast<TermContext *>(_localctx)->una->symbol->getReturnType() == "void"){
                  			// 	writeIntoErrorFile(
                  			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
                  			// 	);

                  			// 	writeIntoparserLogFile(
                  			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
                  			// 	);
                  			// 	syntaxErrorCount++;
                  			// }



                  			writeIntoparserLogFile(
                  				_localctx->print_text + string("\n")
                  			);

                  			

                  			writeIntoCodeFile(
                  				string("\tPOP BX; term: term MULOP una") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
                  			);
                  			// Assuming all are correct Assembly code

                  			writeIntoCodeFile(
                  				string("\tPOP AX")
                  			);


                  				
                  			if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText()== "*"){
                  				writeIntoCodeFile(
                  					string("\tIMUL BX\n\tPUSH AX")
                  				);
                  			} else if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() == "/"){
                  				writeIntoCodeFile(
                  					string("\tCWD\n\tIDIV BX\n\tPUSH AX")
                  				);
                  			}	else if(antlrcpp::downCast<TermContext *>(_localctx)->mul->getText() == "%") {
                  				writeIntoCodeFile(
                  					string("\tCWD\n\tIDIV BX\n\tPUSH DX")
                  				);
                  			}
                  			


                  			antlrcpp::downCast<TermContext *>(_localctx)->symbol =  nullptr;

                  		
                  	  
      }
      setState(405);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105046Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105046Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105046Parser::ADDOP, 0);
}

C2105046Parser::Unary_expressionContext* C2105046Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105046Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105046Parser::Unary_expressionContext::NOT() {
  return getToken(C2105046Parser::NOT, 0);
}

C2105046Parser::FactorContext* C2105046Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105046Parser::FactorContext>(0);
}


size_t C2105046Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105046Parser::RuleUnary_expression;
}

void C2105046Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105046Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}


std::any C2105046Parser::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Unary_expressionContext* C2105046Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105046Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(417);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105046Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(406);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addop = match(C2105046Parser::ADDOP);
        setState(407);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una = unary_expression();

        			writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : ADDOP unary_expression\n")
        			);
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addop->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->print_text;


        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        			);

        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->dataType;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->symbol =  nullptr;

        			
        			if(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addop->getText() == "-"){
        				// if(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->symbol == nullptr){
        					
        				// } else {
        						
        				// 		SymbolInfo* symbol = antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->symbol;
        				// 		if(symbol->getIsGlobal()){
        				// 			writeIntoCodeFile(
        				// 				string("\tMOV AX, ") + _localctx->symbol->getName() + string("; unary_expr : addop unary_expression")
        				// 			);
        				// 		} else {
        				// 			string offset = to_string(symbol->getOffset());
        				// 			writeIntoCodeFile(
        				// 				string("\tMOV AX, [BP - ") + offset + string("]; unary_expr : addop unary_expression")
        				// 			);
        				// 		}
        				// }

        				writeIntoCodeFile(
        					string("\tPOP AX; unary_expr : addop unary_expression") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
        				);
        				writeIntoCodeFile(
        					string("\tNEG AX\n\tPUSH AX")
        				);
        			}

        			
        			
        		
        break;
      }

      case C2105046Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(410);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->not_ = match(C2105046Parser::NOT);
        setState(411);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una = unary_expression();

        			writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : NOT unary_expression\n")
        			);
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->not_->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->print_text;
        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        			);

        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->dataType;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->symbol =  nullptr;

        			string not_zero_label = getLabel();
        			string done_label = getLabel();

        			if(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->symbol == nullptr){
        				writeIntoCodeFile(
        					string("\tPOP AX")
        				);
        			} else {
        				SymbolInfo* symbol = antlrcpp::downCast<Unary_expressionContext *>(_localctx)->una->symbol;
        				if(symbol->getIsGlobal()){
        					writeIntoCodeFile(
        						string("\tMOV AX, ") + symbol->getName() 
        					);
        				} else {
        					string offset = to_string(symbol->getOffset());
        					writeIntoCodeFile(
        						string("\tMOV AX, [BP - ") + offset + string("]")
        					);
        				}
        				
        				
        			}

        			writeIntoCodeFile(
        				string("\tCMP AX, 0; unary_expr: not unary_expression\n\tJNE ") + not_zero_label + 
        				string("\n\tMOV AX, 1\n\tJMP ") + done_label +
        				string("\n") + not_zero_label + string(":\n") +
        				string("\tMOV AX, 0\n") + done_label + string(":\n") +
        				string("\tPUSH AX")
        			);
        		 
        break;
      }

      case C2105046Parser::LPAREN:
      case C2105046Parser::ID:
      case C2105046Parser::CONST_INT:
      case C2105046Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(414);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

        			writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : factor\n")
        			);

        			writeIntoparserLogFile(
        				antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->print_text + string("\n")
        			);
        			
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->print_text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->print_text;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->dataType =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->dataType;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->isArray;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->symbol =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->symbol;
        			// string msg = "false";
        			// if(_localctx->isArray){
        			// 	msg = "true";
        			// }

        			// writeIntoparserLogFile(
        			// 	string("DEBUG UNA lexpr condition check: ") + msg
        			// );
        		 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105046Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::VariableContext* C2105046Parser::FactorContext::variable() {
  return getRuleContext<C2105046Parser::VariableContext>(0);
}

tree::TerminalNode* C2105046Parser::FactorContext::ID() {
  return getToken(C2105046Parser::ID, 0);
}

tree::TerminalNode* C2105046Parser::FactorContext::LPAREN() {
  return getToken(C2105046Parser::LPAREN, 0);
}

C2105046Parser::Argument_listContext* C2105046Parser::FactorContext::argument_list() {
  return getRuleContext<C2105046Parser::Argument_listContext>(0);
}

tree::TerminalNode* C2105046Parser::FactorContext::RPAREN() {
  return getToken(C2105046Parser::RPAREN, 0);
}

C2105046Parser::ExpressionContext* C2105046Parser::FactorContext::expression() {
  return getRuleContext<C2105046Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105046Parser::FactorContext::CONST_INT() {
  return getToken(C2105046Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105046Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105046Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105046Parser::FactorContext::INCOP() {
  return getToken(C2105046Parser::INCOP, 0);
}

tree::TerminalNode* C2105046Parser::FactorContext::DECOP() {
  return getToken(C2105046Parser::DECOP, 0);
}


size_t C2105046Parser::FactorContext::getRuleIndex() const {
  return C2105046Parser::RuleFactor;
}

void C2105046Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105046Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any C2105046Parser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::FactorContext* C2105046Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105046Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(445);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(419);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

      		writeIntoparserLogFile(
         			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable\n")
        		);

      		writeIntoparserLogFile(
      			string(antlrcpp::downCast<FactorContext *>(_localctx)->v->print_text) + string("\n")
      		);

      		antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->print_text;
      		antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  antlrcpp::downCast<FactorContext *>(_localctx)->v->dataType;
      		antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->isArray;
      		antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  antlrcpp::downCast<FactorContext *>(_localctx)->v->symbol;
      		// string msg = "false";
      		// if(_localctx->isArray){
      		// 	msg = "true";
      		// }

      		// writeIntoparserLogFile(
      		// 	string("DEBUG factor lexpr condition check: ") + msg
      		// );

      		SymbolInfo * symbol = antlrcpp::downCast<FactorContext *>(_localctx)->v->symbol;

      		if(symbol->getIsArray()){
      			if(symbol->getIsGlobal()){
      				writeIntoCodeFile(
      					string("\tPOP BX ; arr offset\n") +
      					string("\tMOV AX, ") + symbol->getName() + string("[BX]") + 
      					string("\n\tPUSH AX; var push")
      				);
      			} else {
      				string offset = to_string(symbol->getOffset());
      				writeIntoCodeFile(	
      					string("\tPOP BX ; arr offset\n") +
      					string("\tSHL BX, 1\n") +
      					string("\tMOV AX, ") + offset + string("\n") +
      					string("\tSUB AX, BX\n") +
      					string("\tMOV BX, AX\n") +
      					string("\tMOV SI, BX\n") +
      					string("\tNEG SI\n") +
      					string("\tMOV AX, [BP + SI]\n") + 
      					string("\tPUSH AX; var push")
      				);
      			}
      		} else {
      			if(symbol->getIsGlobal()){
      				writeIntoCodeFile(
      					string("\tMOV AX, ") + symbol->getName() +
      					string("\n\tPUSH AX; var push")
      				);
      			} else {
      				string offset = to_string(symbol->getOffset());
      				writeIntoCodeFile(
      					string("\tMOV AX, [BP - ") + offset + string("]\n") + 
      					string("\tPUSH AX; var push")
      				);
      			}
      		}
      		
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(422);
      antlrcpp::downCast<FactorContext *>(_localctx)->id = match(C2105046Parser::ID);
      setState(423);
      antlrcpp::downCast<FactorContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(424);
      antlrcpp::downCast<FactorContext *>(_localctx)->arg_l = argument_list();
      setState(425);
      antlrcpp::downCast<FactorContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);

      		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : ID LPAREN argument_list RPAREN\n")
      		);
      		antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->print_text + antlrcpp::downCast<FactorContext *>(_localctx)->rpr->getText();
      		
      		string name = antlrcpp::downCast<FactorContext *>(_localctx)->id->getText();
      		SymbolInfo* symbol = symbolTable.lookUp(name);
      		if(symbol != nullptr){
      			if(symbol->getDataType() == "FUNCTION"){
      				vector<string>params = symbol->getParameters();
      				// writeIntoparserLogFile(
      				// 	string("DEBUG params size: ") + to_string(params.size()) + string(": arg_l argTypes size:  ") + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes.size())
      				// );
      				if(params.size() == antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes.size()){
      					for(int i = 0; i < params.size(); i++){
      						bool is_params_arr = false;
      						string params_data_type = params[i];
      						if(params[i].length() >= 2 && params[i].substr(params[i].length() - 2) == "[]"){
      							is_params_arr = true;
      							params_data_type = params[i].substr(0, params[i].length() - 2);
      						}
      						bool is_arg_arr = false;
      						string arg_data_type = antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i];
      						
      						if(antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i].length() >= 2 && antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i].substr(antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i].length() - 2) == "[]"){
      							is_arg_arr = true;
      							arg_data_type = antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i].substr(0, antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i].length() - 2);
      						}

      						// writeIntoparserLogFile(
      						// 	string("DEBUG params TYPE: ") + string(params_data_type) + string(": arg_l argTypes:  ") + string(arg_data_type)
      						// );
      						// writeIntoparserLogFile(
      						// 	string("DEBUG params TYPE: ") + string(params[i]) + string(": arg_l argTypes:  ") + string(antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argTypes[i])
      						// );

      						if(arg_data_type == params_data_type || (params_data_type == "float" && arg_data_type == "int")){
      							if(is_arg_arr && is_arg_arr != is_params_arr){
      								writeIntoErrorFile(
      									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argNames[i] + string(" is an array\n")
      								);
      								writeIntoparserLogFile(
      									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + antlrcpp::downCast<FactorContext *>(_localctx)->arg_l->argNames[i] + string(" is an array\n")
      								);
      								syntaxErrorCount++;
      							} else if (is_arg_arr != is_params_arr) {
      								writeIntoErrorFile(
      									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      								);
      								writeIntoparserLogFile(
      									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
      								);
      								syntaxErrorCount++;
      							}
      						}	else {
      							writeIntoErrorFile(
      								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getText()) + string("\n")
      							);
      							writeIntoparserLogFile(
      								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getText()) + string("\n")
      							);
      							syntaxErrorCount++;
      						}


      					}
      				} else {
      					writeIntoErrorFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + name + string("\n")
      					);
      					writeIntoparserLogFile(
      						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + name + string("\n")
      					);
      					syntaxErrorCount++;
      				}
      				antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  "FUNCTION";
      			} else {
      				writeIntoErrorFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
      				);
      				writeIntoparserLogFile(
      					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
      				);
      				syntaxErrorCount++;
      			}
      			antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  symbol;
      		} else {
      			writeIntoErrorFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
      			);
      			writeIntoparserLogFile(
      				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  "invalid";
      			syntaxErrorCount++;
      		}

      		writeIntoparserLogFile(
      			_localctx->print_text + string("\n")
      		);
      		antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;

      		writeIntoCodeFile(
      			string("\tCALL ") + name + string(" ; factor: function call") + string("Line ") + to_string(_input->LT(-1)->getLine()) +
      			string("\n\tPUSH AX")
      		);

      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(428);
      antlrcpp::downCast<FactorContext *>(_localctx)->lpr = match(C2105046Parser::LPAREN);
      setState(429);
      antlrcpp::downCast<FactorContext *>(_localctx)->expr = expression(0);
      setState(430);
      antlrcpp::downCast<FactorContext *>(_localctx)->rpr = match(C2105046Parser::RPAREN);

      		writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : LPAREN expression RPAREN\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->lpr->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->expr->print_text + antlrcpp::downCast<FactorContext *>(_localctx)->rpr->getText();
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
      			antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  antlrcpp::downCast<FactorContext *>(_localctx)->expr->dataType;
      			antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(433);
      antlrcpp::downCast<FactorContext *>(_localctx)->ci = match(C2105046Parser::CONST_INT);

      		writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_INT\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  "int";
      			antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;
      			writeIntoCodeFile(
      				string("\tMOV AX, ") + antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText() +  string("; Line ") + to_string(_input->LT(-1)->getLine()) + string("\n") +
      				string("\tPUSH AX")
      			);
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(435);
      antlrcpp::downCast<FactorContext *>(_localctx)->cf = match(C2105046Parser::CONST_FLOAT);

      		writeIntoparserLogFile(
      				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_FLOAT\n")
      			);
      			antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->dataType =  "float";
      			antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
      			antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;
      			writeIntoparserLogFile(
      				_localctx->print_text + string("\n")
      			);
      			writeIntoCodeFile(
      				string("\tPUSH ") + antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText()
      			);
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(437);
      antlrcpp::downCast<FactorContext *>(_localctx)->var = variable();
      setState(438);
      antlrcpp::downCast<FactorContext *>(_localctx)->incop = match(C2105046Parser::INCOP);

      		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable INCOP\n")
      		);
      		antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->var->print_text + antlrcpp::downCast<FactorContext *>(_localctx)->incop->getText();
      		writeIntoparserLogFile(
      			_localctx->print_text + string("\n")
      		);

      		SymbolInfo* symbol = antlrcpp::downCast<FactorContext *>(_localctx)->var->symbol;

      		if(symbol){
      			if(symbol->getIsGlobal()){
      				if(symbol->getIsArray()){
      					string actual_offset = to_string(2 * stoi(antlrcpp::downCast<FactorContext *>(_localctx)->var->arr_ind));
      					writeIntoCodeFile(
      						string("\tMOV AX, ") + symbol->getName() + string("[") + actual_offset + string("]; var inc\n") +
      						string("\tPUSH AX\n") +
      						string("\tADD AX, 1\n") + 
      						string("\tMOV ") + symbol->getName() + string("[") + actual_offset + string("], AX\n") 
      					);
      				} else {
      					writeIntoCodeFile(
      						string("\tMOV AX, ") + symbol->getName() + string("; var inc\n") +
      						string("\tPUSH AX\n") +
      						string("\tADD AX, 1\n") + 
      						string("\tMOV ") + symbol->getName() + string(", AX\n") 
      					);
      				}
      				
      			} else {
      				if(symbol->getIsArray()){
      					string offset = to_string(symbol->getOffset());
      					string actual_offset = to_string(stoi(offset) - 2 * stoi(antlrcpp::downCast<FactorContext *>(_localctx)->var->arr_ind));
      					writeIntoCodeFile(
      						string("\tMOV AX, [BP - ") + actual_offset + string("]; var inc\n") +
      						string("\tPUSH AX\n") +
      						string("\tADD AX, 1\n") + 
      						string("\tMOV [BP - ") + actual_offset + string("], AX\n") 
      					);
      				} else {
      					writeIntoCodeFile(
      						string("\tMOV AX, [BP - ") + to_string(symbol->getOffset()) + string("]; var inc\n") +
      						string("\tPUSH AX\n") +
      						string("\tADD AX, 1\n") + 
      						string("\tMOV [BP - ") + to_string(symbol->getOffset()) + string("], AX\n") 
      					);
      				}
      				
      			}
      		}
      		antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(441);
      antlrcpp::downCast<FactorContext *>(_localctx)->var = variable();
      setState(442);
      antlrcpp::downCast<FactorContext *>(_localctx)->decop = match(C2105046Parser::DECOP);

      		writeIntoparserLogFile(
      			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable DECOP\n")
      		);
      		antlrcpp::downCast<FactorContext *>(_localctx)->print_text =  antlrcpp::downCast<FactorContext *>(_localctx)->var->print_text + antlrcpp::downCast<FactorContext *>(_localctx)->decop->getText();
      		writeIntoparserLogFile(
      			_localctx->print_text + string("\n")
      		);
      		SymbolInfo* symbol = antlrcpp::downCast<FactorContext *>(_localctx)->var->symbol;
      		if(symbol){
      			if(symbol->getIsGlobal()){
      				if(symbol->getIsArray()){
      					string actual_offset = to_string(2 * stoi(antlrcpp::downCast<FactorContext *>(_localctx)->var->arr_ind));
      					writeIntoCodeFile(
      						string("\tMOV AX, ") + symbol->getName() + string("[") + actual_offset + string("]; var dec\n") +
      						string("\tPUSH AX\n") +
      						string("\tSUB AX, 1\n") + 
      						string("\tMOV ") + symbol->getName() + string("[") + actual_offset + string("], AX; var dec\n") 
      					);
      				} else {
      					writeIntoCodeFile(
      						string("\tMOV AX, ") + symbol->getName() + string("; var dec\n") +
      						string("\tPUSH AX\n") +
      						string("\tSUB AX, 1\n") + 
      						string("\tMOV ") + symbol->getName() + string(", AX\n") 
      					);
      				}
      				
      			} else {
      				if(symbol->getIsArray()){
      					string offset = to_string(symbol->getOffset());
      					string actual_offset = to_string(stoi(offset) - 2 * stoi(antlrcpp::downCast<FactorContext *>(_localctx)->var->arr_ind));
      					writeIntoCodeFile(
      						string("\tMOV AX, [BP - ") + actual_offset + string("]; var dec\n") +
      						string("\tPUSH AX\n") +
      						string("\tSUB AX, 1\n") + 
      						string("\tMOV [BP - ") + actual_offset + string("], AX\n") 
      					);
      				} else {
      					writeIntoCodeFile(
      						string("\tMOV AX, [BP - ") + to_string(symbol->getOffset()) + string("]; var dec\n") +
      						string("\tPUSH AX\n") +
      						string("\tSUB AX, 1\n") + 
      						string("\tMOV [BP - ") + to_string(symbol->getOffset()) + string("], AX\n") 
      					);
      				}
      				
      			}
      			
      		}
      		antlrcpp::downCast<FactorContext *>(_localctx)->symbol =  nullptr;
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105046Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::ArgumentsContext* C2105046Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105046Parser::ArgumentsContext>(0);
}


size_t C2105046Parser::Argument_listContext::getRuleIndex() const {
  return C2105046Parser::RuleArgument_list;
}

void C2105046Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105046Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}


std::any C2105046Parser::Argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitArgument_list(this);
  else
    return visitor->visitChildren(this);
}

C2105046Parser::Argument_listContext* C2105046Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105046Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105046Parser::LPAREN:
      case C2105046Parser::ADDOP:
      case C2105046Parser::NOT:
      case C2105046Parser::ID:
      case C2105046Parser::CONST_INT:
      case C2105046Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(447);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->args = arguments(0);

        		writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : arguments\n")
        			);
        			antlrcpp::downCast<Argument_listContext *>(_localctx)->print_text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->args->print_text;
        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        			);
        			antlrcpp::downCast<Argument_listContext *>(_localctx)->argTypes =  antlrcpp::downCast<Argument_listContext *>(_localctx)->args->argTypes;
        			antlrcpp::downCast<Argument_listContext *>(_localctx)->argNames =  antlrcpp::downCast<Argument_listContext *>(_localctx)->args->argNames;
        	
        break;
      }

      case C2105046Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        		writeIntoparserLogFile(
        				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : \n")
        			);
        			antlrcpp::downCast<Argument_listContext *>(_localctx)->print_text =  "";
        			writeIntoparserLogFile(
        				_localctx->print_text + string("\n")
        		);
        	
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105046Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105046Parser::Logic_expressionContext* C2105046Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105046Parser::Logic_expressionContext>(0);
}

C2105046Parser::ArgumentsContext* C2105046Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105046Parser::ArgumentsContext>(0);
}

tree::TerminalNode* C2105046Parser::ArgumentsContext::COMMA() {
  return getToken(C2105046Parser::COMMA, 0);
}


size_t C2105046Parser::ArgumentsContext::getRuleIndex() const {
  return C2105046Parser::RuleArguments;
}

void C2105046Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105046Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105046ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any C2105046Parser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105046ParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}


C2105046Parser::ArgumentsContext* C2105046Parser::arguments() {
   return arguments(0);
}

C2105046Parser::ArgumentsContext* C2105046Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105046Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105046Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C2105046Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(454);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr = logic_expression();

    			writeIntoparserLogFile(
    				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : logic_expression\n")
    			);
    			antlrcpp::downCast<ArgumentsContext *>(_localctx)->print_text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->print_text;
    			writeIntoparserLogFile(
    				_localctx->print_text + string("\n")
    			);
    			
    			if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->isArray){
    				_localctx->argTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->dataType + "[]");
    				// writeIntoparserLogFile(
    				// 	string("DEBUG lexpr condition check true: ") 
    				// );
    			}	else {
    				_localctx->argTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->dataType);
    				// writeIntoparserLogFile(
    				// 	string("DEBUG lexpr condition check false: ") 
    				// );
    			}

    			if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->symbol == nullptr){
    				_localctx->argNames.push_back("");
    			}
    			else {
    				_localctx->argNames.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->symbol->getName());
    			}

    			writeIntoCodeFile(
    				string("\t; pushing parameter into stack ") + antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->print_text + string("\n") 
    			);
    			
    		  
    _ctx->stop = _input->LT(-1);
    setState(464);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->args = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(457);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(458);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->cm = match(C2105046Parser::COMMA);
        setState(459);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr = logic_expression();

                  		writeIntoparserLogFile(
                  				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : arguments COMMA logic_expression\n")
                  			);
                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->print_text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->args->print_text + antlrcpp::downCast<ArgumentsContext *>(_localctx)->cm->getText() + antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->print_text;
                  			writeIntoparserLogFile(
                  				_localctx->print_text + string("\n")
                  			);

                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->argTypes =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->args->argTypes;
                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->argNames =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->args->argNames;
                  			if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->isArray){
                  				_localctx->argTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->dataType + "[]");
                  				// writeIntoparserLogFile(
                  				// 	string("DEBUG lexpr condition check true: ") 
                  				// );
                  			}	else {
                  				_localctx->argTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->dataType);
                  				// writeIntoparserLogFile(
                  				// 	string("DEBUG lexpr condition check false: ") 
                  				// );
                  			}

                  			if(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->symbol == nullptr){
                  				_localctx->argNames.push_back("");
                  			}
                  			else {
                  				_localctx->argNames.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->lexpr->symbol->getName());
                  			}

                  			writeIntoCodeFile(
                  				string("\t; pushing parameter into stack\n") 
                  			);
                  	 
      }
      setState(466);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105046Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 15: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105046Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105046Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105046parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105046parserParserOnceFlag, c2105046parserParserInitialize);
#endif
}
