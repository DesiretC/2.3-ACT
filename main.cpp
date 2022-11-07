#include "bitacora.hpp"
#include "Fila.hpp"
#include "Lista2Circular.hpp"
#include <vector>
#include <fstream> //Biblioteca para lectura y escritura de archivos

int main(){
  
    //Lectura de archivos
    ifstream datos; //Stack
    datos.open("bitacoraSecundaria-1.txt");
    string entrada;

    while(getline(datos,entrada))
        cout<<entrada<<endl;
    
    datos.close();

    //Lectura de archivo separada
   datos.open("bitacoraSecundaria-1.txt");
    string mes, dia,hora,ipp,falla;
    Lista2Circular<Bitacora*> * listaDatos = new Lista2Circular<Bitacora*>(); //heap apuntadores a bitácora
    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ipp,' ');
        getline(datos,falla);
        //log.push_back(new Bitacora(mes,dia,hora,ipp,falla));
        listaDatos->agregarInicio(new Bitacora(mes,dia,hora,ipp,falla));
    }
    datos.close();


    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"----------- Datos con clave -----------"<<endl;

    listaDatos->imprimirLista2Circular();
    NodoT<Bitacora*> * nodo = listaDatos->getHead();
    cout<<"Lista circular"<<endl;
    do{
        nodo->getDato()->imprimirRegistro();
        nodo= nodo->getSiguiente();
    }while(nodo!=listaDatos->getHead());
    
}