#include <iostream>
#include <vector>

using namespace std;
int i,plusgrandevaleur=0,valeurtemp,apparitionvaleur,cpt;
int val,n;
bool trouve, changer;
int main()
{
    vector<int> v1 = {-2, 3, 7, 1, 2, 3, 7, 3, -2, 7, 0};
    //Question 1
        for(i=0; i<v1.size()-1; i++)
        {

            cout<<v1[i]<<";";




        }
        cout<<v1[v1.size()-1];

    //Question 2
        vector<int> v2;
        for(i=v1.size()-1; i>=-1; i--)
        {
            v2.push_back(v1[i]);
        }
    //Question 3
    for(i=0; i<v1.size(); i++)
    {
        valeurtemp=v1[i];
        if(valeurtemp>plusgrandevaleur)
        {
            plusgrandevaleur=valeurtemp;
            cpt=0;
            changer=true;

        }

        if(plusgrandevaleur>=valeurtemp && changer)
        {
            cpt++;
        }
        else
        {
            cpt=0;
        }



    }
    cout<<"La valeur la plus grande est "<<plusgrandevaleur<<" et elle apparait "<<cpt<<" fois";

    //Question 4

    cout<<"Saissisez une valeur et un nombre positif"<<endl;
    cin>>val;
    cin>>n;
    for(i=0; i<v1.size(); i++)
    {

        if(val==v1[i] || n<=cpt)
        {
            trouve=true;
        }


    }
    if(trouve)
    {
        cout<<"La valeur "<<val<<" apparait au moins "<<n<<" fois.";
    }
    else
    {
        "non trouvé";
    }









    return 0;
}

//     Jeu d'essai
//Test abstrait                                                   Test concret              Résultat attendu
//cas1
//La valeur apparait dans le vecteur au moins n fois               3 et 2                    La valeur 3 apparait au moins 2 fois
//cas2
//LA valeur n'apparait pas dans le vecteur                          20 et 5                   non trouvé
//cas3
//La valeur apparait dans le vecteur mais pas au moins n fois       7 et 15                   non trouvé

