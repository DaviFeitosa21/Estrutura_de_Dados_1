#include <stdio.h>

#define TAM 100

typedef struct {
    int itens[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == TAM - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return -1;
}

int tamanho(Pilha p) {
    return p.topo + 1;
}

void exibirPilha(Pilha p, const char* nome) {
    printf("Pilha %s (topo -> base): ", nome);
    if (estaVazia(&p)) {
        printf("(vazia)\n");
        return;
    }
    for (int i = p.topo; i >= 0; i--) {
        printf("%d ", p.itens[i]);
    }
    printf("\n");
}

Pilha intercalaPilha(Pilha p1, Pilha p2) {
    Pilha resultado, aux1, aux2;
    inicializar(&resultado);
    inicializar(&aux1);
    inicializar(&aux2);

    if (tamanho(p1) != tamanho(p2)) {
        printf("As pilhas nao tem o mesmo tamanho. Nao e possível intercalar.\n");
        return resultado;
    }

    while (!estaVazia(&p1)) empilhar(&aux1, desempilhar(&p1));
    while (!estaVazia(&p2)) empilhar(&aux2, desempilhar(&p2));

    while (!estaVazia(&aux1) && !estaVazia(&aux2)) {
        empilhar(&resultado, desempilhar(&aux1));
        empilhar(&resultado, desempilhar(&aux2));
    }

    return resultado;
}

int main() {
    Pilha p1, p2, p3;
    inicializar(&p1);
    inicializar(&p2);

    empilhar(&p1, 5);
    empilhar(&p1, 3);
    empilhar(&p1, 1);

    empilhar(&p2, 6);
    empilhar(&p2, 4);
    empilhar(&p2, 2);

    exibirPilha(p1, "P1");
    exibirPilha(p2, "P2");

    p3 = intercalaPilha(p1, p2);

    exibirPilha(p3, "P3 (intercalada)");

    return 0;
}
