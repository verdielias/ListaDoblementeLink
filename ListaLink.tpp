/**
*   \file ListaLink.tpp
*   \author Elías Peregrina Cázares
*   \date 25/02/3035   
*/

#include "ListaLink.hpp"


template <typename type>
ListaLink<type>::ListaLink() : size(0){
    
}

template <typename type>
ListaLink<type>::ListaLink(const ListaLink &li){   
    *this = li;
}


template <typename type>
ListaLink<type>::~ListaLink(){
    LimpiaLista();
}



template <typename type>
ListaLink<type> & ListaLink<type>::operator=(const ListaLink<type> &li){
    if (this == &li) return *this;

    LimpiaLista();

    Element *aux = li.primElement;

    for (unsigned i = 0; i < li.size; ++i){
        AddUltimo(aux->valor);
        aux = aux->sigElement;
    }

    return *this;
}


template <typename type>
void ListaLink<type>::AddPrimero(type val){
    Element *aux = new Element;
    aux -> valor = val;

    if(EstaVacia()){
        primElement = aux;
        ultElement = aux;
    }else{
        aux -> sigElement = primElement;
        primElement = aux;
    }

    ++size;
}

template <typename type>
void ListaLink<type>::AddUltimo(type val){
    Element *aux = new Element;
    aux -> valor = val;

    if(EstaVacia()){
        primElement = aux;
        ultElement = aux;
    }else{
        ultElement -> sigElement = aux;
        ultElement = aux;
    }
    
    ++size;
}

template <typename type>
void ListaLink<type>::AddMedio(type val, unsigned index){
    if(index < 0 || index > size-1) throw "\326ndice inv\240lido";
    
    if(index == 0) {
        Primero(val);
        return;
    }
    
    if(index == size - 1){
        Ultimo(val);
        return;
    }

    Element *ElementActual = primElement;
    Element *aux = new Element;
    aux -> valor = val;

    for(unsigned i = 1; i < index; ++i){
        ElementActual = ElementActual -> sigElement;
    }

    aux -> sigElement = ElementActual -> sigElement;
    ElementActual -> sigElement = aux;

    ++size;
}

template <typename type>
void ListaLink<type>::NoPrimero(){
    if(EstaVacia()) throw "Lista vac\241a";
    
    Element *deleteElement = primElement;
    primElement = primElement -> sigElement;
    delete deleteElement;

    --size;
}

template <typename type>
void ListaLink<type>::NoUltimo(){
    if(EstaVacia()) throw "Lista vac\241a";

    if(size == 1){
        delete primElement;
        primElement = ultElement = NULL;
    }else{
        Element *aux = primElement;

        for(unsigned i = 1; i < size - 1; ++i){
            aux = aux -> sigElement;
        }

        delete ultElement;
        ultElement = aux;
        ultElement -> sigElement = NULL;
    }

    --size;
}

template <typename type>
void ListaLink<type>::NoMedio(unsigned int index){
    if(index < 0 || index > size-1) throw "\326ndice inv\240lido";
    if(EstaVacia()) throw "Lista vac\241a";

    if(index == 0){
        NoUltimo();
        return;
    }
    if(index == size - 1){
        NoUltimo();
        return;
    }

    Element *aux = primElement;

    for(unsigned i = 2; i < index; ++i){
        aux = aux -> sigElement;
    }

    Element *deleteElement = aux -> sigElement;
    aux -> sigElement = deleteElement -> sigElement;
    delete deleteElement;

    --size;
}

template <typename type>
void ListaLink<type>::NoValor(type val){
    if(EstaVacia()) throw "Lista vac\241a";
    
    if(DamePrimero() == val) NoUltimo();

    Element *previous = primElement;
    Element *aux = primElement -> sigElement;

    for(unsigned i = 1; i < size; ++i){
        if(aux -> valor == val)
        {
            previous -> sigElement = aux -> sigElement;
            delete aux;
            --size;
            return;
        };
        previous = aux;
        aux = aux -> sigElement;
    }

    throw "Valor no encontrado en la lista";
}

template <typename type>
type ListaLink<type>::DamePrimero() const{
    
    return primElement -> valor;
}

template <typename type>
type ListaLink<type>::DameUltimo() const{
    
    return ultElement -> valor;
}

template <typename type>
type ListaLink<type>::DameMedio(unsigned index) const{
    if(index < 0 || index > size-1) throw "\326ndice inv\240lido";
    if(EstaVacia()) throw "La lista vac\241a";

    if(index == 0){
        return DamePrimero();
    }
    
    if(index == size - 1){
        return DameUltimo();
    }

    Element *ElementActual = primElement;

    for(unsigned i = 1; i < index; ++i){
        ElementActual = ElementActual -> sigElement;
    }

    return ElementActual -> valor;
}

template <typename type>
unsigned ListaLink<type>::DameValor(type val) const{
    if(EstaVacia()) throw "la lista vac\241a";

    if(DamePrimero() == val) return 0;

    Element *aux = primElement -> sigElement;

    for(unsigned i = 1; i < size; ++i){
        if(aux -> valor == val) return i;
        aux = aux -> sigElement;
    }

    throw "Valor no encontrado en la lista";
}

template <typename type>
unsigned ListaLink<type>::SizeLista() const{
    
    return size;
}

template <typename type>
bool ListaLink<type>::EstaVacia() const{
    
    return !size;
}


template <typename type>
void ListaLink<type>::LimpiaLista(){
    
    while(!EstaVacia()) NoUltimo();
}

template <typename type>
void ListaLink<type>::PrintLista(){
    if(EstaVacia()) throw "La lista vac\241a";

    Element *aux = primElement;

    cout << "[ ";
    for(unsigned i = 0; i < size; ++i){
        cout << aux -> valor << ", ";
        aux = aux -> sigElement;
    }
    cout << "\b\b ]";
}

template <typename type>
std::ostream & operator<<(std::ostream &output, ListaLink<type> &li){
    li.PrintLista();

    return output;
}

template <typename type>
std::istream & operator>>(std::istream &input, ListaLink<type> &li){
    type val;
    input >> val;

    li.Ultimo(val);

    return input;
}