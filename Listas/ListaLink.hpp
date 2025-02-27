/**
*   \file ListaLink.hpp
*   \author Elías Peregrina Cázares
*   \date   25/02/2025
*/

#ifndef ListaLink_HPP_INCLUDED
#define ListaLink_HPP_INCLUDED


#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename type>
class ListaLink{
    public:
        explicit ListaLink();
        ListaLink(const ListaLink &li);
        ~ListaLink();
        ListaLink& operator=(const ListaLink &li);
        
        void AddPrimero(type val);
        void AddUltimo(type val);
        void AddMedio(type val, unsigned int index);
        void NoPrimero();
        void NoUltimo();
        void NoMedio(unsigned int index);
        void NoValor(type val);
        type DamePrimero() const;
        type DameUltimo() const;
        type DameMedio(unsigned index) const;
        unsigned DameValor(type val) const;
        unsigned SizeLista() const;
        bool EstaVacia() const;
        void LimpiaLista();
        void PrintLista();

    private:
        unsigned size;

        struct Element
        {
            type valor;
            Element *sigElement;
        };

        Element *primElement;
        Element *ultElement;
};

#include "ListaLink.tpp"

#endif // LISTALINK_HPP_INCLUDED