
// Generated from C2105046Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105046ParserVisitor.h"


/**
 * This class provides an empty implementation of C2105046ParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  C2105046ParserBaseVisitor : public C2105046ParserVisitor {
public:

  virtual std::any visitStart(C2105046Parser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(C2105046Parser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit(C2105046Parser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration(C2105046Parser::Func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_definition(C2105046Parser::Func_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(C2105046Parser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement(C2105046Parser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(C2105046Parser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list_err(C2105046Parser::Declaration_list_errContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_specifier(C2105046Parser::Type_specifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list(C2105046Parser::Declaration_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(C2105046Parser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(C2105046Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement(C2105046Parser::Expression_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(C2105046Parser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(C2105046Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_expression(C2105046Parser::Logic_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression(C2105046Parser::Rel_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression(C2105046Parser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(C2105046Parser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(C2105046Parser::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(C2105046Parser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument_list(C2105046Parser::Argument_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(C2105046Parser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

