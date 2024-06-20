#include <stdio.h>

	// POTENCIA RECURSIVA ((( (BASE * BASE) (n) VEZES

int potenciaRecursiva(int base, int expo){
	
	if(expo == 0) { // caso de parada 1
		return 1;
	}
	else if(expo == 1){ // Caso de parada 2
		return base;
	}
	else{
		return base * potenciaRecursiva(base, expo - 1);  // Chamada Recursiva
	}
	
}

int main(){
	int x, y;
	
	printf("DIGITE UM VALOR PARA A BASE, E UM VALOR PARA O EXPOENTE: ");
	scanf("%d %d", &x, &y);
	
	printf("\n\nO resultado e: %d", potenciaRecursiva(x, y));
	
	return 0;
}
