#include <iostream>
#include <vector>
#include"gestionNotes.h"
#include <string>
using namespace std;
const int NBETUD = 20 ;
const int AFFICHENOTES = 1 ;
const int MOY = 2 ;
const int MAJOR = 3 ;
const int QUIT = 0;

void calcMoyenne(const vector<vector<int>> &notes, vector<float> & moy)
{
    //remplissage du vecteur des moyennes
    for(int i=0; i<notes.size() ; i++)
    {
        for(int j=0; j< notes[i].size(); j++)
            moy[i]+=notes[i][j];
        moy[i]=moy[i]/notes[i].size();
    }
}

bool invalide(int c)
{

    bool pasvalide=false;
    if(c!=AFFICHENOTES  && c!=MOY && c!=MAJOR &&c!=QUIT)
    {
        pasvalide=true;
        return(pasvalide);
    }
    else
    {
        return(false);
    }

}

int affichageMenu(int x)
{


    // affichage du menu
    cout<< "\n Que voulez-vous faire  ?" << endl;
    cout << AFFICHENOTES<<"  pour afficher toutes les notes de chaque etudiant."<< endl;
    cout <<MOY<<"  pour afficher toutes les moyennes de chaque etudiant."<< endl;
    cout << MAJOR<<"  pour afficher l'etudiant ayant la meilleure moyenne."<< endl;
    cout << QUIT <<"  pour quitter le programme."<< endl;

    //choix de l'utilisateur

    while (invalide(x)==true)
    {
        cout << "Choix invalide"<<endl;
        cin>> x;
    }
    return(x);

}

void affichageNotes(const vector<vector<int>> &x,const vector<string> &y)
{

    {
        for(int i=0; i< NBETUD ; i++)
        {
            cout<<"Les "<<x[i].size() <<" notes de "<<y[i]<<" :"<<endl;
            for(int j=0; j<x[i].size(); j++)
            {
                cout << x[i][j]<<" ";
            }
            cout << endl << endl;
        }
    }
}

void affichageMoyennes (const vector<float> &x, const vector<string> &y)
{
    //affichage des moyennes
    for(int i=0; i< NBETUD ; i++)
    {

        cout<<"La moyenne de "<<y[i]<<":\t";
        cout << x[i]<<endl;
    }
}

int meilleurEtudiant (const vector<float> &x)
{

    //calcul de l'indice du meilleur etudiant
    int imax=0;
    for(int i=1; i<NBETUD; i++)
        imax = x[imax]< x[i] ? i : imax;

    return(imax);

}
