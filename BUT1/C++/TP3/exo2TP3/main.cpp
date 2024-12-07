#include <iostream>

using namespace std;

int main()
{
    int nbEtoiles,i,nbl,cpt;
    char unCar;
    cout<<"Saissisez un charactère"<<endl;
    cin>>unCar;
    cout<<"Saissez un entier n donné qui affichera n charactères"<<endl;
    cin>>nbEtoiles;
    cout<<"Combien de ligne ?"<<endl;
    cin>>nbl;

    while(nbEtoiles<0)
    {

        cout<<"Erreur. Veuillez saisir un nombre strictement positif"<<endl;
        cin>>nbEtoiles;
    }
    while (nbl<0){

        cout<<"Erreur. Veuillez saisir un nombre strictement positif"<<endl;
        cin>>nbl;
    }




    for(cpt=0; cpt<nbl; cpt=cpt+1)
    {

        for(i=0 ; i<nbEtoiles ; i++)
        {


            cout<<unCar;


        }

        cout<<endl;
    }


    return 0;
}
//--------------Jeux d'essai-------------
/* *,7,2:*******
         *******
   y,3,5:yyy
         yyy
         yyy
         yyy
         yyy

   9,6,1:999999
  -,-6,8:Erreur. Veuillez saisir un nombre strictement positif
  -,6,-8:Erreur. Veuillez saisir un nombre strictement positif
 +,-6,-8:Erreur. Veuillez saisir un nombre strictement positif
*/
