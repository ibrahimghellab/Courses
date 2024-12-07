#include <iostream>

using namespace std;

int main()
{
    float temp;

    cout<<"Entrer une température"<<endl;
    cin>>temp;

    if(15<temp && temp<25)
    {

        cout<<"Cette température me convient :-)"<<endl;

    }
    else
    {
        if(temp<15)
        {
            cout<<"Il fais trop froid:-("<<endl;
        }
        else
        {

            cout<<"Il fait trop chaud :-)"<<endl;
        }
    }






    return 0;
}



//-------jeu d'essai------
//11 il fais trop froid
//22 cette température me convient
//45 il fais trop chaud
