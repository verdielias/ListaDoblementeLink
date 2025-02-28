#include <iostream>
#include "ListaSimple.hpp"
using namespace std;

int main()
{
    try{
        ListaDoble<char> lista;
        //lista.EliminarAlFinal(); probado lista vacia
        lista.AgregarAlInicio('A');
        lista.AgregarAlFinal('E');
        lista.AgregarAlFinal('O');
        lista.AgregrarEnPosicion('I', 2);
        lista.Imprimir();
        cout << endl;
        lista.EliminarAlInicio();

        lista.Imprimir();
        cout << endl;
        lista.EliminarAlFinal();
        lista.Imprimir();
        lista.AgregarAlInicio('B');
        lista.AgregarAlInicio('I');
        lista.AgregarAlInicio('M');
        lista.AgregarAlInicio('O');
        //lista[2] = 'Z';
        cout << endl;
        lista.Imprimir();
        cout << endl;
        cout << "Cantidad de elementos: "<< lista.ConocerNumElem() << endl;
        cout << endl;
        lista.EliminarEnPosicion(4);
        lista.Imprimir();
        cout << endl;
        lista.EliminarValor('I');
        lista.Imprimir();

        cout << endl;
        lista.ImprimirReversa();
        cout << endl;
        cout << "Buscar I: "<< (lista.Buscar('I') ? "Si hay" : "No hay") << endl;
        cout << endl;
        cout << "Buscar N: "<< (lista.Buscar('N') ? "Si hay" : "No hay") << endl;
        cout << endl;

        lista.Vaciar();
        lista.Imprimir();

    }catch(const char * mensaje){
        cerr << mensaje << endl;
    }


    return 0;
}
