#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX 100

typedef struct ALUNO {
    char nome[MAX];
    int matricula;
    struct ALUNO *proximo;
}*tipoLista;

tipoLista criarItem(char nome[], int matricula) {
    tipoLista novoItem = (tipoLista) malloc(sizeof(struct ALUNO));

    if(novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return NULL;
    }
    else {
        strcpy(novoItem->nome, nome);
        novoItem->matricula = matricula;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirOrdenado(tipoLista lista, char nome[], int matricula) {
    tipoLista novoItem = criarItem(nome, matricula);

    if(lista == NULL || strcmp(novoItem->nome, lista->nome) < 0) {
        novoItem->proximo = lista;
        return novoItem;
    }
    else {
        //novoItem->proximo = lista;

        tipoLista listaAux = lista;
        while(listaAux->proximo != NULL && strcmp(novoItem->nome, listaAux->proximo->nome) > 0) {
            listaAux = listaAux->proximo;
        }

        novoItem->proximo = listaAux->proximo;
        listaAux->proximo = novoItem;

        return lista;
    }
}

tipoLista removerAluno(tipoLista lista, int matricula) {
    if(lista == NULL) {
        printf("\nVazia!\n");
        return lista;
    }
    else {
        tipoLista atual = lista;
        tipoLista anterior = NULL;

        if(lista->matricula == matricula) {
            tipoLista listaAux = lista;
            lista = lista->proximo;
            free(listaAux);
            printf("Aluno com matricula %d removido.\n", matricula);
            return lista;
        }

        while(atual != NULL && atual->matricula != matricula) {
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual == NULL) {
            printf("Aluno com matrícula %d não encontrado.\n", matricula);
            return lista;
        }

        anterior->proximo = atual->proximo;
        free(atual);
        printf("Aluno com matrícula %d removido.\n", matricula);

        return lista;
    }
}

void exibir(tipoLista lista) {
    printf("\n---Lista atual---\n");

    if(lista == NULL) {
        printf("\nVazia!\n");
    }
    else {
        tipoLista listaAuxiliar = lista;

        while(listaAuxiliar != NULL) {
            printf("Nome: %s | Matrícula: %d\n", listaAuxiliar->nome, listaAuxiliar->matricula);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main() {
    int opcao = -1;
    int valor = 0;
    tipoLista lista = NULL;

    char nome[MAX];
    int matricula;

    while(opcao != 0) {
        exibir(lista);
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir Aluno\n");
        printf("2: Remover Aluno\n");

        scanf("%d",&opcao);

        switch(opcao) {
        case 1:
            printf("Nome do aluno: ");
            scanf(" %s", nome);

            printf("Matrícula: ");
            scanf("%d", &matricula);

            lista = inserirOrdenado(lista, nome, matricula);
            exibir(lista);
            break;
        case 2:
            printf("Digite a matrícula do aluno a remover: ");
            scanf("%d", &matricula);
            lista = removerAluno(lista, matricula);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}