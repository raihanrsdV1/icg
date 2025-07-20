parser grammar C2105046Parser;

options {
    tokenVocab = C2105046Lexer;
}

@parser::header {
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

}

@parser::members {
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
}


start : {
		writeIntoCodeFile(
			string("; c to assembly conversion by Raihan RSD\n.MODEL SMALL\n.STACK 100H\n.CODE\n")
		);
		writeIntoTmpFile(
			string(".DATA\n\tCR EQU 0dh\n\tLF EQU 0ah \n\tnumber DB \"00000$\"")
		);
	}

 p=program
	{
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


	;

program returns [string print_text]
	: p=program u=unit 	{
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : program unit\n")
		);
		writeIntoparserLogFile(
			string($p.print_text) + string("\n") + string($u.print_text) + string("\n")
		);

		$print_text = $p.print_text + "\n" + $u.print_text;
	}
	| u=unit	{
		writeIntoparserLogFile(
  			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": program : unit\n")
  		);
		  writeIntoparserLogFile(
	 		string($u.print_text) + string("\n")
		);

		$print_text = $u.print_text;
		
	}
	;
	
unit returns [string print_text]
	: vd=var_declaration	{
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : var_declaration\n")
  	  	);	
		writeIntoparserLogFile(
			string($vd.print_text) + string("\n")
		);
		$print_text = $vd.print_text;
	}
     | f_dl=func_declaration	{
		  writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_declaration\n")
		  );

		  writeIntoparserLogFile(
			string($f_dl.print_text) + string("\n")
		  );

		$print_text = $f_dl.print_text;
	 }
     | f_def=func_definition	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unit : func_definition\n")
			);
			$print_text = $f_def.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
	 }
	 
     ;
     
func_declaration returns [string print_text]
		: ts=type_specifier id=ID LPAREN
		{
			inDeclaration = true;
		}
		pl=parameter_list RPAREN sm=SEMICOLON	{
			inDeclaration = false;
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n")
			);

			writeIntoparserLogFile(
				string($ts.text) + string(" ") + string($id->getText()) + string("(") + string($pl.print_text) + string(");\n")
			);

			$print_text = string($ts.text) + string(" ") + string($id->getText()) + string("(") + string($pl.print_text) + string(");");
			string name = string($id->getText());

			if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			} 
			SymbolInfo* symbol = symbolTable.lookUp(name);
			symbol->setIsDeclaredOnly(true);
			
			//SymbolInfo* symbol = symbolTable.lookUp(name);
			symbol->setParameters($pl.args, $ts.print_text);
		}
		| ts=type_specifier id=ID l_p=LPAREN r_p=RPAREN sm=SEMICOLON	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n")
			);

			writeIntoparserLogFile(
				string($ts.text) + string(" ") + string($id->getText()) + string("();\n")
			);

			$print_text = $ts.print_text + " " + $id->getText() + "()" + $sm->getText();
			string name = string($id->getText());
			if(!symbolTable.insert(name, "ID", nullptr, "FUNCTION")){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText()) + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			} 
			SymbolInfo* symbol = symbolTable.lookUp(name);
			symbol->setIsDeclaredOnly(true);
			symbol->setParameters(vector<string>(), $ts.print_text);
		}
		;
		 
