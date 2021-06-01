#include <stdio.h>
#include <stdlib.h>
/*Dado un árbol binario proveniente de la conversión de un árbol general, hallar la cantidad de
nodos que habia en niveles impares. */
typedef struct nodo
{
    int nodo;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){


    return 0;
}

int nodosImpares(TArbol A,int nAct){ //nAct entra con el nivel de la raiz, es decir 1
    if (A)
        if (nAct%2==1)
            return 1+nodosImpares(A->der,nAct)+nodosImpares(A->izq,nAct+1); //cuando me muevo a la izquierda aumento un nivel en el nario
        else
            return nodosImpares(A->der,nAct)+nodosImpares(A->izq,nAct+1);
    else
        return 0;
}

void nodosImparesvoid(TArbol A,int nAct,int *cont){
    if (A){
        if (nAct%2==1)
            (*cont)++;
        
        nodosImparesvoid(A->der,nAct,cont);
        nodosImparesvoid(A->izq,nAct+1,cont);
    }
}