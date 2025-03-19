#include <stdio.h>

struct Alunos {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};

int maxAlunos = 50, mediaAluno = 0;

void MatricularAluno(struct Alunos alunos[], int *quantAlunos) {
    printf("=================REGISTRO DE ALUNOS=================\n");
    printf("Digite quantos alunos deseja registrar:\n");
    scanf("%d", quantAlunos);

    for(int i = 0; i < *quantAlunos; i++) {
        printf("\nDigite o nome do aluno %d:\n->", i + 1);
        scanf(" %s", alunos[i].nome);

        printf("Infome a matricula do aluno %d:\n->", i + 1);
        scanf(" %s", alunos[i].matricula);

        printf("Informe a turma do aluno %d:\n->", i + 1);
        scanf(" %c", &alunos[i].turma);

        printf("Digite a nota 1 do aluno %d:\n->", i + 1);
        scanf("%f", &alunos[i].p1);

        printf("Digite a nota 2 do aluno %d:\n->", i + 1);
        scanf("%f", &alunos[i].p2);

        printf("Digite a nota 3 do aluno %d:\n->", i + 1);
        scanf("%f", &alunos[i].p3);
    }
}

void ConsultaAlunos(struct Alunos alunos[], int quantAlunos) {
    for (int i = 0; i < quantAlunos; i++) {
        printf("\nAluno: %d\n", i + 1);
        printf("Nome do aluno: %s\n", alunos[i].nome);
        printf("Matrucula do aluno: %s\n", alunos[i].matricula);
        printf("Turma do aluno: %c\n", alunos[i].turma);
        printf("Notas do aluno:\n");
        printf("Nota 1: %.2f / Nota 2: %.2f / Nota 3: %.2f\n", alunos[i].p1, alunos[i].p2, alunos[i].p3);
    }
}

float MediaTurma(struct Alunos alunos[], int quantAlunos, char turma) {
    float somaMedias = 0;
    int contaAlunos = 0;

    for (int i = 0; i < quantAlunos; i++) {
        if (alunos[i].turma == turma) {
            float mediaAluno = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / 3.0;
            somaMedias += mediaAluno;
            contaAlunos++;
        }
    }

    return somaMedias / contaAlunos;
}

int main() {
    struct Alunos alunos[maxAlunos];

    int quantAlunos = 0;
    char consultaMedia;
    float mediaFinalTurma;

    MatricularAluno(alunos, &quantAlunos);
    ConsultaAlunos(alunos, quantAlunos);

    printf("\nDigite uma turma para consultar a media:\n");
    scanf(" %c", &consultaMedia);

    mediaFinalTurma = MediaTurma(alunos, quantAlunos, consultaMedia);

    printf("Media final da turma: %.2f", mediaFinalTurma);
}