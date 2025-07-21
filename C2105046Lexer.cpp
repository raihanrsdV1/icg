
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;


// Generated from C2105046Lexer.g4 by ANTLR 4.13.2


#include "C2105046Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105046LexerStaticData final {
  C2105046LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105046LexerStaticData(const C2105046LexerStaticData&) = delete;
  C2105046LexerStaticData(C2105046LexerStaticData&&) = delete;
  C2105046LexerStaticData& operator=(const C2105046LexerStaticData&) = delete;
  C2105046LexerStaticData& operator=(C2105046LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105046lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105046LexerStaticData> c2105046lexerLexerStaticData = nullptr;

void c2105046lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105046lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105046lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105046LexerStaticData>(
    std::vector<std::string>{
      "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
      "WHILE", "PRINTLN", "PRINTF", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "INVALID_CHAR"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,35,327,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,
  	1,0,1,0,1,0,5,0,76,8,0,10,0,12,0,79,9,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,5,1,90,8,1,10,1,12,1,93,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,
  	1,2,1,2,5,2,106,8,2,10,2,12,2,109,9,2,1,2,1,2,1,2,1,2,1,2,1,3,4,3,117,
  	8,3,11,3,12,3,118,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,
  	1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,22,
  	1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,
  	1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,3,28,255,8,28,1,29,1,29,1,29,1,29,1,29,1,29,3,29,263,8,29,1,
  	30,1,30,1,30,1,31,1,31,5,31,270,8,31,10,31,12,31,273,9,31,1,31,1,31,1,
  	32,4,32,278,8,32,11,32,12,32,279,1,32,1,32,1,33,4,33,285,8,33,11,33,12,
  	33,286,1,33,1,33,5,33,291,8,33,10,33,12,33,294,9,33,3,33,296,8,33,1,33,
  	1,33,3,33,300,8,33,1,33,4,33,303,8,33,11,33,12,33,304,3,33,307,8,33,1,
  	33,1,33,1,33,4,33,312,8,33,11,33,12,33,313,1,33,1,33,4,33,318,8,33,11,
  	33,12,33,319,1,33,1,33,3,33,324,8,33,1,34,1,34,1,91,0,35,1,1,3,2,5,3,
  	7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,
  	33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,
  	28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,1,0,10,2,0,10,10,13,13,4,
  	0,10,10,13,13,34,34,92,92,3,0,9,10,12,13,32,32,2,0,43,43,45,45,3,0,37,
  	37,42,42,47,47,2,0,60,60,62,62,3,0,65,90,95,95,97,122,4,0,48,57,65,90,
  	95,95,97,122,1,0,48,57,2,0,69,69,101,101,349,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,
  	0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,
  	0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,
  	37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,
  	0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,
  	0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,
  	69,1,0,0,0,1,71,1,0,0,0,3,84,1,0,0,0,5,101,1,0,0,0,7,116,1,0,0,0,9,122,
  	1,0,0,0,11,127,1,0,0,0,13,134,1,0,0,0,15,140,1,0,0,0,17,148,1,0,0,0,19,
  	158,1,0,0,0,21,167,1,0,0,0,23,176,1,0,0,0,25,182,1,0,0,0,27,190,1,0,0,
  	0,29,197,1,0,0,0,31,200,1,0,0,0,33,203,1,0,0,0,35,206,1,0,0,0,37,209,
  	1,0,0,0,39,212,1,0,0,0,41,215,1,0,0,0,43,218,1,0,0,0,45,221,1,0,0,0,47,
  	224,1,0,0,0,49,227,1,0,0,0,51,230,1,0,0,0,53,235,1,0,0,0,55,240,1,0,0,
  	0,57,254,1,0,0,0,59,262,1,0,0,0,61,264,1,0,0,0,63,267,1,0,0,0,65,277,
  	1,0,0,0,67,323,1,0,0,0,69,325,1,0,0,0,71,72,5,47,0,0,72,73,5,47,0,0,73,
  	77,1,0,0,0,74,76,8,0,0,0,75,74,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,
  	78,1,0,0,0,78,80,1,0,0,0,79,77,1,0,0,0,80,81,6,0,0,0,81,82,1,0,0,0,82,
  	83,6,0,1,0,83,2,1,0,0,0,84,85,5,47,0,0,85,86,5,42,0,0,86,91,1,0,0,0,87,
  	90,9,0,0,0,88,90,7,0,0,0,89,87,1,0,0,0,89,88,1,0,0,0,90,93,1,0,0,0,91,
  	92,1,0,0,0,91,89,1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,95,5,42,0,0,95,
  	96,5,47,0,0,96,97,1,0,0,0,97,98,6,1,2,0,98,99,1,0,0,0,99,100,6,1,1,0,
  	100,4,1,0,0,0,101,107,5,34,0,0,102,103,5,92,0,0,103,106,9,0,0,0,104,106,
  	8,1,0,0,105,102,1,0,0,0,105,104,1,0,0,0,106,109,1,0,0,0,107,105,1,0,0,
  	0,107,108,1,0,0,0,108,110,1,0,0,0,109,107,1,0,0,0,110,111,5,34,0,0,111,
  	112,6,2,3,0,112,113,1,0,0,0,113,114,6,2,1,0,114,6,1,0,0,0,115,117,7,2,
  	0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,
  	120,1,0,0,0,120,121,6,3,1,0,121,8,1,0,0,0,122,123,5,105,0,0,123,124,5,
  	102,0,0,124,125,1,0,0,0,125,126,6,4,4,0,126,10,1,0,0,0,127,128,5,101,
  	0,0,128,129,5,108,0,0,129,130,5,115,0,0,130,131,5,101,0,0,131,132,1,0,
  	0,0,132,133,6,5,5,0,133,12,1,0,0,0,134,135,5,102,0,0,135,136,5,111,0,
  	0,136,137,5,114,0,0,137,138,1,0,0,0,138,139,6,6,6,0,139,14,1,0,0,0,140,
  	141,5,119,0,0,141,142,5,104,0,0,142,143,5,105,0,0,143,144,5,108,0,0,144,
  	145,5,101,0,0,145,146,1,0,0,0,146,147,6,7,7,0,147,16,1,0,0,0,148,149,
  	5,112,0,0,149,150,5,114,0,0,150,151,5,105,0,0,151,152,5,110,0,0,152,153,
  	5,116,0,0,153,154,5,108,0,0,154,155,5,110,0,0,155,156,1,0,0,0,156,157,
  	6,8,8,0,157,18,1,0,0,0,158,159,5,112,0,0,159,160,5,114,0,0,160,161,5,
  	105,0,0,161,162,5,110,0,0,162,163,5,116,0,0,163,164,5,102,0,0,164,165,
  	1,0,0,0,165,166,6,9,9,0,166,20,1,0,0,0,167,168,5,114,0,0,168,169,5,101,
  	0,0,169,170,5,116,0,0,170,171,5,117,0,0,171,172,5,114,0,0,172,173,5,110,
  	0,0,173,174,1,0,0,0,174,175,6,10,10,0,175,22,1,0,0,0,176,177,5,105,0,
  	0,177,178,5,110,0,0,178,179,5,116,0,0,179,180,1,0,0,0,180,181,6,11,11,
  	0,181,24,1,0,0,0,182,183,5,102,0,0,183,184,5,108,0,0,184,185,5,111,0,
  	0,185,186,5,97,0,0,186,187,5,116,0,0,187,188,1,0,0,0,188,189,6,12,12,
  	0,189,26,1,0,0,0,190,191,5,118,0,0,191,192,5,111,0,0,192,193,5,105,0,
  	0,193,194,5,100,0,0,194,195,1,0,0,0,195,196,6,13,13,0,196,28,1,0,0,0,
  	197,198,5,40,0,0,198,199,6,14,14,0,199,30,1,0,0,0,200,201,5,41,0,0,201,
  	202,6,15,15,0,202,32,1,0,0,0,203,204,5,123,0,0,204,205,6,16,16,0,205,
  	34,1,0,0,0,206,207,5,125,0,0,207,208,6,17,17,0,208,36,1,0,0,0,209,210,
  	5,91,0,0,210,211,6,18,18,0,211,38,1,0,0,0,212,213,5,93,0,0,213,214,6,
  	19,19,0,214,40,1,0,0,0,215,216,5,59,0,0,216,217,6,20,20,0,217,42,1,0,
  	0,0,218,219,5,44,0,0,219,220,6,21,21,0,220,44,1,0,0,0,221,222,7,3,0,0,
  	222,223,6,22,22,0,223,46,1,0,0,0,224,225,7,3,0,0,225,226,6,23,23,0,226,
  	48,1,0,0,0,227,228,7,4,0,0,228,229,6,24,24,0,229,50,1,0,0,0,230,231,5,
  	43,0,0,231,232,5,43,0,0,232,233,1,0,0,0,233,234,6,25,25,0,234,52,1,0,
  	0,0,235,236,5,45,0,0,236,237,5,45,0,0,237,238,1,0,0,0,238,239,6,26,26,
  	0,239,54,1,0,0,0,240,241,5,33,0,0,241,242,6,27,27,0,242,56,1,0,0,0,243,
  	244,5,60,0,0,244,255,5,61,0,0,245,246,5,61,0,0,246,255,5,61,0,0,247,248,
  	5,62,0,0,248,255,5,61,0,0,249,255,7,5,0,0,250,251,5,33,0,0,251,252,5,
  	61,0,0,252,253,1,0,0,0,253,255,6,28,28,0,254,243,1,0,0,0,254,245,1,0,
  	0,0,254,247,1,0,0,0,254,249,1,0,0,0,254,250,1,0,0,0,255,58,1,0,0,0,256,
  	257,5,38,0,0,257,263,5,38,0,0,258,259,5,124,0,0,259,260,5,124,0,0,260,
  	261,1,0,0,0,261,263,6,29,29,0,262,256,1,0,0,0,262,258,1,0,0,0,263,60,
  	1,0,0,0,264,265,5,61,0,0,265,266,6,30,30,0,266,62,1,0,0,0,267,271,7,6,
  	0,0,268,270,7,7,0,0,269,268,1,0,0,0,270,273,1,0,0,0,271,269,1,0,0,0,271,
  	272,1,0,0,0,272,274,1,0,0,0,273,271,1,0,0,0,274,275,6,31,31,0,275,64,
  	1,0,0,0,276,278,7,8,0,0,277,276,1,0,0,0,278,279,1,0,0,0,279,277,1,0,0,
  	0,279,280,1,0,0,0,280,281,1,0,0,0,281,282,6,32,32,0,282,66,1,0,0,0,283,
  	285,7,8,0,0,284,283,1,0,0,0,285,286,1,0,0,0,286,284,1,0,0,0,286,287,1,
  	0,0,0,287,295,1,0,0,0,288,292,5,46,0,0,289,291,7,8,0,0,290,289,1,0,0,
  	0,291,294,1,0,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,296,1,0,0,0,294,
  	292,1,0,0,0,295,288,1,0,0,0,295,296,1,0,0,0,296,306,1,0,0,0,297,299,7,
  	9,0,0,298,300,7,3,0,0,299,298,1,0,0,0,299,300,1,0,0,0,300,302,1,0,0,0,
  	301,303,7,8,0,0,302,301,1,0,0,0,303,304,1,0,0,0,304,302,1,0,0,0,304,305,
  	1,0,0,0,305,307,1,0,0,0,306,297,1,0,0,0,306,307,1,0,0,0,307,308,1,0,0,
  	0,308,324,6,33,33,0,309,311,5,46,0,0,310,312,7,8,0,0,311,310,1,0,0,0,
  	312,313,1,0,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,315,1,0,0,0,315,324,
  	6,33,34,0,316,318,7,8,0,0,317,316,1,0,0,0,318,319,1,0,0,0,319,317,1,0,
  	0,0,319,320,1,0,0,0,320,321,1,0,0,0,321,322,5,46,0,0,322,324,6,33,35,
  	0,323,284,1,0,0,0,323,309,1,0,0,0,323,317,1,0,0,0,324,68,1,0,0,0,325,
  	326,9,0,0,0,326,70,1,0,0,0,20,0,77,89,91,105,107,118,254,262,271,279,
  	286,292,295,299,304,306,313,319,323,36,1,0,0,6,0,0,1,1,1,1,2,2,1,4,3,
  	1,5,4,1,6,5,1,7,6,1,8,7,1,9,8,1,10,9,1,11,10,1,12,11,1,13,12,1,14,13,
  	1,15,14,1,16,15,1,17,16,1,18,17,1,19,18,1,20,19,1,21,20,1,22,21,1,23,
  	22,1,24,23,1,25,24,1,26,25,1,27,26,1,28,27,1,29,28,1,30,29,1,31,30,1,
  	32,31,1,33,32,1,33,33,1,33,34
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105046lexerLexerStaticData = std::move(staticData);
}

}

C2105046Lexer::C2105046Lexer(CharStream *input) : Lexer(input) {
  C2105046Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105046lexerLexerStaticData->atn, c2105046lexerLexerStaticData->decisionToDFA, c2105046lexerLexerStaticData->sharedContextCache);
}

