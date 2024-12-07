#ifndef _ENFANT_
#define _ENFANT_

class Enfant {
   private:

    string _nom;
    vector<Cadeau> _sac;
 public:
    Enfant(const string & n="toto");
    string nom()const;
    void affiche()const;
    void recoitCadeau(const Cadeau& c);

    bool possede(const Cadeau& c);

};

#endif
