#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 34
//vamos a crear una lista de invitados,a una boda
typedef char tString[MAX];
typedef struct{
	tString nombre;
	int mesa;
	int cantidaLugares;
	float donacion;
}tInvitado;

typedef struct nodoLista{
	tInvitado invitado;
	struct nodoLista *siguiente;
}tListaInvitados;

void inicializarLista();
bool listaVacia();
tInvitado agregarInvitado();
void insertarLista(tInvitado);
void insertarAdelante(tInvitado);
void insertarPrimero(tInvitado);
void insertarPos(int, tInvitado);
int posicion();
void mostrarLista(tListaInvitados *);
void eliminarInvitado();
void eliminarPos();

tListaInvitados * invitados;

int main(){
	inicializarLista();
	tInvitado nuevoInvitado = agregarInvitado();
	insertarLista(nuevoInvitado);
	mostrarLista(invitados);
	int p = posicion();
	tInvitado nuevoInvitado2 = agregarInvitado();
	insertarPos(p,nuevoInvitado2);
	//insertarLista(nuevoInvitado2);
	mostrarLista(invitados);

	return 0;
}

void inicializarLista(){
	invitados = NULL;
	printf("LISTA INICIADA CORRECTAMENTE");	
}

bool listaVacia(tListaInvitados * pListaInvitado){

	return (pListaInvitado == NULL);
}

tInvitado agregarInvitado(){
tInvitado invitado;	
	printf("\n DATOS DEL PROXIMO INVITADO");
	printf("\ningresar el nombre :");
	scanf("%s",&invitado.nombre);
	printf("Mesa : ");
	scanf("%d",&invitado.mesa);
	printf("Cantidad De Personas :");
	scanf("%d",&invitado.cantidaLugares);
	printf("Donacion :");
	scanf("%f", &invitado.donacion);
	
	return invitado;

}

void insertarLista(tInvitado pInvitado){
	
	if(listaVacia(invitados)){
		insertarPrimero(pInvitado);
		printf("--se agrego el primer invitados de la lista ---");
	}else{
		insertarAdelante(pInvitado);
		printf("---agregado a la Lista de invitados---");
	}
	
}

void insertarPrimero(tInvitado pInvitado){
					
	tListaInvitados * nuevoInvitado;
	nuevoInvitado = (tListaInvitados *)malloc(sizeof(tListaInvitados));
	nuevoInvitado->invitado = pInvitado;
	nuevoInvitado->siguiente = NULL;
	invitados = nuevoInvitado;

}

void insertarAdelante(tInvitado pInvitado){
	tListaInvitados * nuevoInvitado;
	nuevoInvitado = (tListaInvitados *)malloc(sizeof(tListaInvitados));
	nuevoInvitado->invitado = pInvitado;
	nuevoInvitado->siguiente = invitados;
	invitados = nuevoInvitado;
}

int posicion(){
	int p;
	printf("ingresar posicion");
	scanf("%d", &p);
	return p;

}
void insertarPos(int p, tInvitado pInvitado){
	tListaInvitados * lisAux = invitados;
	int i;
	for(i<1;i<p<-1;i++){
	lisAux = lisAux->siguiente;
	}
	tListaInvitados * nuevoInvitado;
	nuevoInvitado = (tListaInvitados *)malloc(sizeof(tListaInvitados));
	nuevoInvitado->invitado = pInvitado;
	nuevoInvitado->siguiente = lisAux->siguiente;
	lisAux->siguiente = nuevoInvitado;
}
void 

void mostrarLista(tListaInvitados * pListaInvitado){
	tListaInvitados * lisAux = pListaInvitado;
	printf("\n----------------------------------");
	printf("\n\tLISTA DE INVITADOS");
	printf("\n----------------------------------");
	while(lisAux != NULL){
		/*
			tString nombre;
	int mesa;
	int cantidaLugares;
	float donacion;*/
	printf("\nINVITADO : %s", lisAux->invitado.nombre);
	printf("\nMESA :%d", lisAux->invitado.mesa);
	printf("\nLUGARES : %d",lisAux->invitado.cantidaLugares);
	printf("\nDONACION :$ %2.2f",lisAux->invitado.donacion);
	
	lisAux = lisAux->siguiente ;
	}
	printf("\n");
	
}