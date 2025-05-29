#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM {
    int item;
    struct ITEM *proximo;
}*tipoLista;

tipoLista criarItem(int valor) {
    tipoLista novoItem = (tipoLista) malloc(sizeof(tipoLista));

    if(novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return NULL;
    }
    else {
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista) { 
    tipoLista novoItem = criarItem(valor);
    
    if(lista == NULL) {
        return novoItem;
    }
    else {
        novoItem->proximo = lista;    
        return novoItem;
    }   
}

tipoLista inserirDireita(int valor, tipoLista lista) {
    tipoLista novoItem = criarItem(valor);
    
    if(lista == NULL) {
        return novoItem;
    }
    else {
        tipoLista listaAuxiliar = lista;
        while(listaAuxiliar->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->proximo = NULL;
        return lista;
    }
}

tipoLista removerEsquerda(tipoLista lista) {
    if(lista==NULL) {
        printf("\nVazia!\n");
        return lista;
    }
    else {

        tipoLista listaAuxiliar;
        listaAuxiliar = lista;
        lista = lista->proximo;

        free(listaAuxiliar);
        listaAuxiliar = NULL;
    }
    return lista;
}

tipoLista removerDireita(tipoLista lista) {
    if(lista==NULL) {
        printf("\nVazia!\n");
    }
    else {
        if(lista->proximo == NULL) { 
            free(lista);
            lista = NULL;
        }else {
            tipoLista listaAuxiliar;
            listaAuxiliar = lista;

            while(listaAuxiliar->proximo->proximo != NULL) {
                listaAuxiliar = listaAuxiliar->proximo;
            }

            tipoLista itemDescartar;
            itemDescartar = listaAuxiliar->proximo;

            free(itemDescartar);
            itemDescartar = NULL;
            listaAuxiliar->proximo = NULL;
        }
    }

    return lista;
}

void exibir(tipoLista lista) {
    printf("\n---Lista atual---\n");

    if(lista==NULL) {
        printf("\nVazia!\n");
    }
    else {
        tipoLista listaAuxiliar = lista;

        while(listaAuxiliar != NULL) {
            printf("[%d] ",listaAuxiliar->item);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

void pesquisar(int valor, tipoLista lista) {
    int contador = 0;
    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL) {
        if( listaAuxiliar->item == valor ) {
            contador++;
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }
    printf("\nHouve %d ocorrencia(s) do valor %d\n", contador, valor);
}

tipoLista inserirOrdenado(int valor, tipoLista lista) {
    tipoLista novoItem = criarItem(valor);

    if (lista == NULL || valor < lista->item) {
        novoItem->proximo = lista;
        return novoItem;
    }

    tipoLista atual = lista;
    while (atual->proximo != NULL && atual->proximo->item < valor) {
        atual = atual->proximo;
    }

    novoItem->proximo = atual->proximo;
    atual->proximo = novoItem;

    return lista;
}

tipoLista removerValor(int valor, tipoLista lista) {
    if (lista == NULL) {
        printf("\nLista vazia!\n");
        return NULL;
    }

    tipoLista atual = lista;
    tipoLista anterior = NULL;

    while (atual != NULL && atual->item != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nValor %d não encontrado na lista.\n", valor);
        return lista;
    }

    if (anterior == NULL) {
        // valor está no início
        lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("\nValor %d removido da lista.\n", valor);
    return lista;
}

int main() {
    int opcao = -1;
    int valor = 0;
    tipoLista lista = NULL;

    while(opcao != 0) {
        exibir(lista);
        valor = 0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Remover no inicio\n");
        printf("4: Remover no final\n");
        printf("5: Pesquisar\n");
        printf("6: Inserir em ordem (meio)\n");
        printf("7: Remover um valor específico\n");

        scanf("%d",&opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirEsquerda(valor, lista);
            break;
        case 2:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            lista = removerEsquerda(lista);
            break;
        case 4:
            lista = removerDireita(lista);
            break;
        case 5:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor, lista);
            break;
        case 6:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = inserirOrdenado(valor, lista);
            break;
        case 7:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = removerValor(valor, lista);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}