#include <iostream>
#include <vector>
#include "appartement.h"
#include "piece.h"

using namespace std;

int main()
{

    Piece chambre01(3,4,"chambre01");
    Piece chambre02(3,4,"chambre02");
    Piece chambre03(3,4,"chambre03");
    Piece chambre04(3,4,"chambre04");
    Piece chambre05(3,4,"chambre05");
    Piece chambre06(3,4,"chambre06");
    Piece chambre07(3,4,"chambre07");
    Piece chambre08(3,4,"chambre08");
    Piece chambre09(3,4,"chambre08");

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


    return 0;
}