func_definition returns [string print_text]
    : ts=type_specifier id=ID 
      {
		string name = string($id->getText());
		bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
		bool wasDeclared = false;
		SymbolInfo* symbol = symbolTable.lookUp(name);
		wasDeclared = symbol->getIsDeclaredOnly();
		if(!canInsert && !wasDeclared){
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText()) + string("\n")
			);
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
			);
			syntaxErrorCount++;
		}
		else {
			// SymbolInfo* symbol = symbolTable.lookUp(name);
			if(wasDeclared){
				if(symbol->getReturnType() != $ts.print_text){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string($id->getText()) + string("\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string($id->getText())+ string("\n")
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
		if($id->getText() == "main"){
			writeIntoCodeFile(
			string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
			);
		} else {
			writeIntoCodeFile(
			$id->getText() + 
			string(" PROC")
			);
		}

		writeIntoCodeFile(
			string("\tPUSH BP\n\tMOV BP, SP") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
		);

		string return_label = getLabel();

		current_return_label = return_label;

		scopeOffset.push_back(0);
      }
     lpr=LPAREN  pl=parameter_list {
		writeIntoCodeFile(
			string("; sotring parameter information in scope table")
		);
		scopeOffset.back() = -2;
		for(int i = $pl.vars.size() - 1; i >= 0; i--){ 
			scopeOffset.back() -= 2;
			SymbolInfo* symbol = symbolTable.lookUp($pl.vars[i]);
			symbol->setAsmData(scopeOffset.back(), false);
		}

		scopeOffset.back() = 0;

	 } rpr=RPAREN csm=compound_statement	{
		
		
        int param_count = $pl.vars.size();
		if(wasDeclared){
			if(symbol->getParameters().size() != $pl.args.size()){
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string($id->getText()) + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			}

		}
		if($csm.return_type != $ts.print_text){
			if($ts.print_text == "void" && !(($csm.return_type == "") || ($csm.return_type == "void"))){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string($id->getText()) + string(" with void return type \n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Cannot return value from function ") + string($id->getText())+ string(" with void return type \n")
				);
				syntaxErrorCount++;
			}
			else if(!($ts.print_text == "void" && $csm.return_type == "")){
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Return type mismatch in function ") + string($id->getText()) + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Return type mismatch in function ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			}
		}

		writeIntoparserLogFile(
            string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n")
        );
        $print_text = $ts.print_text + string(" ") + $id->getText() + $lpr->getText() + $pl.print_text + $rpr->getText() + $csm.print_text;
        writeIntoparserLogFile(
            $print_text + string("\n")
        );
		symbol->setParameters($pl.args, $ts.print_text);

		// Assembly Code 
		if($id->getText() == "main"){ 
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
			$id->getText() + string(" ENDP")
		);
		// scopeOffset.pop_back();
		
    }
    | ts=type_specifier id=ID 
      {
		string name = string($id->getText());
		bool canInsert = symbolTable.insert(name, "ID", nullptr,"FUNCTION");
		bool wasDeclared = false;
		SymbolInfo* symbol = symbolTable.lookUp(name);
		wasDeclared = symbol->getIsDeclaredOnly();
		if(!canInsert && !wasDeclared){
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText()) + string("\n")
			);
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
			);
			syntaxErrorCount++;
		}
		else {
			// SymbolInfo* symbol = symbolTable.lookUp(name);
			if(wasDeclared){
				if(symbol->getReturnType() != $ts.print_text){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string($id->getText()) + string("\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Return type mismatch of ") + string($id->getText())+ string("\n")
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
		if($id->getText() == "main"){
			writeIntoCodeFile(
			string("\nmain PROC\n\tMOV AX, @DATA\n\tMOV DS, AX")
			);
		} else {
			writeIntoCodeFile(
			$id->getText() + 
			string(" PROC")
			);
		}

		writeIntoCodeFile(
			string("\tPUSH BP\n\tMOV BP, SP") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
		);

		scopeOffset.push_back(0);

		string return_label = getLabel();

		current_return_label = return_label;

      }
      lpr=LPAREN rpr=RPAREN  csm=compound_statement	{
        

		if(wasDeclared){
			if(symbol->getParameters().size() > 0){
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string($id->getText()) + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Total number of arguments mismatch with declaration in function ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			}
		}

		if($csm.return_type != $ts.print_text){
			if($ts.print_text == "void" && !(($csm.return_type == "") || ($csm.return_type == "void"))){
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Cannot return value from function ") + string($id->getText()) + string(" with void return type\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Cannot return value from function ") + string($id->getText())+ string(" with void return type\n")
				);
				syntaxErrorCount++;
			}
			else if(!($ts.print_text == "void" && $csm.return_type == "")){
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Return type mismatch in function ") + string($id->getText()) + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": Return type mismatch in function ") + string($id->getText())+ string("\n")
				);
				syntaxErrorCount++;
			}
		}

		writeIntoparserLogFile(
            string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n")
        );
        $print_text = $ts.print_text + string(" ") + $id->getText() + $lpr->getText() + $rpr->getText() + $csm.print_text;

        writeIntoparserLogFile(
            $print_text + string("\n")
        );

		symbol->setParameters(vector<string>(), $ts.print_text);
		// Assembly Code 
		if($id->getText() == "main"){ 
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
			$id->getText() + string(" ENDP")
		);

		// scopeOffset.pop_back();

    }
    ;				


parameter_list  returns [string print_text, vector<string> args, vector<string> vars]
		: pl=parameter_list COMMA ts=type_specifier id=ID	{
			string name = $id->getText();
			if(!inDeclaration){
				if(!symbolTable.insert(name, "ID", nullptr, $ts.print_text)){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string(" in parameter\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string(" in parameter\n")
					);
					syntaxErrorCount++;
				}	else{
					$args = $pl.args;
					$args.push_back($ts.print_text);
				}
			} else {
				$args = $pl.args;
				$args.push_back($ts.print_text);
			}

			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
			);

			writeIntoparserLogFile(
				string($pl.print_text) + string(",") + string($ts.print_text) + string(" ") + string($id->getText()) + string("\n")
			);


			// writeIntoCodeFile(
			// 	string("\t; defining paramter into stack offset")
			// );

			// SymbolInfo* symbol = symbolTable.lookUp(name);
			// scopeOffset.back() -= 2;

			// symbol->setAsmData(scopeOffset.back(), false);

			$vars = $pl.vars;
			$vars.push_back(name);
			$print_text = $pl.print_text + "," + $ts.print_text + " " + $id->getText();

		}
		| pl=parameter_list cm=COMMA ts=type_specifier 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
			);
			$print_text = $pl.print_text + $cm->getText() + $ts.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$args = $pl.args;
			$args.push_back($ts.print_text);
		}
		| pl=parameter_list add_op=ADDOP 	{
			// syntax error handle rule
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
			);
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n")
			);
			$args = $pl.args;
			$print_text= $pl.print_text;
			syntaxErrorCount++;
		}
 		| ts=type_specifier id=ID		{
			
			string name = $id->getText();
			if(!inDeclaration){
				if(!symbolTable.insert(name, "ID", nullptr, $ts.print_text)){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string(" in parameter\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string(" in parameter\n")
					);
					syntaxErrorCount++;
				} else {
					$args.push_back($ts.print_text);
				}
			} else {
				
				$args.push_back($ts.print_text);
			}

			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
   		   );

		   writeIntoparserLogFile(
	  			string($ts.print_text) + string(" ") + string($id->getText()) + string("\n")
	 		);

			$print_text = $ts.print_text + " " + $id->getText();
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
			$vars.push_back(name);

		}
		| ts=type_specifier 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
			);
			$print_text = $ts.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$args.push_back($ts.print_text);
		}
		| pl=parameter_list COMMA ts=type_specifier id=ID LTHIRD RTHIRD	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier ID\n")
			);

			writeIntoparserLogFile(
				string($pl.print_text) + string(",") + string($ts.print_text) + string(" ") + string($id->getText()) + string("\n")
			);

			$print_text = $pl.print_text + "," + $ts.print_text + " " + $id->getText();
			string name = $id->getText();
			if(!inDeclaration){
				if(!symbolTable.insert(name, "ID", nullptr, $ts.print_text)){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
					);
					syntaxErrorCount++;
				}	else {
					$args = $pl.args;
					$args.push_back($ts.print_text + "[]");
					SymbolInfo* symbol = symbolTable.lookUp(name);
					symbol->setIsArray();
				}
			}

		}
		| pl=parameter_list cm=COMMA ts=type_specifier LTHIRD RTHIRD	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : parameter_list COMMA type_specifier\n")
			);
			$print_text = $pl.print_text + $cm->getText() + $ts.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$args = $pl.args;
			$args.push_back($ts.print_text + "[]");
		}
 		| ts=type_specifier id=ID LTHIRD RTHIRD	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier ID\n")
   		   );

		   writeIntoparserLogFile(
	  			string($ts.print_text) + string(" ") + string($id->getText()) + string("\n")
	 		);

			$print_text = $ts.print_text + " " + $id->getText();
			// symbolTable.enterScope();
			scoped = true;
			string name = $id->getText();
			if(!inDeclaration){
				if(!symbolTable.insert(name, "ID", nullptr, $ts.print_text)){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Multiple declaration of ") + string($id->getText())+ string("\n")
					);
					syntaxErrorCount++;
				} else {
					$args.push_back($ts.print_text + "[]");
					SymbolInfo* symbol = symbolTable.lookUp(name);
					symbol->setIsArray();
				}
			}

		}
		| ts=type_specifier LTHIRD RTHIRD	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": parameter_list : type_specifier\n")
			);
			$print_text = $ts.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$args.push_back($ts.print_text + "[]");
		}
 			;

 		
