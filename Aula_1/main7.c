#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char primeiro_nome[50];
    char ultimo_nome[50];
    float indice_graduacao;
} Estudante;

typedef struct {
    char primeiro_nome[50];
    char ultimo_nome[50];
    float salario;
} Funcionario;

void conceder_aumento(Funcionario funcionarios[], int num_func, Estudante estudantes[], int num_est) {
    for (int i = 0; i < num_func; i++) {
        for (int j = 0; j < num_est; j++) {
            if (strcmp(funcionarios[i].ultimo_nome, estudantes[j].ultimo_nome) == 0 &&
                strcmp(funcionarios[i].primeiro_nome, estudantes[j].primeiro_nome) == 0) {
                if (estudantes[j].indice_graduacao > 3.0) {
                    funcionarios[i].salario *= 1.10;
                }
            }
        }
    }
}

int main() {
    Funcionario funcionarios[MAX];
    Estudante estudantes[MAX];
    int num_func, num_est;

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &num_func);
    for (int i = 0; i < num_func; i++) {
        printf("Digite o primeiro nome, ultimo nome e salario do funcionario %d: ", i + 1);
        scanf("%s %s %f", funcionarios[i].primeiro_nome, funcionarios[i].ultimo_nome, &funcionarios[i].salario);
    }

    printf("Digite o numero de estudantes: ");
    scanf("%d", &num_est);
    for (int i = 0; i < num_est; i++) {
        printf("Digite o primeiro nome, ultimo nome e indice de graduacao do estudante %d: ", i + 1);
        scanf("%s %s %f", estudantes[i].primeiro_nome, estudantes[i].ultimo_nome, &estudantes[i].indice_graduacao);
    }

    conceder_aumento(funcionarios, num_func, estudantes, num_est);

    printf("\nSalarios atualizados:\n");
    for (int i = 0; i < num_func; i++) {
        printf("%s %s: Salario atualizado = %.2f\n", 
                funcionarios[i].primeiro_nome, 
                funcionarios[i].ultimo_nome, 
                funcionarios[i].salario);
    }

    return 0;
}