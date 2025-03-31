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

//void mostrarProductos(tListaProductos*);

tListaProducto * productos;


int main(){
    inicializarLista();
    tProducto nuevoProducto = ingresarProducto();
    insertarProducto(nuevoProducto);

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