C2105046Lexer::~C2105046Lexer() {
  delete _interpreter;
}

std::string C2105046Lexer::getGrammarFileName() const {
  return "C2105046Lexer.g4";
}

const std::vector<std::string>& C2105046Lexer::getRuleNames() const {
  return c2105046lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105046Lexer::getChannelNames() const {
  return c2105046lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105046Lexer::getModeNames() const {
  return c2105046lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105046Lexer::getVocabulary() const {
  return c2105046lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105046Lexer::getSerializedATN() const {
  return c2105046lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105046Lexer::getATN() const {
  return *c2105046lexerLexerStaticData->atn;
}


void C2105046Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: PRINTLNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: PRINTFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: VOIDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: LCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: RCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: LTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: RTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: SEMICOLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: COMMAAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: ADDOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: SUBOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: MULOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: INCOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: DECOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: NOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: RELOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: LOGICOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: ASSIGNOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: IDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: CONST_INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: CONST_FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C2105046Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <SINGLE LINE COMMENT> Lexeme "
              + getText()
            );
         break;

  default:
    break;
  }
}

void C2105046Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
          // extra braces create a new scope for your variables
          {
            std::string txt = getText();
            std::string content = txt.substr(2, txt.size() - 4);
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <MULTI LINE COMMENT> Lexeme /*"
              + content + "*/"
            );
          }
         break;

  default:
    break;
  }
}

void C2105046Lexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <STRING> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}

void C2105046Lexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::PRINTFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::VOIDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::LCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::RCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::COMMAAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::ADDOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::SUBOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SUBOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::MULOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::INCOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::DECOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::NOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::RELOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::IDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105046Lexer::CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 33: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 34: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}



void C2105046Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105046lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105046lexerLexerOnceFlag, c2105046lexerLexerInitialize);
#endif
}