compound_statement returns [string print_text, string return_type]
		: lcl=LCURL		{
			if(!scoped){
				symbolTable.enterScope();
				scopeOffset.push_back(0);
			}
			scoped = false;

		} stms=statements rcl=RCURL	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL statements RCURL\n")
			);
			$print_text = $lcl->getText() + string("\n") + $stms.print_text + string("\n") + $rcl->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			symbolTable.printForParser();
			writeIntoparserLogFile(
				string("")
			);
			symbolTable.exitScope();
			$return_type = $stms.return_type;
		}
 		    | LCURL RCURL	{
				writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": compound_statement : LCURL RCURL\n")
			);
			$print_text = string("{}");

			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			symbolTable.printForParser();
			writeIntoparserLogFile(
				string("")
			);
			symbolTable.exitScope();
			scopeOffset.pop_back();
			$return_type = "void";
			}
 		    ;
 		    
var_declaration returns [string print_text]
    : ts=type_specifier dl=declaration_list sm=SEMICOLON {
        writeIntoparserLogFile(
			string("Line ") + to_string($sm->getLine()) + string(": var_declaration : type_specifier declaration_list SEMICOLON\n")
		);

		

		if($ts.print_text == "void"){
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void")  + string("\n")
			);
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable type cannot be void") + string("\n")
			);

			syntaxErrorCount++;
		}

		writeIntoparserLogFile(
			string($ts.print_text)+ string(" ") + string($dl.print_text) + string($sm->getText()) + string("\n")
		);
		$print_text = $ts.print_text + " " + $dl.print_text  + $sm->getText();

		for(int i = 0; i < $dl.ids.size(); i++){
			
			string str = $dl.ids[i];
			string actual_name = str;
			string length = $dl.id_size[i];
			bool isArray = false;

			
			// Check if the last 2 characters are "[]"
			if (str.length() >= 2 && str.substr(str.length() - 2) == "[]") {
				// It's an array - remove the "[]" to get actual name
				actual_name = str.substr(0, str.length() - 2);
				isArray = true;
			}
			
			// if(!symbolTable.insert(actual_name, "ID", nullptr, $ts.print_text, isArray)){
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


    | t=type_specifier de=declaration_list_err sm=SEMICOLON {
        writeIntoErrorFile(
            string("Line# ") + to_string($sm->getLine()) +
            " with error name: " + $de.error_name +
            " - Syntax error at declaration list of variable declaration"
        );

        syntaxErrorCount++;
      }
    ;

declaration_list_err returns [string error_name]: {
        $error_name = "Error in declaration list";
    };

 		 
type_specifier returns [string print_text]	
        : i=INT {
            writeIntoparserLogFile(
				string("Line ") + to_string($i->getLine()) + string(": type_specifier : INT\n")
			);

			writeIntoparserLogFile(
					string("int\n")
			);
			$print_text = $i->getText();
			

        }
 		| f=FLOAT {
            writeIntoparserLogFile(
				string("Line ") + to_string($f->getLine()) + string(": type_specifier : FLOAT\n")
			);

			writeIntoparserLogFile(
				string($f->getText()) + string("\n")
			);

			$print_text = $f->getText();
        }
 		| v=VOID {
            writeIntoparserLogFile(
				string("Line ") + to_string($v->getLine()) + string(": type_specifier : VOID\n")
			);

			writeIntoparserLogFile(
				string($v->getText()) + string("\n")
			);

			$print_text = $v->getText();
        }
 		;
 		
declaration_list returns [string print_text, vector<string> ids, vector<string> id_size]
	: d=declaration_list c=COMMA id=ID	{
			writeIntoparserLogFile(
				string("Line ") + to_string($id->getLine()) + string(": declaration_list : declaration_list COMMA ID\n")
			);

			$print_text = $d.print_text + $c->getText() + $id->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$ids = $d.ids;
			$ids.push_back($id->getText());
			// $ids.push_back(make_pair($id->getText(), false));
			$id_size = $d.id_size;
			$id_size.push_back("1");
			string name = $id->getText();
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
 		  | d=declaration_list c=COMMA id=ID third_brac=LTHIRD c_int=CONST_INT r_third=RTHIRD	{
			writeIntoparserLogFile(
	 			string("Line ") + to_string($id->getLine()) + string(": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n")
	   		);

			$print_text = $d.print_text + $c->getText() + $id->getText() + $third_brac->getText() + $c_int->getText() + $r_third->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$ids = $d.ids;
			$ids.push_back($id->getText() + "[]");
			// $ids.push_back(make_pair($id->getText(), true));
			$id_size = $d.id_size;
			$id_size.push_back($c_int->getText());
			
			string name = $id->getText();
			symbolTable.insert(name, "ID", nullptr, "int", true);
			SymbolInfo* symbol = symbolTable.lookUp(name);
			// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
			if(symbolTable.isMainScope()){
				symbol->setAsmData(0, true);
				symbol->setArrSize(stoi($c_int->getText()));
				writeIntoTmpFile(
					string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
				);
			} else {
				// local variables 
				scopeOffset.back() += stoi($c_int->getText()) * 2;
				symbol->setAsmData(scopeOffset.back(), false);
				symbol->setArrSize(stoi($c_int->getText()));
				string codeOffset = to_string(stoi($c_int->getText()) * 2);
				writeIntoCodeFile(
					string("\tSUB SP, ") + codeOffset
				);
			}
		  }
 		  | i=ID	{
			writeIntoparserLogFile(
				string("Line ") + to_string($i->getLine()) + string(": declaration_list : ID\n")
			);
			$print_text = $i->getText();
			writeIntoparserLogFile(
				string($i->getText()) + string("\n")
			);

			$ids.push_back($print_text);
			// $ids.push_back(make_pair($id->getText(), false));
			$id_size.push_back("1");

			string name = $i->getText();
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
 		  | i=ID l_t=LTHIRD c_i=CONST_INT r_t=RTHIRD	{
				writeIntoparserLogFile(
					string("Line ") + to_string($i->getLine()) + string(": declaration_list : ID LTHIRD CONST_INT RTHIRD\n")
				);

				$print_text = $i->getText() + $l_t->getText() + $c_i->getText() + $r_t->getText();
				writeIntoparserLogFile(
					string($i->getText()) + string($l_t->getText()) + string($c_i->getText()) + string($r_t->getText()) + string("\n")
				);

				$ids.push_back($i->getText() + "[]");
				// $ids.push_back(make_pair($id->getText(), true));
				$id_size.push_back($c_i->getText());

				string name = $i->getText();
				symbolTable.insert(name, "ID", nullptr, "int", true);
				SymbolInfo* symbol = symbolTable.lookUp(name);
				// SymbolInfo* symbol = symbolTable.lookUp(actual_name);
				if(symbolTable.isMainScope()){
					symbol->setAsmData(0, true);
					symbol->setArrSize(stoi($c_i->getText()));
					writeIntoTmpFile(
						string("\t") + symbol->getName() + string(" DW ") + to_string(symbol->getArrSize()) + (" DUP (0000h)\n")
					);
				} else {
					// local variables 
					scopeOffset.back() += stoi($c_i->getText()) * 2;
					symbol->setAsmData(scopeOffset.back(), false);
					symbol->setArrSize(stoi($c_i->getText()));
					string codeOffset = to_string(stoi($c_i->getText()) * 2);
					writeIntoCodeFile(
						string("\tSUB SP, ") + codeOffset
					);
				}
		  }
		  | dl=declaration_list add_op=ADDOP id=ID	{
				// syntax error handle
				writeIntoErrorFile(
					string("Error at line ") + to_string($id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
				);

				writeIntoparserLogFile(
					string("Error at line ") + to_string($id->getLine()) + string(": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n")
				);
				syntaxErrorCount++;

				$print_text = $dl.print_text;
				$ids = $dl.ids;
				// writeIntoparserLogFile(
				// 	string($i->getText()) + string($l_t->getText()) + string($c_i->getText()) + string($r_t->getText()) + string("\n")
				// );

				// $ids.push_back($i->getText() + "[]");
		  }
 		  ;


 		  
statements returns [string print_text, string return_type]
	: stm=statement	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statement\n")
			);
			$print_text = $stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = $stm.return_type;
	}
	   | stms=statements stm=statement	{
			if($stm.print_text != ""){
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statements : statements statement\n")
			);
			$print_text = $stms.print_text + string("\n") + $stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = $stm.return_type;
			}
			else {
				$print_text = $stms.print_text;
			}
	   }
	   ;
	   
statement returns [string print_text, string return_type]
		: vd=var_declaration	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : var_declaration\n")
			);
			$print_text = $vd.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";
		}
	  | expr_stm=expression_statement	{
			if($expr_stm.print_text != ""){
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : expression_statement\n")
			);
			$print_text = $expr_stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";
			}
			else {
				$print_text = "";
			}
	  }
	  | csm=compound_statement	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : compound_statement\n")
			);
			$print_text = $csm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";
	  }
	  | fr=FOR
	  {
		symbolTable.enterScope();
		scoped = true;
		string start_label = getLabel();
		string out_label = getLabel();
		string increment_step = getLabel();
		string inside_step = getLabel();
	  }
	  lpr=LPAREN expr_st1=expression_statement
	  {
		// pre comparison steps
		writeIntoCodeFile(
			start_label + string(":") + string("; Line ") + to_string(_input->LT(-1)->getLine())
		);
		pop_flag = false;
	  }
	  expr_st2=expression_statement {
		// post comparison happens here
		writeIntoCodeFile(
			string("\tPOP AX; comparision happens here (for loop starts up)\n\tCMP AX, 0\n\tJE ") + out_label +
			string("\n\tJMP ") + inside_step + string("\n") +
			increment_step + string(":") 
		);
	  }  expr=expression {
		writeIntoCodeFile(
			string("\tPOP AX; incrementing starts here\n\tJMP ") + start_label + string("\n") +
			inside_step + string(":; inside forloop step\n")
		);

	  }  rpr=RPAREN stm=statement	{
			// inside step for for
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n")
			);
			$print_text = $fr->getText() + $lpr->getText() + $expr_st1.print_text + $expr_st2.print_text + $expr.print_text + $rpr->getText() + $stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";

			writeIntoCodeFile(
				string("\tJMP ") + increment_step +
				string("\n") + out_label + string(": ; for loop ends here")
			);
	   }
	  | if=IF {

		string done_label = getLabel();
	  } lpr=LPAREN expr=expression rpr=RPAREN {

		// string done_label = getLabel();
		writeIntoCodeFile(
			string("\tPOP AX; only if condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
			+ string("\n\tCMP AX, 0\n\tJE ") + done_label
		);

	  } stm=statement	{
			writeIntoparserLogFile(
				string("Line ") + to_string($if->getLine()) + string(": statement : IF LPAREN expression RPAREN statement\n")
			);
			$print_text = $if->getText() + $lpr->getText() + $expr.print_text + $rpr->getText() + $stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";

			writeIntoCodeFile(
				done_label + string(":")
			);

	  }
	  | if=IF lpr=LPAREN expr=expression rpr=RPAREN {

		string else_label = getLabel();
		string done_label = getLabel();
		writeIntoCodeFile(
			string("\tPOP AX; if else condition") + string("Line ") + to_string(_input->LT(-1)->getLine())
			+ string("\n\tCMP AX, 0\n\tJE ") + else_label 
		);

	  } stm1=statement {

		writeIntoCodeFile(
			string("\tJMP ") + done_label
		);

	  } else=ELSE {
		writeIntoCodeFile(
			else_label + string(":")
		);
	  } stm2=statement	{ 
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : IF LPAREN expression RPAREN statement ELSE statement\n")
			);
			$print_text = $if->getText() + $lpr->getText() + $expr.print_text + $rpr->getText() + $stm1.print_text + $else->getText() + string(" ") + $stm2.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";
			
			writeIntoCodeFile(
				done_label + string(":")
			);
	  }
	  | while=WHILE {
		string start_label = getLabel();
		string out_label = getLabel();
		writeIntoCodeFile(
			start_label + string(": ; while loop starts") + string("Line ") + to_string(_input->LT(-1)->getLine())
		);
	  } lpr=LPAREN expr=expression rpr=RPAREN {
		writeIntoCodeFile(
			string("\tPOP AX\n\tCMP AX, 0\n\tJE ") + out_label
		);
	  } stm=statement	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : WHILE LPAREN expression RPAREN statement\n")
			);
			$print_text = $while->getText() + $lpr->getText() + $expr.print_text + $rpr->getText() + $stm.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = "void";

			writeIntoCodeFile(
				string("\tJMP ") + start_label 
				+ string("\n") + out_label + string(": ; while loop ends\n")
			);
	  }
	  | pln=PRINTLN lpr=LPAREN id=ID rpr=RPAREN sm=SEMICOLON	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n")
			);
			$print_text = $pln->getText() + $lpr->getText() + $id->getText() + $rpr->getText() + $sm->getText();
			string name = $id->getText();
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
				$print_text + string("\n")
			);
			$return_type = "void";

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
	  | ret=RETURN expr=expression sm=SEMICOLON	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": statement : RETURN expression SEMICOLON\n")
			);
			$print_text = $ret->getText() + string(" ") + $expr.print_text + $sm->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$return_type = $expr.dataType;
			writeIntoCodeFile(
				string("\tPOP AX; return statement written here") + string("; Line ") + to_string(_input->LT(-1)->getLine())
				+ string("\n\tJMP ") + current_return_label
			);
	  }

	  ;
	  
