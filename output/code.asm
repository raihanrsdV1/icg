; c to assembly conversion by Raihan RSD
.MODEL SMALL
.STACK 100H
.CODE

fact PROC
	PUSH BP
	MOV BP, SP; Line 1
; sotring parameter information in scope table
	MOV AX, [BP - -4]
	PUSH AX; var push
	MOV AX, 0; Line 2
	PUSH AX
	POP BX; rel_expr: simple_expr relop simple_expr; Line 2
	POP AX
	CMP AX, BX
	JE L3
	PUSH 0
	JMP L4
L3:
	PUSH 1
L4:

	POP AX; only if conditionLine 2
	CMP AX, 0
	JE L2
	MOV AX, 1; Line 3
	PUSH AX
	POP AX; return statement written here; Line 3
	JMP L1
L2:
	MOV AX, [BP - -4]
	PUSH AX; var push
	MOV AX, 1; Line 5
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 5
	POP AX
	SUB AX, BX
	PUSH AX
	; pushing parameter into stack n-1

	CALL fact ; factor: function callLine 5
	PUSH AX
	MOV AX, [BP - -4]
	PUSH AX; var push
	POP BX; term: term MULOP una; Line 5
	POP AX
	IMUL BX
	PUSH AX
	POP AX; return statement written here; Line 5
	JMP L1
L1:
	MOV SP, BP
	POP BP
	RET 2
fact ENDP
foo PROC
	PUSH BP
	MOV BP, SP; Line 12
; sotring parameter information in scope table
	MOV AX, [BP - -6]
	PUSH AX; var push
	MOV AX, [BP - -4]
	PUSH AX; var push
	POP BX ; simple expression: simple expression add op term; Line 13
	POP AX
	ADD AX, BX
	PUSH AX
	MOV AX, 5; Line 13
	PUSH AX
	POP BX; rel_expr: simple_expr relop simple_expr; Line 13
	POP AX
	CMP AX, BX
	JLE L7
	PUSH 0
	JMP L8
L7:
	PUSH 1
L8:

	POP AX; only if conditionLine 13
	CMP AX, 0
	JE L6
	MOV AX, 7; Line 14
	PUSH AX
	POP AX; return statement written here; Line 14
	JMP L5
L6:
	MOV AX, [BP - -6]
	PUSH AX; var push
	MOV AX, 2; Line 16
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 16
	POP AX
	SUB AX, BX
	PUSH AX
	; pushing parameter into stack a-2

	MOV AX, [BP - -4]
	PUSH AX; var push
	MOV AX, 1; Line 16
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 16
	POP AX
	SUB AX, BX
	PUSH AX
	; pushing parameter into stack

	CALL foo ; factor: function callLine 16
	PUSH AX
	MOV AX, 2; Line 16
	PUSH AX
	MOV AX, [BP - -6]
	PUSH AX; var push
	MOV AX, 1; Line 16
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 16
	POP AX
	SUB AX, BX
	PUSH AX
	; pushing parameter into stack a-1

	MOV AX, [BP - -4]
	PUSH AX; var push
	MOV AX, 2; Line 16
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 16
	POP AX
	SUB AX, BX
	PUSH AX
	; pushing parameter into stack

	CALL foo ; factor: function callLine 16
	PUSH AX
	POP BX; term: term MULOP una; Line 16
	POP AX
	IMUL BX
	PUSH AX
	POP BX ; simple expression: simple expression add op term; Line 16
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX; return statement written here; Line 16
	JMP L5
L5:
	MOV SP, BP
	POP BP
	RET 4
foo ENDP
h PROC
	PUSH BP
	MOV BP, SP; Line 21
	SUB SP, 2
	MOV AX, 22; Line 23
	PUSH AX
	POP AX
	MOV [BP - 2], AX
	PUSH AX; expression push
	; comes to expression_statement
	POP AX; expression_statement pop
	MOV AX, [BP - 2] ; print function call from here
	CALL print_output
	CALL new_line
L9:
	MOV SP, BP
	POP BP
	RET 
h ENDP
g PROC
	PUSH BP
	MOV BP, SP; Line 27
L10:
	MOV SP, BP
	POP BP
	RET 
g ENDP
gg PROC
	PUSH BP
	MOV BP, SP; Line 31
; sotring parameter information in scope table
	MOV AX, [BP - -6]
	PUSH AX; var push
	MOV AX, [BP - -4]
	PUSH AX; var push
	POP BX; term: term MULOP una; Line 32
	POP AX
	CWD
	IDIV BX
	PUSH DX
	POP AX; return statement written here; Line 32
	JMP L11
L11:
	MOV SP, BP
	POP BP
	RET 4
gg ENDP
hh PROC
	PUSH BP
	MOV BP, SP; Line 35
	MOV AX, 0; Line 36
	PUSH AX
	POP AX
	MOV i, AX
	PUSH AX; expression push
	; comes to expression_statement
	POP AX; expression_statement pop
L13:; Line 36
	MOV AX, i
	PUSH AX; var push
	MOV AX, 5; Line 36
	PUSH AX
	POP BX; rel_expr: simple_expr relop simple_expr; Line 36
	POP AX
	CMP AX, BX
	JLE L17
	PUSH 0
	JMP L18
L17:
	PUSH 1
L18:

	; comes to expression_statement
	POP AX; comparision happens here (for loop starts up)
	CMP AX, 0
	JE L14
	JMP L16
L15:
	MOV AX, i; var inc
	PUSH AX
	ADD AX, 1
	MOV i, AX

	POP AX; incrementing starts here
	JMP L13
L16:; inside forloop step

	MOV AX, i
	PUSH AX; var push
	MOV AX, 101; Line 37
	PUSH AX
	MOV AX, i
	PUSH AX; var push
	POP BX ; simple expression: simple expression add op term; Line 37
	POP AX
	ADD AX, BX
	PUSH AX
