#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* inserirNaLista(No* head, int num) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("\n\tERRO AO ALOCAR MEMORIA!");
        return head;
    }
    
    novo->valor = num;
    
    if (head == NULL) {
        // Se a lista estiver vazia, o novo nó aponta para si mesmo
        novo->prox = novo;
        head = novo;
        
    } else {
    	
        No* temp = head;

        while (temp->prox != head) { // percorrendo a lista para encontrar o último nó
            temp = temp->prox;
        }
        // Insere o novo nó no início
        novo->prox = head;
        temp->prox = novo;
        head = novo;
    }
    
    return head;
}

// Função de exemplo para percorrer e imprimir a lista
void printList(No* head) {
    if (head == NULL) {
        printf("Lista vazia\n");
        return;
    }
    No* temp = head;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    No* head = NULL;
    head = inserirNaLista(head, 1);
    head = inserirNaLista(head, 2);
    head = inserirNaLista(head, 3);

    printList(head);

    return 0;
}

