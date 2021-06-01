#include <stdio.h>
#include <stdlib.h>
#define N 50
/*Corregir los errores en la siguiente función void, la cual genera un arreglo de caracteres con los
nodos de grado 2 de un árbol binario.*/
typedef struct nodo{
    char dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo *TArbol;
int main(){

    return 0;
}

/*void arrgrado2(TArbol a, char v[N], int dimv) { //dim v se pasa como parametro, no se modifica
    if (a != NULL) {
        if(a->izq != NULL && a->der == NULL) {//a->der !=NULL
            (*dimv)++; 
            v[dimv] = a->dato; ///*dimv
        }else // el else es incorrecto, deberia ejecutarse siempre la recursion
        arrgrado2(a->izq, v[], dimv); ///se escribe v a secas
        arrgrado2(a->der, v[], dimv); //dimv esta correctamente invocado, pero recordar que el parametro es *dimv
    }
} */

void arrgrado2(TArbol a, char v[N], int *dimv) {
    if (a != NULL) {
        if(a->izq != NULL && a->der == NULL) {/* grado 2 */
            (*dimv)++;
            v[*dimv] = a->dato;
        }
        arrgrado2(a->izq, v, dimv);
        arrgrado2(a->der, v, dimv);
    }
} 