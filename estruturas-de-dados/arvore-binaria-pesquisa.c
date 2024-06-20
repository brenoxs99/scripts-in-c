#include <stdio.h>
#include <stdlib.h>

// Criando um tipo N�
typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;    
} No;

// Fun��o pedir dados
int pedirDados() {
    int num;
    printf("Digite um novo valor para armazenar na arvore: ");
    scanf("%d", &num);
    return num;
}

// Fun��o Inserir na Arvore e j� aloca
No* inserirNaArvore(No *raiz, int valor) {
	
    if (raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        
		raiz = novo;
		return raiz;
    } else {
        if (valor < raiz->valor) {
            raiz->esq = inserirNaArvore(raiz->esq, valor); // Fun��o recurciva para inserir na esquerda
        } else {
            raiz->dir = inserirNaArvore(raiz->dir, valor); // Fun��o recursiva para inserir na direita
        }
        return raiz;
    }
}

// Fun��o para exibir a �rvore em pr�-ordem
void exibirPre(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibirPre(raiz->esq);
        exibirPre(raiz->dir);
    }
}

// Fun��o para exibir a �rvore em ordem
void exibirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->dir);
    }
}

// Fun��o para exibir a �rvore em p�s-ordem
void exibirPos(No *raiz) {
    if (raiz != NULL) {
        exibirPos(raiz->esq);
        exibirPos(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int main() {
    No *raiz = NULL; // ponteiro aterrado
    int op, valor;

    do {
        printf("===== DIGITE A OPCAO =====\n");
        printf("[1]-INSERIR NA ARVORE\n[2]-EXIBIR EM PRE ORDEM\n[3]-EXIBIR EM ORDEM\n[4]-EXIBIR POS ORDEM\n[0]-SAIR\n");
        printf("\nDIGITE AQUI: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
            	valor = pedirDados(); 
				raiz = inserirNaArvore(raiz, valor);
				break;
			}
			
            case 2: {
            	if(raiz == NULL){
					printf("\nA ARVORE ESTA VAZIA!\n");}
				else{
            		exibirPre(raiz); printf("\n");		
				} 
				break;
			}
            case 3: {
            	exibirEmOrdem(raiz); printf("\n"); 
				break;
			}
            case 4: {
            	exibirPos(raiz); printf("\n");	
				break;
			}
            case 0: printf("\nFIM DO PROGRMA!"); break;
            default: printf("OPCAO INVALIDA!\n"); break;
        }
    } while (op != 0);

    return 0;
}
