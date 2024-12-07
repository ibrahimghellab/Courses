// HB 2022
/// classes Appartement et Piece
/// Fichier appartement.cpp

#include <vector>
#include <iostream>
#include "piece.h"
#include "appartement.h"
#include <string>


/// Constructeur vide : permet de construire un objet Appartement sans aucune pi�ce avec une adresse par d�faut
Appartement::Appartement(){
    _adresse=ADRESSE;
}

/// Constructeur : permet de construire un appartement avec une premiere piece passee en parametre
Appartement::Appartement ( const Piece & p, const string& ad){
  _lesPieces.push_back(p);
  _adresse=ad;
 }

/// affichage : affiche les diff�rentes pi�ces d'un appartement
void Appartement::afficher()const{
  if(_lesPieces.size()==0)
    cout<< "L'appartement est encore en construction... " << endl;
  else{
      cout << "un appartement de " << _lesPieces.size() << " pieces"<<endl;
      for(int i=0; i<_lesPieces.size(); i++)
	_lesPieces[i].afficher();
  }
}

/// ajoutPiece : ajouter une pi�ce � un appartement
void Appartement::ajoutPiece(const Piece& p){
  _lesPieces.push_back(p);  /// _lesPieces est un vector, ajout en derni�re position
}

/// retraitPiece : supprime une pi�ce � un indice donn�
Piece Appartement::retraitPiece(int i){
  //cout << "Appel retraitPiece avec i=" << i ;
  //cout << "   dans un appartement de " << _lesPieces.size() << " pieces" << endl;
  /// pour d�clencher l'exception (prot�ger les bornes) il faut utiliser at et pas []
  Piece resul(_lesPieces.at(i));
  // on remplacee la piece i par la derni�re piece, puis on retire la derniere piece
  _lesPieces[i]=_lesPieces.back();
  _lesPieces.pop_back();
  /// On pourrait utiliser les iterateurs (pas �tudi�s lors du 1er module)
  /// begin : fonction qui retourne un iterateur sur le d�but du Vector
  /// _lesPieces.erase(_lesPieces.begin()+i)
  return resul;
}

/// surface : retourne la superficie de l'appartement
float Appartement::surface ( ) const{
  float s = 0 ;
  for(int i=0; i<_lesPieces.size(); i++){
    s += _lesPieces[i].surface();
  }
  return s ;
}

/// plusGrandePiece : retourne l'indice de la plus grande pi�ce,
/// -1 si appartement vide
int Appartement::plusGrandePiece() const{
  int pgp = -1 ;
  if (_lesPieces.size() > 0 ){
    pgp = 0 ;
    for (int i=1; i<_lesPieces.size(); i++)
      if (_lesPieces[i].surface() > _lesPieces.at(pgp).surface())
	pgp = i ;
  }
  return pgp ;
}

/// ------- compare 2 appartements sur leur surface ---
int Appartement::compare(const Appartement& a)const{
  int resul;
  float surf1,surf2;
  surf1=surface();
  surf2=a.surface();
  if (surf1<surf2)resul =  -1;
  else  if (surf1>surf2)resul= 1;
  else resul= 0;
  return resul;
}

// retourne le nombre de pieces d'un appartement
int Appartement::nbPieces()const{
  return _lesPieces.size();
}

int Appartement::recherche(const string& name){

    bool trouver = false;
    int debut = 0;
    int fin = _lesPieces.size()-1;
    int milieu, ind = -1;
    while(!trouver && debut <= fin){
        milieu = (debut+fin)/2;
        trouver=_lesPieces[milieu].nom() == name ;
        if(trouver)
            ind = milieu;
        else{
            if(_lesPieces[milieu].nom()>name){
                fin = milieu - 1;
            }
            else{
                debut = milieu+1;
            }
        }
    }
    if(trouver)
        return (ind);
    else{
        return(-1);
    }

}

int Appartement::recherchePremier(const string& name)const{

    bool trouver = false, trouverpetit = false;
    int debut = 0;
    int fin = _lesPieces.size()-1;
    int milieu, ind = -1;
    while((!trouver || !trouverpetit) && debut <= fin){
        milieu = (debut+fin)/2;
        trouver=_lesPieces[milieu].nom() == name;
        if(trouver){
            if(milieu!=0){
                if(name == _lesPieces[milieu-1].nom())
                    fin = milieu-1;
                else{
                    ind = milieu;
                    trouverpetit = true;
                }
            }
            else
                return(0);
        }
        else{
            if(_lesPieces[milieu].nom()>name){
                fin = milieu - 1;
            }
            else{
                debut = milieu+1;
            }
        }
    }
    return (ind);

}




int Appartement::rechercheDernier(const string& name)const{

    bool trouver = false, trouvergrand = false;
    int debut = 0;
    int fin = _lesPieces.size()-1;
    int milieu, ind = -1;
    while((!trouver || !trouvergrand) && debut <= fin){
        milieu = (debut+fin)/2;
        trouver=_lesPieces[milieu].nom() == name;
        if(trouver){
            if(milieu!=0){
                if(name == _lesPieces[milieu+1].nom())
                    debut = milieu+1;
                else{
                    ind = milieu;
                    trouvergrand = true;
                }
            }
            else
                return(0);
        }
        else{
            if(_lesPieces[milieu].nom()>name){
                fin = milieu - 1;
            }
            else{
                debut= milieu+1;
            }
        }
    }
    return (ind);

}

