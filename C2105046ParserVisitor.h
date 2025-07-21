
// Generated from C2105046Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105046Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by C2105046Parser.
 */
class  C2105046ParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by C2105046Parser.
   */
    virtual std::any visitStart(C2105046Parser::StartContext *context) = 0;

    virtual std::any visitProgram(C2105046Parser::ProgramContext *context) = 0;

    virtual std::any visitUnit(C2105046Parser::UnitContext *context) = 0;

    virtual std::any visitFunc_declaration(C2105046Parser::Func_declarationContext *context) = 0;

    virtual std::any visitFunc_definition(C2105046Parser::Func_definitionContext *context) = 0;

    virtual std::any visitParameter_list(C2105046Parser::Parameter_listContext *context) = 0;

    virtual std::any visitCompound_statement(C2105046Parser::Compound_statementContext *context) = 0;

    virtual std::any visitVar_declaration(C2105046Parser::Var_declarationContext *context) = 0;

    virtual std::any visitDeclaration_list_err(C2105046Parser::Declaration_list_errContext *context) = 0;

    virtual std::any visitType_specifier(C2105046Parser::Type_specifierContext *context) = 0;

    virtual std::any visitDeclaration_list(C2105046Parser::Declaration_listContext *context) = 0;

    virtual std::any visitStatements(C2105046Parser::StatementsContext *context) = 0;

    virtual std::any visitStatement(C2105046Parser::StatementContext *context) = 0;

    virtual std::any visitExpression_statement(C2105046Parser::Expression_statementContext *context) = 0;

    virtual std::any visitVariable(C2105046Parser::VariableContext *context) = 0;

    virtual std::any visitExpression(C2105046Parser::ExpressionContext *context) = 0;

    virtual std::any visitLogic_expression(C2105046Parser::Logic_expressionContext *context) = 0;

    virtual std::any visitRel_expression(C2105046Parser::Rel_expressionContext *context) = 0;

    virtual std::any visitSimple_expression(C2105046Parser::Simple_expressionContext *context) = 0;

    virtual std::any visitTerm(C2105046Parser::TermContext *context) = 0;

    virtual std::any visitUnary_expression(C2105046Parser::Unary_expressionContext *context) = 0;

    virtual std::any visitFactor(C2105046Parser::FactorContext *context) = 0;

    virtual std::any visitArgument_list(C2105046Parser::Argument_listContext *context) = 0;

    virtual std::any visitArguments(C2105046Parser::ArgumentsContext *context) = 0;


};

