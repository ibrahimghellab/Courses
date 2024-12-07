#ifndef GESTIONNOTES_H_INCLUDED
#define GESTIONNOTES_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
using namespace std;

///Procédure calcMoyenne
///calcule la moyenne de chaque case du vecteur 2D et enregistre le résultat dans la case correspondante du vecteur moyenne.
///Paramètres (D) notes: vecteur de vecteur d'entier
///           (D/R) moy : vecteur de réels
void calcMoyenne(const vector<vector<int>> &notes , vector<float> & moy) ;

///Fonction invalide retourne booléen
///prend en paramètre un
///entier et renvoie vrai si cet entier n’est pas égal à une des constantes NBETUD,AFFICHEETUD, AFFICHENOTES, MOY, MAJOR ou QUIT
///Paramètres (D) c: entier
bool invalide(int c) ;

///Fonction affichageMenu retourne entier
///affichage du menu et demandande à l’utilisateur de saisir une valeur.
///Paramètres (D) x:entier
int affichageMenu(int x);


///Procédure affichageNotes
/// procédure affichant pour chaque étudiant,la liste de ses notes.
///Paramètres (D) x: vecteur de vecteur d'entier
///           (D) y : vecteur de string
void affichageNotes(const vector<vector<int>> &x,const vector<string> &y);

///Procédure affichageMoyennes
///procédure affichant la moyenne de chaque étudiant.
///Paramètres (D) x: vecteur de réels
///           (D) y : vecteur de string
void affichageMoyennes (const vector<float> &x, const vector<string> &y);

///Fonction meilleurEtudiant retourne entier
///fonction retournant l’indice de l’étudiant ayant la meilleure moyenne.
///Paramètres (D) x : vecteur de réels
int meilleurEtudiant (const vector<float> &x);


#endif // GESTIONNOTES_H_INCLUDED
