#include "fonctionFacebook.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    cout<<"Test du sous programme ajoutAmis"<<endl;
    cout<<"Cas g�n�ral : les 2 personnes sont ajout�s en tant qu'amis."<<endl;
    vector<vector<bool>> test;
    test=initialisation(4);
    ajoutAmis(test,1,2);
    if(test[2][1]&&test[1][2])
    {
        cout<<"Test r�ussie"<<endl;

    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }
    cout<<"Test de la proc�dure amisCommuns"<<endl;
    cout<<"Cas g�n�ral : ont un certain nombre d'amis en commun"<<endl;
    if(amisCommuns(test,0,1==2))
    {
        cout<<"Test r�ussie"<<endl;
    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }
    cout<<"Cas limite : a 0 amis en commun"<<endl;
    test=initialisation(3);
    if(amisCommuns(test,0,1)==0)
    {
        cout<<"Test r�ussie"<<endl;
    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }

    cout<<"Test de la fonction groupeAmis"<<endl;
    cout<<"Cas g�n�rale : font un groupe d'amis"<<endl;
    ajoutAmis(test, 0, 1);
    ajoutAmis(test, 0, 2);
    ajoutAmis(test, 1,2);

    if(groupeAmis(test,0,1,2)==true)
    {
        cout<<"Test r�ussie"<<endl;
    }
    else
    {
        cout<<"Test �chou��e"<<endl;
    }
    cout<<"Cas limite : ne fait pas partie d'un groupe"<<endl;
    test=initialisation(5);
    if(groupeAmis(test,0,1,2)==false)
    {
        cout<<"Test r�ussie"<<endl;

    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }





    vector<vector<bool>> amis;  // D�clarer une variable pour le r�seau d'amis
    int NBMEMBRES = 5;  // D�finir le nombre de membres dans le r�seau
    int nv1 = 1;
    int nv2 = 2, nv3 = 4;  // Identifiants des membres

    amis = initialisation(10);  // Initialiser le r�seau avec 10 membres (valeur inutilis�e NBMEMBRES)

    // Afficher le r�seau d'amis initial (chaque membre est ami avec lui-m�me)
    cout << "R�seau d'amis initial : " << endl;
    affichage(amis);

    // Ajouter des amis entre les membres nv1, nv2 et nv3
    ajoutAmis(amis, nv1, nv2);
    ajoutAmis(amis, nv1, nv3);
    ajoutAmis(amis, nv2, nv3);

    // Afficher le r�seau d'amis mis � jour
    cout << "R�seau d'amis apr�s ajout d'amis : " << endl;
    affichage(amis);

    // Compter le nombre d'amis communs entre nv1 et nv2
    int amisCommun = amisCommuns(amis, nv1, nv2);
    cout << "Nombre d'amis communs entre nv1 et nv2 : " << amisCommun << endl;

    // V�rifier si nv1, nv2 et nv3 forment un groupe d'amis
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

