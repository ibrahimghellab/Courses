.DATA
 a REAL8 ?
 b REAL8 ?
 c REAL8 ?
 n REAL8 ?
 tmp REAL8 ?
.CODE
 polynome2double PROC
 ; la fonction appelante passe a dans RCX, b dans RDX,
 ; c dans R8 et n dans R9
 MOVSD a,XMM0
 MOVSD b,XMM1
 MOVSD c,XMM2
 MOVSD n,XMM3
 ; ici IMUL fait une multiplication enti�re sign�e de RAX
 ; (64 bits) par un autre registre ou une autre variable
 ; enti�re de 64 bits et stocke le r�sultat sur 128 bits dans
 ; RDX:RAX mais on supposera ici que le r�sultat tient sur
 ; 64 bits seulement (soit RAX)
 MOVSD XMM0,n
 MULSD XMM0,n ; calcul de n^2
 MULSD XMM0,a ; calcul de a*n^2
 MOVSD tmp,XMM0 ; stockage du r�sultat temporaire
 MOVSD XMM0,n
 MULSD XMM0,b ; calcul de b*n
 ADDSD XMM0,tmp ; calcul de a*n^2 + b*n
 ADDSD XMM0,c ; calcul de a*n^2 + b*n + c
 RET ; le r�sultat � retourner est dans RAX
 polynome2double ENDP
END 