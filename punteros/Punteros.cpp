#include <stdio.h>
//un puntero es una variable que apunta a un objeto, mas precisamente apunta a una direccion de memoria.
//una cosa es la direccion de memoria y otra es el contenido de la variable.
//la direccion de memoria es dada o gestionada por la arquitectura del computador y el sitema opertaivo.
//en C no podemos asignarle la direccion de memoria, pero podemos gestionarlo.
//mientras que el valor de la variable son los datos que son almacenados en la misma.
//por ejemplo: A = 34;es el valor de la variable =34; &A = XD23453, es la direccion de memoria;

//intentamos hacer un programa mas eficiente, estamos separando en funciones.
//mostramos los mensaje del pragrama
void mensaje();
//usamos esta funciion para asignarle el valor a la variable;
void intercambio();
//usamos esta funciion para mostrar los valores ya intercambiado;
void mensajeFinal();

//prototipado
int *punt ;
int var = 435453435;
	
int main(){
	mensaje();
	intercambio();
	mensajeFinal();
	return 0;
	
}


void mensaje(){
	printf("\t** PUNTEROS **\t\n");
	printf("Hola! soy una variable puntero, almaceno una direccion de memoria :%#X \n",punt);
	printf("Hola! yo soy tan solo una variable con un valor asignado, pero me encuentro en esta direccion :%#X",&var);	
	printf("\n el dato que almaceno es de tipo entero :%d\n", var);
}

void intercambio(){
		punt = &var;
}

void mensajeFinal(){
	printf("%#X, %#X",punt,&var);
	printf("\n%d, %d",*punt, var);
}