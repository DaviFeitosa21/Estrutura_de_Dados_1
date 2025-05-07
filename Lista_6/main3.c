#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define TAM_NOME 100

typedef struct{
    char nome[TAM_NOME];
    int idade;
} Paciente;

typedef struct {
    Paciente paciente[TAM];
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

void enfileirar(Fila *fila, Paciente paciente) {
    if(cheia(fila) == 1) {
        printf("\nFila cheia.\n");
    }
    else {
        fila->ultimo++;
        fila->paciente[fila->ultimo] = paciente;
        printf("\nPaciente %s inserido na fila de espera!\n", paciente.nome);
    }
}

void desenfileirar(Fila *fila) {
    Paciente auxiliar;

    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        auxiliar = fila->paciente[fila->primeiro];
        printf("\nPaciente %s chamado para atendimento!\n", fila->paciente[fila->primeiro].nome);
        fila->primeiro++;
    }
}

void mostrarPrimeiro(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("Fila vazia!");
    }
    else {
        printf("\nO proximo paciente da fila e Nome: %s | Idade: %d\n",
            fila->paciente[fila->primeiro].nome,
            fila->paciente[fila->primeiro].idade);
    }
}

void tamanhoFila(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        printf("\nO tamanho da fila de espera e %d\n", (fila->ultimo - fila->primeiro) + 1);
    }
}

void exibir(Fila *fila) {
    int i = fila->primeiro;
    printf("\n---Fila atual---\n");

    while(i <= fila->ultimo) {
        printf("Nome: %s | Idade: %d\n",
               fila->paciente[i].nome,
               fila->paciente[i].idade);
        i++;
    }
}

void atendPrioritario(Fila *fila) {
    if(vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    }
    else {
        int maisVelho = fila->paciente[fila->primeiro].idade;
        int indiceMaisVelho = fila->primeiro;

        for (int i = fila->primeiro + 1; i <= fila->ultimo; i++) {
            if (fila->paciente[i].idade > maisVelho) {
                maisVelho = fila->paciente[i].idade;
                indiceMaisVelho = i;
            }
        }

        printf("Paciente prioritario chamado: %s (Idade: %d)\n", fila->paciente[indiceMaisVelho].nome, fila->paciente[indiceMaisVelho].idade);

        for (int i = indiceMaisVelho; i < fila->ultimo; i++) {
            fila->paciente[i] = fila->paciente[i + 1];
        }

        fila->ultimo--;
    }
}

int main() {
    int opcao = -1;
    Paciente paciente;
    Fila fila;

    iniciar(&fila);
        while(opcao!=0) {
        	exibir(&fila);
            
            printf("\n\nDIGITE 0 PARA SAIR\n");
            printf("Escolha uma opcao\n");
            printf("1: Enfileirar\n");
            printf("2: Desenfileirar\n");
            printf("3: Atendimento Prioritario\n");
            printf("4: Mostrar primeiro\n");
            printf("5: Tamanho\n");
       
            scanf("%d",&opcao);

            switch(opcao) {

            case 1:
                printf("Digite o nome: ");
                scanf("%s", paciente.nome);
                
                printf("Digite a idade: ");
                scanf("%d", &paciente.idade);

                enfileirar(&fila, paciente);
                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                atendPrioritario(&fila);
                break;

            case 4:
                mostrarPrimeiro(&fila);
                break;

            case 5:
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

