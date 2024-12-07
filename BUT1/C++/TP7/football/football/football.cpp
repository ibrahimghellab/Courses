#include"vecteurs.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string joueusecherche;
    vector<string> equipe = {"DURAND","bACHA","RENARD","GEYORO","DIANI","SOMMER"};
    cout<<"Donnez le nom d'une joueuse"<<endl;
    cin>>joueusecherche;
    affiche(equipe);
    normalisation(equipe[1]),
    affiche(equipe);

    char reponse;
    string joueuseremplace;
    if(recherche(equipe,joueusecherche)>=0)
    {
        cout<<"Voulez vous remplacer la joueuse ? o pour oui n pour non"<<endl;
        cin>>reponse;
        if(reponse=='o')
        {
            cout<<"Par qui voulez vous la remplacer"<<endl;
            cin>>joueuseremplace;
            remplacer(equipe,joueusecherche,joueuseremplace);

        }


    }
    else
    {
        cout<<"false"<<endl;
    }

    affiche(equipe);
    cout<<endl<<endl<<endl;



//Test normalisation
    cout<<"Test de la proc�dure normalisation(s)"<<endl;
    cout<<"Cas 1:S contient des minuscules s=renard"<<endl;
    string s="renard";
    normalisation(s);
    if (s=="RENARD")
    {
        cout<<"Test r�ussie s=RENARD"<<endl;

    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }

    cout<<"Cas 2: le nom est d�ja en majuscule s2=RENARD"<<endl;
    string s2="RENARD";
    normalisation(s2);
    if (s2=="RENARD")
    {
        cout<<"Test r�ussie s=RENARD"<<endl;

    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }
    cout<<"Cas 3: la string est vide"<<endl;
    string s3="";
    normalisation(s3);
    if (s3=="")
    {
        cout<<"Test r�ussie s="""<<endl;
    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }

//Test recherche
    cout<<"Test de la fonction recherche"<<endl;
    cout<<"Cas 1: pr�sent dans le vecteur "<<endl;
    vector<string> test= {"AAAA","BBBB","CCCC"};
    string testchercher="aaaa";
    affiche(test);
    cout<<testchercher<<endl;
    if(recherche(test,testchercher)>=0)
    {
        cout<<"Le test est r�ussie car"<<testchercher<<" est pr�sent dans le vecteur test"<<endl;
    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }
    cout<<"Cas 2: non pr�sent dans le vecteur"<<endl;
    testchercher="dddd";
    if(recherche(test,testchercher)==-1)
    {
        cout<<"Le test est r�ussie car"<<testchercher<<" n'est pas pr�sent dans le vecteur test"<<endl;
    }
    else
    {
        cout<<"Test �chou�e"<<endl;
    }
//Test remplacer
    cout<<"Test de la fonction remplacer"<<endl;
    cout<<"Cas1: l'utilisateur veut remplacer et remplace"<<endl;
    testchercher="aaaa";
    string testremplace="xxxx";
    if(remplacer(test,testchercher,testremplace)==true || test[recherche(test,testchercher)]==testremplace){
        cout<<"Test r�ussie, "<<testchercher<<" a �t� remplac�e par "<<testremplace<<endl;
        affiche(test);
    }else{
        cout<<"Test �chou�e"<<endl;
    }



}

