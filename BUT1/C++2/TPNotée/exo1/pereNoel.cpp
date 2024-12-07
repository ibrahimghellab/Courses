#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"
//"train","jeu video","poupee","jeu de societe","ballon","ordinateur","poupee","train","ballon"};

PereNoel::PereNoel(){
    for(int i=0;i<JEUX.size();i++){
        _hotte.push_back(JEUX[i]);
    }
}

bool PereNoel::offreCadeau( Enfant& e){
    if(_hotte.size()<1){
        return(false);
    }else{
        if(e.possede(_hotte[_hotte.size()-1])==false){
            e.recoitCadeau(_hotte[_hotte.size()-1]);

        }

        return(true);

    }
}
