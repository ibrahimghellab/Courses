#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"

#include <iostream>
#include <vector>
using namespace std;


int main(){
  vector<Enfant>lesEnfants; // les enfants qui attendent leurs cadeaux
  cout << "o o o Bonjour les enfants o o o " << endl;
  /// --------- Vous pouvez d�clarer de nouvelles variables
  /// --------- appeler les m�thodes �crites, et faire des affichages
  /// ------- ceci ne sera pas �valu�

 /* Cadeau c("orange");
  Cadeau c1("oranhe");
  cout<<c.memeCadeau(c)<<endl;

  Enfant e1("toto");
  e1.recoitCadeau(c);
  e1.affiche();
  cout<<endl;
  PereNoel p;
  cout<<p.offreCadeau(e1)<<endl;
  e1.affiche();
*/






  /// --------------- ins�rer ici les instructions de la question 5
  /// Obligatoire : tests automatiques de la m�thode *possede* de la classe Enfant)

  Enfant e5("enfant");
  Cadeau c5("orange");
  Enfant e6("enfant");
  e6.recoitCadeau(c5);
cout<<"o o o Test de la methode poss�de o o o "<<endl;
cout<<"Cas 1:L'enfant ne poss�de pas le cadeau";
if(e6.possede(c5)==true){
    cout<<endl<<"Test r�ussie"<<endl;

}else{
    cout<<endl<<"Test �chou�"<<endl;
}
cout<<endl<<endl;
cout<<"Cas 2:L'enfant poss�de d�ja le cadeau"<<endl;
if(e5.possede(c5)==false){
    cout<<"Test r�ussie"<<endl;

}else{
    cout<<"Test �chou�"<<endl;
}

  ///---------------  Question 9 : ajouter 4 enfants au vector lesEnfants

    Enfant e1("Asterix");
    Enfant e2("Boul");
    Enfant e3("Bill");
    Enfant e4("Kirikou");
    lesEnfants.push_back(e1);
    lesEnfants.push_back(e2);
    lesEnfants.push_back(e3);
    lesEnfants.push_back(e4);

  /// --------------- Question  10
  /// Compl�ter les instructions ci-dessous pour la distribution des cadeaux
  int i=0;
  bool encoreDesCadeaux=true; // le pere Noel a-t-il encore des cadeaux dans sa hotte ?
    PereNoel papaNoel;
  // �crire  l'instruction d'amor�age  :
  // - le pere No�l offre un cadeau au 1er enfant : lesEnfants[0]
  // - le booleen encoreDesCadeaux est initialis�.

/// tant qu'il a des cadeaux
  while (encoreDesCadeaux){

    if(papaNoel.offreCadeau(lesEnfants[i])==false){
        encoreDesCadeaux=false;
    }

      i++;
    if(i==lesEnfants.size())
        i=0;
    }
      // recommence au 1er enfant
  // �crire l'instruction de relance :
  // - le pere No�l offre un cadeau � l'enfant num�ro i
  // - le booleen encoreDesCadeaux est mis � jour

  //}

  /// --------------- Question 11 ----------
  /// trouver l'enfant qui a le plus de cadeaux et afficher ses cadeaux


  return 0;
}

