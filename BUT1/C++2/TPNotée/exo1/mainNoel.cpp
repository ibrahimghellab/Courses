#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"

#include <iostream>
#include <vector>
using namespace std;


int main(){
  vector<Enfant>lesEnfants; // les enfants qui attendent leurs cadeaux
  cout << "o o o Bonjour les enfants o o o " << endl;
  /// --------- Vous pouvez déclarer de nouvelles variables
  /// --------- appeler les méthodes écrites, et faire des affichages
  /// ------- ceci ne sera pas évalué

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






  /// --------------- insérer ici les instructions de la question 5
  /// Obligatoire : tests automatiques de la méthode *possede* de la classe Enfant)

  Enfant e5("enfant");
  Cadeau c5("orange");
  Enfant e6("enfant");
  e6.recoitCadeau(c5);
cout<<"o o o Test de la methode possède o o o "<<endl;
cout<<"Cas 1:L'enfant ne possède pas le cadeau";
if(e6.possede(c5)==true){
    cout<<endl<<"Test réussie"<<endl;

}else{
    cout<<endl<<"Test échoué"<<endl;
}
cout<<endl<<endl;
cout<<"Cas 2:L'enfant possède déja le cadeau"<<endl;
if(e5.possede(c5)==false){
    cout<<"Test réussie"<<endl;

}else{
    cout<<"Test échoué"<<endl;
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
  /// Compléter les instructions ci-dessous pour la distribution des cadeaux
  int i=0;
  bool encoreDesCadeaux=true; // le pere Noel a-t-il encore des cadeaux dans sa hotte ?
    PereNoel papaNoel;
  // écrire  l'instruction d'amorçage  :
  // - le pere Noël offre un cadeau au 1er enfant : lesEnfants[0]
  // - le booleen encoreDesCadeaux est initialisé.

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
  // écrire l'instruction de relance :
  // - le pere Noël offre un cadeau à l'enfant numéro i
  // - le booleen encoreDesCadeaux est mis à jour

  //}

  /// --------------- Question 11 ----------
  /// trouver l'enfant qui a le plus de cadeaux et afficher ses cadeaux


  return 0;
}

