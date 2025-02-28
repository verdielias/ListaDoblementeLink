#ifndef ListaDoble_HPP_INCLUDED
#define ListaDoble_HPP_INCLUDED
template<typename T>
class ListaDoble{
public:
    //Constructor
    ListaDoble();
    //Constructor de copias
    ListaDoble(const ListaDoble &LS);
    //Operador igual
    ListaDoble<T>& operator= (const ListaDoble<T> &v);
    // Destructor
    ~ListaDoble();
    //Agregar al inicio
    void AgregarAlInicio(T valor);
    //Agregar al final
    void AgregarAlFinal(T valor);
    //Agregar en cierta posicion
    void AgregrarEnPosicion(T valor, int posicion);
    //Eliminar al inicio
    void EliminarAlInicio();
    //Eliminar al final
    void EliminarAlFinal();
    //Eliminar cierta posicon
    void EliminarEnPosicion( int posicion);
    //Eliminar un valor
    void EliminarValor(T valor);
    //Buscar un valor
    bool Buscar(T valor) const;
    //Obtener el primero
    T ObtenerPrimero() const;
    //Obtener el ultimo
    T ObtenerUltimo() const;
    //Obtener el que esta en cierta posicion
    T ObtenerValor(int posicion) const;
    //Obtener la posicion de cierto elemento
    int ObtenerPosicion(T val) const;
    //Conocer el numero de elementos
    int ConocerNumElem();
    //Copnocer si la lista esta vacia
    bool EstaVacia() const ;
    //Vaciar
    void Vaciar();
    //Imprimir
    void Imprimir() const;
    //Imprimir al revez
    void ImprimirReversa() const;



private:
    int numElem;
    struct Elemento{
      T valor;
      Elemento * siguiente;
      Elemento * anterior;
      Elemento(T v, Elemento * sig = nullptr, Elemento * ant = nullptr){
        valor = v;
        siguiente = sig;
        anterior = ant;

      }
    }*primero, *ultimo;
};

#include "ListaSimple.tpp"

#endif // ListaDoble_HPP_INCLUDED
