// HBM,JL 2023
// gestion d'une equipe de sportives : equipe de France de football feminin 2023
// g++ -std=c++14

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int i, j, k, nbj, cpt;
char changer;
string nvljoueuse, joueusecherche, joueusechanger;
bool trouve = false;

int main()
{
    // D�claration et initialisation de l'�quipe de d�part
    vector<string> equipe = {"DURAND", "BACHA", "RENARD", "GEYORO", "DIANI", "SOMMER"};

    // Demande � l'utilisateur combien de nouvelles joueuses il souhaite ajouter
    cout << "Combien de nouvelle joueuses" << endl;
    cin >> nbj;
    cout << "Nom de la joueuse" << endl;

    // Ajout des nouvelles joueuses � l'�quipe
    for (j = 0; j < nbj; j++)
    {
        cin >> nvljoueuse;
        equipe.push_back(nvljoueuse);
    }

    // Demande � l'utilisateur le nom de la joueuse � v�rifier
    cout << "Quelle joueuse voulez vous verifier ?" << endl;
    cin >> joueusecherche;

    // Convertit le nom de la joueuse entr� en majuscules pour la recherche
    for (k = 0; k < joueusecherche.length(); k++)
    {
        joueusecherche[k] = toupper(joueusecherche[k]);
    }

    cpt = 0;
    // Recherche de la joueuse dans l'�quipe
    while (trouve == false && cpt != equipe.size())
    {
        if (equipe[cpt] == joueusecherche)
        {
            trouve = true;
        }
        else
        {
            cpt++;
        }
    }

    if (trouve)
    {
        // Affiche la position de la joueuse trouv�e et propose de la remplacer
        cout << "joueuse pr�sente dans la case " << cpt << " du vecteur" << endl;
        cout << "Veux tu remplacer ce joueur o ou n" << endl;
        cin >> changer;

        if (changer == 'o')
        {
            // Demande � l'utilisateur par qui il veut remplacer la joueuse
            cout << "Par qui veux tu le changer" << endl;
            cin >> joueusechanger;
            equipe[cpt] = joueusechanger;
            cout << equipe[cpt] << " est dans l'�quipe son num�ro est " << cpt << endl;
        }
    }
    else
    {
        // Si la joueuse n'a pas �t� trouv�e
        cout << "joueuse inconnue" << endl;
    }

    cout << endl << endl;
    // Question d : Affichage de l'�quipe � l'envers
    for (i = equipe.size() - 1; i >= 0; i--)
    {
        cout << equipe[i] << endl;
    }

    cout << endl;
    // Affichage du premier et du dernier �l�ment de l'�quipe
    cout << equipe.front() << endl;
    cout << equipe.back() << endl;

    // Affichage du premier et du dernier �l�ment de l'�quipe � l'aide des indices
    cout << equipe[0] << endl;
    cout << equipe[equipe.size() - 1] << endl;

    return 0;
}

//         jeu d'essai
//cas                                                 joueuse saisie      joueuse remplac�     R�sultat attendu
//test 1
//joueuse pas dans l'equipe                            TOTO                                    TOTO n'est pas dans l'�quipe
//test 2
//1ere joueuse                                         DURAND                                  Durand est dans l'�quipe son num�ro est 0
//test 3
//Derni�re joueuse                                     SOMMER                                  SOMMER est dans l'�quipe son num�ro est 5
//test 4
//Joueuse dans l'�quipe avec des minuscules            ReNaRd                                  RENARD est dans l'�quipe son num�ro est 2
//test 5
//Joueuse dans l'�quipe que l'on veut remplacer        RENARD               TOTO               TOTO est dans l'equipe son num�ro est 2
