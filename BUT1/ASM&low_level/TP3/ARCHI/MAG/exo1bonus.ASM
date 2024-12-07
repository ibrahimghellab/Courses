	;exo1

	LOAD_A #3
	LOAD_B #5
	LOAD_C_A 
	LOAD_A_B
	LOAD_B_C
	
	;exo2
	
		LOAD_A #5
		LOAD_B #4
boucle	JMPZ fin
		MUL_A_B
		DEC_B
		JMP boucle
		fin NOP
		
		
		LOAD_A #5
		LOAD_B #4
		MUL_A_B
		DEC_B
		JMPZ 3
		

	;écrire un programme qui charge 3 valeurs dans les registres A, B et C puis qui les trie dans l'ordre A<=B<=charge
	
		LOAD_A valeurs
		LOAD_B valeurs
		LOAD_C valeurs
		A


