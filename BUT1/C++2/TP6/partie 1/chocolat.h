#ifndef CHOCOLAT_H_INCLUDED
#define CHOCOLAT_H_INCLUDED

#include <string>

using namespace std;

 const int POIDS=30; // poids par défaut (en gramme)
 const string NOIR = "noir";
 const int CNOIR = 0;
 const string BLANC = "blanc";
 const int CBLANC = 1;
 const string LAIT = "lait";
 const int CLAIT = 2;

class Chocolat{
  int _nature; // 0 noir, 1 blanc, 2 lait
  int _poids; // poids du chocolat

  string _natureVersString(int n)const;// retourne laString équivalente à la nature
  int _stringVersNature(const string&)const;// retourne la nature équivalente à la string
 public:
    Chocolat(const string &nature="noir",int poids=30);
    Chocolat(int);
    void affiche()const;
    int lePoids()const ;
    string laNature() const ;
    bool operator<(const Chocolat& c)const;

 };

 ostream& operator<<(ostream& o,const Chocolat& c );


#endif // CHOCOLAT_H_INCLUDED

