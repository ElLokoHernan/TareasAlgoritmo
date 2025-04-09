#include <stdio.h>
void contarS();
void motor();
char a;
int cont ;
int main(){
	printf("CONTADOR A PARTIR DE EL CARACTER S\n");
	contarS();
	return 0;
}

void contarS(){
		scanf("%s",&a);
	if( a=='s'){
		cont = cont + 1;
	//printf("\ns cantidad = %d", cont);
	printf("\nPresionanste S, seguimos sumando :%d ", cont);
	contarS();
	}else{
		printf("\npresionar s para ir contando el resultado ");
		contarS();
	}
}

	

	