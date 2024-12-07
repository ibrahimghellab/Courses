/// TP5 Tris et Complexit�
/// 2022-2023
/// fichier main.cpp

#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include "vecteurTrie.h"
#include "outils.h"

/// NOTE: mettre les 2 affichages de vecteur en commentaires pour executer les gros tris
/// et/ou pour l'execution d'un grand nombre de tris.

int main()
{
    VecteurTrie mesDonnees;         /// le vecteur de donn�es
    Algo monAlgo;                   /// l'algorithme de tri
    Ordre monOrdre;                 /// l'ordre des donn�es lors de l'initialisation du vecteur
    int nbElts, nbExec, valMax;     /// les param�tres du tri
    int cptEcrit, cptComp;          /// les compteurs de comparaisons et d'�critures
    int cptEcritTotal, cptCompTotal;

    do
    {
        cptEcritTotal=0, cptCompTotal=0;

        /// d�finition des param�tres du tri
        srand(time(NULL));              /// initialisation de rand
        paramTri(nbElts, valMax, nbExec, monOrdre, monAlgo);

        try
        {
            /// ex�cuter nbExec fois le tri souhait�
            for(int i = 0; i<nbExec; i++)
            {
                cout<<"************************************************************"<<endl;
                /// les compteurs sont remis � 0 pour chaque ex�cution
                cptEcrit=0;
                cptComp=0;

                /// initialiser le vecteur selon les choix de l'utilisateur
                mesDonnees.initVecteur(nbElts, monOrdre, valMax);
                cout << "Vecteur avant le tri :" << endl;
                mesDonnees.afficher();

                /// trier le vecteur
                mesDonnees.trier(monAlgo, cptEcrit, cptComp);
                cout << "\nVecteur apres le tri :" << endl;
                mesDonnees.afficher();
                cout <<"\nNombre d'ecritures: " << cptEcrit << endl
                     <<"Nombre de comparaisons: " << cptComp << endl;

                /// mise � jour du nombre total d'�critures et de comparaison
                cptEcritTotal = cptEcritTotal + cptEcrit;
                cptCompTotal = cptCompTotal + cptComp;
            }
            cout<<"************************************************************"<<endl;

            ///Calcul et affichage des valeurs moyennes des 2 compteurs
            cout <<"\nNombre moyen d'ecritures: "<<(float)cptEcritTotal/nbExec<<endl
                 <<"Nombre moyen de comparaisons: "<<(float)cptCompTotal/nbExec<<endl;
        }
        catch (string mesg)
        {
            cout << mesg << endl;
        }
        catch(out_of_range e)
        {
            cerr << "ERREUR : " << e.what() << endl;
        }
    } while (recommencer());  /// laisse l'utilisateur recommencer si elle le souhaite

    return 0;
}
