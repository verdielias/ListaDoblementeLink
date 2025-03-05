/**

 * \file ListaSimple.tpp

 * \author Flor Machado y Elias Peregrina

 * \date 4/02/2025

 */
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
        this -> AgregarAlFinal(aux -> valor);
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
    if(EstaVacia()){
        AgregarAlInicio(valor);
    }else{
        Elemento * aux = new Elemento(valor);
        ultimo -> siguiente = aux;
        ultimo = aux;
        ++numElem;
    }

}
//Agregar en cierta posicion
template <typename T>
void ListaDoble<T>::AgregarEnPosicion(T valor, int posicion){
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
    }else {
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
    else if(posicion == numElem -1) EliminarAlFinal();
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

    for(int i = 0; i < posicion; ++i){
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
//Operador sobrecargado para acceder a un elemento (lvalue)
template <typename T>
T& ListaDoble<T>::operator[](int index){
    if (index < 0 || index >= numElem ) throw "Indice fuera de rango.";
    Elemento *aux = primero;
    for (int i = 0 ; i < index ; ++i){
        aux = aux->siguiente;
    }
    return aux->valor;
}

template <typename T>
void ListaDoble<T>::IntercambiarListas( ListaDoble<T> &v){
    if (this == &v) return;
    ListaDoble<T> Listaaux;
    Listaaux = v;

    v.Vaciar();
    Elemento *aux = primero;
    while(aux != nullptr){
        v.AgregarAlFinal(aux -> valor);
        aux = aux -> siguiente;
    }

    this -> Vaciar();
    Elemento *aux2 = Listaaux.primero;
    while(aux2 != nullptr){
        this -> AgregarAlFinal(aux2 -> valor);
        aux2 = aux2 -> siguiente;
    }
    return;
}

//Operador sobrecargado para acceder a un elemento (rvalue)
template <typename T>
const T& ListaDoble<T>::operator[](int index) const{
    if (index < 0 || index >= numElem ) throw "Indice fuera de rango.";
    Elemento *aux = primero;
    for (int i = 0 ; i < index ; ++i){
        aux = aux->siguiente;
    }
    return aux->valor;
}

template <typename T>
void ListaDoble<T>::TransferirRango( ListaDoble<T> &v, int inicio, int fin){
    if( (inicio >= fin) || (inicio >= numElem) || (fin >= numElem))throw "No se a podido utilizar este rango";
    for(int i = inicio ; i <= fin; ++i){
        v.AgregarAlFinal(this -> ObtenerValor(i));
    }
    return;
}

template <typename T>
void ListaDoble<T>::TransferirDesdeIndice( ListaDoble<T> &v, int inicio){
    this -> TransferirRango(v,inicio,numElem -1);

}

template <typename T>
void ListaDoble<T>::TransferirElementos(ListaDoble<T> &v){
    this -> TransferirRango(v,0,numElem -1);
}

//Eliminar toda ocurrencia de un elemento
template <typename T>
void ListaDoble<T>::EliminarOcurrencias(T valor){
    Elemento *aux = primero;
    Elemento *prev = nullptr;

    while (aux != nullptr){
        if (aux->valor == valor){
            Elemento *porBorrar = aux;
            if (prev == nullptr){
                primero = aux->siguiente;
            }else{
                prev->siguiente = aux->siguiente;
            }
            aux = aux->siguiente;
            delete porBorrar;
            --numElem;
        }else{
            prev = aux;
            aux = aux->siguiente;
        }
    }
    if (primero == nullptr) {
        ultimo = nullptr;
    }else{
        ultimo = prev;
    }
}

//Eliminar todo elemento que cumpla con cierta condicion
template <typename T>
void ListaDoble<T>::EliminarSi(bool (*condicion)(T)){
    Elemento *aux = primero;
    Elemento *prev = nullptr;

    while (aux != nullptr){
        if (condicion(aux->valor)){
            Elemento *porBorrar = aux;
            if (prev == nullptr){
                primero = aux->siguiente;
            }else{
                prev->siguiente = aux->siguiente;
            }
            aux = aux->siguiente;
            delete porBorrar;
            --numElem;
        }else{
            prev = aux;
            aux = aux->siguiente;
        }
    }
    if (primero == nullptr) {
        ultimo = nullptr;
    }else{
        ultimo = prev;
    }
}

//Eliminar todo elemento repe repe repe repe repe repe repe repe repetido
template <typename T>
void ListaDoble<T>::EliminarRepetidos(){
    Elemento *aux = primero;
    while (aux != nullptr){
        Elemento *prev = aux;
        Elemento *dupe = aux->siguiente;
        while (dupe != nullptr){
            if (dupe->valor == aux->valor){
                Elemento *porBorrar = dupe;
                prev->siguiente = dupe->siguiente;
                dupe = dupe->siguiente;
                delete porBorrar;
            }else{
                prev = dupe;
                dupe = dupe->siguiente;
            }
        }
        aux = aux->siguiente;
    }
    if (primero == nullptr){
        ultimo = nullptr;
    }else{
        aux = primero;
        while (aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        ultimo = aux;
    }
}

template <typename T>
void ListaDoble<T>::OrdenarLista(){
    Elemento * aux = primero;
    aux = aux -> siguiente;
    Elemento * visitar = aux -> anterior;
    bool ordenado = true;
    for(int i = 0; i < numElem; ++i){
        do{
            ordenado = true;
            if((visitar -> valor) > (aux -> valor) ){

                    if(visitar -> anterior == nullptr){
                        AgregarAlInicio(aux -> valor);
                        ordenado = true;
                        Elemento * porBorrar  = aux;
                        aux = aux -> anterior;
                        porBorrar -> siguiente -> anterior = porBorrar -> anterior;
                        porBorrar -> anterior -> siguiente = porBorrar -> siguiente;
                        delete porBorrar;
                    }else{
                        ordenado = false;
                        visitar = visitar -> anterior;
                    }

            }
            if (visitar != aux -> anterior){
                Elemento * nuevo = new Elemento (aux -> valor, visitar ->siguiente, visitar);
                visitar -> siguiente -> anterior = nuevo;
                visitar -> siguiente = nuevo;
                ordenado = true;
                Elemento * porBorrar  = aux;
                aux = aux -> anterior;
                porBorrar -> siguiente -> anterior = porBorrar -> anterior;
                porBorrar -> anterior -> siguiente = porBorrar -> siguiente;
                delete porBorrar;
            }

        }while(true);


        visitar = aux;
        aux = aux -> siguiente;

    }

}
