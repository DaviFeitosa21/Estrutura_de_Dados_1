#include <stdio.h>

typedef struct Pilha {
    int topo;
    struct Pilha *prox;
}*p;

p criarItem(int valor) {
    p novoItem = (p) malloc(sizeof(p));

    if(novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return NULL;
    }
    else {
        novoItem->topo = valor;
        novoItem->prox = NULL;
        return novoItem;
    }
}

p inserir(p pilha, int valor) {
    p novoItem = criarItem(valor);
    novoItem->prox = pilha;
    return novoItem;
}

p remover(p pilha) {
    if(pilha == NULL) {
        printf("\nPilha vazia!\n");
        return pilha;
    }
    else {
        p pilhaAux = pilha->prox;
        free(pilha);
        pilha = NULL;
        return pilhaAux;
    }
}

p exibir(p pilha) {
    printf("\nPilha atual:\n");

    if(pilha == NULL) {
        printf("\nPilha vazia!\n");
    }
    else {
        while(pilha != NULL) {
            printf("\n%d\n", pilha->topo);
            pilha = pilha->prox;
        }
    }
}

void exibirTopo(p pilha) {
    if(pilha == NULL) {
        printf("\nPilha vazia!\n");
    }
    else {
        printf("O topo da pilha e:\n", pilha->topo);
    }
}

void pesquisa(p pilha, int valor) {
    int cont = 0;

    while(pilha != NULL) {
        if(pilha->topo == valor) {
            cont++;
        }

        pilha = pilha->prox;
    }
    
    printf("\nFoi encontrado %d ocorrenco do valor %d\n", cont, valor);
}

int main() {


}