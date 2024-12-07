#include <iostream>
#include <string>
#include "chocolat.h"


using namespace std;

string Chocolat::_natureVersString(int n)const {  // retourne la String équivalente à la nature

 if(n !=0 && n !=1 && n!=2) throw string ("nature incorrecte");
 string s;
 switch(n){
   case 0: s="noir";break;
   case 1: s="blanc";break;
   case 2: s="lait";break;
 }
 return s;
}


int Chocolat::_stringVersNature(const string& n)const{ // retourne la nature équivalente à la string
  if(n != NOIR && n != BLANC && n != LAIT) throw string ("nature incorrecte");
  int nature;
  if(n==NOIR) nature = CNOIR;
  else if(n==BLANC) nature = CBLANC;
  else nature = CLAIT;
  return nature;
 }

  Chocolat::Chocolat(const string &nature,int poids){
      if(poids<0) throw invalid_argument("Le poids est négatif");
    _nature=_stringVersNature(nature);
    _poids=poids;

  }
  Chocolat::Chocolat(int poids){
       if(poids<0) throw invalid_argument("Le poids est négatif");
    _poids=poids;
    _nature=rand()%3;
  }
  void Chocolat::affiche()const{
    cout<<"Le chocolat est de nature "<<_natureVersString(_nature)<<" et de poids "<<_poids<<"g"<<endl;
  }

  int Chocolat::lePoids()const{
    return(_poids);
  }

  string Chocolat::laNature()const{
    return(_natureVersString(_nature));
  }


  ostream& operator<<(ostream& o,const Chocolat& c )
{
    o << c.laNature() << " " << c.lePoids() ;
    return (o) ;
}

 bool Chocolat::operator<(const Chocolat& c)const{
    return(_poids<c._poids);
 }


