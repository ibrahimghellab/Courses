#ifndef FONCTIONFACEBOOK_H_INCLUDED
#define FONCTIONFACEBOOK_H_INCLUDED
#include<iostream>
#include<vector>
#include<string>

using namespace std;

///fonction initialisation retourne vecteur de vecteur de bool�ens
///initialise un vecteur de vecteur avec que des false sauf lorsque on est dans une case ou i=j, on met alors true
///param�tre (D) x:entier
vector<vector<bool>> initialisation (int x);

///proc�dure affichage
///affiche un vecteur de vecteur
///param�tre (D)x : vecteur de vecteur de bool�ens
void affichage (const vector<vector<bool>> &x);

///proc�dure ajoutAmis
///ajout des amis dans un vecteur de vecteur
///param�tres: (D/R) x:vecteur de vecteur de boll�ens
///            (D) y:entier
///            (D) z:entier
void ajoutAmis(vector<vector<bool>>& x,int y, int z);

///fonction amisCommuns retourne entier
///retourne le nombre d'amis en commun entre 2 utilisateurs
///param�tres (D)x:vecteur de vecteur de bool�ens
///           (D)y:entier
///           (D)z:entier
int amisCommuns(const vector<vector<bool>> &x, int y, int z);

///fonction groupeAmis retourne bool�en
///retourne vrai si 3 personnes forment un groupe d�amis o� chacun est amis avec les deux autres et faux sinon.
///param�tres (D) reseau:vecteur de vecteurs de bool�ens
///           (D)a:entier
///           (D)b:entier
///           (D)c:entier

bool groupeAmis(const vector<vector<bool>> &reseau, int a, int b, int c);

#endif // FONCTIONFACEBOOK_H_INCLUDED
