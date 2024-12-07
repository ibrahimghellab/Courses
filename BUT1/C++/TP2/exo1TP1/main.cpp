#include <iostream>

using namespace std;

int main()
{
double a;
double b;


cout<< "Entrer un nombre"<<endl;
cin>>a;
cout<<"Entrer un second nombre"<<endl;
cin>>b;
if(a<=b){
    cout<<"ordre croissant"<<endl;
    }else{

    cout<<"ordre décroissant"<<endl;
    }


    return 0;
}
//Valeurs saisies : 1,5.5 --->ordre croissant
//Valeurs saisies : 5.5,1 --->ordre décroissant
