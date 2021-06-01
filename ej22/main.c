#include <stdlib.h>
#include <stdio.h>

/*Dado un árbol binario que proviene de la transformación de un árbol general, obtener la altura
del árbol original*/

typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){
    
    return 0;
}

void alturaOriginal(TArbol A,int altAct,int *altMax){ //altAct entra en 0, altura de la raiz/alt max variable inicializada en cero o -1
    if (A){
        if (altAct>*altMax)
            *altMax=altAct;

        alturaOriginal(A->der,altAct,altMax);
        alturaOriginal(A->izq,altAct+1,altMax);
    }
}

int alturaOriginalInt(TArbol A){
    int izq,der;
    if (A){
        izq = 1+alturaOriginalInt(A->izq);
        der = alturaOriginalInt(A->der);

        return (izq>der) ? izq:der;
    }else
        return 0;
}

