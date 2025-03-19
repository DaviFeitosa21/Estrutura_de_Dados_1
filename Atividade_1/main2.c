#include <stdio.h>
#include <stdbool.h>

struct dadosPessoais {
    char nome[50];
    float salario;
    int idade;
    bool sexo;
};

float AtribuirSalario(struct dadosPessoais *dadosPessoa, float novoSalario) {
    return dadosPessoa->salario = novoSalario;
}

int main() {

    struct dadosPessoais dadosPessoa;

    float vSalario;

    printf("=================Cadastro de Funcionario=================\n");

    printf("Digite um nome:\n");
    scanf(" %s", dadosPessoa.nome);

    printf("Digite a idade:\n");
    scanf("%f", &dadosPessoa.idade);

    printf("digite o sexo(0 = masculino / 1 = feminino)\n");
    scanf("%d", &dadosPessoa.sexo);

    printf("Digite o salario do funcionario:\n");
    scanf("%f", &vSalario);

    AtribuirSalario(&dadosPessoa, vSalario);

    printf("O novo salario e: %.2f", dadosPessoa.salario);

    return 0;
}