expression_statement 	returns [string print_text]
	: sm=SEMICOLON		{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : SEMICOLON\n")
			);
			$print_text = $sm->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
	 }	
		| expr=expression sm=SEMICOLON {
			if($expr.print_text != ""){
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression_statement : expression SEMICOLON\n")
			);
			$print_text = $expr.print_text + $sm->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			}
			else {
				$print_text = "";
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


	
			;
	  
variable returns [string print_text, string dataType, bool isArray, SymbolInfo * symbol, string arr_ind]
	: id=ID	{
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID\n")
		);
		string name = $id->getText();
		SymbolInfo* symbol = symbolTable.lookUp(name);
		$isArray = false;
		if(symbol == nullptr){
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
			);

			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undeclared variable ") + name + string("\n")
			);
			$dataType = "invalid";
			$symbol = nullptr;
			syntaxErrorCount++;
		} else {
			$dataType = symbol->getDataType();
			$isArray = symbol->getIsArray();
			$symbol = symbol;
			// string msg = "false";
			// if($isArray){
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

		$print_text = $id->getText();
		//$isArray = symbol->getIsArray();
		
		writeIntoparserLogFile(
   			string($id->getText()) + string("\n")
  		);
		
	

	}
	 | id=ID lthr=LTHIRD expr=expression rthr=RTHIRD {
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": variable : ID LTHIRD expression RTHIRD\n")
			);
			$print_text = $id->getText() + $lthr->getText() + $expr.print_text + $rthr->getText();
			$isArray = false;
			if($expr.dataType == "float"){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
				);

				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Expression inside third brackets not an integer\n")
				);
				syntaxErrorCount++;
			}
			

			string name = $id->getText();
			SymbolInfo* symbol = symbolTable.lookUp(name);

			if(symbol == nullptr){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
				);

				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Variable Not defined\n")
				);
				// $dataType = "invalid";
				$symbol = nullptr;
				syntaxErrorCount++;
			} else {
				if(!symbol->getIsArray()){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
					);

					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + name + string (" not an array\n")
					);
					$symbol = nullptr;
					syntaxErrorCount++;
				}
				$dataType = symbol->getDataType();
				$symbol = symbol;
				$arr_ind = $expr.print_text;

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
				$print_text + string("\n")
			);





			// $isArray = symbol->getIsArray();
				
			
	};
	 
