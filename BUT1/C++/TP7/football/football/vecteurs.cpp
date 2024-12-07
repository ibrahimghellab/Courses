#include <iostream>
#include<string>
#include<vector>
#include "vecteurs.h"

using namespace std;

void affiche(const vector<string> & x )
{
    int i;
    cout << endl << endl << "affichage dans l'ordre " << endl ;
    for (i=0 ; i<x.size() ; i++)
    {
        cout << x[i] << endl;
    }
}
void normalisation(string & x)
{
    int l,j;
    l=x.length();
    for (int j=0 ; j<l; j++)
        x[j]=toupper(x[j]);
}

int recherche(const vector<string> & x, string & uneJoueuse)
{

    normalisation(uneJoueuse);

    int i=0;
    bool trouve = false ;
    while ( i<x.size() && ! trouve )
    {
        trouve = (x[i] == uneJoueuse) ;
        i++ ;
    }
    if ( !trouve )
        return(-1);
    else
        return(i-1);
}
bool remplacer(vector<string> & x, string y, string z){

if(recherche(x,y)>=0){

   x[recherche(x,y)]=z;




    return(true);

}else{
return(false);
}
}











