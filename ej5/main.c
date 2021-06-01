#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 20
/*Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario*/
typedef struct nodo{
    char dato[max];
    struct nodo *izq,*der;
}nodo;
typedef nodo *TArbol;

void inserta(TArbol *A,char x[max]);
void cargaArbol(TArbol *A);
void muestraArbol(TArbol A);
int profundidad(TArbol A,int pAct);
void maximaLong(TArbol A,int *lon);
int hijosDer(TArbol A);
int main(){
    TArbol A;int lon=0;
    cargaArbol(&A);
    muestraArbol(A);
    printf("\n %d\n",profundidad(A,0));
    maximaLong(A,&lon);
    printf("Maxima longitud de las cadenas %d\n",lon);
    printf("Hijos a derecha: %d\n",hijosDer(A));
    return 0;
}
void inserta(TArbol *A,char x[max]){
    if (*A==NULL){
        *A=(TArbol) malloc(sizeof(nodo));
        strcpy((*A)->dato,x);
        (*A)->der=NULL;
        (*A)->izq=NULL;
    }else
        if (strcmp(x,(*A)->dato)>0)
            inserta(&((*A)->der),x);
        else
            inserta(&((*A)->izq),x);
}
void cargaArbol(TArbol *A){
    *A=NULL;
    char x[max];
    FILE *arch = fopen("datos.txt","rt");

    while(!feof(arch)){
        fscanf(arch,"%s",x);
        inserta(A,x);
    }
}
void muestraArbol(TArbol A){
    if (A!=NULL){
        muestraArbol(A->izq);
        printf("%s ",A->dato);
        muestraArbol(A->der);
    }
}
int profundidad(TArbol A,int pAct){
    if (A!=NULL){
        if (A->der!=NULL || A->izq!=NULL){
            return profundidad(A->der,pAct+1)>profundidad(A->izq,pAct+1) ? profundidad(A->der,pAct+1) : profundidad(A->izq,pAct+1);
        }else
            return pAct;
    }else
        return -1;
}
void maximaLong(TArbol A,int *lon){ //lon ingresa como -1
    if (A!=NULL){
        maximaLong(A->der,lon);
        maximaLong(A->izq,lon);
        if (strlen(A->dato)>*lon)
            *lon=strlen(A->dato);
    }
}
int hijosDer(TArbol A){
    if (A!=NULL){
        if (A->der!=NULL)
            return 1+hijosDer(A->der)+hijosDer(A->izq);
        else
            return hijosDer(A->der)+hijosDer(A->izq);
    }else
        return 0;
}