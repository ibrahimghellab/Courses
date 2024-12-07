#include <iostream>
#include <stdexcept>
#include "rat.h"
using namespace std;


Rationnel::Rationnel(int num, int den)
{
    if (den==0) throw invalid_argument("Denominateur nul");
    if (den > 0)
    {
        _num = num;
        _den = den;
    }
    else
    {
        _num = -num;
        _den = -den;
    }
    _reduire();
}

void Rationnel::_reduire()
{
    int facteur = pgcd(_num, _den); // facteur commun
    _num /= facteur;
    _den /= facteur;
}

void Rationnel::afficher() const
{
    cout << _num << '/' << _den;
}

int Rationnel::getNum() const
{
    return _num;
}

int Rationnel::getDen() const
{
    return _den;
}

int pgcd(int a, int b)      // utilise pgcdRecursif
{
    int a2 = (a > 0) ? a : -a;
    if (a2 < b)
    {
        int temp = a2;
        a2 = b;
        b = temp;
    }
    return pgcdRecursif(a2, b);
}


int pgcdRecursif(int a, int b)      // utilise l'algorithme d'Euclide
{
    return (b==0) ? a : pgcdRecursif(b, a%b);
}


// Fonctions de test
bool testConstructeurVideEtGetters()
{
    bool ok = true;
    Rationnel r;
    if (!(r.getNum() == 0))
    {
        ok = false;
        cout << "Erreur dans le constructeur vide ou getNum : le numerateur vaut " << r.getNum() << " (attendu : 0)" << endl;
    }
    if (!(r.getDen() == 1))
    {
        ok = false;
        cout << "Erreur dans le constructeur vide ou getDen : le denominateur vaut " << r.getDen() << " (attendu : 1)" << endl;
    }
    return ok;
}

bool testConstructeurParamEtGetters(int n, int d, int nres, int dres, bool exc)
{
    bool ok = true;
    if (exc)
    {
        try
        {
            Rationnel r(n, d);
            ok = false;
            cout << "Erreur dans le constructeur avec parametres : une exception aurait du etre lancee" << endl;
        }
        catch (const invalid_argument &) { }
    }
    else
    {
        try
        {
            Rationnel r(n,d);
            if (!(r.getNum() == nres))
            {
                ok = false;
                cout << "Erreur dans le constructeur avec parametres ou getNum : le numerateur vaut " << r.getNum() << " (attendu : " << nres << ")" << endl;
            }
            if (!(r.getDen() == dres))
            {
                ok = false;
                cout << "Erreur dans le constructeur avec parametres ou getDen : le denominateur vaut " << r.getDen() << " (attendu : " << dres << ")" << endl;
            }
        }
        catch (const invalid_argument &e)
        {
            ok = false;
            cout << "Erreur dans le constructeur avec parametres : l'exception " << e.what() << " a ete lancee" << endl;
        }
    }
    return ok;
}

bool testsConstructeurParamEtGetters()
{
    bool ok = true;
    ok = ok && testConstructeurParamEtGetters(0, 1, 0, 1, false);
    ok = ok && testConstructeurParamEtGetters(1, 2, 1, 2, false);
    ok = ok && testConstructeurParamEtGetters(-1, 2, -1, 2, false);
    ok = ok && testConstructeurParamEtGetters(1, -2, -1, 2, false);
    ok = ok && testConstructeurParamEtGetters(-1, -2, 1, 2, false);
    ok = ok && testConstructeurParamEtGetters(2, 4, 1, 2, false);
    ok = ok && testConstructeurParamEtGetters(1, 0, 1, 0, true);
    return ok;
}

/*Rationnel Rationnel::operator*(const Rationnel& r)const
{
    return(Rationnel(getNum()*r.getNum(),getDen()*r.getDen()));
}
*/
Rationnel Rationnel::operator/(const Rationnel& r)const
{
    return(Rationnel(getNum()*r.getDen(),getDen()*r.getNum()));
}
<<
bool Rationnel::operator==(const Rationnel& r)const
{
    return(r.getNum()==getNum() && r.getDen()==getDen());
}

ostream& operator<<(ostream& o,const Rationnel& r )
{
    o << r.getNum() << " / " << r.getDen() ;
    return (o) ;
}

Rationnel operator-(const Rationnel& r){
    return(Rationnel(-r.getNum(),r.getDen()));


}


 Rationnel Rationnel::operator+(const Rationnel& r)const{

    if(getDen()==r.getDen()){
        return(Rationnel(r.getNum()+getNum(),getDen()));
    }else{

      return(Rationnel(getNum()*r.getDen()+r.getNum()*getDen(),getDen()*r.getDen()));
    }
 }


 bool Rationnel::operator<(const Rationnel& r)const{

    return(getNum()*r.getDen()<r.getNum()*getDen());
 }


 void Rationnel::saisir(istream & in){
  cout << "numerateur ?";
  in>> _num;
  do{
   cout << "denominateur ?";
   in >> _den;
  }while(_den == 0);
  if (_den < 0) {
    _num = -_num;
    _den = -_den;
  }
  _reduire();
}

istream& operator>>(istream& i, Rationnel& r){
     r.saisir(i);

    return (i) ;
}

Rationnel operator*(int nb,const Rationnel& r){
    return(Rationnel(r.getNum()*nb,r.getDen()));
}


Rationnel operator*(const Rationnel& r, const Rationnel& r1){
    return(Rationnel(r1.getNum()*r.getNum(),r1.getDen()*r.getDen()));
}

 bool operator !=(const Rationnel& r1,const Rationnel& r) {
    return(!(r1==r));
 }

 bool operator <=(const Rationnel& r,const Rationnel& r1){
    return(r<r1 || r==r1);
 }

 Rationnel& Rationnel::operator++() {
    *this=*this+1;
    return(*this);
 }

 Rationnel Rationnel::operator++(int){
    Rationnel r=*this;
    *this=*this+1;
    return(r);

 }


 Rationnel operator-(const Rationnel& r1,const Rationnel& r){
     if(r1.getDen()==r.getDen()){
        return(Rationnel(r1.getNum()-r.getNum(),r1.getDen()));
    }else{

      return(Rationnel(r1.getNum()*r.getDen()-r.getNum()*r1.getDen(),r1.getDen()*r.getDen()));
    }
 }


