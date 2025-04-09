#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int * tpEntero;
typedef char * tpCaracter;

tpEntero p1,p2;
tpCaracter q1, q2, q3;

int main(){

    p1 = (int*)malloc(sizeof(int)); 
    p2 = (int *)malloc(sizeof(int)); 
    *p1 = 5; 
    *p2 = *p1 + 20; 
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2); 
    p2 = (int*)malloc(sizeof(int)); 
    *p2 = 2; 
    *p2 = pow(*p2,2); 
    p1 = (int*)malloc(sizeof(int));  
    *p1 = fmod(*p2,3); 
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2); 
//cuando le sumamos a un caracter un numero, lo acomoda seguen el abcedaraio, C++ es crack
    q1 =(char*) malloc(sizeof(char)); 
    q2 = (char*)malloc(sizeof(char));     
    q3 = (char*)malloc(sizeof(char)); 
    *q1 = 'a'; 
    *q2 = (*q1) - 21; 
    *q3 = (*q1) + 10; 
    printf("*q1 igual a %c, *q2 igual a %c, q3 igual a %c\n", *q1, *q2, *q3);

            return 0;

}