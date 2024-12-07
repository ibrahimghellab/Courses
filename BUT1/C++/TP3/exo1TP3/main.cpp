#include <iostream>

using namespace std;

int main()
{
    int entier;
    int i;

    cout<<"Saisir un entier positif"<<endl;
    cin>>entier;

    for(i=2 ; i<entier-1 ; i++)
    {
        if (entier%i==0)
        {

            cout<<i<<endl;

        }
        else
        {

            cout<<"Cet entier n'est pas divisible"<<endl;




    }






    return 0;
}