expression returns [string print_text, string dataType]
 	: 
	variable ASSIGNOP logic_expression ADDOP ASSIGNOP logic_expression	{
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
			);
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": syntax error, unexpected ASSIGNOP\n")
			);
			$print_text = "";
			$dataType="";
			syntaxErrorCount++;
	   } |
	le=logic_expression	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : logic_expression\n")
			);
			$print_text = $le.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$dataType = $le.dataType;
 		}


	   | v=variable assop=ASSIGNOP le=logic_expression 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": expression : variable ASSIGNOP logic_expression\n")
			);
			$print_text = $v.print_text + $assop->getText() + $le.print_text;

			bool is_func = false;

			if($le.symbol != nullptr && $le.symbol->getDataType() == "FUNCTION"){
				is_func = true;
				// writeIntoparserLogFile(
				// 	string("DEBUG comes here ") 
				// );
			}
			
			if($v.dataType != $le.dataType && $v.dataType != "invalid" && $le.dataType != "invalid" && !is_func && !($v.dataType == "float" && $le.dataType == "int")){
				// writeIntoparserLogFile(
				// 	string("DEBUG Variable datatype: ") + string($v.dataType)+ string(" le dataType") + string($le.dataType) + string("\n")
				// );
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type Mismatch\n")
				);
				syntaxErrorCount++;
			}
			else if(is_func && $le.symbol->getReturnType() != $v.dataType ){
				// writeIntoparserLogFile(
				// 	string("DEBUG Variable FUNC: ") + string($v.dataType)+ string(" le dataType") + string($le.dataType) + string("\n")
				// );
				if($le.symbol->getReturnType() == "void"){
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
				$print_text + string("\n")
			);
			$dataType = $v.dataType;

			if($v.isArray && !$le.isArray){
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ $v.print_text + string(" is an array\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ")+ $v.print_text + string(" is an array\n")
				);
				syntaxErrorCount++;
			}

			// Assembly Code 
			SymbolInfo* symbol = $v.symbol;
			if(symbol){
				if(!symbol->getIsGlobal()){
					if(symbol->getIsArray()){
						string str_ind = $v.arr_ind;
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
						string str_ind = $v.arr_ind;
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
	   |
	 	 expression ic=INVALID_CHAR {
		writeIntoparserLogFile(
			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string($ic->getText()) + string("\n")
		);
		writeIntoErrorFile(
			string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Unrecognized character ") + string($ic->getText()) + string("\n")
		);
		// $print_text= "";
		syntaxErrorCount++;
	  }

	   
	   ;
			
logic_expression returns [string print_text, string dataType, bool isArray, SymbolInfo* symbol]
		: 
		re=rel_expression 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression\n")
			);
			$print_text = $re.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$dataType = $re.dataType;
			$isArray = $re.isArray;
			$symbol = $re.symbol;
			// string msg = "false";
			// if($isArray){
			// 	msg = "true";
			// }

			// writeIntoparserLogFile(
			// 	string("DEBUG logic lexpr condition check: ") + msg
			// );
 		}
		 | {
			string check_label = getLabel();
			string done_label = getLabel();
		 } re1=rel_expression	{


			writeIntoCodeFile(
				string("\tPOP AX; logic_expression : rel_expression LOGICOP rel_expression") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
			);


		 } lop=LOGICOP {
			if($lop->getText() == "||"){
				writeIntoCodeFile(
					string("\tCMP AX, 0\n\tJE ") + check_label + 
					string("\n\tPUSH 1\n\tJMP ") + done_label + string("\n") +
					check_label + string(": ; logical check label")
				);
			} else if($lop->getText() == "&&"){
				writeIntoCodeFile(
					string("\tCMP AX, 0\n\tJNE ") + check_label + 
					string("\n\tPUSH 0\n\tJMP ") + done_label + string("\n") +
					check_label + string(":; logical check label")
				);
			}
		 } re2=rel_expression 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": logic_expression : rel_expression LOGICOP rel_expression\n")
			);
			$print_text = $re1.print_text + $lop->getText() + $re2.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$dataType = $re1.dataType;
			$symbol = nullptr;

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
		 ;
			
