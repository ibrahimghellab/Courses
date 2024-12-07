#include <iostream>

using namespace std;
int nmax,i,nmin,cpt;
int main()
{

    cout<<"Entrez un grand entier strictement positif"<<endl;
    cin>>nmax;
    cout<<"Entrer un petit entier strictement positif"<<endl;
    cin>>nmin;
    while(nmin>nmax)
    {
        cout<<"Obéis"<<endl;
        cin>>nmax;
        cin>>nmin;
    }
    cpt=0;
    for(i=nmin; i<=nmax;)
    {


        if(i%7==0)
        {
            cout<<i<<" ";
            cpt++;
            if(cpt>=10)
            {
                cout<<endl;
                cpt=0;
            }
        }



    }


    return 0;
}
/*

Jeu d'essai
*/
