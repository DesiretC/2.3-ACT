#include "NodoT.hpp"

template <class Bitacora>
class ListaCircular{
    NodoT<Bitacora> * last;
    int tam;
    //setters y getters
    public: 
        NodoT<Bitacora> * getLast(){return this->last;}
        void setLast(NodoT<Bitacora> * last){this->last=last;}
        
    ListaCircular(){
        this->last=nullptr;
        this->tam=0;
    }

    void agregarInicio(Bitacora dato){ //O(1)
        if(this->last){//Lista circular tiene nodos
            //Crea un nuevo nodo y lo apunta al head (last->getSiguiente)
            NodoT<Bitacora> * nuevo = new NodoT<Bitacora>(dato,this->last->getSiguiente());
            //Actualizr el apuntador de last y conectarlo al nuevo nodo
            this->last->setSiguiente(nuevo);
        }else{//Lista vacia
            NodoT<Bitacora> * nuevo = new NodoT<Bitacora>(dato,nullptr);//Creando el nuevo nodo
            nuevo->setSiguiente(nuevo);//Como solo hay un nodo el apuntador siguiente será asi mismo
            this->last=nuevo; //El nuevo nodo será el último y el primero al mismo tiempo            
        }
        this->tam++;
    }

    void agregarFin(Bitacora dato){
        if(this->last){//Lista circular tiene nodos
            //Crea un nuevo nodo y lo apunta al head (last->getSiguiente)
            NodoT<Bitacora> * nuevo = new NodoT<Bitacora>(dato,this->last->getSiguiente());
            //Actualizr el apuntador de last y conectarlo al nuevo nodo
            this->last->setSiguiente(nuevo);
            this->last=nuevo;
        }else{//Lista vacia
            NodoT<Bitacora> * nuevo = new NodoT<Bitacora>(dato,nullptr);//Creando el nuevo nodo
            nuevo->setSiguiente(nuevo);//Como solo hay un nodo el apuntador siguiente será asi mismo
            this->last=nuevo; //El nuevo nodo será el último y el primero al mismo tiempo            
        }
        this->tam++;
    }

    void imprimirLista(){
        if(this->last){
            NodoT<Bitacora> * nodo = this->last->getSiguiente();
            do{
                cout<<nodo->getDato()<<" ";
                nodo = nodo->getSiguiente();
            }while(nodo!=this->last->getSiguiente());
        }
        cout<<endl;
    }

    NodoT<Bitacora> * eliminarInicio(){
        if(this->last){
            NodoT<Bitacora> * nodoInicial = this->last->getSiguiente();
            if(this->tam==1)
                this->last=nullptr;
            else    
                this->last->setSiguiente(nodoInicial->getSiguiente());
            this->tam--;
            //opc
            nodoInicial->setSiguiente(nullptr);
            return nodoInicial;
        }
        return nullptr;
    }

};