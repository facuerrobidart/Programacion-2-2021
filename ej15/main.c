#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;
int esABB(TArbol A);
int main(){


    return 0;
}

int esABB(TArbol A){
    if (A!=NULL){
        if (A->izq==NULL && A->der==NULL) //hoja
            return 1;
        else
            if (A->izq && A->der==NULL) //grado 1
                if (A->izq->dato>A->dato)
                    return 0;
                else
                    return esABB(A->izq);
            else
                if (A->der && A->izq==NULL) //grado 1
                    if (A->der->dato<A->dato)
                        return 0;
                    else
                        return esABB(A->der);
                else
                    if (A->izq->dato>A->dato || A->der->dato<A->dato) //grado 2
                        return 0;
                    else 
                        return esABB(A->der)&&esABB(A->izq);                
    }else
        return 1;
}