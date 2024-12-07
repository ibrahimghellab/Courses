//---------jeu d'essai-----------
// 5 - 8 - 12 les valeurs en sortie seront 5 et 12
// 5 - 5 - 5 les valeurs en sortie seront 5 et 5


#include <iostream>

using namespace std;

int main()
{
    double maxi, mini,x,y,z;

    cout<<"Entrer une premiere valeur"<<endl;
    cin>>x;
    cout<<"Entrer une seconde valeur"<<endl;
    cin>>y;
    cout<<"Entrer une troisieme valeur"<<endl;
    cin>>z;

    if(x<y)
    {

        mini=x;
        maxi=y;
    }
    else
    {
        maxi=x;
        mini=y;

    }
    if(z>maxi)
    {

       cout<<"Le maximum est" << z<< endl;
    }
       else{
            cout<<"Le maximum est"<<maxi<<endl;

    }
    if(z<mini){

        cout<<"Le minimum est" <<z <<endl;
    }else{

    cout<<"Le minimm est "<<mini<<endl;


    }












    return 0;
}
