#include <cstdlib>
#include <iostream>

#include "rat.h"

using namespace std;

int main(){
  cout << "----- Tests automatiques -----------------------------------------------" << endl;
  if (testConstructeurVideEtGetters()) cout << "Constructeur vide et getters ok" << endl;
  if (testsConstructeurParamEtGetters()) cout << "Constructeur avec parametres et getters ok" << endl;
  Rationnel test(5,4);
  Rationnel test2(3,2);
  if  (test*test==Rationnel(25,16)) cout<<"L'operateur * est operationnel"<<endl;
  if(test==test)cout<<"L'operateur == est operationelle"<<endl;

cout << "------------------------------------------------------------------------" << endl;

  cout << "----- Programme principal ----------------------------------------------" << endl;
  cout << "Veuillez saisir le numérateur et le dénominateur" << endl;
  int n, d; cin >> n >> d;
  try {
    Rationnel r(n,d);
    cout << "Voici votre rationnel réduit : ";   cout<<r ;cout << endl;
  }catch (const invalid_argument &e) {
    cout << "Erreur : " << e.what() << endl;
  }
  cout << "------------------------------------------------------------------------" << endl;


  Rationnel r2(1,7);
  //cout<<r2;

  Rationnel r1(5,7);

  Rationnel r=r1+r2;

  cout<<r<<endl;


  if(r2<r1==true){
    cout<<"true"<<endl;
  }else{
    cout<<"false"<<endl;
  }

  cout<<endl;
  cout<<r1/r2<<endl;

  cin>>r1;
  cout<<r1;

  Rationnel r42(3,1);
    r2=r1*r42;
cout<<endl<<r2<<endl;
    r2=3*r1;
    cout<<endl<<r2<<endl;
    cout<<r1++;
    cout<<r1<<endl;


    cout<<endl<<endl<<endl<<endl;
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r1-r2;



  return 0;
}
