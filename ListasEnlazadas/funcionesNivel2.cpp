#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
}tListaReproduccion;

void inicializarLista();
void agregarCanciones(tCancion);
tCancion insertarCanciones();
void mostrarLista(tListaReproduccion *);

tListaReproduccion * canciones;

int main(){
    inicializarLista();
    tCancion nuevaCancion = insertarCanciones();
    agregarCanciones(nuevaCancion);
    mostrarLista(canciones);
    tCancion nuevaCancion1 = insertarCanciones();
    agregarCanciones(nuevaCancion1);
    tCancion nuevaCancion2 = insertarCanciones();
    agregarCanciones(nuevaCancion2);
	mostrarLista(canciones);    
    return 0;
}

void inicializarLista(){
    canciones = NULL;
    printf("***Lista de Reproduccion iniciada***");
}

void agregarCanciones(tCancion pCancion){
    tListaReproduccion * nuevaCancion;
    nuevaCancion = (tListaReproduccion *)malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion = pCancion;
    nuevaCancion->siguiente = canciones;
    
    canciones = nuevaCancion;
    printf("**Cancion agregada**");

}

tCancion insertarCanciones(){
    tCancion cancion;
    printf("\nNombre de la cancion : ");
    scanf("%s", &cancion.Cancion);
    printf("\nArtista : ");
    scanf("%s", &cancion.Artista);
    printf("\nAlbum al que pertenece : ");
    scanf("%s", &cancion.Album);
    printf("\nDuracion de la Pista : ");
    scanf("%d", &cancion.Duracion);
    printf("Tamanio de cancion : ");
    scanf("%f", &cancion.Tamano);

    return cancion;
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
        
        listAux = listAux->siguiente;

    printf("\n");
    }
}