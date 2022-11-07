 #ifndef NODO_HPP
#define NODO_HPP
#include <iostream>
using namespace std;

template<typename T>
class NodoT{
    //atributos
    private:
        T dato;
        NodoT<T> * siguiente;
        NodoT<T> * anterior;
    //metodos
    public:
        T getDato(){return this->dato;}
        void setDato(int dato){this->dato=dato;}
        NodoT<T> * getSiguiente(){return this->siguiente;}
        void setSiguiente(NodoT * siguiente){this->siguiente=siguiente;}
        NodoT<T> * getAnterior(){return this->anterior;}
        void setAnterior(NodoT * anterior){this->anterior=anterior;}
        //Constructores
        NodoT<T>(){
            this->dato=NULL;
            this->siguiente=nullptr;
            this->anterior=nullptr;
        } 
        NodoT<T>(T dato,NodoT<T> * siguiente, NodoT<T> * anterior){
            this->dato=dato;
            this->siguiente=siguiente;
            this->anterior=anterior;
        }
      
        //Destructores
        ~NodoT(){
            cout<<"Destructor"<<endl;
        }
};
#endif


