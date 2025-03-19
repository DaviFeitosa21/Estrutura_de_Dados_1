#include <stdio.h>

int main() {
    int n, soma = 0;

    printf("Digite o numero de elementos:\n");
    scanf("%d", &n);

    int *vet = (int *)malloc(n * sizeof(int));

    if(vet == NULL) {
        printf("erro: vetor NULL!!!");
        return 1;
    }

    printf("Digite %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }
    
    printf("\nO resultado soma dos numeros e:\n");
    printf("%d", soma);

    free(vet);

    return 0;
}