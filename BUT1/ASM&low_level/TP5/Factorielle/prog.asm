.DATA
	n	QWORD ?

.CODE
	factoriel PROC
		MOV n,RCX
		MOV RAX,n
		boucle :
			DEC n
			JZ fin
			IMUL n
			JMP boucle
		fin :	
			RET
	factoriel ENDP
END 