// Generated from /Users/raihanrashid/Desktop/BUET CSE course all stuff/3-1/Sessionals/CSE310 Compiler Sessional/ICG/C2105046Parser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link C2105046Parser}.
 */
public interface C2105046ParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(C2105046Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(C2105046Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(C2105046Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(C2105046Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnit(C2105046Parser.UnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnit(C2105046Parser.UnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunc_declaration(C2105046Parser.Func_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunc_declaration(C2105046Parser.Func_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunc_definition(C2105046Parser.Func_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunc_definition(C2105046Parser.Func_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(C2105046Parser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(C2105046Parser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompound_statement(C2105046Parser.Compound_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompound_statement(C2105046Parser.Compound_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(C2105046Parser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(C2105046Parser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list_err(C2105046Parser.Declaration_list_errContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list_err(C2105046Parser.Declaration_list_errContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterType_specifier(C2105046Parser.Type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitType_specifier(C2105046Parser.Type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list(C2105046Parser.Declaration_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list(C2105046Parser.Declaration_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(C2105046Parser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(C2105046Parser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(C2105046Parser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(C2105046Parser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpression_statement(C2105046Parser.Expression_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpression_statement(C2105046Parser.Expression_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(C2105046Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(C2105046Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(C2105046Parser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(C2105046Parser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogic_expression(C2105046Parser.Logic_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogic_expression(C2105046Parser.Logic_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRel_expression(C2105046Parser.Rel_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRel_expression(C2105046Parser.Rel_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expression(C2105046Parser.Simple_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expression(C2105046Parser.Simple_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(C2105046Parser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(C2105046Parser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(C2105046Parser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(C2105046Parser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(C2105046Parser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(C2105046Parser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgument_list(C2105046Parser.Argument_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgument_list(C2105046Parser.Argument_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105046Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(C2105046Parser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105046Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(C2105046Parser.ArgumentsContext ctx);
}