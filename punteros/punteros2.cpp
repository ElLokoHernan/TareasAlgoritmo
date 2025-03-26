#include <stdio.h>
//los parametros son variables punteros.
void sumar(int *a, int *b, int *c);
void PedirDatos();

int x,y,z;
int main(){
    printf("\t**PUNTEROS**\n");
    PedirDatos();
//notece que los parametros que pasamos son las direcciones de a,b y c;
    sumar(&x, &y, &z);
//mostramos el valor almacenado en c.
    printf("Resultado %d",z);
    return 0;
}
//pasamos los parametros en forma de punteros.
void sumar(int *a, int *b, int *c){
    *c = *a + *b;
}

void PedirDatos(){
    printf("ingresar un valor entero para sumar :");
    scanf("%d", &x);
    printf("ingresar otro valor entero para sumar");
    scanf("%d", &y);
    //scanf("%d", &z);//no importa el valor que le asignamos a esta variable, de igual forma, toma el valor que agregamos en la funcion sumar
}