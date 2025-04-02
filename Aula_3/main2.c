#include <stdio.h>

typedef struct Pilha {
    int topo;
    struct Pilha *prox;
}*p;

p criarItem(int valor) {
    p novoItem = (p) malloc(sizeof(p));

    if(novoItem == NULL) {

    }

}

p inserir(p pP, int valor) {
    p novoItem = criarItem(valor);
    novoItem->prox = pP;
    return novoItem;
}



int main() {


}