#include "fonctionFacebook.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fonction d'initialisation pour cr�er le r�seau d'amis
vector<vector<bool>> initialisation(int x)
{
    vector<vector<bool>> friends;  // Le r�seau d'amis
    int i;

    for (i = 0; i < x; i++) {
        friends.push_back(vector<bool>(x, false));  // Initialisation : personne n'est ami avec personne
        friends[i][i] = true;  // Chacun est ami avec lui-m�me
    }
    return friends;
}

// Fonction d'affichage pour afficher le r�seau d'amis
void affichage(const vector<vector<bool>> &x)
{
    int i, j;
    for (i = 0; i < x.size(); i++) {
        cout << i << " est ami avec :";
        for (j = 0; j < i; j++)
            if (x[i][j]) cout << " " << j;  // Afficher les amis de gauche
        for (j = i + 1; j < x[i].size(); j++)
            if (x[i][j]) cout << " " << j;  // Afficher les amis de droite
        cout << endl;
    }
}

// Proc�dure pour ajouter des amis entre deux personnes
void ajoutAmis(vector<vector<bool>> &x, int y, int z)
{
    x[y][z] = x[z][y] = true;  // Mettre � jour la matrice d'amiti� sym�triquement
}

// Fonction pour compter le nombre d'amis communs entre deux personnes
int amisCommuns(const vector<vector<bool>> &x, int y, int z)
{
    int i, cpt = 0;
    for (i = 0; i < x.size(); i++) {
        if (x[y][i] && x[z][i]) {
            cpt++;
        }
    }
    return cpt;
}

// La fonction groupeAmis retourne vrai si 3 personnes forment un groupe d'amis
// o� chacun est ami avec les deux autres, sinon elle retourne faux.
bool groupeAmis(const vector<vector<bool>> &reseau, int a, int b, int c)
{
    // V�rifier si les trois personnes sont mutuellement amies
    bool res = reseau[a][b] && reseau[b][a] && reseau[a][c] && reseau[c][a] && reseau[c][b] && reseau[b][c];
    return res;
}
