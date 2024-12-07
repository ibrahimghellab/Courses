#include <iostream>

using namespace std;

int main()
{
    int temp1;
    int moyenne;
    moyenne = 0;

    cout<< "Entrer une temperature " << endl;
    cin>> temp1;


    moyenne = moyenne + temp1;
    cout<< "Entrer une temperature " << endl;
    cin>> temp1;


    moyenne = moyenne + temp1;
    cout<< "Entrer une temperature " << endl;
    cin>> temp1;


    moyenne = (moyenne + temp1)/3;

    cout<< "la moyenne de la temperature est : "<<moyenne<<endl;



    return 0;
}
