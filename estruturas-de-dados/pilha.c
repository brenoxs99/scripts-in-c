#include <stdio.h>


typedef struct no
{
    int chave;
    struct no * prox;
}No;
//------------------------------------------

int inserirDados(){
    int num;

    printf("\nDigite um valor inteiro: ");
    scanf("%d", &num);

    return num;
}
//------------------------------------------

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
        }else{
            novo->chave = inserirDados();
            novo->prox = topo;
            topo = novo;

            return topo;
        }
    }
}
//------------------------------------------





int main(){
    No* topo = NULL;
    int op;

    do{
        printf("\n[1]-INSERIR NA PILHA\n[2]-EXIBIR TOPO\n[3]-EXCLUIR TOPO");
        scanf("%d", &op);

        switch (op)
        {
        case 1:{
            topo = inserirNaPilha(topo);
            break;
        }
        case 2:{

                break;
        }    
        
            default:
                break;
        }
    }while(op != 0);
    

    return 0;
}