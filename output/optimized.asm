.MODEL SMALL
.STACK 100H
.CODE
foo PROC
	PUSH BP
	MOV BP, SP
	MOV AX, [BP - -6]
	PUSH AX
	MOV AX, [BP - -4]
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	MOV AX, 5
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JLE L3
	PUSH 0
	JMP L4
L3:
	PUSH 1
L4:
	POP AX
	CMP AX, 0
	JE L2
	MOV AX, 7
	JMP L1
L2:
	MOV AX, [BP - -6]
	PUSH AX
	MOV AX, 2
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	MOV AX, [BP - -4]
	PUSH AX
	MOV AX, 1
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	CALL foo 
	PUSH AX
	MOV AX, 2
	PUSH AX
	MOV AX, [BP - -6]
	PUSH AX
	MOV AX, 1
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	MOV AX, [BP - -4]
	PUSH AX
	MOV AX, 2
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	CALL foo 
	PUSH AX
	POP BX
	POP AX
	IMUL BX
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	JMP L1
L1:
	MOV SP, BP
	POP BP
	RET 4
foo ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	MOV AX, 7
	MOV [BP - 2], AX
	MOV AX, 3
	MOV [BP - 4], AX
	MOV AX, [BP - 2]
	PUSH AX
	MOV AX, [BP - 4]
	PUSH AX
	CALL foo 
	MOV [BP - 6], AX
	MOV AX, [BP - 6] 
	CALL print_output
	CALL new_line
	MOV AX, 0
	JMP L5
L5:
	MOV SP, BP
	MOV AX, 4C00H
	INT 21H
main ENDP
    new_line proc
    	push ax
    	push dx
    	mov ah,2
    	mov dl,0Dh
    	int 21h
    	mov ah,2
    	mov dl,0Ah
    	int 21h
    	pop dx
    	pop ax
    	ret
    	new_line endp 
     print_output proc  
    	push ax
    	push bx
    	push cx
    	push dx
    	push si
    	lea si,number
    	mov bx,10
    	add si,4
    	cmp ax,0
    	jnge negate
    	print:
    	xor dx,dx
    	div bx
    	mov [si],dl
    	add [si],'0'
    	dec si
    	cmp ax,0
    	jne print
    	inc si
    	lea dx,si
    	mov ah,9
    	int 21h
    	pop si
    	pop dx
    	pop cx
    	pop bx
    	pop ax
    	ret
    	negate:
    	push ax
    	mov ah,2
    	mov dl,'-'
    	int 21h
    	pop ax
    	neg ax
    	jmp print
    	print_output endp
.DATA
	CR EQU 0dh
	LF EQU 0ah 
	number DB "00000$"
END MAIN
 
