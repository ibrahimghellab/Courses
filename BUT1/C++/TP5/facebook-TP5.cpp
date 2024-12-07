// JL/HBM  2023
// vecteurs 2 dimensions
// les lignes et les colonnes representent des personnes
// chaque case (i,j) contient  un booleen
// indiquant si i et j sont des amis


#include <iostream>
#include <vector>
using namespace std;

bool ami=false;
int i,j,numAmi,numUtilisateur,numPersonne,nbAmis,cpt,cpt0=0,cpt1=0,cpt2=0,cpt3=0,cpt00=0,cpt11=0,cpt22=0,cpt33=0;
char nvAmi;
int main()
{
    vector <vector <bool> >  amis;  // le reseau des amis.

    // Question 1 : initialiser le reseau. Toutes les cases avec false sauf celles de la diagonale (une personne est amie avec elle-meme)
    for (i=0; i<4; i++)
    {


        amis.push_back(vector<bool>(4,false));
        amis[i][i]=true;

    }
    for ( int i =0; i < amis . size () ; i ++)
    {
        for ( int j =0; j < amis [0]. size () ; j ++)
        {
            cout << amis [ i ][ j ] ;

        }
        cout<<endl;
    }


    for ( int i =0; i < amis . size () ; i ++)
    {
        cout<<"La personne " <<i<<" est amie avec : ";
        for ( int j =0; j < amis [i]. size () ; j ++)
        {
            if(amis[i][j] && i!=j)
                cout << j ;

        }
        cout<<endl;
    }
    cout<<"Qui etes vous (Entrer votre numéro)"<<endl;
    cin>>numUtilisateur;
    while(numUtilisateur>3)
    {
        cout<<"Vous ne pouver rentrer que une valeur entre 0 et 3. Recommence"<<endl;
        cin>>numUtilisateur;
    }
    cout<<"Voulez vous devenir ami avec quelqu'un ? o/n"<<endl;
    cin>>nvAmi;


    while((nvAmi=='o'||nvAmi=='O')&&numAmi<=3)
    {
        cout<<"Avec quelle personne voulez vous etre ami ?(Entrer un numéro entre 0 et 3)"<<endl;
        cin>>numAmi;
        while(numAmi>3)
        {
            cout<<"Vous ne pouver rentrer que une valeur entre 0 et 3. Recommence"<<endl;
            cin>>numAmi;
        }




        amis[numUtilisateur][numAmi]="true";
        amis[numAmi][numUtilisateur]="true";


        cout<<"Voulez vous devenir ami avec quelqu'un ? o/n"<<endl;
        cin>>nvAmi;

    }


    for ( int i =0; i < amis . size () ; i ++)
    {
        for ( int j =0; j < amis [i]. size () ; j ++)
        {
            cout << amis [ i ][ j ] ;

        }
        cout<<endl;
    }



    // Q 5
    // nbAmis : compte le nb d'amis de la personne qu'on parcourt
    // numPersonneMaxAmis : numéro de la personne qui a le plus d'amis
    // maxAmis : le nb d'amis maximal de toutes les personnes
    int maxAmis=0; // à déclarer
    int numPersonneMaxAmis=0;
    for(i=0; i<amis.size(); i++)
    {
        nbAmis=0;
        for(j=0; j<amis[i].size(); j++)
        {
            if(amis[i][j] == true){
                nbAmis++;
            }

        }
        if(nbAmis>maxAmis){
                maxAmis=nbAmis;
                numPersonneMaxAmis = i;
            }
    }
    cout<<"La personne qui a le plus d'ami est : "<< numPersonneMaxAmis << " elle a " << maxAmis << " amis !";

    return 0;
}
