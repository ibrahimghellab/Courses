#include<iostream>
#include "calcul.h"

using namespace std;

///Fonction estPositif(x) retourne booléen
///retourne vrai si x est strictement positif faux sinon
///paramètre:(D)x:entier
bool estPositif (int x)
{
    return(x>0);
}

int factorielle(int x)
{
    int fact=1,i;
    for(i=x;i>=1;i--){
        fact=fact*i;
    }
    return(fact);
}

int somme(int x)
{
    int sommetemp=0,i;
    for(i=1;i<=x;i++){
        sommetemp=sommetemp+i;
    }
    return(sommetemp);
}

void diviseur(int x)
{
    int i;
    for(i=1;i<=x;i++){
        if(x%i==0){
            cout<<i<<";";
        }
    }
}
