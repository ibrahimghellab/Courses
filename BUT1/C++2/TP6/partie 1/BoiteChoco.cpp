#include <iostream>
#include <string>
#include "BoiteChoco.h"



BoiteChoco::BoiteChoco(const string & nom,int nbChocolat){
    _nom=nom;
    for(int i=0;i<nbChocolat;i++){
        _contenu.push_back(Chocolat(20));
    }
}

void BoiteChoco::afficher(ostream&o)const{
    o<<"le nom de la boite est "<<_nom<<", elle comporte "<<_contenu.size()-1<<" chocolats qui sont : "<<endl;
    for(int i=0;i<_contenu.size();i++){
        o<<"Le chocolat "<<i<<" est de nature "<<_contenu[i].laNature()<<endl;
    }
}

ostream& operator<<(ostream& o,const BoiteChoco& bc )
{
     bc.afficher(o);
    return (o) ;
}


 void BoiteChoco::ajoutChocolat(const Chocolat& c){
    _contenu.push_back(c);
 }


 BoiteChoco BoiteChoco::operator+=(const Chocolat& c){
    ajoutChocolat(c);
    return(*this);
 }

 bool BoiteChoco::mangeChocolat(Chocolat & c){
     if(_contenu.size()==0){
        return(false);
     }else{
         c=_contenu[_contenu.size()-1];
        _contenu.pop_back();
        return(true);
     }
 }

 string BoiteChoco::leNom()const{
    return(_nom);
 }

 int BoiteChoco::lePoids()const{
    int poids=0;
    for(int i=0;i<_contenu.size();i++){
        poids+=_contenu[i].lePoids();
    }
    return(poids);
 }

  vector<Chocolat> BoiteChoco::leContenu()const{
    return(_contenu);
  }

 int BoiteChoco::laTaille()const{
    return(_contenu.size());
 }

void BoiteChoco::retire(){

    if (_contenu.size()==0) throw invalid_argument("La boite est vide");

    int ChocolatRetire=rand()%_contenu.size();

    for(int i=ChocolatRetire;i<_contenu.size();i++){
        _contenu[i]=_contenu[i+1];

    }
    _contenu.pop_back();
}


