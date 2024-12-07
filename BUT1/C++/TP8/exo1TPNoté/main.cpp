#include <iostream>
#include <vector>
#include"gestionNotes.h"
#include <string>
using namespace std;

const int NBETUD = 20 ;
const int AFFICHENOTES = 1 ;
const int MOY = 2 ;
const int MAJOR = 3 ;
const int QUIT = 0;

int main()
{
    vector<vector<int>> notes (NBETUD );
    vector<float> moyennes (NBETUD,0.0);
    vector<string> etudiants= {"Robert","Johnson","Lucy","Emily","Sean","Clarence","Max",
                               "Vladymmir","Franck","Shaun","Thesee","Carla","Eli","Olga",
                               "Freeman","Benjamin","Baxter","Philipps","Taylor","Kewani"
                              };
    /* g�n�ration des notes des �tudiants
            NE PAS MODIFIER !
    */
    int C = 314 ;
    int n =  C%117 + 53;
    for(unsigned int i=0; i<NBETUD; i++ )
    {
        int nbnotes = 12 + (C*(i+7))%53;
        for(int  j=0; j< nbnotes ; j++ )
        {
            notes[i].push_back(n%21);
            n= (17*n +31)% 367;
        }
    }
    /* FIN de la g�n�ration des notes*/

    return 0;

}
