#include <stdlib.h>
#include <stdio.h>
#define N 15
typedef struct nodo{
    char nombre[N];
    struct nodo *izq,*der;}nodo;
typedef nodo *TArbol;
int main(){
    TArbol A; int contador=0;
    printf("El ganador es: \n");
    muestraRonda(A,1,1); // en el nivel 1 esta el ganador
    printf("Los finalistas:\n");
    muestraRonda(A,1,2);
    printf("Los Semifinalistas:\n");
    muestraRonda(A,1,3);
    printf("Todos los competidores:\n");
    competidores(A,&contador);
    printf("Hay %d competidores en total:\n",contador);
    return 0;
}

void muestraRonda(TArbol A,int nIni,int nObj){ //El ganador esta en el nivel 1, finalistas en el 2, etc.
    if (A!=NULL)
        if (nIni==nObj) // si estoy en la ronda que busco, muestro y no invoco la recursion
            printf("%s\n",A->nombre);
        else{ //si no, voy a la ronda siguiente
            muestraRonda(A->izq,nIni+1,nObj);
            muestraRonda(A->der,nIni,nObj);
        }
}

void competidores(TArbol A,int *cont){ ///cont se inicializa en el main
    if (A!=NULL)
        if (A->der==NULL && A->izq==NULL){
            (*cont)++;
            printf("%s \n",A->nombre);
        }else{
            competidores(A->der,cont);
            competidores(A->izq,cont);
        }
}