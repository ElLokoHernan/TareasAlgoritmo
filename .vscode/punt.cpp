#include <stdio.h>

int main(){
int var = 15;
int * puntero;
puntero = &var;

printf("variable %d, puntero %d", var, &puntero);
return 0;
}