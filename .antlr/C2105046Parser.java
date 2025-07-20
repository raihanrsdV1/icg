// Generated from /Users/raihanrashid/Desktop/BUET CSE course all stuff/3-1/Sessionals/CSE310 Compiler Sessional/ICG/C2105046Parser.g4 by ANTLR 4.13.1

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


import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C2105046Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, PRINTF=10, RETURN=11, INT=12, FLOAT=13, VOID=14, LPAREN=15, 
		RPAREN=16, LCURL=17, RCURL=18, LTHIRD=19, RTHIRD=20, SEMICOLON=21, COMMA=22, 
		ADDOP=23, SUBOP=24, MULOP=25, INCOP=26, DECOP=27, NOT=28, RELOP=29, LOGICOP=30, 
		ASSIGNOP=31, ID=32, CONST_INT=33, CONST_FLOAT=34, INVALID_CHAR=35;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_declaration_list_err = 8, RULE_type_specifier = 9, 
		RULE_declaration_list = 10, RULE_statements = 11, RULE_statement = 12, 
		RULE_expression_statement = 13, RULE_variable = 14, RULE_expression = 15, 
		RULE_logic_expression = 16, RULE_rel_expression = 17, RULE_simple_expression = 18, 
		RULE_term = 19, RULE_unary_expression = 20, RULE_factor = 21, RULE_argument_list = 22, 
		RULE_arguments = 23;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "declaration_list_err", "type_specifier", 
			"declaration_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'println'", 
			"'printf'", "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", 
			"'}'", "'['", "']'", "';'", "','", null, null, null, "'++'", "'--'", 
			"'!'", null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "PRINTF", "RETURN", "INT", "FLOAT", "VOID", 
			"LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", 
			"COMMA", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", 
			"LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "INVALID_CHAR"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C2105046Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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

	public C2105046Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext p;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{

					writeIntoCodeFile(
						string("; c to assembly conversion by Raihan RSD\n.MODEL SMALL\n.STACK 100H\n.CODE\n")
					);
					writeIntoTmpFile(
						string(".DATA\n\tCR EQU 0dh\n\tLF EQU 0ah \n\tnumber DB \"00000$\"")
					);
				
			setState(49);
			((StartContext)_localctx).p = program(0);

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
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public string print_text;
		public ProgramContext p;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(53);
			((ProgramContext)_localctx).u = unit();

					writeIntoparserLogFile(
			  			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : unit\n")
			  		);
					  writeIntoparserLogFile(
				 		string(((ProgramContext)_localctx).u.print_text) + string("\n")
					);

					((ProgramContext)_localctx).print_text =  ((ProgramContext)_localctx).u.print_text;
					
				
			}
			_ctx.stop = _input.LT(-1);
			setState(62);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.p = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(56);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(57);
					((ProgramContext)_localctx).u = unit();

					          		writeIntoparserLogFile(
					          			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : program unit\n")
					          		);
					          		writeIntoparserLogFile(
					          			string(((ProgramContext)_localctx).p.print_text) + string("\n") + string(((ProgramContext)_localctx).u.print_text) + string("\n")
					          		);

					          		((ProgramContext)_localctx).print_text =  ((ProgramContext)_localctx).p.print_text + "\n" + ((ProgramContext)_localctx).u.print_text;
					          	
					}
					} 
				}
				setState(64);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public string print_text;
		public Var_declarationContext vd;
		public Func_declarationContext f_dl;
		public Func_definitionContext f_def;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(74);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				((UnitContext)_localctx).vd = var_declaration();

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : var_declaration\n")
				  	  	);	
						writeIntoparserLogFile(
							string(((UnitContext)_localctx).vd.print_text) + string("\n")
						);
						((UnitContext)_localctx).print_text =  ((UnitContext)_localctx).vd.print_text;
					
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(68);
				((UnitContext)_localctx).f_dl = func_declaration();

						  writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_declaration\n")
						  );

						  writeIntoparserLogFile(
							string(((UnitContext)_localctx).f_dl.print_text) + string("\n")
						  );

						((UnitContext)_localctx).print_text =  ((UnitContext)_localctx).f_dl.print_text;
					 
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(71);
				((UnitContext)_localctx).f_def = func_definition();

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_definition\n")
							);
							((UnitContext)_localctx).print_text =  ((UnitContext)_localctx).f_def.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
					 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public string print_text;
		public Type_specifierContext ts;
		public Token id;
		public Parameter_listContext pl;
		public Token sm;
		public Token l_p;
		public Token r_p;
		public TerminalNode LPAREN() { return getToken(C2105046Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105046Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105046Parser.SEMICOLON, 0); }
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(92);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				((Func_declarationContext)_localctx).ts = type_specifier();
				setState(77);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(78);
				match(LPAREN);

							inDeclaration = true;
						
				setState(80);
				((Func_declarationContext)_localctx).pl = parameter_list(0);
				setState(81);
				match(RPAREN);
				setState(82);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

							inDeclaration = false;
							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n")
							);

							writeIntoparserLogFile(
								string((((Func_declarationContext)_localctx).ts!=null?_input.getText(((Func_declarationContext)_localctx).ts.start,((Func_declarationContext)_localctx).ts.stop):null)) + string(" ") + string(((Func_declarationContext)_localctx).id->getText()) + string("(") + string(((Func_declarationContext)_localctx).pl.print_text) + string(");\n")
							);

							((Func_declarationContext)_localctx).print_text =  string((((Func_declarationContext)_localctx).ts!=null?_input.getText(((Func_declarationContext)_localctx).ts.start,((Func_declarationContext)_localctx).ts.stop):null)) + string(" ") + string(((Func_declarationContext)_localctx).id->getText()) + string("(") + string(((Func_declarationContext)_localctx).pl.print_text) + string(");");
							string name = string(((Func_declarationContext)_localctx).id->getText());

							if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_declarationContext)_localctx).id->getText())+ string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_declarationContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							} 
							SymbolInfo* symbol = symbolTable.lookUp(name);
							symbol->setIsDeclaredOnly(true);
							
							//SymbolInfo* symbol = symbolTable.lookUp(name);
							symbol->setParameters(((Func_declarationContext)_localctx).pl.args, ((Func_declarationContext)_localctx).ts.print_text);
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				((Func_declarationContext)_localctx).ts = type_specifier();
				setState(86);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(87);
				((Func_declarationContext)_localctx).l_p = match(LPAREN);
				setState(88);
				((Func_declarationContext)_localctx).r_p = match(RPAREN);
				setState(89);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n")
							);

							writeIntoparserLogFile(
								string((((Func_declarationContext)_localctx).ts!=null?_input.getText(((Func_declarationContext)_localctx).ts.start,((Func_declarationContext)_localctx).ts.stop):null)) + string(" ") + string(((Func_declarationContext)_localctx).id->getText()) + string("();\n")
							);

							((Func_declarationContext)_localctx).print_text =  ((Func_declarationContext)_localctx).ts.print_text + " " + ((Func_declarationContext)_localctx).id->getText() + "()" + ((Func_declarationContext)_localctx).sm->getText();
							string name = string(((Func_declarationContext)_localctx).id->getText());
							if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_declarationContext)_localctx).id->getText()) + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_declarationContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							} 
							SymbolInfo* symbol = symbolTable.lookUp(name);
							symbol->setIsDeclaredOnly(true);
							symbol->setParameters(vector<string>(), ((Func_declarationContext)_localctx).ts.print_text);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public string print_text;
		public Type_specifierContext ts;
		public Token id;
		public Token lpr;
		public Parameter_listContext pl;
		public Token rpr;
		public Compound_statementContext csm;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105046Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105046Parser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(112);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(94);
				((Func_definitionContext)_localctx).ts = type_specifier();
				setState(95);
				((Func_definitionContext)_localctx).id = match(ID);

						string name = string(((Func_definitionContext)_localctx).id->getText());
						bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
						bool wasDeclared = false;
						SymbolInfo* symbol = symbolTable.lookUp(name);
						wasDeclared = symbol->getIsDeclaredOnly();
						if(!canInsert && !wasDeclared){
							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
							);
							syntaxErrorCount++;
						}
						else {
							// SymbolInfo* symbol = symbolTable.lookUp(name);
							if(wasDeclared){
								if(symbol->getReturnType() != ((Func_definitionContext)_localctx).ts.print_text){
									writeIntoErrorFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
									);
									writeIntoparserLogFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
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
						if(((Func_definitionContext)_localctx).id->getText() == "main"){
							writeIntoCodeFile(
							string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
							);
						} else {
							writeIntoCodeFile(
							((Func_definitionContext)_localctx).id->getText() + 
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
				((Func_definitionContext)_localctx).lpr = match(LPAREN);
				setState(98);
				((Func_definitionContext)_localctx).pl = parameter_list(0);

						writeIntoCodeFile(
							string("; sotring parameter information in scope table")
						);
						scopeOffset.back() = -2;
						for(int i = ((Func_definitionContext)_localctx).pl.vars.size() - 1; i >= 0; i--){ 
							scopeOffset.back() -= 2;
							SymbolInfo* symbol = symbolTable.lookUp(((Func_definitionContext)_localctx).pl.vars[i]);
							symbol->setAsmData(scopeOffset.back(), false);
						}

						scopeOffset.back() = 0;

					 
				setState(100);
				((Func_definitionContext)_localctx).rpr = match(RPAREN);
				setState(101);
				((Func_definitionContext)_localctx).csm = compound_statement();

						
						
				        int param_count = ((Func_definitionContext)_localctx).pl.vars.size();
						if(wasDeclared){
							if(symbol->getParameters().size() != ((Func_definitionContext)_localctx).pl.args.size()){
								writeIntoErrorFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							}

						}
						if(((Func_definitionContext)_localctx).csm.return_type != ((Func_definitionContext)_localctx).ts.print_text){
							if(((Func_definitionContext)_localctx).ts.print_text == "void" && !((((Func_definitionContext)_localctx).csm.return_type == "") || (((Func_definitionContext)_localctx).csm.return_type == "void"))){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string(((Func_definitionContext)_localctx).id->getText()) + string(" with void return type \n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string(((Func_definitionContext)_localctx).id->getText())+ string(" with void return type \n")
								);
								syntaxErrorCount++;
							}
							else if(!(((Func_definitionContext)_localctx).ts.print_text == "void" && ((Func_definitionContext)_localctx).csm.return_type == "")){
								writeIntoErrorFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Return type mismatch in function ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Return type mismatch in function ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							}
						}

						writeIntoparserLogFile(
				            string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n")
				        );
				        ((Func_definitionContext)_localctx).print_text =  ((Func_definitionContext)_localctx).ts.print_text + string(" ") + ((Func_definitionContext)_localctx).id->getText() + ((Func_definitionContext)_localctx).lpr->getText() + ((Func_definitionContext)_localctx).pl.print_text + ((Func_definitionContext)_localctx).rpr->getText() + ((Func_definitionContext)_localctx).csm.print_text;
				        writeIntoparserLogFile(
				            _localctx.print_text + string("\n")
				        );
						symbol->setParameters(((Func_definitionContext)_localctx).pl.args, ((Func_definitionContext)_localctx).ts.print_text);

						// Assembly Code 
						if(((Func_definitionContext)_localctx).id->getText() == "main"){ 
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
							((Func_definitionContext)_localctx).id->getText() + string(" ENDP")
						);
						// scopeOffset.pop_back();
						
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(104);
				((Func_definitionContext)_localctx).ts = type_specifier();
				setState(105);
				((Func_definitionContext)_localctx).id = match(ID);

						string name = string(((Func_definitionContext)_localctx).id->getText());
						bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
						bool wasDeclared = false;
						SymbolInfo* symbol = symbolTable.lookUp(name);
						wasDeclared = symbol->getIsDeclaredOnly();
						if(!canInsert && !wasDeclared){
							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
							);
							syntaxErrorCount++;
						}
						else {
							// SymbolInfo* symbol = symbolTable.lookUp(name);
							if(wasDeclared){
								if(symbol->getReturnType() != ((Func_definitionContext)_localctx).ts.print_text){
									writeIntoErrorFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
									);
									writeIntoparserLogFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
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
						if(((Func_definitionContext)_localctx).id->getText() == "main"){
							writeIntoCodeFile(
							string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
							);
						} else {
							writeIntoCodeFile(
							((Func_definitionContext)_localctx).id->getText() + 
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
				((Func_definitionContext)_localctx).lpr = match(LPAREN);
				setState(108);
				((Func_definitionContext)_localctx).rpr = match(RPAREN);
				setState(109);
				((Func_definitionContext)_localctx).csm = compound_statement();

				        

						if(wasDeclared){
							if(symbol->getParameters().size() > 0){
								writeIntoErrorFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							}
						}

						if(((Func_definitionContext)_localctx).csm.return_type != ((Func_definitionContext)_localctx).ts.print_text){
							if(((Func_definitionContext)_localctx).ts.print_text == "void" && !((((Func_definitionContext)_localctx).csm.return_type == "") || (((Func_definitionContext)_localctx).csm.return_type == "void"))){
								writeIntoErrorFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Cannot return value from function ") + string(((Func_definitionContext)_localctx).id->getText()) + string(" with void return type\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Cannot return value from function ") + string(((Func_definitionContext)_localctx).id->getText())+ string(" with void return type\n")
								);
								syntaxErrorCount++;
							}
							else if(!(((Func_definitionContext)_localctx).ts.print_text == "void" && ((Func_definitionContext)_localctx).csm.return_type == "")){
								writeIntoErrorFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Return type mismatch in function ") + string(((Func_definitionContext)_localctx).id->getText()) + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(((Func_definitionContext)_localctx).id->getLine()) + string(": Return type mismatch in function ") + string(((Func_definitionContext)_localctx).id->getText())+ string("\n")
								);
								syntaxErrorCount++;
							}
						}

						writeIntoparserLogFile(
				            string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n")
				        );
				        ((Func_definitionContext)_localctx).print_text =  ((Func_definitionContext)_localctx).ts.print_text + string(" ") + ((Func_definitionContext)_localctx).id->getText() + ((Func_definitionContext)_localctx).lpr->getText() + ((Func_definitionContext)_localctx).rpr->getText() + ((Func_definitionContext)_localctx).csm.print_text;

				        writeIntoparserLogFile(
				            _localctx.print_text + string("\n")
				        );

						symbol->setParameters(vector<string>(), ((Func_definitionContext)_localctx).ts.print_text);
						// Assembly Code 
						if(((Func_definitionContext)_localctx).id->getText() == "main"){ 
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
							((Func_definitionContext)_localctx).id->getText() + string(" ENDP")
						);

						// scopeOffset.pop_back();

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public string print_text;
		public vector<string> args;
		public vector<string> vars;
		public Parameter_listContext pl;
		public Type_specifierContext ts;
		public Token id;
		public Token cm;
		public Token add_op;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105046Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105046Parser.RTHIRD, 0); }
		public TerminalNode COMMA() { return getToken(C2105046Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105046Parser.ADDOP, 0); }
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(133);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(115);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(116);
				((Parameter_listContext)_localctx).id = match(ID);

							
							string name = ((Parameter_listContext)_localctx).id->getText();
							if(!inDeclaration){
								if(!symbolTable.insert(name, "ID", nullptr, ((Parameter_listContext)_localctx).ts.print_text)){
									writeIntoErrorFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string(" in parameter\n")
									);
									writeIntoparserLogFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string(" in parameter\n")
									);
									syntaxErrorCount++;
								} else {
									_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
								}
							} else {
								
								_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
							}

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
				   		   );

						   writeIntoparserLogFile(
					  			string(((Parameter_listContext)_localctx).ts.print_text) + string(" ") + string(((Parameter_listContext)_localctx).id->getText()) + string("\n")
					 		);

							((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).ts.print_text + " " + ((Parameter_listContext)_localctx).id->getText();
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
							_localctx.vars.push_back(name);

						
				}
				break;
			case 2:
				{
				setState(119);
				((Parameter_listContext)_localctx).ts = type_specifier();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
							);
							((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).ts.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
						
				}
				break;
			case 3:
				{
				setState(122);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(123);
				((Parameter_listContext)_localctx).id = match(ID);
				setState(124);
				match(LTHIRD);
				setState(125);
				match(RTHIRD);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
				   		   );

						   writeIntoparserLogFile(
					  			string(((Parameter_listContext)_localctx).ts.print_text) + string(" ") + string(((Parameter_listContext)_localctx).id->getText()) + string("\n")
					 		);

							((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).ts.print_text + " " + ((Parameter_listContext)_localctx).id->getText();
							// symbolTable.enterScope();
							scoped = true;
							string name = ((Parameter_listContext)_localctx).id->getText();
							if(!inDeclaration){
								if(!symbolTable.insert(name, "ID", nullptr, ((Parameter_listContext)_localctx).ts.print_text)){
									writeIntoErrorFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string("\n")
									);
									writeIntoparserLogFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string("\n")
									);
									syntaxErrorCount++;
								} else {
									_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text + "[]");
									SymbolInfo* symbol = symbolTable.lookUp(name);
									symbol->setIsArray();
								}
							}

						
				}
				break;
			case 4:
				{
				setState(128);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(129);
				match(LTHIRD);
				setState(130);
				match(RTHIRD);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
							);
							((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).ts.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text + "[]");
						
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(166);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(164);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(135);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(136);
						match(COMMA);
						setState(137);
						((Parameter_listContext)_localctx).ts = type_specifier();
						setState(138);
						((Parameter_listContext)_localctx).id = match(ID);

						          			string name = ((Parameter_listContext)_localctx).id->getText();
						          			if(!inDeclaration){
						          				if(!symbolTable.insert(name, "ID", nullptr, ((Parameter_listContext)_localctx).ts.print_text)){
						          					writeIntoErrorFile(
						          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string(" in parameter\n")
						          					);
						          					writeIntoparserLogFile(
						          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string(" in parameter\n")
						          					);
						          					syntaxErrorCount++;
						          				}	else{
						          					((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          					_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
						          				}
						          			} else {
						          				((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          				_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
						          			}

						          			writeIntoparserLogFile(
						          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
						          			);

						          			writeIntoparserLogFile(
						          				string(((Parameter_listContext)_localctx).pl.print_text) + string(",") + string(((Parameter_listContext)_localctx).ts.print_text) + string(" ") + string(((Parameter_listContext)_localctx).id->getText()) + string("\n")
						          			);


						          			// writeIntoCodeFile(
						          			// 	string("\t; defining paramter into stack offset")
						          			// );

						          			// SymbolInfo* symbol = symbolTable.lookUp(name);
						          			// scopeOffset.back() -= 2;

						          			// symbol->setAsmData(scopeOffset.back(), false);

						          			((Parameter_listContext)_localctx).vars =  ((Parameter_listContext)_localctx).pl.vars;
						          			_localctx.vars.push_back(name);
						          			((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).pl.print_text + "," + ((Parameter_listContext)_localctx).ts.print_text + " " + ((Parameter_listContext)_localctx).id->getText();

						          		
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(141);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(142);
						((Parameter_listContext)_localctx).cm = match(COMMA);
						setState(143);
						((Parameter_listContext)_localctx).ts = type_specifier();

						          			writeIntoparserLogFile(
						          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
						          			);
						          			((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).pl.print_text + ((Parameter_listContext)_localctx).cm->getText() + ((Parameter_listContext)_localctx).ts.print_text;
						          			writeIntoparserLogFile(
						          				_localctx.print_text + string("\n")
						          			);
						          			((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          			_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text);
						          		
						}
						break;
					case 3:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(146);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(147);
						((Parameter_listContext)_localctx).add_op = match(ADDOP);

						          			// syntax error handle rule
						          			writeIntoparserLogFile(
						          				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
						          			);
						          			writeIntoErrorFile(
						          				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
						          			);
						          			((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          			((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).pl.print_text;
						          			syntaxErrorCount++;
						          		
						}
						break;
					case 4:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(149);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(150);
						match(COMMA);
						setState(151);
						((Parameter_listContext)_localctx).ts = type_specifier();
						setState(152);
						((Parameter_listContext)_localctx).id = match(ID);
						setState(153);
						match(LTHIRD);
						setState(154);
						match(RTHIRD);

						          			writeIntoparserLogFile(
						          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
						          			);

						          			writeIntoparserLogFile(
						          				string(((Parameter_listContext)_localctx).pl.print_text) + string(",") + string(((Parameter_listContext)_localctx).ts.print_text) + string(" ") + string(((Parameter_listContext)_localctx).id->getText()) + string("\n")
						          			);

						          			((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).pl.print_text + "," + ((Parameter_listContext)_localctx).ts.print_text + " " + ((Parameter_listContext)_localctx).id->getText();
						          			string name = ((Parameter_listContext)_localctx).id->getText();
						          			if(!inDeclaration){
						          				if(!symbolTable.insert(name, "ID", nullptr, ((Parameter_listContext)_localctx).ts.print_text)){
						          					writeIntoErrorFile(
						          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string("\n")
						          					);
						          					writeIntoparserLogFile(
						          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string(((Parameter_listContext)_localctx).id->getText())+ string("\n")
						          					);
						          					syntaxErrorCount++;
						          				}	else {
						          					((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          					_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text + "[]");
						          					SymbolInfo* symbol = symbolTable.lookUp(name);
						          					symbol->setIsArray();
						          				}
						          			}

						          		
						}
						break;
					case 5:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(157);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(158);
						((Parameter_listContext)_localctx).cm = match(COMMA);
						setState(159);
						((Parameter_listContext)_localctx).ts = type_specifier();
						setState(160);
						match(LTHIRD);
						setState(161);
						match(RTHIRD);

						          			writeIntoparserLogFile(
						          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
						          			);
						          			((Parameter_listContext)_localctx).print_text =  ((Parameter_listContext)_localctx).pl.print_text + ((Parameter_listContext)_localctx).cm->getText() + ((Parameter_listContext)_localctx).ts.print_text;
						          			writeIntoparserLogFile(
						          				_localctx.print_text + string("\n")
						          			);
						          			((Parameter_listContext)_localctx).args =  ((Parameter_listContext)_localctx).pl.args;
						          			_localctx.args.push_back(((Parameter_listContext)_localctx).ts.print_text + "[]");
						          		
						}
						break;
					}
					} 
				}
				setState(168);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public string print_text;
		public string return_type;
		public Token lcl;
		public StatementsContext stms;
		public Token rcl;
		public TerminalNode LCURL() { return getToken(C2105046Parser.LCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode RCURL() { return getToken(C2105046Parser.RCURL, 0); }
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(178);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(169);
				((Compound_statementContext)_localctx).lcl = match(LCURL);

							if(!scoped){
								symbolTable.enterScope();
								scopeOffset.push_back(0);
							}
							scoped = false;

						
				setState(171);
				((Compound_statementContext)_localctx).stms = statements(0);
				setState(172);
				((Compound_statementContext)_localctx).rcl = match(RCURL);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL statements RCURL\n")
							);
							((Compound_statementContext)_localctx).print_text =  ((Compound_statementContext)_localctx).lcl->getText() + string("\n") + ((Compound_statementContext)_localctx).stms.print_text + string("\n") + ((Compound_statementContext)_localctx).rcl->getText();
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							symbolTable.printForParser();
							writeIntoparserLogFile(
								string("")
							);
							symbolTable.exitScope();
							((Compound_statementContext)_localctx).return_type =  ((Compound_statementContext)_localctx).stms.return_type;
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				match(LCURL);
				setState(176);
				match(RCURL);

								writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL RCURL\n")
							);
							((Compound_statementContext)_localctx).print_text =  string("{}");

							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							symbolTable.printForParser();
							writeIntoparserLogFile(
								string("")
							);
							symbolTable.exitScope();
							scopeOffset.pop_back();
							((Compound_statementContext)_localctx).return_type =  "void";
							
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public string print_text;
		public Type_specifierContext ts;
		public Declaration_listContext dl;
		public Token sm;
		public Type_specifierContext t;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105046Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			setState(190);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(180);
				((Var_declarationContext)_localctx).ts = type_specifier();
				setState(181);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(182);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        writeIntoparserLogFile(
							string("Line ") + to_string(((Var_declarationContext)_localctx).sm->getLine()) + string(": var_declaration : type_specifier declaration_list SEMICOLON\n")
						);

						

						if(((Var_declarationContext)_localctx).ts.print_text == "void"){
							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void")  + string("\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void") + string("\n")
							);

							syntaxErrorCount++;
						}

						writeIntoparserLogFile(
							string(((Var_declarationContext)_localctx).ts.print_text)+ string(" ") + string(((Var_declarationContext)_localctx).dl.print_text) + string(((Var_declarationContext)_localctx).sm->getText()) + string("\n")
						);
						((Var_declarationContext)_localctx).print_text =  ((Var_declarationContext)_localctx).ts.print_text + " " + ((Var_declarationContext)_localctx).dl.print_text  + ((Var_declarationContext)_localctx).sm->getText();

						for(int i = 0; i < ((Var_declarationContext)_localctx).dl.ids.size(); i++){
							
							string str = ((Var_declarationContext)_localctx).dl.ids[i];
							string actual_name = str;
							string length = ((Var_declarationContext)_localctx).dl.id_size[i];
							bool isArray = false;

							
							// Check if the last 2 characters are "[]"
							if (str.length() >= 2 && str.substr(str.length() - 2) == "[]") {
								// It's an array - remove the "[]" to get actual name
								actual_name = str.substr(0, str.length() - 2);
								isArray = true;
							}
							
							// if(!symbolTable.insert(actual_name, "ID", nullptr, ((Var_declarationContext)_localctx).ts.print_text, isArray)){
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

						

				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(185);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(186);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(187);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        writeIntoErrorFile(
				            string("Line# ") + to_string(((Var_declarationContext)_localctx).sm->getLine()) +
				            " with error name: " + ((Var_declarationContext)_localctx).de.error_name +
				            " - Syntax error at declaration list of variable declaration"
				        );

				        syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public string print_text;
		public Token i;
		public Token f;
		public Token v;
		public TerminalNode INT() { return getToken(C2105046Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C2105046Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C2105046Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(200);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(194);
				((Type_specifierContext)_localctx).i = match(INT);

				            writeIntoparserLogFile(
								string("Line ") + to_string(((Type_specifierContext)_localctx).i->getLine()) + string(": type_specifier : INT\n")
							);

							writeIntoparserLogFile(
									string("int\n")
							);
							((Type_specifierContext)_localctx).print_text =  ((Type_specifierContext)_localctx).i->getText();
							

				        
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(196);
				((Type_specifierContext)_localctx).f = match(FLOAT);

				            writeIntoparserLogFile(
								string("Line ") + to_string(((Type_specifierContext)_localctx).f->getLine()) + string(": type_specifier : FLOAT\n")
							);

							writeIntoparserLogFile(
								string(((Type_specifierContext)_localctx).f->getText()) + string("\n")
							);

							((Type_specifierContext)_localctx).print_text =  ((Type_specifierContext)_localctx).f->getText();
				        
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(198);
				((Type_specifierContext)_localctx).v = match(VOID);

				            writeIntoparserLogFile(
								string("Line ") + to_string(((Type_specifierContext)_localctx).v->getLine()) + string(": type_specifier : VOID\n")
							);

							writeIntoparserLogFile(
								string(((Type_specifierContext)_localctx).v->getText()) + string("\n")
							);

							((Type_specifierContext)_localctx).print_text =  ((Type_specifierContext)_localctx).v->getText();
				        
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public string print_text;
		public vector<string> ids;
		public vector<string> id_size;
		public Declaration_listContext d;
		public Declaration_listContext dl;
		public Token i;
		public Token l_t;
		public Token c_i;
		public Token r_t;
		public Token c;
		public Token id;
		public Token third_brac;
		public Token c_int;
		public Token r_third;
		public Token add_op;
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105046Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C2105046Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105046Parser.RTHIRD, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105046Parser.COMMA, 0); }
		public TerminalNode ADDOP() { return getToken(C2105046Parser.ADDOP, 0); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(210);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(203);
				((Declaration_listContext)_localctx).i = match(ID);

							writeIntoparserLogFile(
								string("Line ") + to_string(((Declaration_listContext)_localctx).i->getLine()) + string(": declaration_list : ID\n")
							);
							((Declaration_listContext)_localctx).print_text =  ((Declaration_listContext)_localctx).i->getText();
							writeIntoparserLogFile(
								string(((Declaration_listContext)_localctx).i->getText()) + string("\n")
							);

							_localctx.ids.push_back(_localctx.print_text);
							// _localctx.ids.push_back(make_pair(((Declaration_listContext)_localctx).id->getText(), false));
							_localctx.id_size.push_back("1");

							string name = ((Declaration_listContext)_localctx).i->getText();
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
						  
				}
				break;
			case 2:
				{
				setState(205);
				((Declaration_listContext)_localctx).i = match(ID);
				setState(206);
				((Declaration_listContext)_localctx).l_t = match(LTHIRD);
				setState(207);
				((Declaration_listContext)_localctx).c_i = match(CONST_INT);
				setState(208);
				((Declaration_listContext)_localctx).r_t = match(RTHIRD);

								writeIntoparserLogFile(
									string("Line ") + to_string(((Declaration_listContext)_localctx).i->getLine()) + string(": declaration_list : ID LTHIRD CONST_INT RTHIRD\n")
								);

								((Declaration_listContext)_localctx).print_text =  ((Declaration_listContext)_localctx).i->getText() + ((Declaration_listContext)_localctx).l_t->getText() + ((Declaration_listContext)_localctx).c_i->getText() + ((Declaration_listContext)_localctx).r_t->getText();
								writeIntoparserLogFile(
									string(((Declaration_listContext)_localctx).i->getText()) + string(((Declaration_listContext)_localctx).l_t->getText()) + string(((Declaration_listContext)_localctx).c_i->getText()) + string(((Declaration_listContext)_localctx).r_t->getText()) + string("\n")
								);

								_localctx.ids.push_back(((Declaration_listContext)_localctx).i->getText() + "[]");
								// _localctx.ids.push_back(make_pair(((Declaration_listContext)_localctx).id->getText(), true));
								_localctx.id_size.push_back(((Declaration_listContext)_localctx).c_i->getText());

								string name = ((Declaration_listContext)_localctx).i->getText();
								symbolTable.insert(name, "ID", nullptr, "int", true);
								SymbolInfo* symbol = symbolTable.lookUp(name);
								// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
								if(symbolTable.isMainScope()){
									symbol->setAsmData(0, true);
									symbol->setArrSize(stoi(((Declaration_listContext)_localctx).c_i->getText()));
									writeIntoTmpFile(
										string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
									);
								} else {
									// local variables 
									scopeOffset.back() += stoi(((Declaration_listContext)_localctx).c_i->getText()) * 2;
									symbol->setAsmData(scopeOffset.back(), false);
									symbol->setArrSize(stoi(((Declaration_listContext)_localctx).c_i->getText()));
									string codeOffset = to_string(stoi(((Declaration_listContext)_localctx).c_i->getText()) * 2);
									writeIntoCodeFile(
										string("\tSUB SP, ") + codeOffset
									);
								}
						  
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(229);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(227);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.d = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(212);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(213);
						((Declaration_listContext)_localctx).c = match(COMMA);
						setState(214);
						((Declaration_listContext)_localctx).id = match(ID);

						          			writeIntoparserLogFile(
						          				string("Line ") + to_string(((Declaration_listContext)_localctx).id->getLine()) + string(": declaration_list : declaration_list COMMA ID\n")
						          			);

						          			((Declaration_listContext)_localctx).print_text =  ((Declaration_listContext)_localctx).d.print_text + ((Declaration_listContext)_localctx).c->getText() + ((Declaration_listContext)_localctx).id->getText();
						          			writeIntoparserLogFile(
						          				_localctx.print_text + string("\n")
						          			);

						          			((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).d.ids;
						          			_localctx.ids.push_back(((Declaration_listContext)_localctx).id->getText());
						          			// _localctx.ids.push_back(make_pair(((Declaration_listContext)_localctx).id->getText(), false));
						          			((Declaration_listContext)_localctx).id_size =  ((Declaration_listContext)_localctx).d.id_size;
						          			_localctx.id_size.push_back("1");
						          			string name = ((Declaration_listContext)_localctx).id->getText();
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

						          			
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.d = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(216);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(217);
						((Declaration_listContext)_localctx).c = match(COMMA);
						setState(218);
						((Declaration_listContext)_localctx).id = match(ID);
						setState(219);
						((Declaration_listContext)_localctx).third_brac = match(LTHIRD);
						setState(220);
						((Declaration_listContext)_localctx).c_int = match(CONST_INT);
						setState(221);
						((Declaration_listContext)_localctx).r_third = match(RTHIRD);

						          			writeIntoparserLogFile(
						          	 			string("Line ") + to_string(((Declaration_listContext)_localctx).id->getLine()) + string(": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n")
						          	   		);

						          			((Declaration_listContext)_localctx).print_text =  ((Declaration_listContext)_localctx).d.print_text + ((Declaration_listContext)_localctx).c->getText() + ((Declaration_listContext)_localctx).id->getText() + ((Declaration_listContext)_localctx).third_brac->getText() + ((Declaration_listContext)_localctx).c_int->getText() + ((Declaration_listContext)_localctx).r_third->getText();
						          			writeIntoparserLogFile(
						          				_localctx.print_text + string("\n")
						          			);
						          			((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).d.ids;
						          			_localctx.ids.push_back(((Declaration_listContext)_localctx).id->getText() + "[]");
						          			// _localctx.ids.push_back(make_pair(((Declaration_listContext)_localctx).id->getText(), true));
						          			((Declaration_listContext)_localctx).id_size =  ((Declaration_listContext)_localctx).d.id_size;
						          			_localctx.id_size.push_back(((Declaration_listContext)_localctx).c_int->getText());
						          			
						          			string name = ((Declaration_listContext)_localctx).id->getText();
						          			symbolTable.insert(name, "ID", nullptr, "int", true);
						          			SymbolInfo* symbol = symbolTable.lookUp(name);
						          			// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
						          			if(symbolTable.isMainScope()){
						          				symbol->setAsmData(0, true);
						          				symbol->setArrSize(stoi(((Declaration_listContext)_localctx).c_int->getText()));
						          				writeIntoTmpFile(
						          					string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
						          				);
						          			} else {
						          				// local variables 
						          				scopeOffset.back() += stoi(((Declaration_listContext)_localctx).c_int->getText()) * 2;
						          				symbol->setAsmData(scopeOffset.back(), false);
						          				symbol->setArrSize(stoi(((Declaration_listContext)_localctx).c_int->getText()));
						          				string codeOffset = to_string(stoi(((Declaration_listContext)_localctx).c_int->getText()) * 2);
						          				writeIntoCodeFile(
						          					string("\tSUB SP, ") + codeOffset
						          				);
						          			}
						          		  
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(223);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(224);
						((Declaration_listContext)_localctx).add_op = match(ADDOP);
						setState(225);
						((Declaration_listContext)_localctx).id = match(ID);

						          				// syntax error handle
						          				writeIntoErrorFile(
						          					string("Error at line ") + to_string(((Declaration_listContext)_localctx).id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
						          				);

						          				writeIntoparserLogFile(
						          					string("Error at line ") + to_string(((Declaration_listContext)_localctx).id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
						          				);
						          				syntaxErrorCount++;

						          				((Declaration_listContext)_localctx).print_text =  ((Declaration_listContext)_localctx).dl.print_text;
						          				((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).dl.ids;
						          				// writeIntoparserLogFile(
						          				// 	string(((Declaration_listContext)_localctx).i->getText()) + string(((Declaration_listContext)_localctx).l_t->getText()) + string(((Declaration_listContext)_localctx).c_i->getText()) + string(((Declaration_listContext)_localctx).r_t->getText()) + string("\n")
						          				// );

						          				// _localctx.ids.push_back(((Declaration_listContext)_localctx).i->getText() + "[]");
						          		  
						}
						break;
					}
					} 
				}
				setState(231);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public string print_text;
		public string return_type;
		public StatementsContext stms;
		public StatementContext stm;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(233);
			((StatementsContext)_localctx).stm = statement();

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statement\n")
						);
						((StatementsContext)_localctx).print_text =  ((StatementsContext)_localctx).stm.print_text;
						writeIntoparserLogFile(
							_localctx.print_text + string("\n")
						);
						((StatementsContext)_localctx).return_type =  ((StatementsContext)_localctx).stm.return_type;
				
			}
			_ctx.stop = _input.LT(-1);
			setState(242);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.stms = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(236);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(237);
					((StatementsContext)_localctx).stm = statement();

					          			if(((StatementsContext)_localctx).stm.print_text != ""){
					          			writeIntoparserLogFile(
					          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statements statement\n")
					          			);
					          			((StatementsContext)_localctx).print_text =  ((StatementsContext)_localctx).stms.print_text + string("\n") + ((StatementsContext)_localctx).stm.print_text;
					          			writeIntoparserLogFile(
					          				_localctx.print_text + string("\n")
					          			);
					          			((StatementsContext)_localctx).return_type =  ((StatementsContext)_localctx).stm.return_type;
					          			}
					          			else {
					          				((StatementsContext)_localctx).print_text =  ((StatementsContext)_localctx).stms.print_text;
					          			}
					          	   
					}
					} 
				}
				setState(244);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public string print_text;
		public string return_type;
		public Var_declarationContext vd;
		public Expression_statementContext expr_stm;
		public Compound_statementContext csm;
		public Token fr;
		public Token lpr;
		public Expression_statementContext expr_st1;
		public Expression_statementContext expr_st2;
		public ExpressionContext expr;
		public Token rpr;
		public StatementContext stm;
		public Token if_;
		public StatementContext stm1;
		public Token else_;
		public StatementContext stm2;
		public Token while_;
		public Token pln;
		public Token id;
		public Token sm;
		public Token ret;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C2105046Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C2105046Parser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105046Parser.RPAREN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C2105046Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C2105046Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C2105046Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C2105046Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105046Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C2105046Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(308);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(245);
				((StatementContext)_localctx).vd = var_declaration();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : var_declaration\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).vd.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(248);
				((StatementContext)_localctx).expr_stm = expression_statement();

							if(((StatementContext)_localctx).expr_stm.print_text != ""){
							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : expression_statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).expr_stm.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";
							}
							else {
								((StatementContext)_localctx).print_text =  "";
							}
					  
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(251);
				((StatementContext)_localctx).csm = compound_statement();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : compound_statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).csm.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";
					  
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(254);
				((StatementContext)_localctx).fr = match(FOR);

						symbolTable.enterScope();
						scoped = true;
						string start_label = getLabel();
						string out_label = getLabel();
						string increment_step = getLabel();
						string inside_step = getLabel();
					  
				setState(256);
				((StatementContext)_localctx).lpr = match(LPAREN);
				setState(257);
				((StatementContext)_localctx).expr_st1 = expression_statement();

						// pre comparison steps
						writeIntoCodeFile(
							start_label + string(":") + string("; Line ") + to_string(_input->LT(-1)->getLine())
						);
						pop_flag = false;
					  
				setState(259);
				((StatementContext)_localctx).expr_st2 = expression_statement();

						// post comparison happens here
						writeIntoCodeFile(
							string("\tPOP AX; comparision happens here (for loop starts up)\n\tCMP AX, 0\n\tJE ") + out_label +
							string("\n\tJMP ") + inside_step + string("\n") +
							increment_step + string(":") 
						);
					  
				setState(261);
				((StatementContext)_localctx).expr = expression(0);

						writeIntoCodeFile(
							string("\tPOP AX; incrementing starts here\n\tJMP ") + start_label + string("\n") +
							inside_step + string(":; inside forloop step\n")
						);

					  
				setState(263);
				((StatementContext)_localctx).rpr = match(RPAREN);
				setState(264);
				((StatementContext)_localctx).stm = statement();

							// inside step for for
							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).fr->getText() + ((StatementContext)_localctx).lpr->getText() + ((StatementContext)_localctx).expr_st1.print_text + ((StatementContext)_localctx).expr_st2.print_text + ((StatementContext)_localctx).expr.print_text + ((StatementContext)_localctx).rpr->getText() + ((StatementContext)_localctx).stm.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";

							writeIntoCodeFile(
								string("\tJMP ") + increment_step +
								string("\n") + out_label + string(": ; for loop ends here")
							);
					   
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(267);
				((StatementContext)_localctx).if_ = match(IF);


						string done_label = getLabel();
					  
				setState(269);
				((StatementContext)_localctx).lpr = match(LPAREN);
				setState(270);
				((StatementContext)_localctx).expr = expression(0);
				setState(271);
				((StatementContext)_localctx).rpr = match(RPAREN);


						// string done_label = getLabel();
						writeIntoCodeFile(
							string("\tPOP AX; only if condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
							+ string("\n\tCMP AX, 0\n\tJE ") + done_label
						);

					  
				setState(273);
				((StatementContext)_localctx).stm = statement();

							writeIntoparserLogFile(
								string("Line ") + to_string(((StatementContext)_localctx).if_->getLine()) + string(": statement : IF LPAREN expression RPAREN statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).if_->getText() + ((StatementContext)_localctx).lpr->getText() + ((StatementContext)_localctx).expr.print_text + ((StatementContext)_localctx).rpr->getText() + ((StatementContext)_localctx).stm.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";

							writeIntoCodeFile(
								done_label + string(":")
							);

					  
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(276);
				((StatementContext)_localctx).if_ = match(IF);
				setState(277);
				((StatementContext)_localctx).lpr = match(LPAREN);
				setState(278);
				((StatementContext)_localctx).expr = expression(0);
				setState(279);
				((StatementContext)_localctx).rpr = match(RPAREN);


						string else_label = getLabel();
						string done_label = getLabel();
						writeIntoCodeFile(
							string("\tPOP AX; if else condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
							+ string("\n\tCMP AX, 0\n\tJE ") + else_label 
						);

					  
				setState(281);
				((StatementContext)_localctx).stm1 = statement();


						writeIntoCodeFile(
							string("\tJMP ") + done_label
						);

					  
				setState(283);
				((StatementContext)_localctx).else_ = match(ELSE);

						writeIntoCodeFile(
							else_label + string(":")
						);
					  
				setState(285);
				((StatementContext)_localctx).stm2 = statement();
				 
							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : IF LPAREN expression RPAREN statement ELSE statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).if_->getText() + ((StatementContext)_localctx).lpr->getText() + ((StatementContext)_localctx).expr.print_text + ((StatementContext)_localctx).rpr->getText() + ((StatementContext)_localctx).stm1.print_text + ((StatementContext)_localctx).else_->getText() + string(" ") + ((StatementContext)_localctx).stm2.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";
							
							writeIntoCodeFile(
								done_label + string(":")
							);
					  
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(288);
				((StatementContext)_localctx).while_ = match(WHILE);

						string start_label = getLabel();
						string out_label = getLabel();
						writeIntoCodeFile(
							start_label + string(": ; while loop starts") + string("Line ") + to_string(_input->LT(-1)->getLine())
						);
					  
				setState(290);
				((StatementContext)_localctx).lpr = match(LPAREN);
				setState(291);
				((StatementContext)_localctx).expr = expression(0);
				setState(292);
				((StatementContext)_localctx).rpr = match(RPAREN);

						writeIntoCodeFile(
							string("\tPOP AX\n\tCMP AX, 0\n\tJE ") + out_label
						);
					  
				setState(294);
				((StatementContext)_localctx).stm = statement();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : WHILE LPAREN expression RPAREN statement\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).while_->getText() + ((StatementContext)_localctx).lpr->getText() + ((StatementContext)_localctx).expr.print_text + ((StatementContext)_localctx).rpr->getText() + ((StatementContext)_localctx).stm.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";

							writeIntoCodeFile(
								string("\tJMP ") + start_label 
								+ string("\n") + out_label + string(": ; while loop ends\n")
							);
					  
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(297);
				((StatementContext)_localctx).pln = match(PRINTLN);
				setState(298);
				((StatementContext)_localctx).lpr = match(LPAREN);
				setState(299);
				((StatementContext)_localctx).id = match(ID);
				setState(300);
				((StatementContext)_localctx).rpr = match(RPAREN);
				setState(301);
				((StatementContext)_localctx).sm = match(SEMICOLON);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).pln->getText() + ((StatementContext)_localctx).lpr->getText() + ((StatementContext)_localctx).id->getText() + ((StatementContext)_localctx).rpr->getText() + ((StatementContext)_localctx).sm->getText();
							string name = ((StatementContext)_localctx).id->getText();
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
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  "void";

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
					  
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(303);
				((StatementContext)_localctx).ret = match(RETURN);
				setState(304);
				((StatementContext)_localctx).expr = expression(0);
				setState(305);
				((StatementContext)_localctx).sm = match(SEMICOLON);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : RETURN expression SEMICOLON\n")
							);
							((StatementContext)_localctx).print_text =  ((StatementContext)_localctx).ret->getText() + string(" ") + ((StatementContext)_localctx).expr.print_text + ((StatementContext)_localctx).sm->getText();
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((StatementContext)_localctx).return_type =  ((StatementContext)_localctx).expr.dataType;
							writeIntoCodeFile(
								string("\tPOP AX; return statement written here") + string("; Line ") + to_string(_input->LT(-1)->getLine())
								+ string("\n\tJMP ") + current_return_label
							);
					  
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public string print_text;
		public Token sm;
		public ExpressionContext expr;
		public TerminalNode SEMICOLON() { return getToken(C2105046Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_expression_statement);
		try {
			setState(316);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(310);
				((Expression_statementContext)_localctx).sm = match(SEMICOLON);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : SEMICOLON\n")
							);
							((Expression_statementContext)_localctx).print_text =  ((Expression_statementContext)_localctx).sm->getText();
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
					 
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(312);
				((Expression_statementContext)_localctx).expr = expression(0);
				setState(313);
				((Expression_statementContext)_localctx).sm = match(SEMICOLON);

							if(((Expression_statementContext)_localctx).expr.print_text != ""){
							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : expression SEMICOLON\n")
							);
							((Expression_statementContext)_localctx).print_text =  ((Expression_statementContext)_localctx).expr.print_text + ((Expression_statementContext)_localctx).sm->getText();
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							}
							else {
								((Expression_statementContext)_localctx).print_text =  "";
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

							
					
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo * symbol;
		public string arr_ind;
		public Token id;
		public Token lthr;
		public ExpressionContext expr;
		public Token rthr;
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105046Parser.LTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RTHIRD() { return getToken(C2105046Parser.RTHIRD, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable);
		try {
			setState(326);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(318);
				((VariableContext)_localctx).id = match(ID);

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID\n")
						);
						string name = ((VariableContext)_localctx).id->getText();
						SymbolInfo* symbol = symbolTable.lookUp(name);
						((VariableContext)_localctx).isArray =  false;
						if(symbol == nullptr){
							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
							);

							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
							);
							((VariableContext)_localctx).dataType =  "invalid";
							((VariableContext)_localctx).symbol =  nullptr;
							syntaxErrorCount++;
						} else {
							((VariableContext)_localctx).dataType =  symbol->getDataType();
							((VariableContext)_localctx).isArray =  symbol->getIsArray();
							((VariableContext)_localctx).symbol =  symbol;
							// string msg = "false";
							// if(_localctx.isArray){
							// 	msg = "true";
							// }
							// writeIntoparserLogFile(
							// 	string("DEBUG var condition check true: ") + msg
							// );
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

						((VariableContext)_localctx).print_text =  ((VariableContext)_localctx).id->getText();
						//((VariableContext)_localctx).isArray =  symbol->getIsArray();
						
						writeIntoparserLogFile(
				   			string(((VariableContext)_localctx).id->getText()) + string("\n")
				  		);
						
					

					
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(320);
				((VariableContext)_localctx).id = match(ID);
				setState(321);
				((VariableContext)_localctx).lthr = match(LTHIRD);
				setState(322);
				((VariableContext)_localctx).expr = expression(0);
				setState(323);
				((VariableContext)_localctx).rthr = match(RTHIRD);

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID LTHIRD expression RTHIRD\n")
							);
							((VariableContext)_localctx).print_text =  ((VariableContext)_localctx).id->getText() + ((VariableContext)_localctx).lthr->getText() + ((VariableContext)_localctx).expr.print_text + ((VariableContext)_localctx).rthr->getText();
							((VariableContext)_localctx).isArray =  false;
							if(((VariableContext)_localctx).expr.dataType == "float"){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
								);

								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
								);
								syntaxErrorCount++;
							}
							

							string name = ((VariableContext)_localctx).id->getText();
							SymbolInfo* symbol = symbolTable.lookUp(name);

							if(symbol == nullptr){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
								);

								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
								);
								// ((VariableContext)_localctx).dataType =  "invalid";
								((VariableContext)_localctx).symbol =  nullptr;
								syntaxErrorCount++;
							} else {
								if(!symbol->getIsArray()){
									writeIntoErrorFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
									);

									writeIntoparserLogFile(
										string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
									);
									((VariableContext)_localctx).symbol =  nullptr;
									syntaxErrorCount++;
								}
								((VariableContext)_localctx).dataType =  symbol->getDataType();
								((VariableContext)_localctx).symbol =  symbol;
								((VariableContext)_localctx).arr_ind =  ((VariableContext)_localctx).expr.print_text;

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
							}

							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);





							// ((VariableContext)_localctx).isArray =  symbol->getIsArray();
								
							
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public Logic_expressionContext le;
		public VariableContext v;
		public Token assop;
		public Token ic;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public List<TerminalNode> ASSIGNOP() { return getTokens(C2105046Parser.ASSIGNOP); }
		public TerminalNode ASSIGNOP(int i) {
			return getToken(C2105046Parser.ASSIGNOP, i);
		}
		public List<Logic_expressionContext> logic_expression() {
			return getRuleContexts(Logic_expressionContext.class);
		}
		public Logic_expressionContext logic_expression(int i) {
			return getRuleContext(Logic_expressionContext.class,i);
		}
		public TerminalNode ADDOP() { return getToken(C2105046Parser.ADDOP, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode INVALID_CHAR() { return getToken(C2105046Parser.INVALID_CHAR, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(345);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(329);
				variable();
				setState(330);
				match(ASSIGNOP);
				setState(331);
				logic_expression();
				setState(332);
				match(ADDOP);
				setState(333);
				match(ASSIGNOP);
				setState(334);
				logic_expression();

							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
							);
							((ExpressionContext)_localctx).print_text =  "";
							((ExpressionContext)_localctx).dataType = "";
							syntaxErrorCount++;
					   
				}
				break;
			case 2:
				{
				setState(337);
				((ExpressionContext)_localctx).le = logic_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : logic_expression\n")
							);
							((ExpressionContext)_localctx).print_text =  ((ExpressionContext)_localctx).le.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((ExpressionContext)_localctx).dataType =  ((ExpressionContext)_localctx).le.dataType;
				 		
				}
				break;
			case 3:
				{
				setState(340);
				((ExpressionContext)_localctx).v = variable();
				setState(341);
				((ExpressionContext)_localctx).assop = match(ASSIGNOP);
				setState(342);
				((ExpressionContext)_localctx).le = logic_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : variable ASSIGNOP logic_expression\n")
							);
							((ExpressionContext)_localctx).print_text =  ((ExpressionContext)_localctx).v.print_text + ((ExpressionContext)_localctx).assop->getText() + ((ExpressionContext)_localctx).le.print_text;

							bool is_func = false;

							if(((ExpressionContext)_localctx).le.symbol != nullptr && ((ExpressionContext)_localctx).le.symbol->getDataType() == "FUNCTION"){
								is_func = true;
								// writeIntoparserLogFile(
								// 	string("DEBUG comes here ") 
								// );
							}
							
							if(((ExpressionContext)_localctx).v.dataType != ((ExpressionContext)_localctx).le.dataType && ((ExpressionContext)_localctx).v.dataType != "invalid" && ((ExpressionContext)_localctx).le.dataType != "invalid" && !is_func && !(((ExpressionContext)_localctx).v.dataType == "float" && ((ExpressionContext)_localctx).le.dataType == "int")){
								// writeIntoparserLogFile(
								// 	string("DEBUG Variable datatype: ") + string(((ExpressionContext)_localctx).v.dataType)+ string(" le dataType") + string(((ExpressionContext)_localctx).le.dataType) + string("\n")
								// );
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
								);
								syntaxErrorCount++;
							}
							else if(is_func && ((ExpressionContext)_localctx).le.symbol->getReturnType() != ((ExpressionContext)_localctx).v.dataType ){
								// writeIntoparserLogFile(
								// 	string("DEBUG Variable FUNC: ") + string(((ExpressionContext)_localctx).v.dataType)+ string(" le dataType") + string(((ExpressionContext)_localctx).le.dataType) + string("\n")
								// );
								if(((ExpressionContext)_localctx).le.symbol->getReturnType() == "void"){
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


							

							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((ExpressionContext)_localctx).dataType =  ((ExpressionContext)_localctx).v.dataType;

							if(((ExpressionContext)_localctx).v.isArray && !((ExpressionContext)_localctx).le.isArray){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ ((ExpressionContext)_localctx).v.print_text + string(" is an array\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ ((ExpressionContext)_localctx).v.print_text + string(" is an array\n")
								);
								syntaxErrorCount++;
							}

							// Assembly Code 
							SymbolInfo* symbol = ((ExpressionContext)_localctx).v.symbol;
							if(symbol){
								if(!symbol->getIsGlobal()){
									if(symbol->getIsArray()){
										string str_ind = ((ExpressionContext)_localctx).v.arr_ind;
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
										string str_ind = ((ExpressionContext)_localctx).v.arr_ind;
										string actual_offset = to_string(stoi(str_ind) * 2);
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
							
					   
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(352);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expression);
					setState(347);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(348);
					((ExpressionContext)_localctx).ic = match(INVALID_CHAR);

					          		writeIntoparserLogFile(
					          			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string(((ExpressionContext)_localctx).ic->getText()) + string("\n")
					          		);
					          		writeIntoErrorFile(
					          			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string(((ExpressionContext)_localctx).ic->getText()) + string("\n")
					          		);
					          		// ((ExpressionContext)_localctx).print_text =  "";
					          		syntaxErrorCount++;
					          	  
					}
					} 
				}
				setState(354);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo* symbol;
		public Rel_expressionContext re;
		public Rel_expressionContext re1;
		public Token lop;
		public Rel_expressionContext re2;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C2105046Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_logic_expression);
		try {
			setState(366);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(355);
				((Logic_expressionContext)_localctx).re = rel_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression\n")
							);
							((Logic_expressionContext)_localctx).print_text =  ((Logic_expressionContext)_localctx).re.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							((Logic_expressionContext)_localctx).dataType =  ((Logic_expressionContext)_localctx).re.dataType;
							((Logic_expressionContext)_localctx).isArray =  ((Logic_expressionContext)_localctx).re.isArray;
							((Logic_expressionContext)_localctx).symbol =  ((Logic_expressionContext)_localctx).re.symbol;
							// string msg = "false";
							// if(_localctx.isArray){
							// 	msg = "true";
							// }

							// writeIntoparserLogFile(
							// 	string("DEBUG logic lexpr condition check: ") + msg
							// );
				 		
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{

							string check_label = getLabel();
							string done_label = getLabel();
						 
				setState(359);
				((Logic_expressionContext)_localctx).re1 = rel_expression();



							writeIntoCodeFile(
								string("\tPOP AX; logic_expression : rel_expression LOGICOP rel_expression") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
							);


						 
				setState(361);
				((Logic_expressionContext)_localctx).lop = match(LOGICOP);

							if(((Logic_expressionContext)_localctx).lop->getText() == "||"){
								writeIntoCodeFile(
									string("\tCMP AX, 0\n\tJE ") + check_label + 
									string("\n\tPUSH 1\n\tJMP ") + done_label + string("\n") +
									check_label + string(": ; logical check label")
								);
							} else if(((Logic_expressionContext)_localctx).lop->getText() == "&&"){
								writeIntoCodeFile(
									string("\tCMP AX, 0\n\tJNE ") + check_label + 
									string("\n\tPUSH 0\n\tJMP ") + done_label + string("\n") +
									check_label + string(":; logical check label")
								);
							}
						 
				setState(363);
				((Logic_expressionContext)_localctx).re2 = rel_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression LOGICOP rel_expression\n")
							);
							((Logic_expressionContext)_localctx).print_text =  ((Logic_expressionContext)_localctx).re1.print_text + ((Logic_expressionContext)_localctx).lop->getText() + ((Logic_expressionContext)_localctx).re2.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((Logic_expressionContext)_localctx).dataType =  ((Logic_expressionContext)_localctx).re1.dataType;
							((Logic_expressionContext)_localctx).symbol =  nullptr;

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
						 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo* symbol;
		public Simple_expressionContext se;
		public Simple_expressionContext se1;
		public Token relop;
		public Simple_expressionContext se2;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C2105046Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_rel_expression);
		try {
			setState(376);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(368);
				((Rel_expressionContext)_localctx).se = simple_expression(0);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression\n")
							);
							((Rel_expressionContext)_localctx).print_text =  ((Rel_expressionContext)_localctx).se.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((Rel_expressionContext)_localctx).dataType =  ((Rel_expressionContext)_localctx).se.dataType;
							((Rel_expressionContext)_localctx).isArray =  ((Rel_expressionContext)_localctx).se.isArray;
							((Rel_expressionContext)_localctx).symbol =  ((Rel_expressionContext)_localctx).se.symbol;
							// string msg = "false";
							// if(_localctx.isArray){
							// 	msg = "true";
							// }

							// writeIntoparserLogFile(
							// 	string("DEBUG rel lexpr condition check: ") + msg
							// );
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(371);
				((Rel_expressionContext)_localctx).se1 = simple_expression(0);
				setState(372);
				((Rel_expressionContext)_localctx).relop = match(RELOP);
				setState(373);
				((Rel_expressionContext)_localctx).se2 = simple_expression(0);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression RELOP simple_expression\n")
							);
							((Rel_expressionContext)_localctx).print_text =  ((Rel_expressionContext)_localctx).se1.print_text + ((Rel_expressionContext)_localctx).relop->getText() + ((Rel_expressionContext)_localctx).se2.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							((Rel_expressionContext)_localctx).dataType =  "int";
							((Rel_expressionContext)_localctx).symbol =  nullptr;

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
							if(((Rel_expressionContext)_localctx).relop->getText() == ">"){
								writeIntoCodeFile(
									string("\tJG ") + true_label
								);
							} else if(((Rel_expressionContext)_localctx).relop->getText() == ">="){
								writeIntoCodeFile(
									string("\tJGE ") + true_label
								);
							} else if(((Rel_expressionContext)_localctx).relop->getText() == "<="){
								writeIntoCodeFile(
									string("\tJLE ") + true_label
								);
							} else if(((Rel_expressionContext)_localctx).relop->getText() == "<"){
								writeIntoCodeFile(
									string("\tJL ") + true_label
								);
							} else if(((Rel_expressionContext)_localctx).relop->getText() == "!="){
								writeIntoCodeFile(
									string("\tJNE ") + true_label
								);
							} else if(((Rel_expressionContext)_localctx).relop->getText() == "=="){
								writeIntoCodeFile(
									string("\tJE ") + true_label
								);
							}

							writeIntoCodeFile(
								string("\tPUSH 0\n\tJMP ") + done_label
								+ string("\n") + true_label + string(":\n") +
								string("\tPUSH 1\n") + done_label + string (":\n") 
							);


						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo* symbol;
		public Simple_expressionContext se;
		public TermContext t;
		public Token ao;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105046Parser.ADDOP, 0); }
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(379);
			((Simple_expressionContext)_localctx).t = term(0);

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : term\n")
							);
							((Simple_expressionContext)_localctx).print_text =  ((Simple_expressionContext)_localctx).t.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							((Simple_expressionContext)_localctx).dataType =  ((Simple_expressionContext)_localctx).t.dataType;
							((Simple_expressionContext)_localctx).isArray =  ((Simple_expressionContext)_localctx).t.isArray;
							((Simple_expressionContext)_localctx).symbol =  ((Simple_expressionContext)_localctx).t.symbol;
							// string msg = "false";
							// if(_localctx.isArray){
							// 	msg = "true";
							// }

							// writeIntoparserLogFile(
							// 	string("DEBUG simple lexpr condition check: ") + msg
							// );
						
			}
			_ctx.stop = _input.LT(-1);
			setState(389);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.se = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(382);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(383);
					((Simple_expressionContext)_localctx).ao = match(ADDOP);
					setState(384);
					((Simple_expressionContext)_localctx).t = term(0);

					          				writeIntoparserLogFile(
					          					string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : simple_expression ADDOP term\n")
					          				);

					          				((Simple_expressionContext)_localctx).print_text =  ((Simple_expressionContext)_localctx).se.print_text + ((Simple_expressionContext)_localctx).ao->getText() + ((Simple_expressionContext)_localctx).t.print_text;
					          				writeIntoparserLogFile(
					          					_localctx.print_text + string("\n")
					          				);
					          				
					          				if(((Simple_expressionContext)_localctx).se.dataType == "int" && ((Simple_expressionContext)_localctx).t.dataType == "float"){
					          					writeIntoErrorFile(
					          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
					          					);
					          					writeIntoparserLogFile(
					          						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
					          					);
					          					((Simple_expressionContext)_localctx).dataType =  "invalid";
					          					syntaxErrorCount++;
					          				}
					          				else if(((Simple_expressionContext)_localctx).se.dataType == "float" && ((Simple_expressionContext)_localctx).t.dataType == "int"){
					          					((Simple_expressionContext)_localctx).dataType =  "float";
					          				}
					          				else {
					          					((Simple_expressionContext)_localctx).dataType =  "int";
					          				}

					          				((Simple_expressionContext)_localctx).symbol =  nullptr;

					          				// Assembly codes

					          				writeIntoCodeFile(
					          					string("\tPOP BX ; simple expression: simple expression add op term") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
					          				);

					          				writeIntoCodeFile(
					          					string("\tPOP AX")
					          				);


					          				if(((Simple_expressionContext)_localctx).ao->getText() == "+"){
					          					writeIntoCodeFile(
					          						string("\tADD AX, BX\n\tPUSH AX")
					          					);
					          				} else if(((Simple_expressionContext)_localctx).ao->getText() == "-"){
					          					writeIntoCodeFile(
					          						string("\tSUB AX, BX\n\tPUSH AX")
					          					);
					          				}

					          				
					          		  
					}
					} 
				}
				setState(391);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo* symbol;
		public TermContext t;
		public Unary_expressionContext u;
		public Token mul;
		public Unary_expressionContext una;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C2105046Parser.MULOP, 0); }
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(393);
			((TermContext)_localctx).u = unary_expression();

					writeIntoparserLogFile(
						string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : unary_expression\n")
					);

					writeIntoparserLogFile(
						((TermContext)_localctx).u.print_text + string("\n")
					);

					((TermContext)_localctx).print_text =  ((TermContext)_localctx).u.print_text;
					((TermContext)_localctx).dataType =  ((TermContext)_localctx).u.dataType;
					((TermContext)_localctx).isArray =  ((TermContext)_localctx).u.isArray;
					((TermContext)_localctx).symbol =  ((TermContext)_localctx).u.symbol;

					// string msg = "false";
					// if(_localctx.isArray){
					// 	msg = "true";
					// }

					// writeIntoparserLogFile(
					// 	string("DEBUG term lexpr condition check: ") + msg
					// );

				
			}
			_ctx.stop = _input.LT(-1);
			setState(403);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(396);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(397);
					((TermContext)_localctx).mul = match(MULOP);
					setState(398);
					((TermContext)_localctx).una = unary_expression();

					          		writeIntoparserLogFile(
					          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
					          			);
					          			// bool invalid = false;
					          			((TermContext)_localctx).print_text =  ((TermContext)_localctx).t.print_text + ((TermContext)_localctx).mul->getText() + ((TermContext)_localctx).una.print_text;
					          			if(((TermContext)_localctx).t.dataType == "float" || ((TermContext)_localctx).una.dataType == "float"){
					          				((TermContext)_localctx).dataType =  "float";
					          			} else {
					          				((TermContext)_localctx).dataType =  "int";
					          			}

					          			// // test
					          			// writeIntoparserLogFile(
					          			// 	string("test1 ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
					          			// );

					          			if(((TermContext)_localctx).mul->getText() == "%" && ((TermContext)_localctx).una.dataType != "int"){
					          				((TermContext)_localctx).dataType =  "int";
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


					          			if(((TermContext)_localctx).mul->getText() == "%" && ((TermContext)_localctx).una.print_text == "0"){
					          				((TermContext)_localctx).dataType =  "int";
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


					          			if(((TermContext)_localctx).mul->getText() == "/" && ((TermContext)_localctx).una.print_text == "0"){
					          				((TermContext)_localctx).dataType =  "int";
					          				writeIntoErrorFile(
					          					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
					          				);

					          				writeIntoparserLogFile(
					          					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
					          				);
					          				syntaxErrorCount++;
					          			}

					          			

					          			// if(((TermContext)_localctx).una.dataType == "FUNCTION" &&  ((TermContext)_localctx).una.symbol->getReturnType() == "void"){
					          			// 	writeIntoErrorFile(
					          			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
					          			// 	);

					          			// 	writeIntoparserLogFile(
					          			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
					          			// 	);
					          			// 	syntaxErrorCount++;
					          			// }



					          			writeIntoparserLogFile(
					          				_localctx.print_text + string("\n")
					          			);

					          			

					          			writeIntoCodeFile(
					          				string("\tPOP BX; term: term MULOP una") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
					          			);
					          			// Assuming all are correct Assembly code

					          			writeIntoCodeFile(
					          				string("\tPOP AX")
					          			);


					          				
					          			if(((TermContext)_localctx).mul->getText()== "*"){
					          				writeIntoCodeFile(
					          					string("\tMUL BX\n\tPUSH AX")
					          				);
					          			} else if(((TermContext)_localctx).mul->getText() == "/"){
					          				writeIntoCodeFile(
					          					string("\tXOR DX, DX\n\tDIV BX\n\tPUSH AX")
					          				);
					          			}	else if(((TermContext)_localctx).mul->getText() == "%") {
					          				writeIntoCodeFile(
					          					string("\tXOR DX, DX\n\tDIV BX\n\tPUSH DX")
					          				);
					          			}
					          			


					          			((TermContext)_localctx).symbol =  nullptr;

					          		
					          	 
					}
					} 
				}
				setState(405);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo* symbol;
		public Token addop;
		public Unary_expressionContext una;
		public Token not;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C2105046Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C2105046Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_unary_expression);
		try {
			setState(417);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(406);
				((Unary_expressionContext)_localctx).addop = match(ADDOP);
				setState(407);
				((Unary_expressionContext)_localctx).una = unary_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : ADDOP unary_expression\n")
							);
							((Unary_expressionContext)_localctx).print_text =  ((Unary_expressionContext)_localctx).addop->getText() + ((Unary_expressionContext)_localctx).una.print_text;


							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							((Unary_expressionContext)_localctx).dataType =  ((Unary_expressionContext)_localctx).una.dataType;
							((Unary_expressionContext)_localctx).symbol =  nullptr;

							
							if(((Unary_expressionContext)_localctx).addop->getText() == "-"){
								// if(((Unary_expressionContext)_localctx).una.symbol == nullptr){
									
								// } else {
										
								// 		SymbolInfo* symbol = ((Unary_expressionContext)_localctx).una.symbol;
								// 		if(symbol->getIsGlobal()){
								// 			writeIntoCodeFile(
								// 				string("\tMOV AX, ") + _localctx.symbol->getName() + string("; unary_expr : addop unary_expression")
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

							
							
						
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(410);
				((Unary_expressionContext)_localctx).not = match(NOT);
				setState(411);
				((Unary_expressionContext)_localctx).una = unary_expression();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : NOT unary_expression\n")
							);
							((Unary_expressionContext)_localctx).print_text =  ((Unary_expressionContext)_localctx).not->getText() + ((Unary_expressionContext)_localctx).una.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);

							((Unary_expressionContext)_localctx).dataType =  ((Unary_expressionContext)_localctx).una.dataType;
							((Unary_expressionContext)_localctx).symbol =  nullptr;

							string not_zero_label = getLabel();
							string done_label = getLabel();

							if(((Unary_expressionContext)_localctx).una.symbol == nullptr){
								writeIntoCodeFile(
									string("\tPOP AX")
								);
							} else {
								SymbolInfo* symbol = ((Unary_expressionContext)_localctx).una.symbol;
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
						 
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(414);
				((Unary_expressionContext)_localctx).f = factor();

							writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : factor\n")
							);

							writeIntoparserLogFile(
								((Unary_expressionContext)_localctx).f.print_text + string("\n")
							);
							
							((Unary_expressionContext)_localctx).print_text =  ((Unary_expressionContext)_localctx).f.print_text;
							((Unary_expressionContext)_localctx).dataType =  ((Unary_expressionContext)_localctx).f.dataType;
							((Unary_expressionContext)_localctx).isArray =  ((Unary_expressionContext)_localctx).f.isArray;
							((Unary_expressionContext)_localctx).symbol =  ((Unary_expressionContext)_localctx).f.symbol;
							// string msg = "false";
							// if(_localctx.isArray){
							// 	msg = "true";
							// }

							// writeIntoparserLogFile(
							// 	string("DEBUG UNA lexpr condition check: ") + msg
							// );
						 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public string print_text;
		public string dataType;
		public bool isArray;
		public SymbolInfo * symbol;
		public VariableContext v;
		public Token id;
		public Token lpr;
		public Argument_listContext arg_l;
		public Token rpr;
		public ExpressionContext expr;
		public Token ci;
		public Token cf;
		public VariableContext var;
		public Token incop;
		public Token decop;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105046Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105046Parser.LPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105046Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C2105046Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C2105046Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C2105046Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C2105046Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_factor);
		try {
			setState(445);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(419);
				((FactorContext)_localctx).v = variable();

						writeIntoparserLogFile(
				   			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable\n")
				  		);

						writeIntoparserLogFile(
							string(((FactorContext)_localctx).v.print_text) + string("\n")
						);

						((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).v.print_text;
						((FactorContext)_localctx).dataType =  ((FactorContext)_localctx).v.dataType;
						((FactorContext)_localctx).isArray =  ((FactorContext)_localctx).v.isArray;
						((FactorContext)_localctx).symbol =  ((FactorContext)_localctx).v.symbol;
						// string msg = "false";
						// if(_localctx.isArray){
						// 	msg = "true";
						// }

						// writeIntoparserLogFile(
						// 	string("DEBUG factor lexpr condition check: ") + msg
						// );
						
						

					
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(422);
				((FactorContext)_localctx).id = match(ID);
				setState(423);
				((FactorContext)_localctx).lpr = match(LPAREN);
				setState(424);
				((FactorContext)_localctx).arg_l = argument_list();
				setState(425);
				((FactorContext)_localctx).rpr = match(RPAREN);

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : ID LPAREN argument_list RPAREN\n")
						);
						((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).id->getText() + ((FactorContext)_localctx).lpr->getText() + ((FactorContext)_localctx).arg_l.print_text + ((FactorContext)_localctx).rpr->getText();
						
						string name = ((FactorContext)_localctx).id->getText();
						SymbolInfo* symbol = symbolTable.lookUp(name);
						if(symbol != nullptr){
							if(symbol->getDataType() == "FUNCTION"){
								vector<string>params = symbol->getParameters();
								// writeIntoparserLogFile(
								// 	string("DEBUG params size: ") + to_string(params.size()) + string(": arg_l argTypes size:  ") + to_string(((FactorContext)_localctx).arg_l.argTypes.size())
								// );
								if(params.size() == ((FactorContext)_localctx).arg_l.argTypes.size()){
									for(int i = 0; i < params.size(); i++){
										bool is_params_arr = false;
										string params_data_type = params[i];
										if(params[i].length() >= 2 && params[i].substr(params[i].length() - 2) == "[]"){
											is_params_arr = true;
											params_data_type = params[i].substr(0, params[i].length() - 2);
										}
										bool is_arg_arr = false;
										string arg_data_type = ((FactorContext)_localctx).arg_l.argTypes[i];
										
										if(((FactorContext)_localctx).arg_l.argTypes[i].length() >= 2 && ((FactorContext)_localctx).arg_l.argTypes[i].substr(((FactorContext)_localctx).arg_l.argTypes[i].length() - 2) == "[]"){
											is_arg_arr = true;
											arg_data_type = ((FactorContext)_localctx).arg_l.argTypes[i].substr(0, ((FactorContext)_localctx).arg_l.argTypes[i].length() - 2);
										}

										// writeIntoparserLogFile(
										// 	string("DEBUG params TYPE: ") + string(params_data_type) + string(": arg_l argTypes:  ") + string(arg_data_type)
										// );
										// writeIntoparserLogFile(
										// 	string("DEBUG params TYPE: ") + string(params[i]) + string(": arg_l argTypes:  ") + string(((FactorContext)_localctx).arg_l.argTypes[i])
										// );

										if(arg_data_type == params_data_type || (params_data_type == "float" && arg_data_type == "int")){
											if(is_arg_arr && is_arg_arr != is_params_arr){
												writeIntoErrorFile(
													string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + ((FactorContext)_localctx).arg_l.argNames[i] + string(" is an array\n")
												);
												writeIntoparserLogFile(
													string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + ((FactorContext)_localctx).arg_l.argNames[i] + string(" is an array\n")
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
												string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string(((FactorContext)_localctx).id->getText()) + string("\n")
											);
											writeIntoparserLogFile(
												string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string(((FactorContext)_localctx).id->getText()) + string("\n")
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
								((FactorContext)_localctx).dataType =  "FUNCTION";
							} else {
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
								);
								syntaxErrorCount++;
							}
							((FactorContext)_localctx).symbol =  symbol;
						} else {
							writeIntoErrorFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
							);
							((FactorContext)_localctx).dataType =  "invalid";
							syntaxErrorCount++;
						}

						writeIntoparserLogFile(
							_localctx.print_text + string("\n")
						);
						((FactorContext)_localctx).symbol =  nullptr;

						writeIntoCodeFile(
							string("\tCALL ") + name + string(" ; factor: function call") + string("Line ") + to_string(_input->LT(-1)->getLine()) +
							string("\n\tPUSH AX")
						);

					
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(428);
				((FactorContext)_localctx).lpr = match(LPAREN);
				setState(429);
				((FactorContext)_localctx).expr = expression(0);
				setState(430);
				((FactorContext)_localctx).rpr = match(RPAREN);

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : LPAREN expression RPAREN\n")
							);
							((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).lpr->getText() + ((FactorContext)_localctx).expr.print_text + ((FactorContext)_localctx).rpr->getText();
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((FactorContext)_localctx).isArray =  false;
							((FactorContext)_localctx).dataType =  ((FactorContext)_localctx).expr.dataType;
							((FactorContext)_localctx).symbol =  nullptr;
					
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(433);
				((FactorContext)_localctx).ci = match(CONST_INT);

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_INT\n")
							);
							((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).ci->getText();
							((FactorContext)_localctx).dataType =  "int";
							((FactorContext)_localctx).isArray =  false;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((FactorContext)_localctx).symbol =  nullptr;
							writeIntoCodeFile(
								string("\tPUSH ") + ((FactorContext)_localctx).ci->getText() +  string("; Line ") + to_string(_input->LT(-1)->getLine())
							);
					
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(435);
				((FactorContext)_localctx).cf = match(CONST_FLOAT);

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_FLOAT\n")
							);
							((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).cf->getText();
							((FactorContext)_localctx).dataType =  "float";
							((FactorContext)_localctx).isArray =  false;
							((FactorContext)_localctx).symbol =  nullptr;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							writeIntoCodeFile(
								string("\tPUSH ") + ((FactorContext)_localctx).cf->getText()
							);
					
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(437);
				((FactorContext)_localctx).var = variable();
				setState(438);
				((FactorContext)_localctx).incop = match(INCOP);

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable INCOP\n")
						);
						((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).var.print_text + ((FactorContext)_localctx).incop->getText();
						writeIntoparserLogFile(
							_localctx.print_text + string("\n")
						);

						SymbolInfo* symbol = ((FactorContext)_localctx).var.symbol;

						if(symbol){
							if(symbol->getIsGlobal()){
								if(symbol->getIsArray()){
									string actual_offset = to_string(2 * stoi(((FactorContext)_localctx).var.arr_ind));
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
									string actual_offset = to_string(stoi(offset) - 2 * stoi(((FactorContext)_localctx).var.arr_ind));
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
						((FactorContext)_localctx).symbol =  nullptr;
					
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(441);
				((FactorContext)_localctx).var = variable();
				setState(442);
				((FactorContext)_localctx).decop = match(DECOP);

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable DECOP\n")
						);
						((FactorContext)_localctx).print_text =  ((FactorContext)_localctx).var.print_text + ((FactorContext)_localctx).decop->getText();
						writeIntoparserLogFile(
							_localctx.print_text + string("\n")
						);
						SymbolInfo* symbol = ((FactorContext)_localctx).var.symbol;
						if(symbol){
							if(symbol->getIsGlobal()){
								if(symbol->getIsArray()){
									string actual_offset = to_string(2 * stoi(((FactorContext)_localctx).var.arr_ind));
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
									string actual_offset = to_string(stoi(offset) - 2 * stoi(((FactorContext)_localctx).var.arr_ind));
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
						((FactorContext)_localctx).symbol =  nullptr;
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public string print_text;
		public vector<string> argTypes;
		public vector<string> argNames;
		public ArgumentsContext args;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_argument_list);
		try {
			setState(451);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(447);
				((Argument_listContext)_localctx).args = arguments(0);

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : arguments\n")
							);
							((Argument_listContext)_localctx).print_text =  ((Argument_listContext)_localctx).args.print_text;
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
							);
							((Argument_listContext)_localctx).argTypes =  ((Argument_listContext)_localctx).args.argTypes;
							((Argument_listContext)_localctx).argNames =  ((Argument_listContext)_localctx).args.argNames;
					
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{

						writeIntoparserLogFile(
								string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : \n")
							);
							((Argument_listContext)_localctx).print_text =  "";
							writeIntoparserLogFile(
								_localctx.print_text + string("\n")
						);
					
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public string print_text;
		public vector<string> argTypes;
		public vector<string> argNames;
		public ArgumentsContext args;
		public Logic_expressionContext lexpr;
		public Token cm;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105046Parser.COMMA, 0); }
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 46;
		enterRecursionRule(_localctx, 46, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(454);
			((ArgumentsContext)_localctx).lexpr = logic_expression();

						writeIntoparserLogFile(
							string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : logic_expression\n")
						);
						((ArgumentsContext)_localctx).print_text =  ((ArgumentsContext)_localctx).lexpr.print_text;
						writeIntoparserLogFile(
							_localctx.print_text + string("\n")
						);
						
						if(((ArgumentsContext)_localctx).lexpr.isArray){
							_localctx.argTypes.push_back(((ArgumentsContext)_localctx).lexpr.dataType + "[]");
							// writeIntoparserLogFile(
							// 	string("DEBUG lexpr condition check true: ") 
							// );
						}	else {
							_localctx.argTypes.push_back(((ArgumentsContext)_localctx).lexpr.dataType);
							// writeIntoparserLogFile(
							// 	string("DEBUG lexpr condition check false: ") 
							// );
						}

						if(((ArgumentsContext)_localctx).lexpr.symbol == nullptr){
							_localctx.argNames.push_back("");
						}
						else {
							_localctx.argNames.push_back(((ArgumentsContext)_localctx).lexpr.symbol->getName());
						}

						writeIntoCodeFile(
							string("\t; pushing parameter into stack ") + ((ArgumentsContext)_localctx).lexpr.print_text + string("\n") 
						);
						
					  
			}
			_ctx.stop = _input.LT(-1);
			setState(464);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.args = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(457);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(458);
					((ArgumentsContext)_localctx).cm = match(COMMA);
					setState(459);
					((ArgumentsContext)_localctx).lexpr = logic_expression();

					          		writeIntoparserLogFile(
					          				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : arguments COMMA logic_expression\n")
					          			);
					          			((ArgumentsContext)_localctx).print_text =  ((ArgumentsContext)_localctx).args.print_text + ((ArgumentsContext)_localctx).cm->getText() + ((ArgumentsContext)_localctx).lexpr.print_text;
					          			writeIntoparserLogFile(
					          				_localctx.print_text + string("\n")
					          			);

					          			((ArgumentsContext)_localctx).argTypes =  ((ArgumentsContext)_localctx).args.argTypes;
					          			((ArgumentsContext)_localctx).argNames =  ((ArgumentsContext)_localctx).args.argNames;
					          			if(((ArgumentsContext)_localctx).lexpr.isArray){
					          				_localctx.argTypes.push_back(((ArgumentsContext)_localctx).lexpr.dataType + "[]");
					          				// writeIntoparserLogFile(
					          				// 	string("DEBUG lexpr condition check true: ") 
					          				// );
					          			}	else {
					          				_localctx.argTypes.push_back(((ArgumentsContext)_localctx).lexpr.dataType);
					          				// writeIntoparserLogFile(
					          				// 	string("DEBUG lexpr condition check false: ") 
					          				// );
					          			}

					          			if(((ArgumentsContext)_localctx).lexpr.symbol == nullptr){
					          				_localctx.argNames.push_back("");
					          			}
					          			else {
					          				_localctx.argNames.push_back(((ArgumentsContext)_localctx).lexpr.symbol->getName());
					          			}

					          			writeIntoCodeFile(
					          				string("\t; pushing parameter into stack\n") 
					          			);
					          	
					}
					} 
				}
				setState(466);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 10:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 11:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 15:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 18:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 19:
			return term_sempred((TermContext)_localctx, predIndex);
		case 23:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 9);
		case 2:
			return precpred(_ctx, 8);
		case 3:
			return precpred(_ctx, 7);
		case 4:
			return precpred(_ctx, 4);
		case 5:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 5);
		case 7:
			return precpred(_ctx, 4);
		case 8:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 11:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 13:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001#\u01d4\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001=\b\u0001"+
		"\n\u0001\f\u0001@\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002"+
		"K\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003"+
		"]\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004q\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005\u0086\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"\u00a5\b\u0005\n\u0005\f\u0005\u00a8\t\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006\u00b3\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0003\u0007\u00bf\b\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0003\t\u00c9\b\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00d3\b\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0005\n\u00e4\b\n\n\n\f\n\u00e7\t\n\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0005\u000b\u00f1\b\u000b\n\u000b\f\u000b\u00f4\t\u000b\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003"+
		"\f\u0135\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u013d"+
		"\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u0147\b\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u015a\b\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0005\u000f\u015f\b\u000f\n\u000f\f\u000f"+
		"\u0162\t\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0003\u0010\u016f\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u0179\b\u0011"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u0184\b\u0012\n\u0012"+
		"\f\u0012\u0187\t\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005\u0013"+
		"\u0192\b\u0013\n\u0013\f\u0013\u0195\t\u0013\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u01a2\b\u0014\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0003\u0015\u01be\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0003\u0016\u01c4\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0005"+
		"\u0017\u01cf\b\u0017\n\u0017\f\u0017\u01d2\t\u0017\u0001\u0017\u0000\b"+
		"\u0002\n\u0014\u0016\u001e$&.\u0018\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.\u0000\u0000"+
		"\u01ec\u00000\u0001\u0000\u0000\u0000\u00024\u0001\u0000\u0000\u0000\u0004"+
		"J\u0001\u0000\u0000\u0000\u0006\\\u0001\u0000\u0000\u0000\bp\u0001\u0000"+
		"\u0000\u0000\n\u0085\u0001\u0000\u0000\u0000\f\u00b2\u0001\u0000\u0000"+
		"\u0000\u000e\u00be\u0001\u0000\u0000\u0000\u0010\u00c0\u0001\u0000\u0000"+
		"\u0000\u0012\u00c8\u0001\u0000\u0000\u0000\u0014\u00d2\u0001\u0000\u0000"+
		"\u0000\u0016\u00e8\u0001\u0000\u0000\u0000\u0018\u0134\u0001\u0000\u0000"+
		"\u0000\u001a\u013c\u0001\u0000\u0000\u0000\u001c\u0146\u0001\u0000\u0000"+
		"\u0000\u001e\u0159\u0001\u0000\u0000\u0000 \u016e\u0001\u0000\u0000\u0000"+
		"\"\u0178\u0001\u0000\u0000\u0000$\u017a\u0001\u0000\u0000\u0000&\u0188"+
		"\u0001\u0000\u0000\u0000(\u01a1\u0001\u0000\u0000\u0000*\u01bd\u0001\u0000"+
		"\u0000\u0000,\u01c3\u0001\u0000\u0000\u0000.\u01c5\u0001\u0000\u0000\u0000"+
		"01\u0006\u0000\uffff\uffff\u000012\u0003\u0002\u0001\u000023\u0006\u0000"+
		"\uffff\uffff\u00003\u0001\u0001\u0000\u0000\u000045\u0006\u0001\uffff"+
		"\uffff\u000056\u0003\u0004\u0002\u000067\u0006\u0001\uffff\uffff\u0000"+
		"7>\u0001\u0000\u0000\u000089\n\u0002\u0000\u00009:\u0003\u0004\u0002\u0000"+
		":;\u0006\u0001\uffff\uffff\u0000;=\u0001\u0000\u0000\u0000<8\u0001\u0000"+
		"\u0000\u0000=@\u0001\u0000\u0000\u0000><\u0001\u0000\u0000\u0000>?\u0001"+
		"\u0000\u0000\u0000?\u0003\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000"+
		"\u0000AB\u0003\u000e\u0007\u0000BC\u0006\u0002\uffff\uffff\u0000CK\u0001"+
		"\u0000\u0000\u0000DE\u0003\u0006\u0003\u0000EF\u0006\u0002\uffff\uffff"+
		"\u0000FK\u0001\u0000\u0000\u0000GH\u0003\b\u0004\u0000HI\u0006\u0002\uffff"+
		"\uffff\u0000IK\u0001\u0000\u0000\u0000JA\u0001\u0000\u0000\u0000JD\u0001"+
		"\u0000\u0000\u0000JG\u0001\u0000\u0000\u0000K\u0005\u0001\u0000\u0000"+
		"\u0000LM\u0003\u0012\t\u0000MN\u0005 \u0000\u0000NO\u0005\u000f\u0000"+
		"\u0000OP\u0006\u0003\uffff\uffff\u0000PQ\u0003\n\u0005\u0000QR\u0005\u0010"+
		"\u0000\u0000RS\u0005\u0015\u0000\u0000ST\u0006\u0003\uffff\uffff\u0000"+
		"T]\u0001\u0000\u0000\u0000UV\u0003\u0012\t\u0000VW\u0005 \u0000\u0000"+
		"WX\u0005\u000f\u0000\u0000XY\u0005\u0010\u0000\u0000YZ\u0005\u0015\u0000"+
		"\u0000Z[\u0006\u0003\uffff\uffff\u0000[]\u0001\u0000\u0000\u0000\\L\u0001"+
		"\u0000\u0000\u0000\\U\u0001\u0000\u0000\u0000]\u0007\u0001\u0000\u0000"+
		"\u0000^_\u0003\u0012\t\u0000_`\u0005 \u0000\u0000`a\u0006\u0004\uffff"+
		"\uffff\u0000ab\u0005\u000f\u0000\u0000bc\u0003\n\u0005\u0000cd\u0006\u0004"+
		"\uffff\uffff\u0000de\u0005\u0010\u0000\u0000ef\u0003\f\u0006\u0000fg\u0006"+
		"\u0004\uffff\uffff\u0000gq\u0001\u0000\u0000\u0000hi\u0003\u0012\t\u0000"+
		"ij\u0005 \u0000\u0000jk\u0006\u0004\uffff\uffff\u0000kl\u0005\u000f\u0000"+
		"\u0000lm\u0005\u0010\u0000\u0000mn\u0003\f\u0006\u0000no\u0006\u0004\uffff"+
		"\uffff\u0000oq\u0001\u0000\u0000\u0000p^\u0001\u0000\u0000\u0000ph\u0001"+
		"\u0000\u0000\u0000q\t\u0001\u0000\u0000\u0000rs\u0006\u0005\uffff\uffff"+
		"\u0000st\u0003\u0012\t\u0000tu\u0005 \u0000\u0000uv\u0006\u0005\uffff"+
		"\uffff\u0000v\u0086\u0001\u0000\u0000\u0000wx\u0003\u0012\t\u0000xy\u0006"+
		"\u0005\uffff\uffff\u0000y\u0086\u0001\u0000\u0000\u0000z{\u0003\u0012"+
		"\t\u0000{|\u0005 \u0000\u0000|}\u0005\u0013\u0000\u0000}~\u0005\u0014"+
		"\u0000\u0000~\u007f\u0006\u0005\uffff\uffff\u0000\u007f\u0086\u0001\u0000"+
		"\u0000\u0000\u0080\u0081\u0003\u0012\t\u0000\u0081\u0082\u0005\u0013\u0000"+
		"\u0000\u0082\u0083\u0005\u0014\u0000\u0000\u0083\u0084\u0006\u0005\uffff"+
		"\uffff\u0000\u0084\u0086\u0001\u0000\u0000\u0000\u0085r\u0001\u0000\u0000"+
		"\u0000\u0085w\u0001\u0000\u0000\u0000\u0085z\u0001\u0000\u0000\u0000\u0085"+
		"\u0080\u0001\u0000\u0000\u0000\u0086\u00a6\u0001\u0000\u0000\u0000\u0087"+
		"\u0088\n\t\u0000\u0000\u0088\u0089\u0005\u0016\u0000\u0000\u0089\u008a"+
		"\u0003\u0012\t\u0000\u008a\u008b\u0005 \u0000\u0000\u008b\u008c\u0006"+
		"\u0005\uffff\uffff\u0000\u008c\u00a5\u0001\u0000\u0000\u0000\u008d\u008e"+
		"\n\b\u0000\u0000\u008e\u008f\u0005\u0016\u0000\u0000\u008f\u0090\u0003"+
		"\u0012\t\u0000\u0090\u0091\u0006\u0005\uffff\uffff\u0000\u0091\u00a5\u0001"+
		"\u0000\u0000\u0000\u0092\u0093\n\u0007\u0000\u0000\u0093\u0094\u0005\u0017"+
		"\u0000\u0000\u0094\u00a5\u0006\u0005\uffff\uffff\u0000\u0095\u0096\n\u0004"+
		"\u0000\u0000\u0096\u0097\u0005\u0016\u0000\u0000\u0097\u0098\u0003\u0012"+
		"\t\u0000\u0098\u0099\u0005 \u0000\u0000\u0099\u009a\u0005\u0013\u0000"+
		"\u0000\u009a\u009b\u0005\u0014\u0000\u0000\u009b\u009c\u0006\u0005\uffff"+
		"\uffff\u0000\u009c\u00a5\u0001\u0000\u0000\u0000\u009d\u009e\n\u0003\u0000"+
		"\u0000\u009e\u009f\u0005\u0016\u0000\u0000\u009f\u00a0\u0003\u0012\t\u0000"+
		"\u00a0\u00a1\u0005\u0013\u0000\u0000\u00a1\u00a2\u0005\u0014\u0000\u0000"+
		"\u00a2\u00a3\u0006\u0005\uffff\uffff\u0000\u00a3\u00a5\u0001\u0000\u0000"+
		"\u0000\u00a4\u0087\u0001\u0000\u0000\u0000\u00a4\u008d\u0001\u0000\u0000"+
		"\u0000\u00a4\u0092\u0001\u0000\u0000\u0000\u00a4\u0095\u0001\u0000\u0000"+
		"\u0000\u00a4\u009d\u0001\u0000\u0000\u0000\u00a5\u00a8\u0001\u0000\u0000"+
		"\u0000\u00a6\u00a4\u0001\u0000\u0000\u0000\u00a6\u00a7\u0001\u0000\u0000"+
		"\u0000\u00a7\u000b\u0001\u0000\u0000\u0000\u00a8\u00a6\u0001\u0000\u0000"+
		"\u0000\u00a9\u00aa\u0005\u0011\u0000\u0000\u00aa\u00ab\u0006\u0006\uffff"+
		"\uffff\u0000\u00ab\u00ac\u0003\u0016\u000b\u0000\u00ac\u00ad\u0005\u0012"+
		"\u0000\u0000\u00ad\u00ae\u0006\u0006\uffff\uffff\u0000\u00ae\u00b3\u0001"+
		"\u0000\u0000\u0000\u00af\u00b0\u0005\u0011\u0000\u0000\u00b0\u00b1\u0005"+
		"\u0012\u0000\u0000\u00b1\u00b3\u0006\u0006\uffff\uffff\u0000\u00b2\u00a9"+
		"\u0001\u0000\u0000\u0000\u00b2\u00af\u0001\u0000\u0000\u0000\u00b3\r\u0001"+
		"\u0000\u0000\u0000\u00b4\u00b5\u0003\u0012\t\u0000\u00b5\u00b6\u0003\u0014"+
		"\n\u0000\u00b6\u00b7\u0005\u0015\u0000\u0000\u00b7\u00b8\u0006\u0007\uffff"+
		"\uffff\u0000\u00b8\u00bf\u0001\u0000\u0000\u0000\u00b9\u00ba\u0003\u0012"+
		"\t\u0000\u00ba\u00bb\u0003\u0010\b\u0000\u00bb\u00bc\u0005\u0015\u0000"+
		"\u0000\u00bc\u00bd\u0006\u0007\uffff\uffff\u0000\u00bd\u00bf\u0001\u0000"+
		"\u0000\u0000\u00be\u00b4\u0001\u0000\u0000\u0000\u00be\u00b9\u0001\u0000"+
		"\u0000\u0000\u00bf\u000f\u0001\u0000\u0000\u0000\u00c0\u00c1\u0006\b\uffff"+
		"\uffff\u0000\u00c1\u0011\u0001\u0000\u0000\u0000\u00c2\u00c3\u0005\f\u0000"+
		"\u0000\u00c3\u00c9\u0006\t\uffff\uffff\u0000\u00c4\u00c5\u0005\r\u0000"+
		"\u0000\u00c5\u00c9\u0006\t\uffff\uffff\u0000\u00c6\u00c7\u0005\u000e\u0000"+
		"\u0000\u00c7\u00c9\u0006\t\uffff\uffff\u0000\u00c8\u00c2\u0001\u0000\u0000"+
		"\u0000\u00c8\u00c4\u0001\u0000\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000"+
		"\u0000\u00c9\u0013\u0001\u0000\u0000\u0000\u00ca\u00cb\u0006\n\uffff\uffff"+
		"\u0000\u00cb\u00cc\u0005 \u0000\u0000\u00cc\u00d3\u0006\n\uffff\uffff"+
		"\u0000\u00cd\u00ce\u0005 \u0000\u0000\u00ce\u00cf\u0005\u0013\u0000\u0000"+
		"\u00cf\u00d0\u0005!\u0000\u0000\u00d0\u00d1\u0005\u0014\u0000\u0000\u00d1"+
		"\u00d3\u0006\n\uffff\uffff\u0000\u00d2\u00ca\u0001\u0000\u0000\u0000\u00d2"+
		"\u00cd\u0001\u0000\u0000\u0000\u00d3\u00e5\u0001\u0000\u0000\u0000\u00d4"+
		"\u00d5\n\u0005\u0000\u0000\u00d5\u00d6\u0005\u0016\u0000\u0000\u00d6\u00d7"+
		"\u0005 \u0000\u0000\u00d7\u00e4\u0006\n\uffff\uffff\u0000\u00d8\u00d9"+
		"\n\u0004\u0000\u0000\u00d9\u00da\u0005\u0016\u0000\u0000\u00da\u00db\u0005"+
		" \u0000\u0000\u00db\u00dc\u0005\u0013\u0000\u0000\u00dc\u00dd\u0005!\u0000"+
		"\u0000\u00dd\u00de\u0005\u0014\u0000\u0000\u00de\u00e4\u0006\n\uffff\uffff"+
		"\u0000\u00df\u00e0\n\u0001\u0000\u0000\u00e0\u00e1\u0005\u0017\u0000\u0000"+
		"\u00e1\u00e2\u0005 \u0000\u0000\u00e2\u00e4\u0006\n\uffff\uffff\u0000"+
		"\u00e3\u00d4\u0001\u0000\u0000\u0000\u00e3\u00d8\u0001\u0000\u0000\u0000"+
		"\u00e3\u00df\u0001\u0000\u0000\u0000\u00e4\u00e7\u0001\u0000\u0000\u0000"+
		"\u00e5\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e6\u0001\u0000\u0000\u0000"+
		"\u00e6\u0015\u0001\u0000\u0000\u0000\u00e7\u00e5\u0001\u0000\u0000\u0000"+
		"\u00e8\u00e9\u0006\u000b\uffff\uffff\u0000\u00e9\u00ea\u0003\u0018\f\u0000"+
		"\u00ea\u00eb\u0006\u000b\uffff\uffff\u0000\u00eb\u00f2\u0001\u0000\u0000"+
		"\u0000\u00ec\u00ed\n\u0001\u0000\u0000\u00ed\u00ee\u0003\u0018\f\u0000"+
		"\u00ee\u00ef\u0006\u000b\uffff\uffff\u0000\u00ef\u00f1\u0001\u0000\u0000"+
		"\u0000\u00f0\u00ec\u0001\u0000\u0000\u0000\u00f1\u00f4\u0001\u0000\u0000"+
		"\u0000\u00f2\u00f0\u0001\u0000\u0000\u0000\u00f2\u00f3\u0001\u0000\u0000"+
		"\u0000\u00f3\u0017\u0001\u0000\u0000\u0000\u00f4\u00f2\u0001\u0000\u0000"+
		"\u0000\u00f5\u00f6\u0003\u000e\u0007\u0000\u00f6\u00f7\u0006\f\uffff\uffff"+
		"\u0000\u00f7\u0135\u0001\u0000\u0000\u0000\u00f8\u00f9\u0003\u001a\r\u0000"+
		"\u00f9\u00fa\u0006\f\uffff\uffff\u0000\u00fa\u0135\u0001\u0000\u0000\u0000"+
		"\u00fb\u00fc\u0003\f\u0006\u0000\u00fc\u00fd\u0006\f\uffff\uffff\u0000"+
		"\u00fd\u0135\u0001\u0000\u0000\u0000\u00fe\u00ff\u0005\u0007\u0000\u0000"+
		"\u00ff\u0100\u0006\f\uffff\uffff\u0000\u0100\u0101\u0005\u000f\u0000\u0000"+
		"\u0101\u0102\u0003\u001a\r\u0000\u0102\u0103\u0006\f\uffff\uffff\u0000"+
		"\u0103\u0104\u0003\u001a\r\u0000\u0104\u0105\u0006\f\uffff\uffff\u0000"+
		"\u0105\u0106\u0003\u001e\u000f\u0000\u0106\u0107\u0006\f\uffff\uffff\u0000"+
		"\u0107\u0108\u0005\u0010\u0000\u0000\u0108\u0109\u0003\u0018\f\u0000\u0109"+
		"\u010a\u0006\f\uffff\uffff\u0000\u010a\u0135\u0001\u0000\u0000\u0000\u010b"+
		"\u010c\u0005\u0005\u0000\u0000\u010c\u010d\u0006\f\uffff\uffff\u0000\u010d"+
		"\u010e\u0005\u000f\u0000\u0000\u010e\u010f\u0003\u001e\u000f\u0000\u010f"+
		"\u0110\u0005\u0010\u0000\u0000\u0110\u0111\u0006\f\uffff\uffff\u0000\u0111"+
		"\u0112\u0003\u0018\f\u0000\u0112\u0113\u0006\f\uffff\uffff\u0000\u0113"+
		"\u0135\u0001\u0000\u0000\u0000\u0114\u0115\u0005\u0005\u0000\u0000\u0115"+
		"\u0116\u0005\u000f\u0000\u0000\u0116\u0117\u0003\u001e\u000f\u0000\u0117"+
		"\u0118\u0005\u0010\u0000\u0000\u0118\u0119\u0006\f\uffff\uffff\u0000\u0119"+
		"\u011a\u0003\u0018\f\u0000\u011a\u011b\u0006\f\uffff\uffff\u0000\u011b"+
		"\u011c\u0005\u0006\u0000\u0000\u011c\u011d\u0006\f\uffff\uffff\u0000\u011d"+
		"\u011e\u0003\u0018\f\u0000\u011e\u011f\u0006\f\uffff\uffff\u0000\u011f"+
		"\u0135\u0001\u0000\u0000\u0000\u0120\u0121\u0005\b\u0000\u0000\u0121\u0122"+
		"\u0006\f\uffff\uffff\u0000\u0122\u0123\u0005\u000f\u0000\u0000\u0123\u0124"+
		"\u0003\u001e\u000f\u0000\u0124\u0125\u0005\u0010\u0000\u0000\u0125\u0126"+
		"\u0006\f\uffff\uffff\u0000\u0126\u0127\u0003\u0018\f\u0000\u0127\u0128"+
		"\u0006\f\uffff\uffff\u0000\u0128\u0135\u0001\u0000\u0000\u0000\u0129\u012a"+
		"\u0005\t\u0000\u0000\u012a\u012b\u0005\u000f\u0000\u0000\u012b\u012c\u0005"+
		" \u0000\u0000\u012c\u012d\u0005\u0010\u0000\u0000\u012d\u012e\u0005\u0015"+
		"\u0000\u0000\u012e\u0135\u0006\f\uffff\uffff\u0000\u012f\u0130\u0005\u000b"+
		"\u0000\u0000\u0130\u0131\u0003\u001e\u000f\u0000\u0131\u0132\u0005\u0015"+
		"\u0000\u0000\u0132\u0133\u0006\f\uffff\uffff\u0000\u0133\u0135\u0001\u0000"+
		"\u0000\u0000\u0134\u00f5\u0001\u0000\u0000\u0000\u0134\u00f8\u0001\u0000"+
		"\u0000\u0000\u0134\u00fb\u0001\u0000\u0000\u0000\u0134\u00fe\u0001\u0000"+
		"\u0000\u0000\u0134\u010b\u0001\u0000\u0000\u0000\u0134\u0114\u0001\u0000"+
		"\u0000\u0000\u0134\u0120\u0001\u0000\u0000\u0000\u0134\u0129\u0001\u0000"+
		"\u0000\u0000\u0134\u012f\u0001\u0000\u0000\u0000\u0135\u0019\u0001\u0000"+
		"\u0000\u0000\u0136\u0137\u0005\u0015\u0000\u0000\u0137\u013d\u0006\r\uffff"+
		"\uffff\u0000\u0138\u0139\u0003\u001e\u000f\u0000\u0139\u013a\u0005\u0015"+
		"\u0000\u0000\u013a\u013b\u0006\r\uffff\uffff\u0000\u013b\u013d\u0001\u0000"+
		"\u0000\u0000\u013c\u0136\u0001\u0000\u0000\u0000\u013c\u0138\u0001\u0000"+
		"\u0000\u0000\u013d\u001b\u0001\u0000\u0000\u0000\u013e\u013f\u0005 \u0000"+
		"\u0000\u013f\u0147\u0006\u000e\uffff\uffff\u0000\u0140\u0141\u0005 \u0000"+
		"\u0000\u0141\u0142\u0005\u0013\u0000\u0000\u0142\u0143\u0003\u001e\u000f"+
		"\u0000\u0143\u0144\u0005\u0014\u0000\u0000\u0144\u0145\u0006\u000e\uffff"+
		"\uffff\u0000\u0145\u0147\u0001\u0000\u0000\u0000\u0146\u013e\u0001\u0000"+
		"\u0000\u0000\u0146\u0140\u0001\u0000\u0000\u0000\u0147\u001d\u0001\u0000"+
		"\u0000\u0000\u0148\u0149\u0006\u000f\uffff\uffff\u0000\u0149\u014a\u0003"+
		"\u001c\u000e\u0000\u014a\u014b\u0005\u001f\u0000\u0000\u014b\u014c\u0003"+
		" \u0010\u0000\u014c\u014d\u0005\u0017\u0000\u0000\u014d\u014e\u0005\u001f"+
		"\u0000\u0000\u014e\u014f\u0003 \u0010\u0000\u014f\u0150\u0006\u000f\uffff"+
		"\uffff\u0000\u0150\u015a\u0001\u0000\u0000\u0000\u0151\u0152\u0003 \u0010"+
		"\u0000\u0152\u0153\u0006\u000f\uffff\uffff\u0000\u0153\u015a\u0001\u0000"+
		"\u0000\u0000\u0154\u0155\u0003\u001c\u000e\u0000\u0155\u0156\u0005\u001f"+
		"\u0000\u0000\u0156\u0157\u0003 \u0010\u0000\u0157\u0158\u0006\u000f\uffff"+
		"\uffff\u0000\u0158\u015a\u0001\u0000\u0000\u0000\u0159\u0148\u0001\u0000"+
		"\u0000\u0000\u0159\u0151\u0001\u0000\u0000\u0000\u0159\u0154\u0001\u0000"+
		"\u0000\u0000\u015a\u0160\u0001\u0000\u0000\u0000\u015b\u015c\n\u0001\u0000"+
		"\u0000\u015c\u015d\u0005#\u0000\u0000\u015d\u015f\u0006\u000f\uffff\uffff"+
		"\u0000\u015e\u015b\u0001\u0000\u0000\u0000\u015f\u0162\u0001\u0000\u0000"+
		"\u0000\u0160\u015e\u0001\u0000\u0000\u0000\u0160\u0161\u0001\u0000\u0000"+
		"\u0000\u0161\u001f\u0001\u0000\u0000\u0000\u0162\u0160\u0001\u0000\u0000"+
		"\u0000\u0163\u0164\u0003\"\u0011\u0000\u0164\u0165\u0006\u0010\uffff\uffff"+
		"\u0000\u0165\u016f\u0001\u0000\u0000\u0000\u0166\u0167\u0006\u0010\uffff"+
		"\uffff\u0000\u0167\u0168\u0003\"\u0011\u0000\u0168\u0169\u0006\u0010\uffff"+
		"\uffff\u0000\u0169\u016a\u0005\u001e\u0000\u0000\u016a\u016b\u0006\u0010"+
		"\uffff\uffff\u0000\u016b\u016c\u0003\"\u0011\u0000\u016c\u016d\u0006\u0010"+
		"\uffff\uffff\u0000\u016d\u016f\u0001\u0000\u0000\u0000\u016e\u0163\u0001"+
		"\u0000\u0000\u0000\u016e\u0166\u0001\u0000\u0000\u0000\u016f!\u0001\u0000"+
		"\u0000\u0000\u0170\u0171\u0003$\u0012\u0000\u0171\u0172\u0006\u0011\uffff"+
		"\uffff\u0000\u0172\u0179\u0001\u0000\u0000\u0000\u0173\u0174\u0003$\u0012"+
		"\u0000\u0174\u0175\u0005\u001d\u0000\u0000\u0175\u0176\u0003$\u0012\u0000"+
		"\u0176\u0177\u0006\u0011\uffff\uffff\u0000\u0177\u0179\u0001\u0000\u0000"+
		"\u0000\u0178\u0170\u0001\u0000\u0000\u0000\u0178\u0173\u0001\u0000\u0000"+
		"\u0000\u0179#\u0001\u0000\u0000\u0000\u017a\u017b\u0006\u0012\uffff\uffff"+
		"\u0000\u017b\u017c\u0003&\u0013\u0000\u017c\u017d\u0006\u0012\uffff\uffff"+
		"\u0000\u017d\u0185\u0001\u0000\u0000\u0000\u017e\u017f\n\u0001\u0000\u0000"+
		"\u017f\u0180\u0005\u0017\u0000\u0000\u0180\u0181\u0003&\u0013\u0000\u0181"+
		"\u0182\u0006\u0012\uffff\uffff\u0000\u0182\u0184\u0001\u0000\u0000\u0000"+
		"\u0183\u017e\u0001\u0000\u0000\u0000\u0184\u0187\u0001\u0000\u0000\u0000"+
		"\u0185\u0183\u0001\u0000\u0000\u0000\u0185\u0186\u0001\u0000\u0000\u0000"+
		"\u0186%\u0001\u0000\u0000\u0000\u0187\u0185\u0001\u0000\u0000\u0000\u0188"+
		"\u0189\u0006\u0013\uffff\uffff\u0000\u0189\u018a\u0003(\u0014\u0000\u018a"+
		"\u018b\u0006\u0013\uffff\uffff\u0000\u018b\u0193\u0001\u0000\u0000\u0000"+
		"\u018c\u018d\n\u0001\u0000\u0000\u018d\u018e\u0005\u0019\u0000\u0000\u018e"+
		"\u018f\u0003(\u0014\u0000\u018f\u0190\u0006\u0013\uffff\uffff\u0000\u0190"+
		"\u0192\u0001\u0000\u0000\u0000\u0191\u018c\u0001\u0000\u0000\u0000\u0192"+
		"\u0195\u0001\u0000\u0000\u0000\u0193\u0191\u0001\u0000\u0000\u0000\u0193"+
		"\u0194\u0001\u0000\u0000\u0000\u0194\'\u0001\u0000\u0000\u0000\u0195\u0193"+
		"\u0001\u0000\u0000\u0000\u0196\u0197\u0005\u0017\u0000\u0000\u0197\u0198"+
		"\u0003(\u0014\u0000\u0198\u0199\u0006\u0014\uffff\uffff\u0000\u0199\u01a2"+
		"\u0001\u0000\u0000\u0000\u019a\u019b\u0005\u001c\u0000\u0000\u019b\u019c"+
		"\u0003(\u0014\u0000\u019c\u019d\u0006\u0014\uffff\uffff\u0000\u019d\u01a2"+
		"\u0001\u0000\u0000\u0000\u019e\u019f\u0003*\u0015\u0000\u019f\u01a0\u0006"+
		"\u0014\uffff\uffff\u0000\u01a0\u01a2\u0001\u0000\u0000\u0000\u01a1\u0196"+
		"\u0001\u0000\u0000\u0000\u01a1\u019a\u0001\u0000\u0000\u0000\u01a1\u019e"+
		"\u0001\u0000\u0000\u0000\u01a2)\u0001\u0000\u0000\u0000\u01a3\u01a4\u0003"+
		"\u001c\u000e\u0000\u01a4\u01a5\u0006\u0015\uffff\uffff\u0000\u01a5\u01be"+
		"\u0001\u0000\u0000\u0000\u01a6\u01a7\u0005 \u0000\u0000\u01a7\u01a8\u0005"+
		"\u000f\u0000\u0000\u01a8\u01a9\u0003,\u0016\u0000\u01a9\u01aa\u0005\u0010"+
		"\u0000\u0000\u01aa\u01ab\u0006\u0015\uffff\uffff\u0000\u01ab\u01be\u0001"+
		"\u0000\u0000\u0000\u01ac\u01ad\u0005\u000f\u0000\u0000\u01ad\u01ae\u0003"+
		"\u001e\u000f\u0000\u01ae\u01af\u0005\u0010\u0000\u0000\u01af\u01b0\u0006"+
		"\u0015\uffff\uffff\u0000\u01b0\u01be\u0001\u0000\u0000\u0000\u01b1\u01b2"+
		"\u0005!\u0000\u0000\u01b2\u01be\u0006\u0015\uffff\uffff\u0000\u01b3\u01b4"+
		"\u0005\"\u0000\u0000\u01b4\u01be\u0006\u0015\uffff\uffff\u0000\u01b5\u01b6"+
		"\u0003\u001c\u000e\u0000\u01b6\u01b7\u0005\u001a\u0000\u0000\u01b7\u01b8"+
		"\u0006\u0015\uffff\uffff\u0000\u01b8\u01be\u0001\u0000\u0000\u0000\u01b9"+
		"\u01ba\u0003\u001c\u000e\u0000\u01ba\u01bb\u0005\u001b\u0000\u0000\u01bb"+
		"\u01bc\u0006\u0015\uffff\uffff\u0000\u01bc\u01be\u0001\u0000\u0000\u0000"+
		"\u01bd\u01a3\u0001\u0000\u0000\u0000\u01bd\u01a6\u0001\u0000\u0000\u0000"+
		"\u01bd\u01ac\u0001\u0000\u0000\u0000\u01bd\u01b1\u0001\u0000\u0000\u0000"+
		"\u01bd\u01b3\u0001\u0000\u0000\u0000\u01bd\u01b5\u0001\u0000\u0000\u0000"+
		"\u01bd\u01b9\u0001\u0000\u0000\u0000\u01be+\u0001\u0000\u0000\u0000\u01bf"+
		"\u01c0\u0003.\u0017\u0000\u01c0\u01c1\u0006\u0016\uffff\uffff\u0000\u01c1"+
		"\u01c4\u0001\u0000\u0000\u0000\u01c2\u01c4\u0006\u0016\uffff\uffff\u0000"+
		"\u01c3\u01bf\u0001\u0000\u0000\u0000\u01c3\u01c2\u0001\u0000\u0000\u0000"+
		"\u01c4-\u0001\u0000\u0000\u0000\u01c5\u01c6\u0006\u0017\uffff\uffff\u0000"+
		"\u01c6\u01c7\u0003 \u0010\u0000\u01c7\u01c8\u0006\u0017\uffff\uffff\u0000"+
		"\u01c8\u01d0\u0001\u0000\u0000\u0000\u01c9\u01ca\n\u0002\u0000\u0000\u01ca"+
		"\u01cb\u0005\u0016\u0000\u0000\u01cb\u01cc\u0003 \u0010\u0000\u01cc\u01cd"+
		"\u0006\u0017\uffff\uffff\u0000\u01cd\u01cf\u0001\u0000\u0000\u0000\u01ce"+
		"\u01c9\u0001\u0000\u0000\u0000\u01cf\u01d2\u0001\u0000\u0000\u0000\u01d0"+
		"\u01ce\u0001\u0000\u0000\u0000\u01d0\u01d1\u0001\u0000\u0000\u0000\u01d1"+
		"/\u0001\u0000\u0000\u0000\u01d2\u01d0\u0001\u0000\u0000\u0000\u001b>J"+
		"\\p\u0085\u00a4\u00a6\u00b2\u00be\u00c8\u00d2\u00e3\u00e5\u00f2\u0134"+
		"\u013c\u0146\u0159\u0160\u016e\u0178\u0185\u0193\u01a1\u01bd\u01c3\u01d0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}