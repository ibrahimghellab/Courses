/// TP recherche, R101-2 2023-2024
/// promotion.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include "etudiant.h"
#include "promotion.h"

using namespace std;

/// Affichage d'une promotion compl�te.
void Promotion::afficher()const
{
    int nbEtudiants = _promo.size();
    cout << "\nPromo " << _nom << " de " << nbEtudiants << " etudiants : " << endl;
    for (int i=0 ; i<nbEtudiants ; i++)
    {
        cout << "("<< i << ")  ";
        _promo[i].afficher();
    }
    cout << endl;
}

/// Affiche la promo entre indices d�b et fin.
/// Propage exception d�clench�e par at() si indice invalide.
void Promotion::afficherBornes(int deb, int fin)const
{
    for (int i=deb ; i<= fin ; i++)
    {
        cout << "("<< i << ")  ";
        _promo.at(i).afficher(); /// at(i) lance exception si indice invalide
    }
    cout << endl;
}

/// Retourne l'�tudiant en position ind du vecteur.
/// Propage exception d�clench�e par at() si indice invalide.
Etudiant Promotion::getEtud(int ind) const
{
    return(_promo.at(ind)); /// at(i) lance exception si indice invalide
}

/// Initialisation d'une promotion par lecture d'un fichier.
/// D�clenche exception chaine si erreur fichier.
/// Contenu fichier : 1�re info = nom promo, puis nom, pr�nom, groupe, num de chaque �tudiant.
void Promotion::init(const string & ficEtudiants)
{
    /// les infos dans le fichier
    string nom;
    string prenom;
    string groupe;
    int num;

    /// parcours du fichier
    ifstream ific(ficEtudiants.c_str(), ios::in); /// ouvrir le fichier en lecture
    if(!ific.is_open())   /// si pb ouverture
        throw string ("l'ouverture du fichier a echoue : " + ficEtudiants);
    ific >> _nom; /// 1�re info lue est le nom de la promo, par ex. S1
    while(!ific.eof()) /// tant qu'on n'a pas atteint la  fin du fichier
    {
        /// lire les infos pour chaque �tudiant
        ific >> nom;
        ific >> prenom;
        ific >> groupe;
        ific >> num;
        /// cr�er l'�tudiant et l'ajouter � la fin du vector
        _promo.push_back(Etudiant(num, nom, prenom, groupe));
    }
    ific.close(); /// fermer le fichier
}


int Promotion::rechercheEtudiant(const string& groupe,const string& nometudiant)const{
    bool trouver = false;
    int debut = 0;
    int fin = _promo.size()-1;
    int milieu, ind = -1;
    while(!trouver && debut <= fin){
        milieu = (debut+fin)/2;
        trouver=_promo[milieu].getNameEtud() == nometudiant && _promo[milieu].getGrpEtud()==groupe;
        if(trouver)
            ind = milieu;
        else{
            if((_promo[milieu].getGrpEtud()>groupe)||(_promo[milieu].getGrpEtud()==groupe && _promo[milieu].getNameEtud()>nometudiant)){
                fin = milieu - 1;
            }
            else{
                debut = milieu+1;
            }
        }
    }
    return (ind);
}
