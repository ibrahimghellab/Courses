#include "cadeau.h"
#include "enfant.h"

Enfant::Enfant(const string &n)
{
    _nom=n;
}
string Enfant::nom()const
{
    return _nom;
}

void Enfant::affiche()const
{
    cout<<_nom<<" : "<<endl;
    if(_sac.size()>=1)
    {
        for(int i=0; i<_sac.size(); i++)
        {
            cout<<_sac[i].getDesc()<<" , ";
        }
    }
    else
    {
        cout<<"n'a pas encore de cadeaux"<<endl;
    }
}

void Enfant::recoitCadeau(const Cadeau& c)
{
    _sac.push_back(c);
}

bool Enfant::possede(const Cadeau& c)
{
    int i=0;
    bool trouve;
    while(i<_sac.size() && !trouve)
    {
        if(c.getDesc()==_sac[i].getDesc())
        {
            trouve=true;
        }
        i++;
    }
    return(trouve);
}

