#ifndef FONCTIONFACEBOOK_H_INCLUDED
#define FONCTIONFACEBOOK_H_INCLUDED
#include<iostream>
#include<vector>
#include<string>

using namespace std;

///fonction initialisation retourne vecteur de vecteur de booléens
///initialise un vecteur de vecteur avec que des false sauf lorsque on est dans une case ou i=j, on met alors true
///paramètre (D) x:entier
vector<vector<bool>> initialisation (int x);

///procédure affichage
///affiche un vecteur de vecteur
///paramètre (D)x : vecteur de vecteur de booléens
void affichage (const vector<vector<bool>> &x);

///procédure ajoutAmis
///ajout des amis dans un vecteur de vecteur
///paramètres: (D/R) x:vecteur de vecteur de bolléens
///            (D) y:entier
///            (D) z:entier
void ajoutAmis(vector<vector<bool>>& x,int y, int z);

///fonction amisCommuns retourne entier
///retourne le nombre d'amis en commun entre 2 utilisateurs
///paramètres (D)x:vecteur de vecteur de booléens
///           (D)y:entier
///           (D)z:entier
int amisCommuns(const vector<vector<bool>> &x, int y, int z);

///fonction groupeAmis retourne booléen
///retourne vrai si 3 personnes forment un groupe d’amis où chacun est amis avec les deux autres et faux sinon.
///paramètres (D) reseau:vecteur de vecteurs de booléens
///           (D)a:entier
///           (D)b:entier
///           (D)c:entier

bool groupeAmis(const vector<vector<bool>> &reseau, int a, int b, int c);

#endif // FONCTIONFACEBOOK_H_INCLUDED
