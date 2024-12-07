// HB novembre 2022
// classe Permis pour gerer un permis de conduire
#ifndef _PERMIS_H_
#define _PERMIS_H_

#include <string>
using namespace std;


const int MAXP = 12; // Nombre de points maximal pour un permis
const int MINP = 0; //  Nombre de points minimal


class Permis {
  string _nom;  //  Nom du d�tenteur du permis
  string _prenom;//  Prenom du d�tenteur du permis
  string _date;//  Date de délivrance du permis, au format JJ/MM/AAAA (ex: 09/10/2021)
  string _numero;//Numero du permis (ex: 0123456789)
  int _nbpoints;//  Nombre du points du permis, compris entre MINP et MAXP

 public:

  ~Permis();
  /*--------------  Permis();
    constructeur vide
    Construit le permis d'une personne inconnue, avec 12 points par d�faut
  */
 // Permis ();

 /*-------------  Permis (const string&, const string&, const string&, const string&, int); constructeur a partir des informations
   Construit un permis � partir du nom et du pr�nom du d�tenteur, de
   la date de d�livrance, du num�ro, et du nombre de points
 */
  Permis (const string& x="inconnu", const string& y="inconnu", const string& z="non renseigne", const string& a="00000", int b=MAXP);
  /* ----------- void affiche() const;
     affichage d'un permis
     Affiche toutes les donn�es associ�es au permis cible
  */
  void affiche() const;

  /*------------- int getNbpoints() const;
    Nombre de points d'un permis
    Renvoie le nombre de points du permis cible
   */
  int getNbpoints() const;

  /*--------------  string getNom() const;
    Nom du d�tenteur d'un permis
    Renvoie le nom du d�tenteur du permis cible
   */
   /*----------- void retraitPoints(int);
    Retire des points � un permis
    Retire au permis cible le nombre de points pass� en param�tre, pour
    un minimum de MINP.
   */

  void retraitPoints(int);

  string getNom();

  void incrementPoints();

  void decrementPoints();

  bool compare(const Permis &);

  void saisirPermis();

  void modifierNom();
};

    void ajoutePoints(Permis&, int);
#endif
