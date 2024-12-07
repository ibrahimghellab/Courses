#include <iostream>

using namespace std;

int main()
{
    char lettre;
    cout<<"Tapez une lettre correspondant a une saison"<<endl;
    cin>>lettre;
       switch(lettre)
    {
    case 'e':cout<<"Il s'agit de l'été"<<endl;break;
    case 'a':cout<<"Il s'agit de l'automne"<<endl;break;
    case 'h':cout<<"Il s'agit de l'hiver"<<endl;break;
    case 'p':cout<<"Il s'agit du printemps"<<endl;break;
    default:
        cout<<"La lettre ne correspond a aucune saison"<<endl;
        break;


    }








    return 0;
}
