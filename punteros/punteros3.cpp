#include <stdio.h>
#include <stdlib.h>


int main(){
    int x = 5;
    int (*y),malloc(sizeof(int));
    y = &x;
    printf("%d", *y);
    printf("\n%d", x);
    
    return 0;

}