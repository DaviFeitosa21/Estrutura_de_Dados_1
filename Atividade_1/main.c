#include <stdio.h>

struct contaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
};

void CriarConta(struct contaBancaria *contaBanco) {
    printf("Antes de realizar operacoes uma conta deve ser criada!\n");
    printf("Digite os dados para criacao da conta:\n");

    printf("Informe o numero da conta:\n->");
    scanf("%d", &contaBanco->numeroConta);

    printf("Informe o nome do titular da conta:\n->");
    scanf(" %s", contaBanco->nomeTitular);

    printf("Informe o saldo incial da conta:\n->");
    scanf("%f", &contaBanco->saldo);
}

float DepositarValor(struct contaBancaria *contaBanco, float valorDeposito) {
    return contaBanco->saldo += valorDeposito;
}

float SacarValor(struct contaBancaria *contaBanco, float valorSaque) {
    return contaBanco->saldo -= valorSaque;
}

float ConsultaSaldo(struct contaBancaria *contaBanco) {
    return contaBanco->saldo;
}

int main() {
    struct contaBancaria contaBanco;

    int menuOpcoes;

    float vDeposito, vSaque;

    CriarConta(&contaBanco);

    do {
        printf("\n=============TAD=============\n");
        printf("OPERACOES:\n");
        printf("1 - Depositos\n2 - Saques\n3 - Consultar Saldo\n");
        scanf("%d", &menuOpcoes);

    
        switch (menuOpcoes) {
        case 1:
            printf("Digite um valor para deposito:\n->");
            scanf("%f", &vDeposito);
            printf("Deposito realizado! Seu novo saldo e: %.2f\n", DepositarValor(&contaBanco, vDeposito));
            break;
        
        case 2:
            printf("Digite um valor para saque:\n->");
            scanf("%f", &vSaque);
            printf("Saque realizado! Seu novo saldo e: %.2f\n", SacarValor(&contaBanco, vSaque));
            break;

        case 3:
            printf("O saldo da conta e: %.2f\n", ConsultaSaldo(&contaBanco));
            break;
        
        default:
            printf("Opcao nao reconhecida! Tente novamente.");
            break;
        }
        
    } while (menuOpcoes != 3);
    
    return 0;
}