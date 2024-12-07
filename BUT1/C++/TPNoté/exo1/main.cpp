#include <iostream>
using namespace std;
const int SUP = 10;
const int MAXESSAIS = 4;
int n, multiplen,cpt=0;
int main()
{
    cout<<"Donne-moi un nombre positif plus petit que 10"<<endl;
    cin>>n;
    cout<<"Donne moi un multiple de ta valeur"<<endl;
    cin>>multiplen;





    while(multiplen%n!=0 && cpt<4)
    {
        cout<<n<<" n'est pas un multiple de "<<multiplen<<". Essaye encore :"<<endl;
        cin>>multiplen;
        cpt++;

    }
    if (cpt>=4)
    {
        cout<<"Dommage,"<<n<<" n'est toujours pas un multiple de "<<multiplen<<". Relance le programme quand tuvoudras rejouer !"<<endl;

    }
    else
    {
        cout<< "Bravo ! Tu as trouvé un multiple de "<<n<<" en "<<cpt+1<< "essais."<<endl;
    }






    return 0;
}
