#include <stdio.h>

int fatorialRecursivo(int num){
	
	if(num == 1 || num == 0){
		return 1;
	}else{
		return num * fatorialRecursivo(num -1);
	}
}

int main(){
	int num;
	
	printf("DIGITE UM NUMERO INTEIRO: ");
	scanf("%d", &num);
	
	printf("%d", fatorialRecursivo(num));
	
	return 0;
}
