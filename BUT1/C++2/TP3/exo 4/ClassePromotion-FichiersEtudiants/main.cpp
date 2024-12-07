/// TP recherche, R101-2 2023-2024
/// main.cpp

#include <iostream>
#include <stdexcept>    /// exception out-of-range
#include <vector>       /// classe vector
#include <fstream>      /// lecture fichier

#include "etudiant.h"
#include "promotion.h"

using namespace std;

int main()
{



    try
    {
        Promotion promoS1;
        promoS1.init("listeEtudiants.txt");
        promoS1.afficher();
        cout<<endl<<promoS1.rechercheEtudiant("1B","GOSSET");
    }

    catch (string msg) /// lancee si erreur lecture fichier
    {
        cout << "ERREUR pb ouverture du fichier : " << msg << endl;
    }

    catch (invalid_argument e)
    {
        cerr << "ERREUR : " << e.what() << endl;
    }

    catch(out_of_range e)
    {
        cerr << "ERREUR : " << e.what() << endl;
    }

    return 0;
}
