#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "permis.h"

using namespace std;


int main() {
  vector<Permis> vp(10);
  Permis pdef;
  Permis p("Duck", "Donald", "09/06/1934", "012345", 7);
  Permis p1("Kesse", "Zoh", "01/02/3456",  "678910",7);
  Permis p2("Ghellab", "Ibrahim", "45/68/9652", "456741",12);

  Permis p6("GDdzd");



  p6.affiche();

  cout << endl << "----- Tests manuels de affiche -----------------------------------------" << endl;
  pdef.affiche();
  p.affiche();
  cout << endl << "----- Tests automatiques de getNbpoints --------------------------------" << endl;
  bool ok = true;
  if (!(p.getNbpoints() == 7)) {
    ok = false;
    cout << "Erreur : p.getNbpoints() = " << p.getNbpoints() << " (attendu : 7)" << endl;
  }
  if (ok) cout << "Methode getNbpoints correcte" << endl;

  cout << endl << "----- Tests automatiques de retraitPoints ------------------------------" << endl;
  ok = true;
  p.retraitPoints(3);
  if (!(p.getNbpoints() == 4)) {
    ok = false;
    cout << "Erreur : apres avoir retire 3 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 4)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(0);
  if (!(p.getNbpoints() == 7)) {
    ok = false;
    cout << "Erreur : apres avoir retire 0 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 7)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(7);
  if (!(p.getNbpoints() == 0)) {
    ok = false;
    cout << "Erreur : apres avoir retire 7 points e un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(10);
  if (!(p.getNbpoints() == 0)) {
    ok = false;
    cout << "Erreur : apr�s avoir retire 10 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  if (ok) cout << "Methode retraitPoints correcte" << endl;

  //cout<<p1<<endl;
  //cout<<p1._nom<<endl;

   cout << endl << "----- Tests manuels de getNom -----------------------------------------" << endl;
  cout<<p1.getNom()<<endl;

  cout << endl << "----- Tests manuels de incrementPoints -----------------------------------------" << endl;
    p1.retraitPoints(4);
    cout<<"Le nombre de points avant incr�mentation: ";
    cout<<p1.getNbpoints()<<endl;
    try{
        p1.incrementPoints();

    }catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}


    cout<<"Le nombre de points apr�s incr�mentation: ";
     cout<<p1.getNbpoints()<<endl;


cout<<endl<<endl;
    cout<<"Le nombre de points avant incr�mentation: ";
    cout<<p1.getNbpoints()<<endl;
    try{
        p2.incrementPoints();

    }catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}

     cout<<"Le nombre de points apr�s incr�mentation: ";
     cout<<p2.getNbpoints()<<endl;

     cout << endl << "----- Tests manuels de decrementPoints -----------------------------------------" << endl;
    p1.retraitPoints(4);
    cout<<"Le nombre de points avant d�cr�mentation: ";
    cout<<p1.getNbpoints()<<endl;
    try{
        p1.retraitPoints(5);
        p1.decrementPoints();

    }catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}

     cout<<"Le nombre de points apr�s d�cr�mentation: ";
     cout<<p1.getNbpoints()<<endl;

    cout<<endl<<endl;

     cout<<"Le nombre de points avant d�cr�mentation: ";
    cout<<p2.getNbpoints()<<endl;
    try{

        p2.decrementPoints();

    }catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}

     cout<<"Le nombre de points apr�s d�cr�mentation: ";
     cout<<p2.getNbpoints()<<endl;


 cout << endl << "----- Tests manuels de ajoutePoints -----------------------------------------" << endl;
     ajoutePoints(p,2);
     cout<<"Vous avez maintenant"<<p.getNbpoints();
cout << endl << "----- Tests manuels de destruction -----------------------------------------" << endl;
    try{
        Permis p3("Ghellab", "Ibrahim", "45/68/9652", "456741",440);
    }catch(const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}


    /*if (p1 == p2) cout << "c'est pareil" << endl;*/
cout << endl << "----- Tests manuels de compare -----------------------------------------" << endl;
    Permis p4("Ghellab", "Ibrahim", "45/68/9652", "456741",7);
    Permis p5("Ghellab", "Ibrahim", "45/68/9652", "456741",7);

    if(p4.compare(p5))
        cout<<"Le nombre de points sur le permis sont identiques"<<endl;
    else
        cout<<"Le nombre de points sur le permis ne sont pas identiques"<<endl;

    for(int i=0;i<vp.size();i++){
        vp[i].affiche();
    }



Permis pa("Toto");
if (pa.compare(string("Toto"))) cout << "on ne peut pas comparer un permis � un string" << endl;
else cout << "on peut comparer un permis � un string" << endl;

if (pa.compare(string("Titi"))) cout << "on ne peut pas comparer un permis � un string" << endl;
else cout << "on peut comparer un permis � un string" << endl;

try{
p1.saisirPermis();
}catch (const invalid_argument &e){
    cerr<<"ERR: "<<e.what()<<endl;}

    p1.modifierNom();
    p1.affiche();

       return 0;
}


/*Reponnse aux questions
1)a)Le fichier permis.h contient la d�claration de la classe avec certaines donn�es qui sont publics et d'autres priv�es, ses d�finitions et ses m�thodes
  b)Le fichier permis.cpp contient la d�finition  la classe Permis et de ses m�thodes. La pr�sence de Permis:: signifie que la fonction membre qui suit les :: est une partie interne de la classe.
    Lorsque l'on retire Permis:: de la d�finition de la fonction membre affiche, le projet ne compile pas. affiche() devient alors une proc�dure externe � la classe Permis.
  c)Le fichier main.cpp contient les tests manuels et automatiques r�alis�es sur notre classe
  d)Il y a l'appel des constructeurs ainsi que les tests �ff�ctu�es sur les diff�rentes fonctions membres qui sont affich�es.L'appel des constructeur s'effectue chaque fois que Permis (const string&, const string&, const string&, const string&, int) est appell�
2)b)Le projet ne compile pas car on ne peut pas afficher un objet de la classe avec cout
  c)Le projet ne compile toujours pas car par d�faut lorsque des attributs ne sont pas mis en public par la classe ils sont consid�r� comme private.
  d)La fonction membre retraitPoint modifie les param�tres contenu dans sa d�finition ainsi elle ne porte pas le  type const alors que la fonction affiche quand a elle ne modifie rien ainsi elle porte le type const.
4)b) Le code ne compile pas
5)b)Le destructeur est appell� � la fin de la ou les objets sont utilis�s. Les objets sont d�truits dans l'ordre inverse de leur cr�ation.
7)Le code ne compile pas car l'op�rande == n'est pas compatible avec la classe Permis.
10)1) Un permis est cr�e avec les valeurs par d�faut mais avec comme nom le string que l'on a mis comme param�tre car les valeurs par d�faut sont toujours la si on ne rentre pas de param�tre qui est cens� les remplacer
   2)Le programme ne compile pas et l y aura une erreur car les d�finitions sont ambigus. Pour ne plus avoir d'erreur on peut mettre en commentaire le prototype du constructeur vide ainsi que sa d�finition pour que ce ne soit plus ambigus.
11)Le message affich� sur le terminal de sortie est : on ne peut pas comparer un permis � un string.





    */

