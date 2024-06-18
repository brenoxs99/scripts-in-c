#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
	struct no *anter;
}No;

int solicitaDados(){
	int n;
	
	printf("Digite um valor inteiro para inserir na fila: ");
	scanf("%d", &n);
	return n;
}

No* inserirNaFila(No* Fila){
	No* novo = (No *)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("\n\tERRO AO ALOCAR MEMORIA!");
	}else{
		if(Fila == NULL){
			novo->valor = solicitaDados();	
			novo->anter = NULL;
			novo->prox  = NULL;
			Fila = novo;
		}else{
			novo->valor = solicitaDados();
			novo->anter = NULL;
			novo->prox  = Fila;
			Fila->anter = novo;
			Fila = novo;
		}
		
	}
	return Fila;
}

void consultaInicio(No* Fila){
	No *aux = Fila;
	
	
	if(Fila == NULL){
		printf("\n\tA FILA ESTA VAZIA!");
	}else{
		while(aux != NULL){
			
			if(aux->prox == NULL){
				printf("\n\tO inicio da Fila eh: %d", aux->valor);
			}
			aux = aux->prox;
		}
	}
}

void consultaFim(No *Fila){
	if(Fila == NULL){
		printf("\n\tA FILA ESTA VAZIA!");
	}else if(Fila->anter == NULL){
		printf("\n\tO fim da fila eh: %d", Fila->valor);
	}
	
}

No* desenfileirar(No *Fila){
	No *aux = Fila;
	No *desaloca;
	
	if(Fila == NULL){
		printf("\n\tA FILA ESTA VAZIA!");
	}else{
		while(aux != NULL){
			aux = aux->prox;
			if(aux->prox == NULL){
				desaloca = aux->anter;
				free(aux);
				Fila = desaloca;
				Fila->prox = NULL;
				
				return Fila;
			}
		}
	}
}

int main(){
	No *Fila = NULL;
	int op;
	
	do{
		printf("\n\n>>> ESTRUTURA DE DADOS FILA <<<");
		printf("\n       MENU DA FILA");
		printf("\n[1]-ENFILEIRAR");
		printf("\n[2]-DESENFILEIRAR");
		printf("\n[3]-CONSULTA INICIO DA FILA");
		printf("\n[4]-CONSULTA FIM DA FILA");
		printf("\n[5]-LIMPA TELA");
		printf("\n[0]-SAIR");
		printf("\n\tDIGITE AQUI A OPCAO: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:{
				Fila = inserirNaFila(Fila);
				break;
			}
			case 2:{
				Fila = desenfileirar(Fila);
				break;
			}
			case 3:{
				consultaInicio(Fila);
				break;
			}
			case 4:{
				consultaFim(Fila);
				break;
			}
			case 5:{
				system("cls");
				break;
			}
				
			default:{
				printf("\nOPCAO INVALIDA! DIGITE NOVAMENTE\n");
				break;
			}
		}
	}while(op != 0);
	
	return 0;
}
