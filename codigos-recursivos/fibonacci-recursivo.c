#include <stdio.h>

	// SEQUENCIA DE FIBONACCI ((((((( O PRÓXIMO NÚMERO É A SOMA DOS ANTERIORES )))))))
	

int somaFibonacci(int num){
	
	if(num == 1){ // Primeiro Termo
		return 0;
	}
	else if(num == 2){ // Segundo Termo
 		return 1;
	}else{
		return somaFibonacci(num - 1) + somaFibonacci(num - 2);
	}
	
}	
	
int main(){
	int n;
	
	printf("DIGITE UM NUMERO INTEIRO: ");
	scanf("%d", &n);
	
	
	printf("\nE o: %d ",  somaFibonacci(n));
	
	return 0;
}  
