#include <string>
#include <iostream>
#include <stdexcept>
#include "permis.h"

using namespace std;


// constructeur vide
/*Permis::Permis(){
  cout << "Construction d'un permis" << endl;
  _nom = "inconnu";
  _prenom = "inconnu";
  _date = "non renseigne";
  _numero = "00000";
  _nbpoints = MAXP;
}*/


// constructeur
Permis::Permis(const string& nom, const string& prenom, const string& date, const string& numero, int points){
  cout << "Construction d'un permis" << endl;
  _nom = nom;
  _prenom = prenom;
  _date = date;
  _numero = numero;
  _nbpoints = points;
  if(points<MINP || points>MAXP){
    throw invalid_argument("Nombre aberrant");
  }
}

// affichage du permis
void Permis::affiche() const {
  cout << "Informations sur le permis de " << _prenom << " "<< _nom << " :" << endl;
  cout << _numero << endl;
  cout << _date << endl;
  cout << "Nombre de points : "<< _nbpoints << endl;
}

// nombre de points
int Permis::getNbpoints() const {
  return _nbpoints;
}

// retrait de points
void Permis::retraitPoints(int nbpointsretires) {
  if (_nbpoints < MINP + nbpointsretires) {
    _nbpoints = MINP;
  } else {
    _nbpoints -= nbpointsretires;
  }
}

//obtient le nom
string Permis::getNom(){
    return(_nom);
}

void Permis::incrementPoints(){
    if(_nbpoints>=MAXP){
        throw invalid_argument("Nombre maxiaml de points déja atteint");
    }else{
        _nbpoints++;
    }
}

void Permis::decrementPoints(){
    if(_nbpoints<=MINP){
        throw invalid_argument("Nombre minimale de points déja atteint");
    }else{
        _nbpoints--;
    }
}

void ajoutePoints(Permis& x, int y){
    int i=0;
    bool trouve=false;
    while(i<y && !trouve)
    try {
        x.incrementPoints();
        i++;
    }catch (const invalid_argument &e){
        trouve=true;
    }
}

Permis::~Permis() {
  cout << "Destruction du Permis" << endl;
  affiche();
}

bool Permis::compare(const Permis & p){
    return(_nbpoints==p._nbpoints);
}

void Permis::saisirPermis(){

    cout<<"Rentrez votre nom"<<endl;
    cin>>_nom;
    cout<<"Rentrez votre prénom"<<endl;
    cin>>_prenom;
    cout<<"Rentrez votre date de naissance"<<endl;
    cin>>_date;
    cout<<"Rentrez votre numéro"<<endl;
    cin>>_numero;
    cout<<"Rentrez votre nombre de points"<<endl;
    cin>>_nbpoints;
    if(_nbpoints<0 || _nbpoints>12){
        throw invalid_argument("Vous avez entrez un nombre aberrant");
    }
}

void Permis::modifierNom(){
    char validation;
    cout<<"Etes vous sur de vouloir modifier le nom de ce permis(o pour oui et n'importe quel autre lettre pour non"<<endl;
    cin>>validation;
    if(validation=='o'){
    cout<<"Quel est le nouveau nom que vous voulez ?"<<endl;
    cin>>_nom;
    }else{
        cout<<"Ok, vous ne modifierez pas votre nom"<<endl;
    }


}
