 /** Classe Rationnel
 * HB
 *
 * Classe permettant de representer des nombres rationnels
 * L'encapsulation garantit que :
 *   - le denominateur est toujours un entier scrictement positif
 *   - la fraction est toujours reduite.
 * Ainsi, la repr�sentation des rationnels est unique.
 */


#ifndef _RAT_H_
#define _RAT_H_

#include <iostream>
#include <cstdlib>

using namespace std;

class Rationnel {
 private:

  int _num; // Num�rateur, positif ou n�gatif
  int _den; // d�nominateur, strictement
  // r�duction d'une fraction: _num / _den devient irr�ductible
  void _reduire();

 public:
  // Constructeur avec num�rateur et d�nominateur
  // v�rification et mise sous forme irreductible
  Rationnel(int=0, int=1);
  //  M�thode d'affichage, par exemple 1/2

  void afficher() const;
  //Renvoie le num�rateur
  int getNum() const;
  // Renvoie le d�nominateur
  int getDen() const;
  Rationnel operator*(const Rationnel& r)const;

  bool operator==(const Rationnel& r)const;

  Rationnel operator+(const Rationnel& r)const;

  bool operator<(const Rationnel& r)const;

  void saisir(istream & in);

  Rationnel operator/(const Rationnel& r)const;


 Rationnel& operator++();

 Rationnel operator++(int);





};

/// Calcul du pgcd de deux entiers quelconques
int pgcd(int a, int b);
// Calcul du pgcd de deux entiers a et b tels que a >= b >= 0
int pgcdRecursif(int a, int b);


// Fonctions de test
bool testConstructeurVideEtGetters();
bool testConstructeurParamEtGetters(int n, int d, int nres, int dres, bool exc);
bool testsConstructeurParamEtGetters();

ostream& operator<<(ostream& o ,const Rationnel& r );



istream& operator>>(istream& i, Rationnel& r);


Rationnel operator-(const Rationnel& r);



Rationnel operator*(const Rationnel& r, const Rationnel& r1);

 bool operator !=(const Rationnel&,const Rationnel&) ;

 bool operator <=(const Rationnel& r,const Rationnel& r1);

 Rationnel operator-(const Rationnel& r1,const Rationnel& r);




#endif
