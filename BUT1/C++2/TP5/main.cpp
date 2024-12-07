#include <iostream>
#include <vector>
#include "appartement.h"
#include "piece.h"

using namespace std;

int main()
{

    Piece chambre01(1,1,"chambre01");
    Piece chambre02(9,8,"chambre02");
    Piece chambre03(9,7,"chambre03");
    Piece chambre04(9,6,"chambre04");
    Piece chambre05(4,4,"chambre05");
    Piece chambre06(3,4,"chambre06");
    Piece chambre07(8,5,"chambre07");
    Piece chambre08(3,10,"chambre08");
    Piece chambre09(3,12,"chambre08");

    Appartement r1;
    r1.ajoutPiece(chambre01);
    r1.ajoutPiece(chambre02);
    r1.ajoutPiece(chambre03);
    r1.ajoutPiece(chambre04);
    r1.ajoutPiece(chambre05);
    r1.ajoutPiece(chambre06);
    r1.ajoutPiece(chambre07);
    r1.ajoutPiece(chambre08);
    r1.ajoutPiece(chambre09);

    cout<<r1.recherche("chambre08");
    cout<<r1.recherchePremier("chambre01");
    cout<<r1.rechercheDernier("chambre08");
    r1.afficher();
    cout<<endl<<endl;
    r1.trier();
    r1.afficher();


    return 0;
}
