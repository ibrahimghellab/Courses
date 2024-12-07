#include <iostream>
#include "chocolat.h"
#include "BoiteChoco.h"
#include <ctime>
#include <stdexcept>

using namespace std;

int main()
{

    srand(time(NULL));

    try{



        Chocolat c1("blanc",20);    // chocolat blanc de 20g
        Chocolat c2;  // chocolat noir de 30g
        Chocolat c3(10);  // chocolat de 10g, nature tirée au sort
        Chocolat c4("blanc") ; // chocolat blanc de 30g

        c1.affiche();
        c2.affiche();
        c3.affiche();
        c4.affiche();

        cout<<c1;



        BoiteChoco bc1("boite",5);
        bc1.afficher(cout);
        bc1.ajoutChocolat(c1);
        cout<<bc1;
        cout<<bc1.mangeChocolat(c1);
        cout<<bc1;
        cout<<bc1.lePoids();


      /*  for(int i=bc1.laTaille()-1;i>=0;i--){
            cout<<"La nature du chocolat mangé est : "<< bc1.leContenu()[i].laNature()<<endl;
            bc1.mangeChocolat(c1);
            cout<<bc1<<endl;
        }
*/
cout<<endl<<endl<<endl<<endl<<bc1;
        bc1.retire();
        cout<<bc1;




    }
    catch(const invalid_argument& e){
        cout<<e.what()<<endl;
    }


     BoiteChoco b1("boite1",5);
        BoiteChoco b2("boite2",4);
        BoiteChoco b3("boite3",2);
        BoiteChoco b4("boite4",3);
        vector<BoiteChoco> magasin;

            magasin.push_back(b1);
            magasin.push_back(b2);
            magasin.push_back(b3);
            magasin.push_back(b4);
            int boitelourde=0;

            for(int i=0;i<magasin.size()-1;i++){
                if(magasin[i].lePoids()>=magasin[boitelourde].lePoids()){
                    boitelourde=i;
                }


            }
cout<<(magasin[boitelourde].leNom());

    return 0;
}
