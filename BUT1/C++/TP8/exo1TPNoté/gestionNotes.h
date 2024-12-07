#ifndef GESTIONNOTES_H_INCLUDED
#define GESTIONNOTES_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
using namespace std;

///Proc�dure calcMoyenne
///calcule la moyenne de chaque case du vecteur 2D et enregistre le r�sultat dans la case correspondante du vecteur moyenne.
///Param�tres (D) notes: vecteur de vecteur d'entier
///           (D/R) moy : vecteur de r�els
void calcMoyenne(const vector<vector<int>> &notes , vector<float> & moy) ;

///Fonction invalide retourne bool�en
///prend en param�tre un
///entier et renvoie vrai si cet entier n�est pas �gal � une des constantes NBETUD,AFFICHEETUD, AFFICHENOTES, MOY, MAJOR ou QUIT
///Param�tres (D) c: entier
bool invalide(int c) ;

///Fonction affichageMenu retourne entier
///affichage du menu et demandande � l�utilisateur de saisir une valeur.
///Param�tres (D) x:entier
int affichageMenu(int x);


///Proc�dure affichageNotes
/// proc�dure affichant pour chaque �tudiant,la liste de ses notes.
///Param�tres (D) x: vecteur de vecteur d'entier
///           (D) y : vecteur de string
void affichageNotes(const vector<vector<int>> &x,const vector<string> &y);

///Proc�dure affichageMoyennes
///proc�dure affichant la moyenne de chaque �tudiant.
///Param�tres (D) x: vecteur de r�els
///           (D) y : vecteur de string
void affichageMoyennes (const vector<float> &x, const vector<string> &y);

///Fonction meilleurEtudiant retourne entier
///fonction retournant l�indice de l��tudiant ayant la meilleure moyenne.
///Param�tres (D) x : vecteur de r�els
int meilleurEtudiant (const vector<float> &x);


#endif // GESTIONNOTES_H_INCLUDED
