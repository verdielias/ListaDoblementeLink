#include <iostream>
#include "ListaSimple.hpp"
using namespace std;

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

        cout << "Intercambiar listas" << endl;
        lista2.AgregarAlFinal('f');
        lista.IntercambiarListas(lista2);


        cout << "swap" << endl;
        lista.Imprimir();
        cout  << endl;
        lista2.Imprimir();

    }catch(const char * mensaje){
        cerr << mensaje << endl;
    }


    return 0;
}
