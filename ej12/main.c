#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;
void inserta(TArbol *A,int x);
void cargaArbol(TArbol *A);
int minimoABB(TArbol A);
int main(){
    TArbol A;
    cargaArbol(&A);
    printf("%d\n",minimoABB(A));
    return 0;
}

/*retornar el valor minimo de un ABB*/
void inserta(TArbol *A,int x){
    if (*A==NULL){
        *A=(TArbol) malloc(sizeof(nodo));
        (*A)->dato=x;
        (*A)->der=NULL;
        (*A)->izq=NULL;
    }else
        if (x>((*A)->dato))
            inserta(&((*A)->der),x);
        else
            inserta(&((*A)->izq),x);
}
void cargaArbol(TArbol *A){
    *A=NULL;
    FILE * arch = fopen("datos.txt","rt");int x;
    while (!feof(arch)){
        fscanf(arch,"%d",&x);
        inserta(A,x); 
    }
    fclose(arch);
}

int minimoABB(TArbol A){
    if (A!=NULL)
        if (A->izq!=NULL)
            return minimoABB(A->izq);
        else
            return A->dato;
    else
        return -1;
}