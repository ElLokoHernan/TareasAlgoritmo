#include <stdio.h> 
#include <stdlib.h> 
typedef char *apuntadorC;  
apuntadorC a1, a2; 
int main() {  
a1 = (char *)malloc(sizeof(char));  
a2 = (char *)malloc(sizeof(char));  
*a1 = 'A';  
*a2 = 'B'; 
printf("%c \n", *a1); 
printf("%c \n", *a2); 
printf("%p \n", a1);
printf("%p \n", a2);
return 0;    
} 