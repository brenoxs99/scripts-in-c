#include <stdio.h>

//FUNÇÃO RECURSIVA DE FAOTRIAL DUPLO
int doublefat(int n){
	if(n == 1)
		return n;
	else
		return n * (n - 2);
}
//------------------------------------------

int main(){
	int num;
	
	do{
		printf("Digite um numero inteiro impar: ");
		scanf("%d", &num);
	}while(num % 2 == 0);
	
	//CHAMANDO A FUNÇÃO RECURSIVA
	printf("\n\t%d fatorial eh: %d", num, doublefat(num));
	
	return 0;
}
