#include <stdio.h>

struct Aluno {
    char nome[30];
    int idade;
};

int main() {
    struct Aluno *aluno;

    int quantAlunos;

    printf("Digite a quantidade de alunos a cadastrar:\n");
    scanf("%d", &quantAlunos);

    aluno = (struct Aluno *)malloc(quantAlunos * sizeof(struct Aluno));

    for (int i = 0; i < quantAlunos; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf(" %s", aluno[i].nome);

        printf("Digite a idade de %s: ", aluno[i].nome);
        scanf("%d", &aluno[i].idade);
    }

    printf("\nLista de Alunos Cadastrados:\n");
    for (int i = 0; i < quantAlunos; i++) {
        printf("Aluno %d: Nome: %s, Idade: %d anos\n", i + 1, aluno[i].nome, aluno[i].idade);
    }

    free(aluno);

    return 0;
}