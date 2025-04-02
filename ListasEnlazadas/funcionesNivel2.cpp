#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30
//lista de reproducion, vamos a agregar canciones para luego ir reproduciendo
typedef char tString[MAX];
typedef struct{
    tString Cancion;
    tString Artista;
    tString Album;
    int Duracion;
    float Tamano;
}tCancion;

typedef struct nodoCanciones{
    tCancion cancion;
    struct nodoCanciones * siguiente;
    int cap ;
}tListaReproduccion;

void inicializarLista();
bool listaVacia();
void agregarCanciones(tCancion);
void insertarPrimerCancion(tCancion);
void insertarCancionAdelante(tCancion);
void insertarCancionenPos(int, tCancion);
tCancion insertarCanciones();
void mostrarLista(tListaReproduccion *);
int ingresarPosicion();

tListaReproduccion * canciones;

int main(){
    inicializarLista();
    int cap= 0;
    tCancion nuevaCancion = insertarCanciones();
    agregarCanciones(nuevaCancion);
    mostrarLista(canciones);
    int posicion = ingresarPosicion();
    tCancion nuevaCancion4 = insertarCanciones();
    insertarCancionenPos(posicion, nuevaCancion4);
    tCancion nuevaCancion1 = insertarCanciones();
    agregarCanciones(nuevaCancion1);
    tCancion nuevaCancion2 = insertarCanciones();
    agregarCanciones(nuevaCancion2);
	mostrarLista(canciones); /*   */
    return 0;
}

void inicializarLista(){
    canciones = NULL;
    printf("***Lista de Reproduccion iniciada***");
}
bool listaVacia(tListaReproduccion * pListaReproduccion){
    return (pListaReproduccion == NULL);
}
void agregarCanciones(tCancion pCancion){
/*    tListaReproduccion * nuevaCancion;
    nuevaCancion = (tListaReproduccion *)malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion = pCancion;
    nuevaCancion->siguiente = canciones;
    
    canciones = nuevaCancion;
    printf("**Cancion agregada**");*/
    if(listaVacia(canciones)){
        insertarPrimerCancion(pCancion);
    }else{
        insertarCancionAdelante(pCancion);
    }

}

tCancion insertarCanciones(){
    tCancion cancion;
    printf("\nNombre de la cancion : ");
    scanf("%s", &cancion.Cancion);
    printf("Artista : ");
    scanf("%s", &cancion.Artista);
    printf("Album al que pertenece : ");
    scanf("%s", &cancion.Album);
    printf("Duracion de la Pista : ");
    scanf("%d", &cancion.Duracion);
    printf("Tamanio de cancion : ");
    scanf("%f", &cancion.Tamano);

    return cancion;
}
void insertarPrimerCancion(tCancion pCancion){
    tListaReproduccion * nuevaCancion;
    nuevaCancion = (tListaReproduccion *)malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion = pCancion;
    //el punteroen de siguiente en esta parte debe apuntar a NULL.
    nuevaCancion->siguiente = NULL;
    canciones = nuevaCancion;
    canciones->cap +1;
    printf("\nCantidad de Canciones : %i\n", canciones->cap);
    printf("**Primer Cancion Agregada**");
}

void insertarCancionAdelante(tCancion pCancion){
    tListaReproduccion * nuevaCancion;
    nuevaCancion =(tListaReproduccion*)malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion=pCancion;
    nuevaCancion->siguiente=canciones;
    canciones = nuevaCancion;
    canciones -> cap +1;

    printf("\nCantidad de canciones :%d\n",canciones->cap);
}
int ingresarPosicion(){
    int posicion;
    printf("\nINGRESAR POSICION : ");
    scanf("%d", &posicion);
    return posicion;
}
void insertarCancionenPos(int posicion, tCancion pCancion){
    tListaReproduccion * listAux = canciones;
    int i;
    for(i=1;i<posicion-1;i++){
        listAux = listAux->siguiente;
    }
    tListaReproduccion * nuevaCancion;
    nuevaCancion = (tListaReproduccion* )malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion = pCancion;
    nuevaCancion->siguiente = listAux->siguiente;
    listAux->siguiente = nuevaCancion;
}

void mostrarLista(tListaReproduccion * pListaCanciones){
    tListaReproduccion * listAux = pListaCanciones;
    printf("------------------------------");
    printf("\n\tLISTA DE CANCIONES");
    printf("\n---------------------------");
    while(listAux != NULL){
        printf("\n Nombre De la Cancion : %s", listAux->cancion.Cancion);
        printf("\n Album al que pertenece : %s", listAux->cancion.Album);
        printf("\nNombre Del Artista : %s", listAux->cancion.Artista);
        printf("\nDuracion de LA cancion : %d", listAux->cancion.Duracion);
        printf("\nTamaño de la Pista : %2.2f", listAux->cancion.Tamano);
        printf("\nCantidad de Canciones : %d",listAux->cap);
        listAux = listAux->siguiente;

    printf("\n");
    }
}