rel_expression	returns [string print_text, string dataType, bool isArray, SymbolInfo* symbol]
	: se=simple_expression 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression\n")
			);
			$print_text = $se.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$dataType = $se.dataType;
			$isArray = $se.isArray;
			$symbol = $se.symbol;
			// string msg = "false";
			// if($isArray){
			// 	msg = "true";
			// }

			// writeIntoparserLogFile(
			// 	string("DEBUG rel lexpr condition check: ") + msg
			// );
		}
		| se1=simple_expression relop=RELOP se2=simple_expression		{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": rel_expression : simple_expression RELOP simple_expression\n")
			);
			$print_text = $se1.print_text + $relop->getText() + $se2.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$dataType = "int";
			$symbol = nullptr;

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
			if($relop->getText() == ">"){
				writeIntoCodeFile(
					string("\tJG ") + true_label
				);
			} else if($relop->getText() == ">="){
				writeIntoCodeFile(
					string("\tJGE ") + true_label
				);
			} else if($relop->getText() == "<="){
				writeIntoCodeFile(
					string("\tJLE ") + true_label
				);
			} else if($relop->getText() == "<"){
				writeIntoCodeFile(
					string("\tJL ") + true_label
				);
			} else if($relop->getText() == "!="){
				writeIntoCodeFile(
					string("\tJNE ") + true_label
				);
			} else if($relop->getText() == "=="){
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

		;
				
simple_expression returns [string print_text, string dataType, bool isArray, SymbolInfo* symbol]
			: t=term {
				writeIntoparserLogFile(
					string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : term\n")
				);
				$print_text = $t.print_text;
				writeIntoparserLogFile(
					$print_text + string("\n")
				);

				$dataType = $t.dataType;
				$isArray = $t.isArray;
				$symbol = $t.symbol;
				// string msg = "false";
				// if($isArray){
				// 	msg = "true";
				// }

				// writeIntoparserLogFile(
				// 	string("DEBUG simple lexpr condition check: ") + msg
				// );
			}
		  | se=simple_expression ao=ADDOP t=term {
				writeIntoparserLogFile(
					string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": simple_expression : simple_expression ADDOP term\n")
				);

				$print_text = $se.print_text + $ao->getText() + $t.print_text;
				writeIntoparserLogFile(
					$print_text + string("\n")
				);
				
				if($se.dataType == "int" && $t.dataType == "float"){
					writeIntoErrorFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
					);
					writeIntoparserLogFile(
						string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": invalid something something\n")
					);
					$dataType = "invalid";
					syntaxErrorCount++;
				}
				else if($se.dataType == "float" && $t.dataType == "int"){
					$dataType = "float";
				}
				else {
					$dataType = "int";
				}

				$symbol = nullptr;

				// Assembly codes

				writeIntoCodeFile(
					string("\tPOP BX ; simple expression: simple expression add op term") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
				);

				writeIntoCodeFile(
					string("\tPOP AX")
				);


				if($ao->getText() == "+"){
					writeIntoCodeFile(
						string("\tADD AX, BX\n\tPUSH AX")
					);
				} else if($ao->getText() == "-"){
					writeIntoCodeFile(
						string("\tSUB AX, BX\n\tPUSH AX")
					);
				}

				
		  }
		  ;
					
