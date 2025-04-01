#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef char tString[MAX];

typedef struct{
    int codProducto;
    tString descripcion;
    float precioUnitario;
}tProducto;

typedef struct nodoProducto{
    tProducto producto;
    struct nodoProducto * siguiente;
}tListaProducto;

void inicializarLista();
void insertarProducto(tProducto);
tProducto ingresarProducto();
void mostrarProductos(tListaProducto *);

tListaProducto * productos;


int main(){
    inicializarLista();
    tProducto nuevoProducto = ingresarProducto();
    insertarProducto(nuevoProducto);

    mostrarProductos(productos);

    return 0;
}

void inicializarLista(){
    productos = NULL;
    printf("LISTA DE PRODUCTOS INICIADA");
}

tProducto ingresarProducto(){
    tProducto producto;
    printf("Ingresar codigo del producto : ");
    scanf("%d", &producto.codProducto);
    printf("Ingresar descripcion del producto : ");
    scanf("%s", &producto.descripcion);
    printf("ingresar precio unitario : ");
    scanf("%f", &producto.precioUnitario);
    return producto;
}

void insertarProducto(tProducto pProducto){
    tListaProducto * nuevoProducto;
    nuevoProducto = (tListaProducto *)malloc(sizeof(tListaProducto));
    nuevoProducto->producto = pProducto;
    nuevoProducto ->siguiente= productos;
    productos = nuevoProducto;
    printf("Producto insertado");
}

void mostrarProductos(tListaProducto * pListaProductos){
    tListaProducto * listaAux = pListaProductos;
    printf("\n**LISTA DE PRODUCTOS**");
    while(listaAux!=NULL){
        printf("\n------");
        printf("\nCodigo : %d", listaAux->producto.codProducto);
        printf("\n Descripcion : %s", listaAux->producto.descripcion);
        printf("\nPrecio : %f", listaAux->producto.precioUnitario);
        printf("\n ---------------");
        listaAux = listaAux->siguiente;
    }
printf("\nSaltamos ");
}