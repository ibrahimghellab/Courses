/// TP Recherche, exo 2, decembre 2023, CB
/// Version etudiants
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

/// ============== Prototypes et constantes

const int STOP = 999;

/// afficher : affiche le contenu du vecteur v suivi des indices
void afficher(const vector<int> & v);

/// rechercheDicho : retourne un indice où se trouve val dans le vecteur v, ou bien -1 si val ne se trouve pas dans tab
int rechercheDicho (const vector<int> & v, int val);

/// recherchePetit : retourne le plus petit indice où se trouve val dans le vecteur v, ou bien -1 si val ne se trouve pas dans tab
int recherchePetit (const vector<int> & tab, int val);

/// ============== Programme principal

int main()
{
    vector<int> v1 = {0,1,2,2,2,5,7,7,7,9};
    int val;    /// la valeur recherchée
    int ind;    /// l'indice retourné par la fonction de recherche

    cout << "Contenu vecteur : " << endl;
    afficher(v1);

    cout << "\nQuelle valeur recherchez vous ? (" << STOP << " pour finir)" << endl;
    cin >> val;

    while (val!=STOP)
    {
        cout << "Resultat recherche dicho de base : " << endl;
        ind = rechercheDicho(v1, val);
        if (ind != -1)
            cout << val << " se trouve dans le tableau a l'indice " << ind << endl;
        else
            cout << val << " ne se trouve pas dans le tableau." << endl;

        cout << "Resultat recherche dicho petit : " << endl;
        ind = recherchePetit(v1, val);
        if (ind != -1)
            cout << "La premiere occurrence de " << val << " se trouve a l'indice "<< ind << endl;
        else
            cout << val << " ne se trouve pas dans le tableau." << endl;

        cout << "\nQuelle valeur recherchez vous ?" << endl;
        cin >> val;
    }

    return 0;
}

/// ============== Définitions des sous-programmes

/// afficher : affiche le contenu du vecteur v suivi des indices
void afficher(const vector<int> & v)
{
    cout << "valeurs : ";
    for (int i=0 ; i<v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl;
    cout << "indices : ";
    for (int i=0 ; i<v.size() ; i++)
        cout << i << " " ;
    cout << endl;
}

/// rechercheDicho : retourne un indice où se trouve val dans le vecteur v, ou bien -1 si val ne se trouve pas dans tab
int rechercheDicho (const vector<int> & v, int val)
{

 bool trouve=false;
 int debut=0,fin=v.size(),milieu;
 while (!trouve && debut<=fin){
    milieu=(debut+fin)/2;
    trouve=v[milieu]==val;
    if (!trouve){
        if(tab[milieu]>val){
            fin=milieu-1;
        }else{
            debut=milieu.1;
        }
    }
 }

    return (12345);
}

/// recherchePetit : retourne le plus petit indice où se trouve val dans le vecteur v, ou bien -1 si val ne se trouve pas dans tab
int recherchePetit (const vector<int> & tab, int val)
{
    return (12345);
}
