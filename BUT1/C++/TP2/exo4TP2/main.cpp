//GHELLAB Ibrahim

#include <iostream>

using namespace std;

int main()
{

    char dureduSpectacle,abonnement,typeSpectacle;
    int age,prix;

    cout<<"Etes vous abonn閟 o ou én"<<endl;
    cin>>abonnement;
    cout<<"Quel age avez vous ?"<<endl;
    cin>>age;
    cout<<"Spectacle court ou long"<<endl;
    cin>>dureduSpectacle;

    switch(dureduSpectacle)
    {
    case 'l':
        if(age<18)
        {
            if(abonnement=='o')
            {

                cout<<"Vous payerez 10 euros"<<endl;break;
            }
            else
            {
                cout<<"Vous payerez 12 euros"<<endl;break;
            }
        }
        else
        {
            if(abonnement=='o')
            {

                cout<<"Vous payerez 18 euros"<<endl;break;
            }
            else
            {

                cout<<"Vous payerez 22 euros"<<endl;break;
            }
        }
    case'c':
        if(age<18)
        {
            if(abonnement=='o')
            {

                cout<<"Vous payerez 6 euros"<<endl;break;
            }
            else
            {
                cout<<"Vous payerez 8 euros"<<endl;break;
            }
        }
        else
        {
            if(abonnement=='o')
            {

                cout<<"Vous payerez 15 euros"<<endl;break;
            }
            else
            {

                cout<<"Vous payerez 18 euros"<<endl;break;
            }


        }
        default:cout<<"Il y a une erreur"<<endl;


    }















return 0;
}

//----------Jeu d'essais----------
//o,58,l : Vous payerez 18 euros
//o,47,c : Vous payerez 15 euros
//o,12,l : Vous payerez 10 euros
//o,8,c  : Vous payerez 6 euros
//n,96,l : Vous payerez 22 euros
//n,96,c : Vous payerez 18 euros
//n,12,l : Vous payerez 12 euros
//n,16,c : Vous payerez 8 euros

