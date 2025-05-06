#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char itens[MAX];
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

void empilhar(Pilha *p, char c) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0';
}

int ehPalindromo(const char *str) {
    Pilha p;
    inicializar(&p);
    
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            empilhar(&p, toupper(str[i]));
        }
    }

    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            char topo = desempilhar(&p);
            if (toupper(str[i]) != topo) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char cadeia[MAX];

    printf("Digite uma cadeia de caracteres: ");
    fgets(cadeia, MAX, stdin);
    cadeia[strcspn(cadeia, "\n")] = 0;

    if (ehPalindromo(cadeia)) {
        printf("A cadeia \"%s\" e palindromo.\n", cadeia);
    } else {
        printf("A cadeia \"%s\" nao e palindromo.\n", cadeia);
    }

    return 0;
}
