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

tListaPacientes * pacientes;

int main(){
    inicializarLista();
    tPaciente nuevoPaciente = ingresarPaciente();
    insertarPaciente(nuevoPaciente);
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