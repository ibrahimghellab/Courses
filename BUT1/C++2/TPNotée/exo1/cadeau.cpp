#include "cadeau.h"


string Cadeau::getDesc() const{
  return _description;
}

bool Cadeau::memeCadeau(const Cadeau& c)const{
    return(c._description==_description);
}

