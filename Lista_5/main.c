#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int topo;
} Alfab;

void initStack(Alfab *s) {
    s->topo = -1;
}

bool isEmpty(Alfab *s) {
    return s->topo == -1;
}

bool isFull(Alfab *s) {
    return s->topo == MAX - 1;
}

void push(Alfab *s, char c) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    s->data[++s->topo] = c;
}

char pop(Alfab *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return s->data[s->topo--];
}

bool isWcMFormat(const char *str) {
    Alfab s;
    initStack(&s);
    int len = strlen(str);
    int i = 0;
    
    while (i < len && str[i] != 'c') {
        if (str[i] != 'a' && str[i] != 'b') {
            return false;
        }
        push(&s, str[i]);
        i++;
    }
    
    if (i == 0 || i == len || str[i] != 'c') {
        return false;
    }
    i++;
    
    while (i < len && !isEmpty(&s)) {
        if (str[i] != pop(&s)) {
            return false;
        }
        i++;
    }
    
    return (i == len && isEmpty(&s));
}

int main() {
    char str[MAX];
    
    printf("Digite uma string para verificar (apenas a, b, c): ");
    scanf("%s", str);
    
    if (isWcMFormat(str)) {
        printf("A string '%s' esta no formato WcM.\n", str);
    } else {
        printf("A string '%s' nao esta no formato WcM.\n", str);
    }
    
    return 0;
}