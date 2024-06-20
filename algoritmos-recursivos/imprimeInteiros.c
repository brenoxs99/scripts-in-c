#include <stdio.h>

	// IMPRIMINDO (n) NUMEROS DE FORMA RECURSIVA


// Imprimindo numeros de forma crescente --> o printf(); vai depois da chamada recursiva.
void imprimirCrescente(int num){
	if(num == 1)
		printf("|%d| ", num);
	else{
		imprimirCrescente(num - 1);
		printf("|%d| ", num);
	}
}

void imprimirDecrescente(int num){
	if(num == 1){
		printf("|%d| ", num);
	}else{
		printf("|%d| ", num);
		imprimirDecrescente(num - 1);
	}
	
}


int main(){
	int op;
	int num;
	
	do{
		
		printf("\n[1]-IMPRIMIR EM ORDEM CRESCENTE\n[2]-IMPRIMIR EM ORDEM DECRESCENTE\n");
		printf("\n\nDIGITE AQUI: ");
		scanf("%d", &op);
		
		switch(op){
			case 0:{
				printf("\n\tO PROGRMA FOI FINALIZADO!");
				break;
			}
			
			case 1:{
				printf("\nDIGITE QUANTOS NUMEROS DESEJA IMPRIMIR DE FORMA CRESCENTE: ");
				scanf("%d", &num);
			
				// Chamando a funcao que irá imprimir os numeros de forma recursiva
				printf("\n\t");
				imprimirCrescente(num);
				printf("\n");
				
				break;
			}
			
			case 2:{
				printf("\nDIGITE QUANTOS NUMEROS DESEJA IMPRIMIR DE FORMA DECRESCENTE: ");
				scanf("%d", &num);
			
				printf("\n\t");
				imprimirDecrescente(num);
				printf("\n");
				
				break;
			}
			default:{
				printf("\n\tOPCAO INVALIDA, DIGITE NOVAMENTE!\n");
				break;
			}
		}
	}while(op != 0);
	
	return 0;
}
