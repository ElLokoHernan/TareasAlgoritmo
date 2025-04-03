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
//vamos a ir observando como elimina las canciones, es decir si desde arriba o desde abajo
void eliminarCanciones();
void eliminarPos();

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
    eliminarCanciones();
    tCancion nuevaCancion1 = insertarCanciones();
    agregarCanciones(nuevaCancion1);
    tCancion nuevaCancion2 = insertarCanciones();
    agregarCanciones(nuevaCancion2);
    eliminarPos();
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

    //en este programa, hicimos varios cambios en esta funcion, pusimos una condicion y 
    //usamos las funciones de lista vacia y de insercciones para determinar el lugar donde se almacena nuestros dato
    if(listaVacia(canciones)){
        insertarPrimerCancion(pCancion);
    }else{
        insertarCancionAdelante(pCancion);
    }

}

tCancion insertarCanciones(){
    //esta funcion se mantiene igual conrespecto al programa anterior, reutilizacion de codigo.
    //
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
    //esta funcion es igual a la funcion que usamos para agregar elemento en el progrma anterio.
    //lo que notabamos es que los datos se agregaban uno a tras del otro, como lo veiamos con la funcion de mostrar los datos 
    //con esto solo, ya tenemos una caracteristica fundamental de la lista, notece que siempre el puntero de los elemento que se agregan apuntan a NULL
    //recordemos que el ultimo elemento de la lista no tiene sucesor, por lo tanto apunta a nudo.
    //en la funcion que sigue, veremos ese cambio de direccion de puntero.
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
    //en esta funcion agregamos los datos uno acontinuacion del otro,
    //siempre y caundo la lista no estee vacia, si esta vacia, entra la funcion de arriba
    tListaReproduccion * nuevaCancion;
    nuevaCancion =(tListaReproduccion*)malloc(sizeof(tListaReproduccion));
    nuevaCancion->cancion=pCancion;
    nuevaCancion->siguiente=canciones;
    canciones = nuevaCancion;
    canciones -> cap +1;

    printf("\nCantidad de canciones :%d\n",canciones->cap);
}
int ingresarPosicion(){
    //necesitamos una posicion para poder agregar el dato donde querramos
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

void eliminarCanciones(){
    if(listaVacia(canciones)){
        printf("\nNO HAY ELEMENTOS PARA ELIMINAR :");
        printf("\n*********Lista vacia**********");
    }else{
        tListaReproduccion * eliminarCancion;
        eliminarCancion = canciones;
        canciones = eliminarCancion->siguiente;
        printf("\n**********");
        printf("\n\tPRODUCTO ELIMINADO");
        printf("\n\t");
        free(eliminarCancion);
        eliminarCancion = NULL;
    }
}

void eliminarPos(){
    if(listaVacia(canciones)){
        printf("\nNO HAY ELEMENTOS PARA ELIMINAR");
        printf("\n");
    }else{
        printf("\nbuscar posicion para eliminar :");
        int p = ingresarPosicion();
        tListaReproduccion * listAux = canciones;
        int i;
        for(i=1;i<p-1;i++){
            listAux = listAux->siguiente;
        }
        tListaReproduccion * eliminarCancion;
        eliminarCancion = listAux->siguiente;
        listAux->siguiente = eliminarCancion->siguiente;
        printf("\ncanion eliminada ");
        free(eliminarCancion);
        eliminarCancion = NULL;

    }


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