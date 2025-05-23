#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define TAM_NOME 100

typedef struct{
    char nome[TAM_NOME];
    int idade;
} Pessoa;

typedef struct {
    Pessoa itens[TAM];
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

void enfileirar(Fila *fila, Pessoa valor) {
    if(cheia(fila) == 1) {
        printf("\nFila cheia.\n");
    }
    else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = valor;
    }
}

void desenfileirar(Fila *fila) {
    Pessoa auxiliar;

    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        auxiliar = fila->itens[fila->primeiro];
        fila->primeiro++;
    }
}

void mostrarPrimeiro(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("Fila vazia!");
    }
    else {
        printf("\nO primeiro da fila e Nome: %s | Idade: %d\n",
            fila->itens[fila->primeiro].nome,
            fila->itens[fila->primeiro].idade);
    }
}

void tamanhoFila(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        printf("\nO tamanho da fila e %d\n", (fila->ultimo - fila->primeiro) + 1);
    }
}

void exibir(Fila *fila) {
    int i = fila->primeiro;
    printf("\n---Fila atual---\n");

    while(i <= fila->ultimo) {
        printf("Nome: %s | Idade: %d\n",
               fila->itens[i].nome,
               fila->itens[i].idade);
        i++;
    }
}

int main() {
    int opcao=-1;
    Pessoa valor;
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
                printf("Digite o nome: ");
                scanf("%s", valor.nome);
                
                printf("Digite a idade: ");
                scanf("%d", &valor.idade);

                enfileirar(&fila, valor);
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

