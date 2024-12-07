#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

const int zne0=2500;
const int zne1=3100;
const int zne2=3500;
const int zne3=4150;
const int zne4=4500;





class Piece
{
private:
    float _largeur;
    float _longueur;
    string _nom;

public:
    Piece();
    Piece(ifstream& entre );

    Piece(float a, float b, const string& c);

    void afficher() const;

    void saisir() ;

    void normalisation ();

    float surface () const ;

    bool plusGrande(const Piece& p) const;

    void  ecrireFichier(ofstream& entre);

};

class Appartement
{
private:
    string _adresse;
    vector<Piece> _ensembledespieces;
    int _zone;

public:
    Appartement();

    Appartement(const string& adr, const Piece& p, int zne);

    void affiche() const;

    void ajoutPiece(const Piece& p);

    int nbPieces() const ;

    float surface() const ;

    int compare(const Appartement& app) const;

    void verification();//verifie si la zone est entre 0 et 4 sinon lance une exeption

    int valeur() const;

    int comparePrix(const Appartement& app) const;


};




#endif // PIECE_H_INCLUDED
