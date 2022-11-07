#ifndef LISTA2CIRCULAR_HPP
#define LISTA2CIRCULAR_HPP
#include "NodoT.hpp"

template <typename T>
class Lista2Circular{
    NodoT<T> * head;
    int tam;
    public:
        Lista2Circular<T>(){
            this->head=nullptr;
            this->tam=0;
        }

        void agregarInicio(T dato){
             if(this->head==nullptr){
                NodoT<T> * nuevo = new NodoT<T>(dato,this->head, this->head);
                nuevo->setAnterior(nuevo);
                nuevo->setSiguiente(nuevo);
                this->head=nuevo;
                this->tam++;
             }
             else{
                NodoT<T> * nuevo = new NodoT<T>(dato, this->head, this->head->getAnterior());
                head->getAnterior()->setSiguiente(nuevo);
                head->setAnterior(nuevo);
                this->head=nuevo;
                this->tam++;
                
             }
        }

          NodoT<T> * buscarNodo(T dato){
            NodoT<T> * nodo= this->head;
            while(nodo){
                if(nodo->getDato()==dato){
                    cout <<"Existe"<<endl;
                    return nodo;
                }
                nodo=nodo->getSiguiente();
            }
            cout << "No existe" <<endl;
            return nullptr;
        }

        void eliminarNodo(T dato){
             NodoT<T> * nodoActual;
             nodoActual=buscarNodo(dato);

            if(this->head==nodoActual){
                nodoActual->getSiguiente()->setAnterior(nodoActual->getAnterior());
                nodoActual->getAnterior()->setSiguiente(nodoActual->getSiguiente());
                this->head=nodoActual->getSiguiente();
            }
            else if(this->head->getAnterior()==nodoActual){
                nodoActual->getAnterior()->setSiguiente(nodoActual->getSiguiente());
                nodoActual->getSiguiente()->setAnterior(nodoActual->getAnterior());
                cout<<this->head->getSiguiente()->getSiguiente()->getSiguiente()->getDato()<<endl;
            }
            else{
                nodoActual->getAnterior()->setSiguiente(nodoActual->getSiguiente());
                nodoActual->getSiguiente()->setAnterior(nodoActual->getAnterior());
            }
        }

        void actualizarNodo(T modifier, T nuevo){
            NodoT<T> * nodoActual=buscarNodo(modifier);
            if(nodoActual==nullptr){
                cout << "Error. Valor Inexistente" <<endl;
            }
            else{
                cout<<modifier<<" se cambia a: "<<nuevo<<endl;
                nodoActual->setDato(nuevo);
            }
        

        }
         void imprimirLista2Circular(){
            cout<<"Lista circular"<<endl;
            if(this->head){
                NodoT<T> * nodo = this->head->getAnterior()->getSiguiente();
                cout<<"head => ";
                do{
                    cout<<nodo->getDato()<<"  ";
                    nodo= nodo->getSiguiente();
    
                }while(nodo!=this->head->getAnterior()->getSiguiente());
            
            }
            cout<<endl;
        }

        NodoT<T> * getHead(){
            return this->head;
        }
}; 
#endif
