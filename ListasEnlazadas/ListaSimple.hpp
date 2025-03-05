#ifndef ListaDoble_HPP_INCLUDED
#define ListaDoble_HPP_INCLUDED

/**

 * \file ListaSimple.hpp

 * \author Flor Machado y Elias Peregrina

 * \date 4/02/2025

 */
template<typename T>
class ListaDoble{
public:
    //Constructor
    /** \brief Constructor de la clase
     */
     ListaDoble();
    //Constructor de copias
    /** \brief Constructor de la clase para copiar otros objetos de la clase
     *
     * \param c const ListaDoble&
     *
     */ListaDoble(const ListaDoble &LS);
    //Operador igual
    /** \brief M&eacute;todo del operador = para copiar objetos de la clase a otros objetos
     *
     * \param const ListaDoble &v, el objeto de la clase que va a copiar
     */ListaDoble<T>& operator= (const ListaDoble<T> &v);
    // Destructor
    /** \brief Destructor de la clase
     *
     *
     */~ListaDoble();
    //Agregar al inicio
    /** \brief M&eacute;todo para a&ntilde;adir cosas de T como primero de la lista
     *
     * \param valor T, el valor que se va a a&ntilde;adir a la lista
     * \return void
     *
     */void AgregarAlInicio(T valor);
    //Agregar al final
    /** \brief M&eacute;todo para a&ntilde;adir cosas de T a lo �ltimo de la lista
     *
     * \param valor T, el valor que se va a a&ntilde;adir a la lista
     * \return void
     *
     */void AgregarAlFinal(T valor);
    //Agregar en cierta posicion
    /** \brief M&eacute;todo para a&ntilde;adir cosas de T en cierta posici�n en la lista
     *
     * \param valor T, el valor que se va a a&ntilde;adir a la lista
     * \return void
     *
     */void AgregarEnPosicion(T valor, int posicion);
    //Eliminar al inicio
    /** \brief M&eacute;todo para eliminar el primero valor de la lista
     *
     * \return void
     *
     */void EliminarAlInicio();
    //Eliminar al final
    /** \brief M&eacute;todo para eliminar el ultimo valor de la lista
     *
     * \return void
     *
     */void EliminarAlFinal();
    //Eliminar cierta posicon
    /** \brief M&eacute;todo para eliminar un valor en cierta posici�n de la lista
     *  \param int posicion, posici�n donde esta el valor a eliminar
     * \return void
     *
     */void EliminarEnPosicion( int posicion);
    //Eliminar un valor
    /** \brief M&eacute;todo para eliminar un valor de la lista
     *  \param T valor, el valor a eliminar
     * \return void
     *
     */void EliminarValor(T valor);
    //Buscar un valor
    /** \brief M�todo para buscar la existencia de un valor en espec�ficio
     *
     * \param valor T, el valor que se quiere encontrar en la lista
     * \return bool, retorna s�, si existe ese valor en la lista
     *
     */
    bool Buscar(T valor) const;
    //Obtener el primero
    /** \brief M&eacute;todo para obtener el primer valor de la lista
     *
     * \return T, el valor que se quiere obtener
     *
     */T ObtenerPrimero() const;
    //Obtener el ultimo
    /** \brief M&eacute;todo para obtener el �ltimo valor de la lista
     *
     * \return T, el valor que se quiere obtener
     *
     */T ObtenerUltimo() const;
    //Obtener el que esta en cierta posicion
    /** \brief M&eacute;todo para obtener un valor en cierta posici�n de la lista
     *\param int posicion, posici�n donde esta el valor que se quiere obtener
     * \return T, el valor que se quiere obtener
     *
     */T ObtenerValor(int posicion) const;
    //Obtener la posicion de cierto elemento
    /** \brief M&eacute;todo para obtener la posici�n de un valor de la lista
     *\param T valor, el valor del que queremos encontrar su posici�n
     * \return int, la posici�n del valor que se quiere obtener
     *
     */int ObtenerPosicion(T val) const;
    //Conocer el numero de elementos
    /** \brief M&eacute;todo para conocer la cantidad de elementos que tiene la lista
     *
     * \return int cantidad de elementos de la lista
     *
     */int ConocerNumElem();
    //Conocer si la lista esta vacia
    /** \brief M&eacute;todo para conocer si la lista esta vac&iacute;a o no
     *
     * \return bool
     *
     */bool EstaVacia() const ;
    //Vaciar
    /** \brief M&eacute;todo que vac&iacute;a la lista
     *
     * \return void
     *
     */void Vaciar();
    //Imprimir
    /** \brief M&eacute;todo que imprime los valores de la lista
     *
     * \return void
     *
     */void Imprimir() const;
    //Imprimir al revez
    /** \brief M&eacute;todo que imprime los valores del �litmo al primero de la lista
     *
     * \return void
     *
     */void ImprimirReversa() const;
    //Intercambiar dos listas entre si
    /** \brief M�todo que intercambia los valores de una lista y la otra
     *
     * \param v ListaDoble<T>&, la lista que se conseguir�n los valores a intercambiar
     * \return void
     *
     */
    void IntercambiarListas( ListaDoble<T> &v);
    //Transferir un rango de elementos de una lista a otra;
    /** \brief M�todo que transfiere valores de una lista, en cierto rango, hacia otra lista
     *
     * \param v ListaDoble<T>&, la lista que se conseguir�n los valores a transferir
     * \param inicio int, el primer valor del rango
     * \param fin int, el �ltimo valor del rango
     * \return void
     *
     */
    void TransferirRango( ListaDoble<T> &v, int inicio, int fin);
    //Operador sobre cargado para acceder a un elemento (lvalue)
    T& operator[](int index);
    //Operador sobre cargado para acceder a un elemento (rvalue)
        const T& operator[](int index) const;
    //Transferir desde cierto indice en adelante
    /** \brief M�todo que transfiere valores de una lista, desde un ind�ce hasta el �ltimo, hacia otra lista
     *
     * \param v ListaDoble<T>&, la lista que se conseguir�n los valores a transferir
     * \param inicio int, la posici�n de donde iniciar lo que se transfiere
     * \return void
     *
     */void TransferirDesdeIndice( ListaDoble<T> &v, int inicio);
    //Transferir todos los elementos de una lista a otra
    /** \brief M�todo que transfiere todos valores de una lista, hacia otra lista
     *
     * \param v ListaDoble<T>&, la lista que se conseguir�n los valores a transferir
     * \return void
     *
     */void TransferirElementos(ListaDoble<T> &v);
    //Eliminar toda ocurrencia de un elemento
     void EliminarOcurrencias(T valor);
    //Eliminar por condicion
     void EliminarSi(bool (*condicion)(T));
    //Eliminar todo elemento repetido
     void EliminarRepetidos();
     //Ordenar datos
     void OrdenarLista();

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
