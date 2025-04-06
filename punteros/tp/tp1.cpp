#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
typedef char tString[MAX];

void PruebaDePuntero();

tString * cadenaApuntada;

int main(){

    PruebaDePuntero();
    return 0;
}

void PruebaDePuntero(){
    cadenaApuntada = (tString *)malloc(sizeof(tString));
    strcpy((*cadenaApuntada), "hernan mario antonio blanco");
    printf("\n EL contenido de la variable es : %s\n ",*cadenaApuntada );
    printf("\n La direccion de la variable apuntadad : %p\n",cadenaApuntada );
    printf("\n La direccion de la variable puntero : %p\n", &cadenaApuntada);


}
