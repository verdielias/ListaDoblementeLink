#include <iostream>
#include "ListaLink.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main(){
    try{
        ListaLink<int> list, list2;
        
        for(int i = 0; i < 10; ++i){
            list.AddUltimo(i);
        }
        cout << list;

        list2 = list;
        cout << endl << list2;
        list2.NoValor(5);
        cout << endl << list2;

    
    }catch(const char *e){
        cerr << "Error:" << e << endl;
    }
    
    return 0;
    
}