#include <iostream>
using namespace std;
extern "C" long long int factoriel(long long int);
int main()
{
	long long int a;
	cout << endl << "Ce programme sert a calculer la valeur de la factorielle  d'un entier" << endl << endl;
		cout << "Entrez une valeur entiere pour a : "; cin >> a;

	cout << endl << "Pour a = " << a << " : " << a << " !"
		<< " = " << factoriel(a) << endl; 
	return 0;
}