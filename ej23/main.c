#include <stdlib.h>
#include <stdio.h>
/*Dado un árbol binario proveniente de la conversión de un árbol general, determinar el grado de
este último.*/
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){
    
    return 0;
}

void gradoArbol(TArbol A,int *gradoMax){ ///gradoMax iniciado en -1, si sale con -1 indica arbol vacio, 0 indica que solo existe la raiz
    int gradoLocal=0; TArbol aux;

    if (A){
        aux=A;
        while (aux){
            gradoLocal++;
            aux=aux->der;
        }
        if (gradoLocal>*gradoMax)
            *gradoMax=gradoLocal;
        gradoArbol(A->der,gradoMax);
        gradoArbol(A->izq,gradoMax);
    }
}

int gradoArbolInt(TArbol A){
    int gradoLocal=0; TArbol aux;int izq,der;

    if (A){
        aux = A->izq;
        while (aux){
            gradoLocal++;
            aux=aux->der;
        }

        izq = gradoArbolInt(A->izq);
        der = gradoArbolInt(A->der);

        if (gradoLocal>izq && gradoLocal>der)
            return gradoLocal;
        else
            return (izq>der) ? izq:der;
    }else
        return 0;
}