term 	returns [string print_text, string dataType, bool isArray, SymbolInfo* symbol]
	:	u=unary_expression	{
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : unary_expression\n")
		);

		writeIntoparserLogFile(
			$u.print_text + string("\n")
		);

		$print_text = $u.print_text;
		$dataType = $u.dataType;
		$isArray = $u.isArray;
		$symbol = $u.symbol;

		// string msg = "false";
		// if($isArray){
		// 	msg = "true";
		// }

		// writeIntoparserLogFile(
		// 	string("DEBUG term lexpr condition check: ") + msg
		// );

	}
     |  t=term mul=MULOP una=unary_expression	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
			);
			// bool invalid = false;
			$print_text = $t.print_text + $mul->getText() + $una.print_text;
			if($t.dataType == "float" || $una.dataType == "float"){
				$dataType = "float";
			} else {
				$dataType = "int";
			}

			// // test
			// writeIntoparserLogFile(
			// 	string("test1 ") + to_string(_input->LT(-1)->getLine()) + string(": term : term MULOP unary_expression\n")
			// );

			if($mul->getText() == "%" && $una.dataType != "int"){
				$dataType = "int";
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


			if($mul->getText() == "%" && $una.print_text == "0"){
				$dataType = "int";
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


			if($mul->getText() == "/" && $una.print_text == "0"){
				$dataType = "int";
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
				);

				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Divide by Zero\n")
				);
				syntaxErrorCount++;
			}

			

			// if($una.dataType == "FUNCTION" &&  $una.symbol->getReturnType() == "void"){
			// 	writeIntoErrorFile(
			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
			// 	);

			// 	writeIntoparserLogFile(
			// 		string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Void function used in expression\n")
			// 	);
			// 	syntaxErrorCount++;
			// }



			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			

			writeIntoCodeFile(
				string("\tPOP BX; term: term MULOP una") +  string("; Line ") + to_string(_input->LT(-1)->getLine())
			);
			// Assuming all are correct Assembly code

			writeIntoCodeFile(
				string("\tPOP AX")
			);


				
			if($mul->getText()== "*"){
				writeIntoCodeFile(
					string("\tMUL BX\n\tPUSH AX")
				);
			} else if($mul->getText() == "/"){
				writeIntoCodeFile(
					string("\tXOR DX, DX\n\tDIV BX\n\tPUSH AX")
				);
			}	else if($mul->getText() == "%") {
				writeIntoCodeFile(
					string("\tXOR DX, DX\n\tDIV BX\n\tPUSH DX")
				);
			}
			


			$symbol = nullptr;

		
	 }
     ;

unary_expression returns [string print_text, string dataType, bool isArray, SymbolInfo* symbol]
		: addop=ADDOP una=unary_expression  {
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : ADDOP unary_expression\n")
			);
			$print_text = $addop->getText() + $una.print_text;


			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$dataType = $una.dataType;
			$symbol = nullptr;

			
			if($addop->getText() == "-"){
				// if($una.symbol == nullptr){
					
				// } else {
						
				// 		SymbolInfo* symbol = $una.symbol;
				// 		if(symbol->getIsGlobal()){
				// 			writeIntoCodeFile(
				// 				string("\tMOV AX, ") + $symbol->getName() + string("; unary_expr : addop unary_expression")
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
		 | not=NOT una=unary_expression {
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : NOT unary_expression\n")
			);
			$print_text = $not->getText() + $una.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$dataType = $una.dataType;
			$symbol = nullptr;

			string not_zero_label = getLabel();
			string done_label = getLabel();

			if($una.symbol == nullptr){
				writeIntoCodeFile(
					string("\tPOP AX")
				);
			} else {
				SymbolInfo* symbol = $una.symbol;
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
		 | f=factor 	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": unary_expression : factor\n")
			);

			writeIntoparserLogFile(
				$f.print_text + string("\n")
			);
			
			$print_text = $f.print_text;
			$dataType = $f.dataType;
			$isArray = $f.isArray;
			$symbol = $f.symbol;
			// string msg = "false";
			// if($isArray){
			// 	msg = "true";
			// }

			// writeIntoparserLogFile(
			// 	string("DEBUG UNA lexpr condition check: ") + msg
			// );
		 }
		 ;
	
