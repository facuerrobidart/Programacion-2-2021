#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;
///. Dado un árbol binario que proviene de la transformación de un bosque, determinar qué
///cantidad de árboles lo componían.

typedef nodo *TArbol;

int main(){

    return 0;
}

int cuantosArboles(TArbol A){ ///A entra como la raiz del bosque
    if (A)
        return 1+cuantosArboles(A->der);
    else
        return 0;
}