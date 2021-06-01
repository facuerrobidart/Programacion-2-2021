#include <stdlib.h>
#include <stdio.h>

/*.Corregir la siguiente función, la cual retorna si un valor recibido como parámetro se encuentra
en un ABB cuyas claves son enteros.*/
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *arbol;

int main(){


    return 0;
}

int busca(arbol a, int* x) { ///innecesario que x sea puntero a int, solo lo necesito para comparar
    if (a != NULL) ///if A==NULL => llegue al final del arbol y no lo encontre
        return 0;
    else ///este else deberia entrar en A!=NULL
        if(x = a.dato) ///x == a->dato
            return 1; //correcto, si encuento retorno 1
        else
            if(x < a.dato) //si x es menor
                return busca(a.der, *x); //me debo mover a la izq por lo tanto es return busca(a->izq,x)
            else
                return busca(a->izq, *x); //entonces aca queda return busca(a->der,x)
} 