factor	returns [string print_text, string dataType, bool isArray, SymbolInfo * symbol]
	: v=variable 	{
		writeIntoparserLogFile(
   			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable\n")
  		);

		writeIntoparserLogFile(
			string($v.print_text) + string("\n")
		);

		$print_text = $v.print_text;
		$dataType = $v.dataType;
		$isArray = $v.isArray;
		$symbol = $v.symbol;
		// string msg = "false";
		// if($isArray){
		// 	msg = "true";
		// }

		// writeIntoparserLogFile(
		// 	string("DEBUG factor lexpr condition check: ") + msg
		// );
		
		

	}
	| id=ID lpr=LPAREN arg_l=argument_list rpr=RPAREN	{
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : ID LPAREN argument_list RPAREN\n")
		);
		$print_text = $id->getText() + $lpr->getText() + $arg_l.print_text + $rpr->getText();
		
		string name = $id->getText();
		SymbolInfo* symbol = symbolTable.lookUp(name);
		if(symbol != nullptr){
			if(symbol->getDataType() == "FUNCTION"){
				vector<string>params = symbol->getParameters();
				// writeIntoparserLogFile(
				// 	string("DEBUG params size: ") + to_string(params.size()) + string(": arg_l argTypes size:  ") + to_string($arg_l.argTypes.size())
				// );
				if(params.size() == $arg_l.argTypes.size()){
					for(int i = 0; i < params.size(); i++){
						bool is_params_arr = false;
						string params_data_type = params[i];
						if(params[i].length() >= 2 && params[i].substr(params[i].length() - 2) == "[]"){
							is_params_arr = true;
							params_data_type = params[i].substr(0, params[i].length() - 2);
						}
						bool is_arg_arr = false;
						string arg_data_type = $arg_l.argTypes[i];
						
						if($arg_l.argTypes[i].length() >= 2 && $arg_l.argTypes[i].substr($arg_l.argTypes[i].length() - 2) == "[]"){
							is_arg_arr = true;
							arg_data_type = $arg_l.argTypes[i].substr(0, $arg_l.argTypes[i].length() - 2);
						}

						// writeIntoparserLogFile(
						// 	string("DEBUG params TYPE: ") + string(params_data_type) + string(": arg_l argTypes:  ") + string(arg_data_type)
						// );
						// writeIntoparserLogFile(
						// 	string("DEBUG params TYPE: ") + string(params[i]) + string(": arg_l argTypes:  ") + string($arg_l.argTypes[i])
						// );

						if(arg_data_type == params_data_type || (params_data_type == "float" && arg_data_type == "int")){
							if(is_arg_arr && is_arg_arr != is_params_arr){
								writeIntoErrorFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + $arg_l.argNames[i] + string(" is an array\n")
								);
								writeIntoparserLogFile(
									string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Type mismatch, ") + $arg_l.argNames[i] + string(" is an array\n")
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
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string($id->getText()) + string("\n")
							);
							writeIntoparserLogFile(
								string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": ") + to_string(i + 1) + string("th argument mismatch in function ")  + string($id->getText()) + string("\n")
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
				$dataType = "FUNCTION";
			} else {
				writeIntoErrorFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
				);
				writeIntoparserLogFile(
					string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
				);
				syntaxErrorCount++;
			}
			$symbol = symbol;
		} else {
			writeIntoErrorFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
			);
			writeIntoparserLogFile(
				string("Error at line ") + to_string(_input->LT(-1)->getLine()) + string(": Undefined function ") + name + string("\n")
			);
			$dataType = "invalid";
			syntaxErrorCount++;
		}

		writeIntoparserLogFile(
			$print_text + string("\n")
		);
		$symbol = nullptr;

		writeIntoCodeFile(
			string("\tCALL ") + name + string(" ; factor: function call") + string("Line ") + to_string(_input->LT(-1)->getLine()) +
			string("\n\tPUSH AX")
		);

	}
	| lpr=LPAREN expr=expression rpr=RPAREN	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : LPAREN expression RPAREN\n")
			);
			$print_text = $lpr->getText() + $expr.print_text + $rpr->getText();
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$isArray = false;
			$dataType = $expr.dataType;
			$symbol = nullptr;
	}
	| ci=CONST_INT {
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_INT\n")
			);
			$print_text = $ci->getText();
			$dataType = "int";
			$isArray = false;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$symbol = nullptr;
			writeIntoCodeFile(
				string("\tPUSH ") + $ci->getText() +  string("; Line ") + to_string(_input->LT(-1)->getLine())
			);
	}
	| cf=CONST_FLOAT	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : CONST_FLOAT\n")
			);
			$print_text = $cf->getText();
			$dataType = "float";
			$isArray = false;
			$symbol = nullptr;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			writeIntoCodeFile(
				string("\tPUSH ") + $cf->getText()
			);
	}
	| var=variable incop=INCOP {
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable INCOP\n")
		);
		$print_text = $var.print_text + $incop->getText();
		writeIntoparserLogFile(
			$print_text + string("\n")
		);

		SymbolInfo* symbol = $var.symbol;

		if(symbol){
			if(symbol->getIsGlobal()){
				if(symbol->getIsArray()){
					string actual_offset = to_string(2 * stoi($var.arr_ind));
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
					string actual_offset = to_string(stoi(offset) - 2 * stoi($var.arr_ind));
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
		$symbol = nullptr;
	}
	| var=variable decop=DECOP {
		writeIntoparserLogFile(
			string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": factor : variable DECOP\n")
		);
		$print_text = $var.print_text + $decop->getText();
		writeIntoparserLogFile(
			$print_text + string("\n")
		);
		SymbolInfo* symbol = $var.symbol;
		if(symbol){
			if(symbol->getIsGlobal()){
				if(symbol->getIsArray()){
					string actual_offset = to_string(2 * stoi($var.arr_ind));
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
					string actual_offset = to_string(stoi(offset) - 2 * stoi($var.arr_ind));
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
		$symbol = nullptr;
	}
	;
	
argument_list returns [string print_text, vector<string> argTypes, vector<string> argNames]
	: args=arguments	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : arguments\n")
			);
			$print_text = $args.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			$argTypes = $args.argTypes;
			$argNames = $args.argNames;
	}
	|	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": argument_list : \n")
			);
			$print_text = "";
			writeIntoparserLogFile(
				$print_text + string("\n")
		);
	}
			  ;
	
arguments returns [string print_text, vector<string> argTypes, vector<string> argNames]
	: args=arguments cm=COMMA lexpr=logic_expression	{
		writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : arguments COMMA logic_expression\n")
			);
			$print_text = $args.print_text + $cm->getText() + $lexpr.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);

			$argTypes = $args.argTypes;
			$argNames = $args.argNames;
			if($lexpr.isArray){
				$argTypes.push_back($lexpr.dataType + "[]");
				// writeIntoparserLogFile(
				// 	string("DEBUG lexpr condition check true: ") 
				// );
			}	else {
				$argTypes.push_back($lexpr.dataType);
				// writeIntoparserLogFile(
				// 	string("DEBUG lexpr condition check false: ") 
				// );
			}

			if($lexpr.symbol == nullptr){
				$argNames.push_back("");
			}
			else {
				$argNames.push_back($lexpr.symbol->getName());
			}

			writeIntoCodeFile(
				string("\t; pushing parameter into stack\n") 
			);
	}
	      | lexpr=logic_expression	{
			writeIntoparserLogFile(
				string("Line ") + to_string(_input->LT(-1)->getLine()) + string(": arguments : logic_expression\n")
			);
			$print_text = $lexpr.print_text;
			writeIntoparserLogFile(
				$print_text + string("\n")
			);
			
			if($lexpr.isArray){
				$argTypes.push_back($lexpr.dataType + "[]");
				// writeIntoparserLogFile(
				// 	string("DEBUG lexpr condition check true: ") 
				// );
			}	else {
				$argTypes.push_back($lexpr.dataType);
				// writeIntoparserLogFile(
				// 	string("DEBUG lexpr condition check false: ") 
				// );
			}

			if($lexpr.symbol == nullptr){
				$argNames.push_back("");
			}
			else {
				$argNames.push_back($lexpr.symbol->getName());
			}

			writeIntoCodeFile(
				string("\t; pushing parameter into stack ") + $lexpr.print_text + string("\n") 
			);
			
		  }
	      ;
