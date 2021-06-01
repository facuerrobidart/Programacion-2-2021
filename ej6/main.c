#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
typedef struct nodo
{
    char dato[N];
    struct nodo *der,*izq;}nodo;

typedef nodo * TArbol;
void inserta(TArbol *A,char x[N]);
void cargaArbol(TArbol *A);
void muestraArbol(TArbol A);
void maxCadA(TArbol A,char pal[N], int *max);

int main(){
    TArbol A; int max=0;char pal[N];
    cargaArbol(&A);
    muestraArbol(A);
    maxCadA(A,pal,&max);
    if (max)
        printf("La cadena mas larga con 'A' es %s con %d caracteres",pal,max);
    else
        printf("No hay cadenas con 'A'");
    return 0;
}
void inserta(TArbol *A,char x[N]){
    if (*A==NULL){
        *A=(TArbol) malloc(sizeof(nodo));
        strcpy((*A)->dato,x);
        (*A)->der=NULL;
        (*A)->izq=NULL;
    }else{
        if (strcmp(x,(*A)->dato)>0)
            inserta(&((*A)->der),x);
        else
            inserta(&((*A)->izq),x);}
}
void cargaArbol(TArbol *A){
    *A=NULL;
    char x[N];
    FILE *arch = fopen("datos.txt","rt");

    while(!feof(arch)){
        fscanf(arch,"%s",x);
        inserta(A,x);
    }
    fclose(arch);
}
void muestraArbol(TArbol A){
    if (A!=NULL){
        printf("%s\n",A->dato);
        muestraArbol(A->izq);
        muestraArbol(A->der);
    }
}
void maxCadA(TArbol A,char pal[N], int *max){ //max entra con valor 0, si sale con ese valor no hay cadenas que comiencen con A
    if (A!=NULL){
        if ((A->dato)[0]=='a' && strlen(A->dato)>*max){
            *max=strlen(A->dato);
            strcpy(pal,A->dato);}
        maxCadA(A->der,pal,max);
        maxCadA(A->izq,pal,max);
    }
}