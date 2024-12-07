#include <iostream>
using namespace std;
const int SUP = 10;
const int MAXESSAIS = 4;
int nb,mult,cpt;
bool trouve;
int main()

{
    cout<<" Donne-moi un nombre positif plus petit que "<<SUP<<" :"<<endl;
    cin>>nb;
    cout<<" Bien. Maintenant donne-moi un multiple de "<<nb<<" :"<<endl;
    cin>>mult;

    cpt=0;
    trouve=false;
    while(cpt<MAXESSAIS && !trouve){
            cpt++;
        if(mult%nb==0){
            cout<<"Bravo ! Tu as trouvé un multiple de " <<nb<<" en "<<cpt<<" essais."<<endl;
            trouve=true;
        }else{
            if(cpt<=3){
            cout<<mult<<"n'est pas un multiple de "<<nb<<". Essaie encore :"<<endl;
            cin>>mult;
            }
        }
    }
    if(!trouve){
        cout<<"Dommage, "<<mult<<" n'est toujours pas un multiple de "<<nb<< ". Relance le programme quand tu voudras rejouer !"<<endl;

    }




    return 0;
}
