#include "fonctionFacebook.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    cout<<"Test du sous programme ajoutAmis"<<endl;
    cout<<"Cas général : les 2 personnes sont ajoutés en tant qu'amis."<<endl;
    vector<vector<bool>> test;
    test=initialisation(4);
    ajoutAmis(test,1,2);
    if(test[2][1]&&test[1][2])
    {
        cout<<"Test réussie"<<endl;

    }
    else
    {
        cout<<"Test échouée"<<endl;
    }
    cout<<"Test de la procédure amisCommuns"<<endl;
    cout<<"Cas général : ont un certain nombre d'amis en commun"<<endl;
    if(amisCommuns(test,0,1==2))
    {
        cout<<"Test réussie"<<endl;
    }
    else
    {
        cout<<"Test échouée"<<endl;
    }
    cout<<"Cas limite : a 0 amis en commun"<<endl;
    test=initialisation(3);
    if(amisCommuns(test,0,1)==0)
    {
        cout<<"Test réussie"<<endl;
    }
    else
    {
        cout<<"Test échouée"<<endl;
    }

    cout<<"Test de la fonction groupeAmis"<<endl;
    cout<<"Cas générale : font un groupe d'amis"<<endl;
    ajoutAmis(test, 0, 1);
    ajoutAmis(test, 0, 2);
    ajoutAmis(test, 1,2);

    if(groupeAmis(test,0,1,2)==true)
    {
        cout<<"Test réussie"<<endl;
    }
    else
    {
        cout<<"Test échouéée"<<endl;
    }
    cout<<"Cas limite : ne fait pas partie d'un groupe"<<endl;
    test=initialisation(5);
    if(groupeAmis(test,0,1,2)==false)
    {
        cout<<"Test réussie"<<endl;

    }
    else
    {
        cout<<"Test échouée"<<endl;
    }





    vector<vector<bool>> amis;  // Déclarer une variable pour le réseau d'amis
    int NBMEMBRES = 5;  // Définir le nombre de membres dans le réseau
    int nv1 = 1;
    int nv2 = 2, nv3 = 4;  // Identifiants des membres

    amis = initialisation(10);  // Initialiser le réseau avec 10 membres (valeur inutilisée NBMEMBRES)

    // Afficher le réseau d'amis initial (chaque membre est ami avec lui-même)
    cout << "Réseau d'amis initial : " << endl;
    affichage(amis);

    // Ajouter des amis entre les membres nv1, nv2 et nv3
    ajoutAmis(amis, nv1, nv2);
    ajoutAmis(amis, nv1, nv3);
    ajoutAmis(amis, nv2, nv3);

    // Afficher le réseau d'amis mis à jour
    cout << "Réseau d'amis après ajout d'amis : " << endl;
    affichage(amis);

    // Compter le nombre d'amis communs entre nv1 et nv2
    int amisCommun = amisCommuns(amis, nv1, nv2);
    cout << "Nombre d'amis communs entre nv1 et nv2 : " << amisCommun << endl;

    // Vérifier si nv1, nv2 et nv3 forment un groupe d'amis
    bool estGroupe = groupeAmis(amis, nv1, nv2, nv3);
    cout << "Est-ce un groupe d'amis ? ";
    if(estGroupe==true)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
}

