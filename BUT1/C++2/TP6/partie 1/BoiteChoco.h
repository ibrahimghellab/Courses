#ifndef BOITECHOCO_H_INCLUDED
#define BOITECHOCO_H_INCLUDED

#include <string>
#include <vector>
#include "chocolat.h"
using namespace std;
class BoiteChoco{
         string _nom; // nom de la boite
         vector<Chocolat> _contenu;   // les Chocolats contenus dans la boite
public :

        BoiteChoco(const string & nom,int nbChocolat);
        void afficher(ostream&o)const;
        void ajoutChocolat(const Chocolat& c);
        BoiteChoco operator+=(const Chocolat& c);
        bool mangeChocolat(Chocolat & c);
        string leNom()const;
        int lePoids()const;
        vector<Chocolat> leContenu()const;
        int laTaille()const;
        void retire();

  };


ostream& operator<<(ostream& o,const BoiteChoco& bc);


#endif // BOITECHOCO_H_INCLUDED
