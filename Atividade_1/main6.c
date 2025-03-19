#include <stdio.h>
#include <stdlib.h>

struct Produto{
    char nome[50];
    int quant, cod;
    float price;
};

void Cadastro(struct Produto p[], int q){
    for(int i = 0; i < q; i++){
        printf("\nCadastro do Produto %d:\n", i+1);
        printf("Codigo: ");
        scanf("%d", &p[i].cod);
        printf("Nome: ");
        scanf("%s", p[i].nome);
        printf("Preco: ");
        scanf("%f", &p[i].price);
        printf("Quantidade: ");
        scanf("%d", &p[i].quant);
    }
}

void Compra(struct Produto p[], int q, int c){
    int cont = 0;
    for(int i = 0; i < q; i++){
        if(p[i].cod == c){
            cont = 1;
            if(p[i].quant >= q){
                p[i].quant -= q;
                printf("\nNota Viscal:\n");
                printf("Produto %s\n", p[i].nome);
                printf("Quantidade Comprada: %d\n", q);
                printf("Valor Total: %g\n", (p[i].price * q));
            }else{
                printf("\nQuantidade Insuficiente no Estoque\n");
                break;
            }
        }
    }
    if(cont == 0){
        printf("\nProduto nao Existe\n");
    }
}

void Imprime(struct Produto p[], int q){
    for(int i = 0; i < q; i++){
        printf("\nProduto %d:\n", i+1);
        printf("Nome: %s\n", p[i].nome);
        printf("Codigo: %d\n", p[i].cod);
        printf("Quantidade em Estoque: %d\n", p[i].quant);
        printf("Preco: %g\n", p[i].price);
    }
}

int main()
{
    int quantP = 0, cod, quantC = 0;
    printf("Quantidade de Produtos para Cadastrar: ");
    scanf("%d", &quantP);
    struct Produto real[quantP];
    Cadastro(real, quantP);
    printf("\nCodigo do Produto a Comprar: ");
    scanf("%d", &cod);
    printf("Quantidade de Produtos a Comprar: ");
    scanf("%d", &quantC);
    Compra(real, quantC, cod);
    Imprime(real, quantP);

    return 0;
}