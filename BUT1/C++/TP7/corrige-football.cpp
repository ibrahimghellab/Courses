// HBM,JL 2023
// gestion d'une equipe de sportives : equipe de France de football feminin 2023
// g++ -std=c++14

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main( ){
    vector<string> equipe = {"DURAND","BACHA","RENARD","GEYORO","DIANI","SOMMER"};

    string uneJoueuse;
    // variables intermédiaires
    int nbSup;   // nbre de noms à ajouter
    int i,j,l;
    bool trouve ;  // vrai si le nom est présent

    // Question b : on indentifie bien les indices de la premiere et de la
    // derniere case valide du tableau
    cout << "Le premier : " << equipe[0] << " " << equipe.front();
    cout << ", le dernier : "<< equipe[equipe.size()-1] << " " << equipe.back() << endl;*

    // Question c : Boucle d'affichage classique
    // Insister sur la fait qu'il faut afficher le tableau apres
    // chaque modification pour verifier son contenu.
    cout << endl << endl << "affichage dans l'ordre " << endl ;
    for (i=0 ; i<equipe.size() ; i++)    {
        cout << equipe[i] << endl;
    }

    // Question d : même chose à l'envers. Attention aux bornes du for
    cout << endl << endl << "affichage dans l'ordre inverse " << endl ;
    for (i=equipe.size()-1 ; i>=0 ; i--)    {
        cout << equipe[i] << endl;
    }

// Question e -------------- ajout de quelques joueuses
// la saisie du nombre de joueuses a ajouter
    cout << "Combien de joueuses voulez vous ajouter ? ";
    cin >> nbSup;
    while( nbSup < 0 )    {
        cout << "Valeur incorrecte";
        cout << "Combien de  voulez vous ajouter ? ";
        cin >> nbSup;
    }
    // Puis boucle d'ajout
    for(i=0; i<nbSup; i++)    {
        cout << "entrer une valeur : ";
        cin >> uneJoueuse;   // utiliser getline si nom peut comprendres des espaces.
        // on assure que les noms sont stockés en majuscules ----- ( question h)
        l=uneJoueuse.length();
        for (int j=0 ; j<l; j++)
            uneJoueuse[j]=toupper(uneJoueuse[j]);
        // ajout a la fin
        equipe.push_back(uneJoueuse);
    }
    cout <<  endl << "--  affichage apres ajout " << endl ;
    for (i=0 ; i<equipe.size() ; i++)    {
        cout << equipe[i] << endl;
    }

// question f -------- recherche ---------
    cout << "quel joueuse rechercher vous ? " ;
    cin >> uneJoueuse ;
    l=uneJoueuse.length();
    for (int j=0 ; j<l; j++)
        uneJoueuse[j]=toupper(uneJoueuse[j]);
// boucle de recherche
    i=0;
    trouve = false ;
    while ( i<equipe.size() && ! trouve )    {
        trouve = (equipe[i] == uneJoueuse) ;
        i++ ;
    }
    if ( !trouve )
        cout << endl << uneJoueuse << " n'existe pas dans le tableau" << endl ;
    else {
        cout << endl << uneJoueuse << " existe dans le tableau, a l'indice "
        <<  i-1 << " verification " << equipe[i-1] << endl ;

        cout << "quelle est sa remplacante ? " ;
        // question g -------------- remplacement
        cin>> uneJoueuse;
        l=uneJoueuse.length();
        for (int j=0 ; j<l; j++)
            uneJoueuse[j]=toupper(uneJoueuse[j]);
        equipe[i-1] = uneJoueuse;
        cout <<  endl << "--  affichage apres remplacement  " << endl ;
        for (i=0 ; i<equipe.size() ; i++)   {
            cout << equipe[i] << endl;
        }
    }

    return 0;
}
