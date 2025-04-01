#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef char tString[MAX];

typedef struct{
    int edad;
    tString nombre;
    float peso;
}tPaciente;

typedef struct nodoPacientes{
    tPaciente paciente;
    struct nodoPacientes * siguiente;
}tListaPacientes;

void inicializarLista();
void insertarPaciente(tPaciente);
tPaciente ingresarPaciente();
void mostrarPacientes(tListaPacientes *);

tListaPacientes * pacientes;

int main(){
    inicializarLista();
    tPaciente nuevoPaciente = ingresarPaciente();
    insertarPaciente(nuevoPaciente);
    mostrarPacientes(pacientes);
    return 0;
}

void inicializarLista(){
    pacientes = NULL;
    printf ("LISTA INICALIZADA");
}

void insertarPaciente(tPaciente pPaciente){
    tListaPacientes * nuevoPaciente;
    nuevoPaciente = (tListaPacientes*)malloc(sizeof(tListaPacientes));
    nuevoPaciente->paciente= pPaciente;
    nuevoPaciente ->siguiente =pacientes;
    pacientes = nuevoPaciente;

    printf("***PACIENTE AGREGADO CORRECTAMENTE***");

}

tPaciente ingresarPaciente(){
    tPaciente paciente;
    printf("\nIngresar la edad del Paciente : ");
    scanf("%d", &paciente.edad);
    printf("Ingresar el nombre del paciente : ");
    scanf("%s", &paciente.nombre);
    printf("Ingresar el peso del Paciente : ");
    scanf("%f", &paciente.peso);
  
    return paciente;
}
//En esta segunda instacion agreamos la funcion que nos permite ver los datos agregados a nuestro programa, la verdad estoy sorprendido con los resultados porque todos esta funcionando 
//a tener en cuenta que para mostrar la lista de paciente es necesario pasarle como parametro una variable puntero. al mostrar la lista, en el main, debemos pasar como parametro la variable apuntada.
void mostrarPacientes(tListaPacientes * pListaPacientes){
    tListaPacientes * listaAux = pListaPacientes;
    printf("\n\tLISTA DE PACIENTES");
    while(listaAux!=NULL){
        printf("\n 0Edad del paciente : %d", listaAux ->paciente.edad);
        printf("\n Nombre del paciente : %s", listaAux->paciente.nombre);
        printf("\n Peso del paciente : %2.2f", listaAux->paciente.peso);
        printf("\n--------");
        listaAux = listaAux->siguiente;
        printf("Saltamos la linea ");
    }
    printf("|n ***");

}