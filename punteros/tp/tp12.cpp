#include <stdio.h>
#include <stdlib.h>

typedef int indice ;
typedef indice * apuntIndice;
indice i;
apuntIndice apunt;

int main(){
    printf("Contenentedor de la variable apuntIndice : %p \n", apunt);
    apunt =(indice*) malloc(sizeof(indice));
    *apunt = 2;
    i=4;
    printf("Contenentedor de la variable apuntIndice : %p \n", apunt);
    printf("Contenentedor de la variable apuntIndice : %p \n", *apunt);
    return 0;
}