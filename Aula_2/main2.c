#include <stdio.h>

struct pessoa {
    char nome[50];
};

int main() {
    struct pessoa *ps;
    
    int n;

    printf("Digite o numero de elementos:\n");
    scanf("%d", &n);

    ps = (struct pessoa *)malloc(n * sizeof(struct pessoa));

    if(ps == NULL) {
        printf("erro: vetor NULL!!!");
        return 1;
    }

    printf("Digite %d nomes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", ps[i].nome);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", ps[i].nome);
    }

    free(ps);

    return 0;
}