#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> v1 = {2,3,-2,-3-2568654,4,4,4};
    //Q1
    for(int i=0;i<v1.size()-1;i++){
        cout<<v1[i]<<";";
    }
    cout<<v1[v1.size()-1]<<endl;

    //Q2

    vector<int> v2;

    for(int i=v1.size()-1;i>=0;i--){
        v2.push_back(v1[i]);
    }

    //Q3
    int maxi=0,cpt=0;
    for(int i=0; i<v1.size(); i++)
        {
            if(v1[i] > maxi)
            {
                maxi = v1[i];
                cpt=1;
            }
            else if (v1[i] == maxi)
                cpt++;
        }


    cout<<"La valeur la plus grande est "<<maxi<<" et elle apparait "<<cpt<<" fois."<<endl;






    return 0;
}
