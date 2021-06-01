
int cuentaNodos(TArbol A){
    if (A)
        return 1+cuentaNodos(A->der)+cuentaNodos(A->izq);
    else
        return 0;
}

void nodosBosques(TArbol A){
    int i=1;
    While (A!=NULL){
        printf("ARBOL %d: %d",i,1+cuentaNodos(A->izq));
        i++;
        A=A->der;
    }
}