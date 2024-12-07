#ifndef VECTEURS_H_INCLUDED
#define VECTEURS_H_INCLUDED

#include<vector>
#include<iostream>
#include <string>
using namespace std;

///Proc�dure affiche(v)
///affiche le contenu du vecteur v
///param�tre (D) v : vecteur de string
void affiche(const vector<string> &);

///Proc�dure normalisation(x)
///met en majuscule la string recu x
///param�tre  (D/R) x : string

void normalisation(string & x);

///Fonction recherche(x) retourne un entier
///recherche une personne dans le vecteur si elle est pr�sente retourner l'indice de la case ou elle est sinon retourner -1
///param�tre (D/R) x : vecteur de string
///          (D) :string

int recherche(const vector<string> &, string&);

///fonction remplacer(x) retourne bool�en
///remplace la personne par une autre si elle existe deja dans le vecteur et retourne vrai sinon retourne faux
///param�tre (D/R) x : vecteur de string
///          (D)


bool remplacer(vector<string> &,string ,string );



#endif // VECTEURS_H_INCLUDED
