#include <iostream>
using namespace std;
extern "C" double polynome2double(double a, double b, double c, double n);
int main()
{
	double a, b, c, n;
	cout << endl << "Ce programme sert a calculer la valeur d'un polynome entier desecond degre a * n ^ 2 + b * n + c" << endl << endl;
		cout << "Entrez une valeur entiere pour a : "; cin >> a;
	cout << "Entrez une valeur entiere pour b : "; cin >> b;
	cout << "Entrez une valeur entiere pour c : "; cin >> c;
	cout << "Entrez une valeur entiere pour n : "; cin >> n;
	cout << endl << "Pour n = " << n << " : " << a << "*n^2 + " << b << "*n + " << c
		<< " = " << polynome2double(a, b, c, n) << endl;
	return 0;
}