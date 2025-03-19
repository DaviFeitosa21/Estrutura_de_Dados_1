#include <stdio.h>

int main() {

    int linhas, colunas;

    printf("Digite a quantidade de linhas da matriz:\n");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas da matriz:\n");
    scanf("%d", &colunas);

    int *vet = (int *)malloc(linhas * colunas * sizeof(int));

    if (vet == NULL) {
        printf("erro: vetor NULL!!!");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor de [%d][%d]\n", i, j);
            scanf("%d", &vet[i * colunas + j]);
        }
    }

    printf("\nMatriz digitada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%3d ", vet[i * colunas + j]);
        }
        printf("\n");
    }

    free(vet);

    return 0;
}