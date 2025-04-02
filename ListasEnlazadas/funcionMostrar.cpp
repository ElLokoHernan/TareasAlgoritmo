#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

typedef char tString[MAX];

typedef struct{
    int edad;
    tString nombre;
    float altura;
    float peso;
}tJugador;

typedef struct nodoJugadores{
    tJugador jugador;
    struct nodoJugadores * siguiente;
}tListaJugadores;

void inicializarLista();
void agregarJugador(tJugador);
tJugador ingresarJugador();
void mostrarLista(tListaJugadores *);

tListaJugadores * jugadores;

int main(){
    inicializarLista();
    tJugador nuevoJugador = ingresarJugador();
    agregarJugador(nuevoJugador);
	mostrarLista(jugadores);
    return 0;
}

void inicializarLista(){
    jugadores = NULL;
    printf("Lista iniciada");
}

void agregarJugador(tJugador pJugador){
    tListaJugadores * nuevoJugador;
    nuevoJugador = (tListaJugadores*)malloc(sizeof(tListaJugadores));
    nuevoJugador->jugador = pJugador;
    nuevoJugador->siguiente = jugadores;
    
	jugadores = nuevoJugador;

    //printf("Jugadore Agregador");

}

tJugador ingresarJugador(){
    tJugador jugador;
    printf("\nIngresar la edad : ");
    scanf("%d", &jugador.edad);
    printf("\nIngresar nombre : ");
    scanf("%s", &jugador.nombre);
    printf("\nIngresar la altura : ");
    scanf("%f", &jugador.altura);
    printf("\nIngresar el peso :");
    scanf("%f", &jugador.peso);
    return jugador;
}

void mostrarLista(tListaJugadores * pListaJugadores){
    tListaJugadores * listAux = pListaJugadores;
    printf("\n **LISTA DE JUGADORES **");
    /*if(listAux == NULL){
        printf("Lista Vacia");
    }*/

    while(listAux != NULL){
        printf("\nEdad : %d", listAux->jugador.edad);
        printf("\nNombre : %s", listAux->jugador.nombre);
        printf("\nAltura : %2.2f", listAux->jugador.altura);
        printf("\nPeso : %2.2f", listAux->jugador.peso);

        printf("\n---------------");
        listAux = listAux->siguiente;
    }

}