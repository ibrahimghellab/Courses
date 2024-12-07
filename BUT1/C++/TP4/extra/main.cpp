#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool croissant = true; // Initialisez croissant � true car c'est le cas de d�part
    bool tousDifferents = true; // Initialisez tousDifferents � true

    vector<float> tab = {0};

    for (int i = 0; i < tab.size() - 1; i++) {
        if (tab[i] > tab[i + 1]) { // Si le tableau n'est pas dans l'ordre croissant
            croissant = false; // D�finissez croissant � false
            break; // Sortez de la boucle d�s qu'un �l�ment non croissant est trouv�
        }

        for (int j = i + 1; j < tab.size(); j++) {
            if (tab[i] == tab[j]) { // Si deux �l�ments sont �gaux, ils ne sont pas tous diff�rents
                tousDifferents = false;
                break; // Sortez de la boucle int�rieure si un �l�ment identique est trouv�
            }
        }
    }

    if (croissant) {
        cout << "Ordre croissant" << endl;
    } else {
        cout << "Ordre d�croissant" << endl;
    }

    if (tousDifferents) {
        cout << "Tous les �l�ments sont diff�rents" << endl;
    } else {
        cout << "Au moins deux �l�ments sont identiques" << endl;
    }

    return 0;
}
