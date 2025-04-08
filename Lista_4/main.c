#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];  
    int topo;        
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia!\n");
        return 0;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}

int topo(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *valor = p->dados[p->topo];
    return 1;
}

void exibir(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    int valor;

    inicializar(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    exibir(&p);

    if (desempilhar(&p, &valor)) {
        printf("Desempilhado: %d\n", valor);
    }

    exibir(&p);

    return 0;
}
