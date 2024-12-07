#include <iostream>
#include <cstdlib> // pour srand et rand
#include <ctime> // pour time
using namespace std;

int valeur,alea;
int main()
{
    srand(time(NULL));//Initialisation du générateur à partir de l'heure courante:
    alea = rand()%100 + 1;

    cout<<"Entrer un nombre pour jouer"<<endl;
    cin>>valeur;
    if(valeur%alea==0)
    {
        cout<<"le nombre proposé est un multiple du nombre à deviner"<<endl;
    }
    else
    {
        if(alea%valeur==0)
        {
            cout<<"le nombre proposé est un diviseur du nombre à deviner"<<endl;
        }
        else
        {
            cout<<"le nombre proposé n’a rien à voir avec le nombre à deviner"<<endl;
        }
    }
    return 0;
}
