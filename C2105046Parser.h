
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

#pragma once


#include "antlr4-runtime.h"




class  C2105046Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, PRINTF = 10, RETURN = 11, INT = 12, 
    FLOAT = 13, VOID = 14, LPAREN = 15, RPAREN = 16, LCURL = 17, RCURL = 18, 
    LTHIRD = 19, RTHIRD = 20, SEMICOLON = 21, COMMA = 22, ADDOP = 23, SUBOP = 24, 
    MULOP = 25, INCOP = 26, DECOP = 27, NOT = 28, RELOP = 29, LOGICOP = 30, 
    ASSIGNOP = 31, ID = 32, CONST_INT = 33, CONST_FLOAT = 34, INVALID_CHAR = 35
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleDeclaration_list_err = 8, RuleType_specifier = 9, 
    RuleDeclaration_list = 10, RuleStatements = 11, RuleStatement = 12, 
    RuleExpression_statement = 13, RuleVariable = 14, RuleExpression = 15, 
    RuleLogic_expression = 16, RuleRel_expression = 17, RuleSimple_expression = 18, 
    RuleTerm = 19, RuleUnary_expression = 20, RuleFactor = 21, RuleArgument_list = 22, 
    RuleArguments = 23
  };

  explicit C2105046Parser(antlr4::TokenStream *input);

  C2105046Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105046Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      void writeIntoparserLogFile(const string message) {
          if (!parserLogFile) {
              cout << "Error opening parserLogFile.txt" << endl;
              return;
          }

          parserLogFile << message << endl;
          parserLogFile.flush();
      }



      void writeIntoErrorFile(const string message) {
          if (!errorFile) {
              cout << "Error opening errorFile.txt" << endl;
              return;
          }
          errorFile << message << endl;
          errorFile.flush();
      }

  	void writeIntoCodeFile(const string message){ 
  		if(!codeFile) {
  			cout << "Error opening Code file" << endl;
  		}
  		codeFile << message << endl;
  		codeFile.flush();
  	}

  	void writeIntoTmpFile(const string message){ 
  		if(!tmpFile) {
  			cout << "Error opening Tmp file" << endl;
  		}
  		tmpFile << message << endl;
  		tmpFile.flush();
  	}

  	string getLabel(){
  		static int label = 0;
  		label++;
  		return string("L") + to_string(label);
  	}


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C2105046Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    C2105046Parser::ProgramContext *p = nullptr;
    C2105046Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    C2105046Parser::Var_declarationContext *vd = nullptr;
    C2105046Parser::Func_declarationContext *f_dl = nullptr;
    C2105046Parser::Func_definitionContext *f_def = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    C2105046Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *id = nullptr;
    C2105046Parser::Parameter_listContext *pl = nullptr;
    antlr4::Token *sm = nullptr;
    antlr4::Token *l_p = nullptr;
    antlr4::Token *r_p = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    C2105046Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *lpr = nullptr;
    C2105046Parser::Parameter_listContext *pl = nullptr;
    antlr4::Token *rpr = nullptr;
    C2105046Parser::Compound_statementContext *csm = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    vector<string> args;
    vector<string> vars;
    C2105046Parser::Parameter_listContext *pl = nullptr;
    C2105046Parser::Type_specifierContext *ts = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *cm = nullptr;
    antlr4::Token *add_op = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string return_type;
    antlr4::Token *lcl = nullptr;
    C2105046Parser::StatementsContext *stms = nullptr;
    antlr4::Token *rcl = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    C2105046Parser::Type_specifierContext *ts = nullptr;
    C2105046Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C2105046Parser::Type_specifierContext *t = nullptr;
    C2105046Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    antlr4::Token *i = nullptr;
    antlr4::Token *f = nullptr;
    antlr4::Token *v = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    vector<string> ids;
    vector<string> id_size;
    C2105046Parser::Declaration_listContext *d = nullptr;
    C2105046Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *i = nullptr;
    antlr4::Token *l_t = nullptr;
    antlr4::Token *c_i = nullptr;
    antlr4::Token *r_t = nullptr;
    antlr4::Token *c = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *third_brac = nullptr;
    antlr4::Token *c_int = nullptr;
    antlr4::Token *r_third = nullptr;
    antlr4::Token *add_op = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string return_type;
    C2105046Parser::StatementsContext *stms = nullptr;
    C2105046Parser::StatementContext *stm = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string return_type;
    C2105046Parser::Var_declarationContext *vd = nullptr;
    C2105046Parser::Expression_statementContext *expr_stm = nullptr;
    C2105046Parser::Compound_statementContext *csm = nullptr;
    antlr4::Token *fr = nullptr;
    antlr4::Token *lpr = nullptr;
    C2105046Parser::Expression_statementContext *expr_st1 = nullptr;
    C2105046Parser::Expression_statementContext *expr_st2 = nullptr;
    C2105046Parser::ExpressionContext *expr = nullptr;
    antlr4::Token *rpr = nullptr;
    C2105046Parser::StatementContext *stm = nullptr;
    antlr4::Token *if_ = nullptr;
    C2105046Parser::StatementContext *stm1 = nullptr;
    antlr4::Token *else_ = nullptr;
    C2105046Parser::StatementContext *stm2 = nullptr;
    antlr4::Token *while_ = nullptr;
    antlr4::Token *pln = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *sm = nullptr;
    antlr4::Token *ret = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    antlr4::Token *sm = nullptr;
    C2105046Parser::ExpressionContext *expr = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo * symbol;
    string arr_ind;
    antlr4::Token *id = nullptr;
    antlr4::Token *lthr = nullptr;
    C2105046Parser::ExpressionContext *expr = nullptr;
    antlr4::Token *rthr = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    C2105046Parser::Logic_expressionContext *le = nullptr;
    C2105046Parser::VariableContext *v = nullptr;
    antlr4::Token *assop = nullptr;
    antlr4::Token *ic = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    std::vector<antlr4::tree::TerminalNode *> ASSIGNOP();
    antlr4::tree::TerminalNode* ASSIGNOP(size_t i);
    std::vector<Logic_expressionContext *> logic_expression();
    Logic_expressionContext* logic_expression(size_t i);
    antlr4::tree::TerminalNode *ADDOP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INVALID_CHAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo* symbol;
    C2105046Parser::Rel_expressionContext *re = nullptr;
    C2105046Parser::Rel_expressionContext *re1 = nullptr;
    antlr4::Token *lop = nullptr;
    C2105046Parser::Rel_expressionContext *re2 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo* symbol;
    C2105046Parser::Simple_expressionContext *se = nullptr;
    C2105046Parser::Simple_expressionContext *se1 = nullptr;
    antlr4::Token *relop = nullptr;
    C2105046Parser::Simple_expressionContext *se2 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo* symbol;
    C2105046Parser::Simple_expressionContext *se = nullptr;
    C2105046Parser::TermContext *t = nullptr;
    antlr4::Token *ao = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo* symbol;
    C2105046Parser::TermContext *t = nullptr;
    C2105046Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *mul = nullptr;
    C2105046Parser::Unary_expressionContext *una = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    TermContext *term();
    antlr4::tree::TerminalNode *MULOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo* symbol;
    antlr4::Token *addop = nullptr;
    C2105046Parser::Unary_expressionContext *una = nullptr;
    antlr4::Token *not_ = nullptr;
    C2105046Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    string dataType;
    bool isArray;
    SymbolInfo * symbol;
    C2105046Parser::VariableContext *v = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *lpr = nullptr;
    C2105046Parser::Argument_listContext *arg_l = nullptr;
    antlr4::Token *rpr = nullptr;
    C2105046Parser::ExpressionContext *expr = nullptr;
    antlr4::Token *ci = nullptr;
    antlr4::Token *cf = nullptr;
    C2105046Parser::VariableContext *var = nullptr;
    antlr4::Token *incop = nullptr;
    antlr4::Token *decop = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    vector<string> argTypes;
    vector<string> argNames;
    C2105046Parser::ArgumentsContext *args = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    string print_text;
    vector<string> argTypes;
    vector<string> argNames;
    C2105046Parser::ArgumentsContext *args = nullptr;
    C2105046Parser::Logic_expressionContext *lexpr = nullptr;
    antlr4::Token *cm = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

