#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool croissant = true; // Initialisez croissant à true car c'est le cas de départ
    bool tousDifferents = true; // Initialisez tousDifferents à true

    vector<float> tab = {0};

    for (int i = 0; i < tab.size() - 1; i++) {
        if (tab[i] > tab[i + 1]) { // Si le tableau n'est pas dans l'ordre croissant
            croissant = false; // Définissez croissant à false
            break; // Sortez de la boucle dès qu'un élément non croissant est trouvé
        }

        for (int j = i + 1; j < tab.size(); j++) {
            if (tab[i] == tab[j]) { // Si deux éléments sont égaux, ils ne sont pas tous différents
                tousDifferents = false;
                break; // Sortez de la boucle intérieure si un élément identique est trouvé
            }
        }
    }

    if (croissant) {
        cout << "Ordre croissant" << endl;
    } else {
        cout << "Ordre décroissant" << endl;
    }

    if (tousDifferents) {
        cout << "Tous les éléments sont différents" << endl;
    } else {
        cout << "Au moins deux éléments sont identiques" << endl;
    }

    return 0;
}
