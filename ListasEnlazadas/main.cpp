#include <iostream>
#include "ListaSimple.hpp"
using namespace std;
/**

 * \file main.cpp

 * \author Flor Machado y Elias Peregrina

 * \date 4/02/2025

 */
 
 bool EsPar(char valor);
 
int main()
{
    try{
        ListaDoble<char> lista, lista2;
        //lista.EliminarAlFinal(); probado lista vacia
        lista.AgregarAlInicio('A');
        lista.AgregarAlFinal('E');
        lista.AgregarAlFinal('O');
        lista.AgregarEnPosicion('I', 2);
        lista.Imprimir();

        cout << endl <<"Intercambiar listas" << endl;
        lista2.AgregarAlFinal('F');


        lista.IntercambiarListas(lista2);
        cout << "swap" << endl;
        lista.Imprimir();
        cout  << endl;
        lista2.Imprimir();

        cout << endl << endl;
        cout << "Transferir rango" << endl;
        lista2.TransferirRango(lista, 0, 2);
        lista.Imprimir();

        cout << endl << endl;
        cout << "Transferir desde indice" << endl;
        lista2.TransferirDesdeIndice(lista, 1);
        lista.Imprimir();

        cout << endl << endl;
        cout << "Transferir elementos" << endl;
        lista2.TransferirElementos(lista);
        lista.Imprimir();
        
        cout << endl << endl;
        cout << "Eliminar todos los repetidos" << endl;
        lista2.EliminarRepetidos();
        lista2.Imprimir();        
        
        cout << endl << endl;
        cout << "Eliminar si son pares" << endl;
        lista2.EliminarSi(EsPar);
        lista2.Imprimir();        
        
        cout << endl << endl;
        cout << "Eliminar ocurrencias" << endl;
        lista2.EliminarOcurrencias('E');
        lista2.Imprimir();
        

        

    }catch(const char * mensaje){
        cerr << mensaje << endl;
    }


    return 0;
}

bool EsPar(char valor) {
    return valor % 2 == 0;
}
        
