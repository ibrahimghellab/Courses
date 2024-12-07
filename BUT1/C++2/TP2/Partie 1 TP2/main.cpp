#include <iostream>
#include"piece.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<Piece> ensem;
    Piece p(15,14,"couCOou");
    p.afficher();
     try{
        Piece p1(0,-5,"osman");

    }catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}

    Piece p2;
    p2.saisir();
    p.afficher();
    p2.afficher();
    cout<<p2.surface();
    cout<<p2.plusGrande(p);

    Appartement ();
    Appartement app1("13 sente Olympe de Gouges",p,1);
    Appartement app2("13 sente Olympe de Gouges",p,4);

    //app1.ajoutPiece(p);
    app1.affiche();

    cout<<"Le nombre de pièces est de "<<app1.nbPieces();


    cout<<"La surface totale de l'appartement est de "<<app1.surface()<<endl;
    cout<<p.surface()<<endl;
    cout<<app1.compare(app2)<<endl<<endl;
    cout<<app1.valeur()<<endl;
    cout<<app1.comparePrix(app1);




       string nomFic="4";
    ofstream entree;



    try {

        entree.open(nomFic);

        if(!(entree.is_open())) throw(nomFic);
        int nbInt;
        if (!entree.eof())
            p.ecrireFichier(entree);


        entree.close();


        cout << endl;
    } catch (const string & s) {
        cerr<< "pb ouverture du fichier : " << s;
    }

        ifstream entree;

    try{
        entree.open(nomFic);

    }





    return 0;


}
