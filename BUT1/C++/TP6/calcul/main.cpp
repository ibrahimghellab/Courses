#include <iostream>
#include "calcul.h"
#include"menu.h"
using namespace std;

int main()
{
    cout<<"On fais le test du sous-programmeestPositif(nb)"<<endl;
    cout<<"Cas gnerale VRAI nb>0 "<<endl;
    if (estPositif(2))
    {
        cout<<"Test reussie 5 positif"<<endl;
    }
    else
    {
        cout<<"Test ratee 5 n'est pas positif"<<endl;

    }
    cout<<"Cas generale FAUX nb<0"<<endl;
    if(estPositif(-5))
    {

        cout<<"Test ratée -5 n'est pas negatif"<<endl;
    }
    else
    {
        cout<<"Test réussie -5 negatif"<<endl;
    }
    cout<<"Cas limite nb=0"<<endl;
    if(estPositif(0))
    {
        cout<<"Test ratee"<<endl;

    }
    else
    {
        cout<<"Test réussie 0 n'est pas positif"<<endl;
    }
    cout<<endl<<endl<<endl;

    int valeurdefact;
    cout<<"On fais le test du sous-programme factorielle(nb)"<<endl;
    cout<<"Cas générale factorielle d'un nombre positif"<<endl;
    if(factorielle(5)==120)
    {
        cout<<"Test réussie, 5!=120"<<endl;
    }
    else
    {
        cout<<"Test ratée, 5! n'est pas égale à 120"<<endl;
    }
    cout<<"Cas limite factorielle de 0"<<endl;
    if(factorielle(0)==1)
    {
        cout<<"Test réussie la factorielle de 0 est 1"<<endl;
    }
    else
    {
        cout<<"Test ratée la factorielle de 0 est différente de 1"<<endl;
    }
    cout<<endl<<endl<<endl;

    cout<<"On fais le test du sous-programme somme(nb)"<<endl;
    cout<<"Cas générale somme de nombres positifs"<<endl;
    if(somme(5)==15)
    {
        cout<<"Test réussie la somme des entiers de 1 a 5 est 15"<<endl;
    }
    else
    {
        cout<<"Test ratée la somme des entiers de 1 a 5 est differente de 15"<<endl;
    }
    cout<<"Cas limite somme de 0"<<endl;
    if(somme(0)==0)
    {
        cout<<"Test réussie la somme de 0 est 0"<<endl;
    }
    else
    {
        cout<<"Test ratee la somme de 0 n'est pas 0"<<endl;
    }

  cout<<endl<<endl<<endl;

    cout<<"On fais le test du sous-programme diviseur"<<endl;
    cout<<"Cas générale diviseur d'un nombre positif"<<endl;
    cout<<"Si les diviseurs de 25 sont 1,5 et 25 alors le test est réussie"<<endl;
    diviseur(25);
    cout<<endl;
    cout<<"Cas limite diviseur d'un nombre premier";
    cout<<"Si les diviseurs de 5 sont 1 et 5 alors le test est réussie";
    diviseur(5);
    cout<<endl;


     cout<<endl<<endl<<endl;
     cout<<endl<<endl<<endl;


    int val;
    cout<<"Saissisez une valeur, nous vérifierons si elle est positive"<<endl;
    cin>>val;
    while(!estPositif(val))
    {
        cout<<"Veuillez saisir une valeur veritablement positive. Recommencer"<<endl;
        cin>>val;
    }

    cout<<val<<" est positif."<<endl;

    cout<<endl<<endl<<endl;



    int valUtilisateur;


    do
    {
        valUtilisateur=menu();



        switch (valUtilisateur)
        {

        case FACT:
            cout<<"La factorielle de "<<val<<" est "<<factorielle(val)<<endl;
            break;
        case SOM:
            cout<<"La somme des entiers de 1 a "<<val<<" est "<<somme(val)<<endl;
            break;
        case DIV:
            cout<<"Les diviseurs de "<<val<<" sont ";
            diviseur(val);
            cout<<endl;
            break;
        case QUIT:
            cout<<"Quitter"<<endl;
            break;



        default:
            cout<<"Entrer une valeur entre 1 et 4"<<endl;
            break;
        }
    }
    while(valUtilisateur!=QUIT);


    return 0;
}
