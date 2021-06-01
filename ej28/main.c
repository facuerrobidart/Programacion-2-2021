#include <stdio.h>
#include <stdlib.h>
/*28. Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:*/
int main(){
    printf("hay %d nodos",nodos(A,raiz(A));
    return 0;
}

//a) retornar la cantidad de nodos que posee.

int nodos(TArbol A, TPosicion p){
    if (!nulo(p)){ // si estoy dentro del arbol
        return 1+nodos(A,hijoMasIzq(p,A))+nodos(A,hnoDer(p,A)); //cuento e invoco hijo y hermano
    }else //si me caigo del arbol cierro la recursion devolviendo cero
        return 0;
}

//b) hallar el porcentaje de claves pares

int pares(TArbol A,TPosicion p){
    if (!nulo(p)){ // si estoy dentro del arbol
        if (info(p,A)%2==0)
            return 1+pares(A,hijoMasIzq(p,A))+pares(A,hnoDer(p,A)); //cuento e invoco hijo y hermano
        else
            return pares(A,hijoMasIzq(p,A))+nodos(A,hnoDer(p,A)); //si no, invoco hijo y hermano
    }else //si me caigo del arbol cierro la recursion devolviendo cero
        return 0;   
}
float porcPares(TArbol A){
    return (float)nodos(A,raiz(A))/pares(A,raiz(A))*100;
}

//c) retornar su grado

int grado(TArbol A,TPosicion p){
    int gradoLocal=0; TPosicion c; int max=0;
    if (!nulo(p)){
        c=hijoMasIzq(p,A);
        while(!nulo(c)){
            gradoLocal++;
            if (grado(A,c)>max)
                max=grado(A,c);
            c=hnoDer(p,A);
        }
        return (gradoLocal>max)?gradoLocal:max;
    }else
        return 0;
}

//d) hallar la cantidad de nodos de grado impar que hay en niveles impares. 

void nodosDoblementeImpares(TArbol A, TPosicion p,int nAct,int *cont){
    if (!nulo(p)){
        if (nAct%2==1 && info(p,A))
            (*cont)++;
    }
}

//e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
//a la cantidad de hijos.(int y void)

int claveIgualGrado(TArbol A,TPosicion p){
    int gradoLocal=0; TPosicion c; int acum=0;

    if (!nulo(p)){
        c=hijoMasIzq(p,A);
        while (!nulo(c)){
            gradoLocal++; //cuento los hijos de p
            acum+=claveIgualGrado(A,c); // en acum guardo los return de los hijos de p
            c=hnoDer(c,A);
        }
        if (info(p,A)==gradoLocal && gradoLocal!=0) //si cumplo la condicion retorno 1 mas los hijos que cumplan la condicion
            return 1+acum;
        else //sino returno los hijos que cumplen la condicion
            return acum;
    }else //si me "caigo" del arbol devuelvo cero
        return 0;
}