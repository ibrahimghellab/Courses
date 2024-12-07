// HBM novembre 2023
// vers les exceptions
// TP8 programme a completer
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

float operation(char op, float a, float b);

int main()
{
    char op; // operation demandee
    float a,b; // on met ici des valeurs pour tester
    float res;
    a=5,b=2;
    op = '*'; //-----------------  test de la multiplication
    cout << a << op << b << endl;
    res =  operation(op,a,b);
    if(res==10)cout << "test OK "<< res<<endl;
    else cout <<"Erreur"<< res << endl;
    op = '+';  //----------------- test de l'addition
    cout << a << op << b << endl;
    res =  operation(op,a,b);
    if(res==7)cout << "test OK "<< res<<endl;
    else cout <<"Erreur"<< res << endl;
    op = '-';  //------------------  test de la soustraction
    cout << a << op << b << endl;
    res =  operation(op,a,b);
    if(res==3)cout << "test OK "<< res<<endl;
    else cout <<"Erreur"<< res << endl;


    op = '/';  //------------------  test de la division
    cout << a << op << b << endl;
    res =  operation(op,a,b);
    if(res==2.5)cout << "test OK "<< res<<endl;
    else cout <<"Erreur"<< res << endl;


try{
    //Test ok
    b=0;
    op='/';
    res=operation(op,a,b);
    cout<<res<<endl;

    }catch (int){
    cerr<<"division par 0 impossible"<<endl<<endl;
}

try{



//Test op
b=0;
op='d';
res=operation(op,a,b);
cout<<res<<endl;
    }catch(string s){
        cerr<<s<<endl;
    }
return 0;
}


// retourne le resultat de l'operation entre a et b
// precisee par le caractere op (+, -, /, *)
float operation(char op, float a, float b)
{

    float res;
    if(op!='+' && op!='-' && op!='/' && op!='*'){
        throw string("opération inconnue ")+op;
    }
    switch(op)
    {
    case '/':
        if(b==0){
            throw string("fqdqzd");
        }
        res = a/b;
        break;
    case '+':
        res = a+b;
        break;
    case '*':
        res = a*b;
        break;
    case '-':
        res = a-b;
        break;
    }
    return res;
}

