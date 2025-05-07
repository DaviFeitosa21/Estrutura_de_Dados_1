#include <stdio.h>
#include <stdlib.h>
#define TAM 20 

typedef struct {
    int primeiro;
    int ultimo;
    int itens[TAM];
}Fila;

void iniciar(Fila *fila) {
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int cheia(Fila *fila) {
    if( fila->ultimo == TAM - 1) {
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

void enfileirar(Fila *fila, int valor) {
    if(cheia(fila) == 1) {
        printf("\nFila cheia!\n");
    }
    else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = valor;
    }
}

void desenfileirar(Fila *fila) {
    int auxiliar = 0;

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
        printf("\nFila vazia!\n");
    }else{
        printf("\nO primeiro da fila e [%d]\n",fila->itens[fila->primeiro]);
    }
}

void tamanho(Fila *fila){
    if(vazia(fila)==1){
         printf("\nFila vazia\n");
    }else {
        printf("\nO tamanho da fila e %d\n",(fila->ultimo - fila->primeiro) + 1);
    }
}


void exibir(Fila *fila) {
    int i = fila->primeiro;
    printf("\n---Fila atual---\n");
    while (i <= fila->ultimo) {
        printf("[%d] ",fila->itens[i]);
        i++;
    }
}

void intercalarFila(Fila *fila1, Fila *fila2) {
    Fila fila3;
    iniciar(&fila3);

    int fila1Contador = 0, fila2Contador = 0;

    for (int i = fila1->primeiro; i <= fila1->ultimo; i++) {
        fila1Contador++;
    }
    
    for (int i = fila2->primeiro; i <= fila2->ultimo; i++) {
        fila2Contador++;
    }

    if (fila1Contador != fila2Contador) {
        printf("\nAs filas não tem o mesmo tamanho. Nao e possível intercalar.\n");
        return;
    }

    int i = fila1->primeiro;
    int j = fila2->primeiro;

    while (i <= fila1->ultimo && j <= fila2->ultimo) {
        enfileirar(&fila3, fila1->itens[i]);
        enfileirar(&fila3, fila2->itens[j]);
        i++;
        j++;
    }

    printf("\n---Fila Intercalada---\n");
    for (int b = fila3.primeiro; b <= fila3.ultimo; b++) {
        printf("[%d] ", fila3.itens[b]);
    }
}

int main() {
    int opcao = -1;
    int valor1 = 0, valor2 = 0;
    Fila fila1;
    Fila fila2;

    iniciar(&fila1);
    iniciar(&fila2);
        while(opcao != 0) {
        	exibir(&fila1);
            exibir(&fila2);
            
            printf("\n\nDIGITE 0 PARA SAIR\n");
            printf("Escolha uma opcao\n");
            printf("1: Enfileirar fila 1\n");
            printf("2: Enfileirar fila 2\n");
            printf("3: Desenfileirar\n");
            printf("4: Intercalar Fila\n");
            printf("5: Mostrar primeiro\n");
            printf("6: Tamanho\n");
       
            scanf("%d",&opcao);

            switch(opcao) {

            case 1:
                printf("Digite um valor para enfileirar a fila 1\n");
                scanf("%d",&valor1);

                enfileirar(&fila1, valor1);
            
                break;

            case 2:
                printf("Digite um valor para enfileirar a fila 2\n");
                scanf("%d",&valor2);

                enfileirar(&fila2, valor2);

                break;

            case 3:
                desenfileirar(&fila1);
                desenfileirar(&fila2);
                break;

            case 4:
                intercalarFila(&fila1, &fila2);
                break;

            case 5:
                mostrarPrimeiro(&fila1);
                mostrarPrimeiro(&fila2);
                break;

            case 6:
                tamanho(&fila1);
                tamanho(&fila2);
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