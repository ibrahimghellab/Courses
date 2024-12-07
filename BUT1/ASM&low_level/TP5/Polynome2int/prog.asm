.DATA
 a QWORD ?
 b QWORD ?
 c QWORD ?
 n QWORD ?
 tmp QWORD ?
.CODE
 polynome2int PROC
 ; la fonction appelante passe a dans RCX, b dans RDX,
 ; c dans R8 et n dans R9
 MOV a,RCX
 MOV b,RDX
 MOV c,R8
 MOV n,R9
 ; ici IMUL fait une multiplication enti�re sign�e de RAX
 ; (64 bits) par un autre registre ou une autre variable
 ; enti�re de 64 bits et stocke le r�sultat sur 128 bits dans
 ; RDX:RAX mais on supposera ici que le r�sultat tient sur
 ; 64 bits seulement (soit RAX)
 MOV RAX,n
 IMUL n ; calcul de n^2
 IMUL a ; calcul de a*n^2
 MOV tmp,RAX ; stockage du r�sultat temporaire
 MOV RAX,n
 IMUL b ; calcul de b*n
 ADD RAX,tmp ; calcul de a*n^2 + b*n
 ADD RAX,c ; calcul de a*n^2 + b*n + c
 RET ; le r�sultat � retourner est dans RAX
 polynome2int ENDP
END 