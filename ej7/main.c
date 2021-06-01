#include <stdio.h>
#include <stdlib.h>
/*Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato*/

typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo *TArbol;

int sumanivel(TArbol A,int nAct,int nObj);
void inserta(TArbol *A,int x);
void cargaArbol(TArbol *A);
void muestraArbol(TArbol A);
int main(){
    TArbol A;int nObj;
    printf("Ingrese el nivel objetivo\n");
    scanf("%d",&nObj);
    cargaArbol(&A);
    muestraArbol(A);
    printf("La suma de los nodos de grado 1 en el nivel %d es %d",nObj,sumanivel(A,1,nObj));
}

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
void muestraArbol(TArbol A){
    if (A!=NULL){
        muestraArbol(A->izq);
        printf("%d\n",A->dato);
        muestraArbol(A->der);
    }
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
int sumanivel(TArbol A,int nAct,int nObj){ //nact entra con nivel de la raiz, es decir 1
    if (A!=NULL)
        if (nAct==nObj) // si el nodo esta en el nivel deseado
            if ((A->der && A->izq==NULL)||(A->der==NULL && A->izq) ) //chequeo grado 1
                return A->dato;
            else
                return 0; //si el nodo no tiene grado 1 retorna cero
        else{
            return sumanivel(A->izq,nAct+1,nObj)+sumanivel(A->der,nAct+1,nObj); //si no esta en el nivel deseado, paso al siguiente
        }
    else
        return 0; //si llego al final del arbol vuelve cero
}