/*#include <stdio.h>

int main() {
    int i=3;
    

    float note1=15;
    float note2=7;
    float note3=20;
    int n=-5;

    float moyenne=(note1+note2+note3)/i;
    printf("hello, world\n");
    printf("La moyenne des %d entiers est %f.%d \n", i, moyenne,n);
    return 0;
}   

*/

#include <stdio.h>
int main() {
double valeur = 10.0;
double *pv = &valeur;
int nombre = 1, *pn;
pn = &nombre;
valeur = *pv + *pn;
printf(" valeur = %f\n", valeur);
printf("&valeur = %p\n", &valeur);
printf("pv = %zu\n", pv.sizeof());
return 0;
}
