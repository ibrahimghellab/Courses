#include <iostream>
#include <vector>
using namespace std;

int i, cpt, valeur; // Déclaration de variables globales (évitez les variables globales si possible)
float moyenne, maxi;
int main()
{
    /*
    Question 1
    cpt = 0; // Initialisation du compteur à zéro

    vector<int> tab; // Déclaration d'un vecteur pour stocker les valeurs

    do
    {
        cout << "Entrer une valeur (-999 pour terminer) : ";
        cin >> valeur;
        tab.push_back(valeur); // Ajout de la valeur au vecteur

        cout << tab[cpt] << endl; // Affichage de la valeur ajoutée
        cpt++;
    }
    while (valeur != -999); // La boucle continue tant que l'utilisateur n'entre pas -999

    if (valeur == -999)
    {
        tab.pop_back(); // Suppression de la valeur -999 du vecteur
    }

    // Affichage des valeurs du vecteur
    cout << "Valeurs du vecteur :";
    for (int i = 0; i < tab.size(); i++)
    {
        cout << " " << tab[i];
    }
    cout << endl;

    return 0;
    }*/

    vector<float> tab2 = {12.5,5,20,15 };

    for(i=0; i<tab2.size(); i++)
    {
        moyenne=moyenne+tab2[i];
    }
    cout<<moyenne/(tab2.size())<<endl;


//          jeu d'essai

//Cas                       valeur saisie                 résultat attendu
//test 1
//valeur puis -999          5416,54674,5,-999             5416 54674 5

//test 2
//directement -999          -999                          rien



//     jeu d'essai
//cas                                                    résultat attendu
//test1
//moyenne d'un vecteur avec pour valeur 10,15,9          11.33333
//moyenne d'un vecteur avec pour valeur 0                0
//moyenne d'un vecteur avec pour valeur 12.5,5,20,15     13.125
