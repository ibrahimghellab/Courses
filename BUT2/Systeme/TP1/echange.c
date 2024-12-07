#include <stdio.h>
void echange1(float a, float b) {
    float temp = a;
    a = b;
    b = temp;
}
void echange2(float *a,float *b){

    float temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    float pi = 2.71828, e = 3.14159;
    printf("Avant echange : pi = %.2f, e = %.2f.\n",pi,e);
    echange2(&pi,&e);
    printf("Apres echange : pi = %.2f, e = %.2f.\n",pi,e);
    return 0;
}