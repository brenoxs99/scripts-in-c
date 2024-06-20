#include <stdio.h>
#include <stdlib.h>
			
			// ESTRUTURA DE DADOS PILHA --> FEITA COM UMA LISTA SIMPLSMENTE ENCADEADA
			// REGRA DE UMM APILHA --> LAST-IN __ FIRST-OUT
			
			// PRINCIPAIS FUNÇÕES*
			// 	- INSERIR NA PILHA
			// 	- CONSULTAR TOPO
			// 	- REMOVER TOPO
			
// criando um novo tipo de dados "No" -- apelido "no"			
typedef struct no{
    int chave;
    struct no * prox; // criando um ponteiro para essa estrutura  de forma recursiva com apelido "no"
}No;
//------------------------------------------

// função que solicita dados
int inserirDados(){
    int num;

    printf("\nDigite um valor inteiro: ");
    scanf("%d", &num);

    return num;
}
//------------------------------------------

//função que aloca um novo "No" ___ E insere na pilha
No* inserirNaPilha(No* topo){
    No* novo = (No *)malloc(sizeof(No));

    if(novo == NULL){
        printf("\nErro ao alocar memoria!");
    }else{

        if(topo == NULL){ // pilha estando vazia
            novo->chave = inserirDados();
            novo->prox = NULL;
            topo = novo;

            return topo;
            
        }else{ // pilha tendo um ou mais dados
		 
            novo->chave = inserirDados();
            novo->prox = topo;
            topo = novo;

            return topo;
        }
    }
}
//------------------------------------------

// função que exibe sempre o topo atual
void exibirtopo(No * topo){
	
	if(topo == NULL){
		printf("\n\tA PILHA ESTA VAZIA!\n");
		
	}else{
	
		printf("\n\tIMPRIMINDO TOPO: %d	\n", topo->chave);
	}
}
//------------------------------------------

// função que remove o topo atual
No* removertopo(No* topo){
	No* aux;
	
	if(topo == NULL){
		printf("\n\tA PILHA ESTA VAZIA!\n");
		
	}else{
		aux = topo->prox; // aux ta recebendo o próximo item da lista
		free(topo);       // desalocando espaço
		topo = aux;       // atualizando o novo topo;
	
		printf("\n\tO TOPO FOI REMOVIDO COM SUCESSO!\n");	
	}

	return topo; // retornado o novo topo
}


int main(){
    No* topo = NULL;
    int op;

	// menuzinho básico sem mistério
    do{
        printf("\n[1]-INSERIR NA PILHA\n[2]-EXIBIR TOPO\n[3]-EXCLUIR TOPO");
        printf("\n\nDIGITE AQUI: " );
        scanf("%d", &op);

        switch (op){
	        case 1:{
	            	topo = inserirNaPilha(topo);
	            break;
	        }
	        case 2:{
	                exibirtopo(topo);
	                break;
	        } 
			case 3:{
	                topo = removertopo(topo);
	                break;
	        }    
	        default:{
	        	printf("\n\tOPCAO INVALIDA!");
				break;
	        }
		}
    }while(op != 0);
    
	return 0;
}	
