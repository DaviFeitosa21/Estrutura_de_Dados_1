#include <stdio.h>

#define TAM 5

struct Pilha {
    int topo;
    int itens[TAM];
};

void inicializarPilha(struct Pilha *p) {
    p->topo = -1;
}

int PilhaVazia(struct Pilha *p) {
    if(p->topo == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int PilhaCheia(struct Pilha *p) {
    if(p->topo == TAM-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void PilhaInserir(struct Pilha *p, int valor) {
    if(PilhaCheia(p) == 1) {
        printf("Nao foi possivel.(Pilha cheia)!!!\n");
    }
    else {
        p->topo++;
        p->itens[p->topo] = valor;
        printf("Valor inserido com sucesso!!!\n");
    }
}

void PilhaRemover(struct Pilha *p) {
    if (PilhaVazia(p) == 1){
        printf("Nao foi possivel.(Pilha vazia)!!!\n");
    }
    else {
        p->topo--;
        printf("Valor removido com sucesso!!!\n");
    }
}

void PilhaExibir(struct Pilha *p) {
    int posPilha = p->topo;

    printf("Situacao atual:\n\n");
    if(PilhaVazia(p) == 1) {
        printf("Pilha vazia!!!\n");
    }
    else {
        while(posPilha != -1) {
            printf("%d\n\n", p->itens[posPilha]);
            posPilha--;
        }
    }
}

void PilhaExibirTopo(struct Pilha *p) {
    if(PilhaVazia(p) == 1) {
        printf("Pilha vazia!!!\n\n");
    }
    else {
        printf("%d", p->itens[p->topo]);
    }
}

int main() {
    struct Pilha p;

    int escolha, valor = 0;

    inicializarPilha(&p);

    do
    {
        PilhaExibir(&p);

        printf("Digite uma opcao:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Visualizar\n");
        printf("4 - Sair\n\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite um valor:\n");
            scanf("%d", &valor);
            PilhaInserir(&p, valor);
            break;
        
        case 2:
            PilhaRemover(&p);
            break;

        case 3:
            PilhaExibir(&p);
            break;
        
        case 4:
            exit(0);
            break;

        default:
            printf("opcao de escolha nao identificada!\n");
            break;
        }
    } while (escolha != 4);

    return 0;
}