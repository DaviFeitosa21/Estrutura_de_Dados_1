#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{
    int id;
    char nome[50];
} Aviao;

typedef struct {
    Aviao itens[TAM];
    int primeiro;
    int ultimo;
}Fila;

void iniciar(Fila *fila) {
    fila->primeiro = 0;
    fila-> ultimo = -1;
}

int cheia(Fila *fila) {
    if(fila->ultimo == TAM - 1) {
        return 1;
    } 
    else {
        return 0;
    }
}

int vazia(Fila *fila) {
    if(fila->primeiro > fila->ultimo) {
        return 1;
    }
    else {
        return 0;
    }
}

void enfileirar(Fila *fila, Aviao aviao) {
    if(cheia(fila) == 1) {
        printf("\nFila cheia.\n");
    }
    else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = aviao;
        printf("Aviao %s adicionado a fila!", aviao.nome);
    }
}

void desenfileirar(Fila *fila) {
    Aviao auxiliar;

    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        auxiliar = fila->itens[fila->primeiro];
        printf("Aviao %s autorizado para decolagem.\n", fila->itens[fila->primeiro].nome);
        fila->primeiro++;
    }
}

void mostrarPrimeiro(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("Fila vazia!");
    }
    else {
        printf("\nO primeiro aviao da fila e ID: %d | Nome: %s\n",
            fila->itens[fila->primeiro].id,
            fila->itens[fila->primeiro].nome);
    }
}

void tamanhoFila(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        printf("\nO tamanho da fila de decolagem e %d\n", (fila->ultimo - fila->primeiro) + 1);
    }
}

void exibir(Fila *fila) {
    int i = fila->primeiro;
    printf("\n---Fila atual---\n");

    while(i <= fila->ultimo) {
        printf("ID: %d | Nome: %s\n",
               fila->itens[i].id,
               fila->itens[i].nome);
        i++;
    }
}

int main() {
    int opcao=-1;
    Aviao item;
    Fila fila;

    iniciar(&fila);
        while(opcao!=0) {
        	exibir(&fila);
            
            printf("\n\nDIGITE 0 PARA SAIR\n");
            printf("Escolha uma opcao\n");
            printf("1: Enfileirar\n");
            printf("2: Desenfileirar\n");
            printf("3: Mostrar primeiro\n");
            printf("4: Tamanho\n");
       
            scanf("%d",&opcao);

            switch(opcao) {

            case 1:
                printf("Digite o ID: ");
                scanf("%d", &item.id);
                
                printf("Digite o Nome: ");
                scanf(" %s", item.nome);

                enfileirar(&fila, item);
                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                mostrarPrimeiro(&fila);
                break;

            case 4:
                tamanhoFila(&fila);
                break;

            case 0:
                printf("Tchau! Ate a proxima\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
        }

    return 0;
}
