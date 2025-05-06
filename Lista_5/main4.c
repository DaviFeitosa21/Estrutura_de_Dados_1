#include <stdio.h>

#define TAM 20

typedef struct {
    int itens[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaCheia(Pilha *p) {
    return p->topo == TAM - 1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = valor;
    }
}

void exibirPilha(Pilha p, const char *nome) {
    printf("\nPilha %s:\n", nome);
    if (estaVazia(&p)) {
        printf("(vazia)\n");
        return;
    }

    for (int i = p.topo; i >= 0; i--) {
        printf("%d\n", p.itens[i]);
    }
}

int main() {
    Pilha pilhaA, pilhaB;
    int numero;

    inicializar(&pilhaA);
    inicializar(&pilhaB);

    printf("Digite 20 numeros inteiros:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            empilhar(&pilhaA, numero);
        } else {
            empilhar(&pilhaB, numero);
        }
    }

    exibirPilha(pilhaA, "A (pares)");
    exibirPilha(pilhaB, "B (impares)");

    return 0;
}
