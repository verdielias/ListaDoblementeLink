
//Constructor
template <typename T>
ListaDoble<T>::ListaDoble(): numElem(0), primero(nullptr), ultimo(nullptr){}
    //Constructor de copias
    template <typename T>
ListaDoble<T>::ListaDoble(const ListaDoble &LS){
    *this = LS;
}
    //Operador igual
    template <typename T>
ListaDoble<T>& ListaDoble<T>::operator= (const ListaDoble<T> &v){
    if (this == &v) return *this;
    this ->Vaciar();
    Elemento *aux = v.primero;

    while(aux != nullptr){
        this.AgregarAlFinal(aux -> valor);
        aux = aux -> siguiente;
    }
    return *this;
}
    // Destructor
    template <typename T>
ListaDoble<T>::~ListaDoble(){
    Vaciar();
}
//Agregar al inicio
template <typename T>
void ListaDoble<T>::AgregarAlInicio(T valor){
    Elemento * nuevo = new Elemento (valor,primero);

    if(EstaVacia()){
        ultimo=nuevo;
    }else{
        primero->anterior = nuevo;
    }
    primero = nuevo;

    ++numElem;
}

//Agregar al final
template <typename T>
void ListaDoble<T>::AgregarAlFinal(T valor){
    if(EstaVacia()) AgregarAlInicio(valor);
    else{
        Elemento * aux = new Elemento(valor);
        ultimo -> siguiente = aux;
        ultimo = aux;
    }
    ++numElem;
}
//Agregar en cierta posicion
template <typename T>
void ListaDoble<T>::AgregrarEnPosicion(T valor, int posicion){
    if(posicion < 0 || posicion  > numElem) throw "No es posible ubicarse en esa posicion";

    if(posicion == 0) AgregarAlInicio(valor);
    else if(posicion == numElem ) AgregarAlFinal(valor);
    else{
        Elemento * aux = primero;
        for(int i = 1; i < posicion; ++i){
         aux = aux -> siguiente;
        }
        Elemento * nuevo = new Elemento (valor, aux ->siguiente, aux);
        aux -> siguiente -> anterior = nuevo;
        aux -> siguiente = nuevo;
        ++numElem;
    }
}
    //Eliminar al inicio
template <typename T>
void ListaDoble<T>::EliminarAlInicio(){
    if(EstaVacia())throw "La lista esta vacia";
    else if(numElem==1){
        primero=nullptr;
        ultimo=nullptr;
    }
    else {
        Elemento * porBorrar  = primero;
        primero = primero -> siguiente;

        porBorrar->siguiente->anterior = nullptr;

        delete porBorrar;
    }

    --numElem;
}
    //Eliminar al final
    template <typename T>
void ListaDoble<T>::EliminarAlFinal(){
    if(EstaVacia())throw "La lista esta vacia";
    Elemento * porBorrar  = ultimo;

    if(numElem == 1) {
        primero = nullptr;
        ultimo = nullptr;
    }
    else {
        Elemento * aux = primero;
        while(aux -> siguiente != ultimo){
            aux = aux -> siguiente;
        }
        aux -> siguiente = nullptr;
        ultimo = aux;
    }
    delete porBorrar;
    --numElem;
}
    //Eliminar cierta posicion
    template <typename T>
void ListaDoble<T>::EliminarEnPosicion( int posicion){
    if(posicion < 0 || posicion  > numElem) throw "No es posible ubicarse en esa posicion";
    if(EstaVacia())throw "La lista esta vacia";
    else if(posicion == 0) EliminarAlInicio();
    else if(posicion == numElem ) EliminarAlFinal();
    else {
        Elemento * porBorrar  = primero;
        for(int i = 0 ; i < posicion; ++i){
            porBorrar = porBorrar -> siguiente;
        }
        porBorrar -> siguiente -> anterior = porBorrar -> anterior;
        porBorrar -> anterior -> siguiente = porBorrar -> siguiente;

        delete porBorrar;
        --numElem;
    }
}
    //Eliminar un valor
    template <typename T>
void ListaDoble<T>::EliminarValor(T valor){
    if(EstaVacia())throw "La lista esta vacia";
    if(!Buscar(valor)) throw "Ese valor no esta en la lista";
    int pos = ObtenerPosicion(valor);
    EliminarEnPosicion(pos);
}
    //Buscar un valor
template <typename T>
bool ListaDoble<T>::Buscar(T valor) const {
    if(ObtenerPosicion( valor) == -1) return false;
    else return true;
}
    //Obtener el primero
    template <typename T>
T ListaDoble<T>::ObtenerPrimero() const{
    return primero -> valor;
}
    //Obtener el ultimo
    template <typename T>
T ListaDoble<T>::ObtenerUltimo() const{
    return ultimo -> valor;
}
    //Obtener el que esta en cierta posicion
    template <typename T>
T ListaDoble<T>::ObtenerValor(int posicion) const{
    if(posicion < 0 || posicion  > numElem) throw "No es posible ubicarse en esa posicion";
    Elemento * aux = primero;

    for(int i = 1, pos = numElem -1; i < pos; ++i){
        aux = aux -> siguiente;
    }
    return aux -> valor;


}
    //Obtener la posicion de cierto elemento
template <typename T>
int ListaDoble<T>::ObtenerPosicion(T val) const {
    Elemento * aux = primero;
    int posicion = 0;
    while(aux != nullptr && aux->valor != val){
         aux = aux -> siguiente;
        ++ posicion;
    }
    if(aux != nullptr){
        return posicion;
    }else {
        return -1;
    }
}
    //Conocer el numero de elementos
    template <typename T>
int ListaDoble<T>::ConocerNumElem(){
    return numElem;
}
    //Copnocer si la lista esta vacia
    template <typename T>
bool ListaDoble<T>::EstaVacia() const{
    if(numElem == 0){
         return true;
    }else return false;

}
    //Vaciar
    template <typename T>
void ListaDoble<T>::Vaciar(){
    while(numElem != 0){
        EliminarAlInicio();
    }
}

    //Imprimir
    template <typename T>
void ListaDoble<T>::Imprimir() const{
    if(EstaVacia())return;
    Elemento *aux = primero;
    int i = 0;
    while(i != (numElem)){
        std::cout << aux -> valor <<  ",";
        aux = aux -> siguiente;
        ++i;
    }
}

//Imprimir Al revez
template <typename T>
void ListaDoble<T>::ImprimirReversa() const{
    if(EstaVacia())return;
    Elemento *aux = ultimo;
    int i = numElem;
    while(i != 0){
        std::cout << aux -> valor <<  ",";
        aux = aux -> anterior;
        --i;
    }
}
