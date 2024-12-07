#include <iostream>
#include <string>
#include "piece.h"
#include <stdexcept>
#include<fstream>
using namespace std;


Piece::Piece(){

    _largeur=3;
    _longueur=4;
    _nom="piecevide";
}

Piece::Piece(float a,float b, const string& c){
    _largeur=a;
    _longueur=b;
    _nom=c;
    normalisation();
}



void Piece::afficher() const{
    cout<<"La piece "<<_nom<<" fais "<<_largeur<<" m de largeur et "<<_longueur<<" m de longueur ."<<endl;
}

 void Piece::saisir() {

    cout<<"Entrez la largeur de votre pièce : ";
    cin>>_largeur;
    cout<<endl;
    cout<<"Entrez la longueur de votre pièce : ";
    cin>>_longueur;
    cout<<endl;
    cout<<"Entrez le nom de votre pièce : ";
    cin>>_nom;
    normalisation();

    //Piece p(_largeur,_longueur,_nom);
 }

 void Piece::normalisation() {
        if(_largeur<_longueur){
        float longeur=_longueur;
        _longueur=_largeur;
        _largeur=longeur;
    }

    if(_longueur<0 || _largeur<0){
        throw invalid_argument("Largeur ou longueur négatives");
    }

    char init;
    string nom=_nom;
    _nom="";
    char temp;
    for(int i=0;i<nom.size();i++){
        init=nom[i];
        temp=tolower(init);
        _nom.push_back(temp);
    }
 }

 float Piece::surface () const {
    return(_longueur*_largeur);
 }



 bool Piece::plusGrande(const Piece& p ) const{

    return(surface()>p.surface());
 }

 Appartement::Appartement(){

     cout<<"Construction d'un appartement vide"<<endl;
     _adresse="1 rue Joliot-Curie 91400 Orsay";
     _zone=zne0;

 }

 Appartement::Appartement(const string& adr, const Piece & p,int zne){
     cout<<"Construction d'un appartement avec paramètres"<<endl;
    _adresse=adr;
    _ensembledespieces.push_back(p);
    while(zne<0||zne>4){

            cout<<"Saissisez une zone comprise entre 0 et 4"<<endl;
            cin>>zne;

    }
    _zone=zne;





    }


 void Appartement::affiche() const{
    cout<<"L'appartement situé au "<<_adresse<<" est composé de " <<_ensembledespieces.size()<<" pièces qui sont :"<<endl;
    for(int i=0;i<_ensembledespieces.size();i++){
        _ensembledespieces[i].afficher();
    }
    cout<<endl<<"Il est situé dans la zone " <<_zone;
 }

 void Appartement::ajoutPiece(const Piece& p){
    _ensembledespieces.push_back(p);
 }

 int Appartement::nbPieces() const{
     return(_ensembledespieces.size());

 }

 float Appartement::surface() const{
     float srfce=0;
    for(int i=0;i<_ensembledespieces.size();i++){
        srfce+=_ensembledespieces[i].surface();
    }
    return(srfce);
 }

void verification(){

}
 int Appartement::compare(const Appartement& app) const{
    if(surface()<app.surface()){
        return(-1);
    }
    if(surface()==app.surface()){
        return(0);
    }
    if(surface()>app.surface()){
        return(1);
    }
 }


 int Appartement::valeur() const{
    switch (_zone){
        case 0:
           return(zne0*surface());
            break;
        case 1:
         return(zne1*surface());
            break;
        case 2:
           return(zne2*surface());
            break;
        case 3:
           return(zne3*surface());
            break;
        case 4:
           return(zne4*surface());
            break;

    }
 }

 int Appartement::comparePrix(const Appartement& app) const{
     if(valeur()<app.valeur()){
        return(-1);
    }
    if(valeur()==app.valeur()){
        return(0);
    }
    if(valeur()>app.valeur()){
        return(1);
    }
 }



 void Piece::ecrireFichier(ofstream& entre){







     entre<<_nom<<endl;
     entre<<_largeur<<endl;
     entre<<_longueur<<endl;




 }




Piece::Piece(ifstream& entre ){

    entre>>_nom;
    entre>>_largeur;
    entre>>_longueur;

}



