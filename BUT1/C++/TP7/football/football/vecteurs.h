#ifndef VECTEURS_H_INCLUDED
#define VECTEURS_H_INCLUDED

#include<vector>
#include<iostream>
#include <string>
using namespace std;

///Procédure affiche(v)
///affiche le contenu du vecteur v
///paramètre (D) v : vecteur de string
void affiche(const vector<string> &);

///Procédure normalisation(x)
///met en majuscule la string recu x
///paramétre  (D/R) x : string

void normalisation(string & x);

///Fonction recherche(x) retourne un entier
///recherche une personne dans le vecteur si elle est présente retourner l'indice de la case ou elle est sinon retourner -1
///paramètre (D/R) x : vecteur de string
///          (D) :string

int recherche(const vector<string> &, string&);

///fonction remplacer(x) retourne booléen
///remplace la personne par une autre si elle existe deja dans le vecteur et retourne vrai sinon retourne faux
///paramètre (D/R) x : vecteur de string
///          (D)


bool remplacer(vector<string> &,string ,string );



#endif // VECTEURS_H_INCLUDED
