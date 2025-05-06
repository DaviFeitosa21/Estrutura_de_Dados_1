#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No* proximo;
} No;

void empilhar(No** topo, Pessoa p) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->pessoa = p;
    novo->proximo = *topo;
    *topo = novo;
}

Pessoa desempilhar(No** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    No* temp = *topo;
    Pessoa p = temp->pessoa;
    *topo = temp->proximo;
    free(temp);
    return p;
}

void removerPorNome(No** topo, const char* nomeRemover) {
    No* pilhaTemp = NULL;
    int encontrado = 0;

    while (*topo != NULL) {
        Pessoa p = desempilhar(topo);
        if (strcmp(p.nome, nomeRemover) == 0) {
            printf("Removendo: %s\n", p.nome);
            encontrado = 1;
            break;
        } else {
            empilhar(&pilhaTemp, p);
        }
    }

    while (pilhaTemp != NULL) {
        empilhar(topo, desempilhar(&pilhaTemp));
    }

    if (!encontrado) {
        printf("Nome \"%s\" não encontrado na pilha.\n", nomeRemover);
    }
}

void exibirPilha(No* topo) {
    printf("\nPilha atual:\n");
    while (topo != NULL) {
        printf("Nome: %s, Idade: %d\n", topo->pessoa.nome, topo->pessoa.idade);
        topo = topo->proximo;
    }
}

int main() {
    No* pilha = NULL;
    int n;

    printf("Quantas pessoas deseja empilhar? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        Pessoa p;
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(p.nome, MAX_NOME, stdin);
        p.nome[strcspn(p.nome, "\n")] = 0;
        printf("Digite a idade: ");
        scanf("%d", &p.idade);
        getchar();
        empilhar(&pilha, p);
    }

    exibirPilha(pilha);

    char nomeRemover[MAX_NOME];
    printf("\nDigite o nome da pessoa que deseja remover: ");
    fgets(nomeRemover, MAX_NOME, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

    removerPorNome(&pilha, nomeRemover);

    exibirPilha(pilha);

    while (pilha != NULL) {
        desempilhar(&pilha);
    }

    return 0;
}
