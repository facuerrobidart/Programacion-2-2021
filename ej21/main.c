#include <stdlib.h>
#include <stdio.h>


/*Dado un árbol binario proveniente de la conversión de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada).*/

typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){
    
    return 0;
}

void promedioGradoK(TArbol A,int grado,int *sum,int *cont){ //sum y cont inicializados en cero
    TArbol aux; int gradoLocal=0;
    if (A){
        aux=A->izq;
        while (aux){ // este while calcula el grado de A
            gradoLocal++;
            aux=aux->der;
        }

        if (gradoLocal==grado){ //si es el grado pedido
            (*sum)+=A->dato;
            (*cont)++;
        }//sumo y cuento
        promedioGradoK(A->der,grado,sum,cont); //invoco a los dos hijos
        promedioGradoK(A->izq,grado,sum,cont);
    }
}