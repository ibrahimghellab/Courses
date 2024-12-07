#include <iostream>
#include <vector>
#include"vecteurs.h"
#include <string>

using namespace std;

void affiche(const vector<string> & x){

   for (int i=0 ; i<x.size() ; i++)    {
        cout << x[i] << endl;
    }
}

void normalisation(vector<string> & x,int y){
    x[y]=toupper(x[y]);
}

