#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string nomFic;
    ofstream sortie;

    vector<int> tab = {1,2,40,5,7,8,10};

    try {
        cout << "Nom du fichier à créer ?"; cin >> nomFic;
        sortie.open(nomFic);
        if(!(sortie.is_open())) throw(nomFic);
        sortie << tab.size() << endl;
        for(int i=0; i<tab.size(); i++)
            sortie << tab[i] << ' ' ; // penser à mettre un séparateur
        sortie << endl;
        sortie.close();
    } catch (const string &s) {
        cerr<< "pb ouverture du fichier : " << s << endl;
    }






    string nomFic;
    ifstream entree;



    try {

        entree.open(nomFic);
        if(!(entree.is_open())) throw(nomFic);
        int nbInt;
        if (!entree.eof())


        entree.close();
        cout << "Nous avons lu :";
        for (int i = 0; i < tab.size(); i++) {
            cout << " " << tab[i];
        }
        cout << endl;
    } catch (const string & s) {
        cerr<< "pb ouverture du fichier : " << s;
    }





    return 0;
}

