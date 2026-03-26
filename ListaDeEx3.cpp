#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    Nodo *esq;
    Nodo *dir;
};

Nodo* criarNodo(int valor) {
    Nodo *novo = new Nodo;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprimir(Nodo *n) {
    if (n != NULL) {
        printf("%d\n", n->valor);
    }
}

int main() {
    Nodo *nodo5 = criarNodo(5);
    Nodo *nodo2 = criarNodo(2);
    Nodo *nodo8 = criarNodo(8);
    Nodo *nodo1 = criarNodo(1);
    Nodo *nodo4 = criarNodo(4);

    nodo5->esq = nodo2;
    nodo5->dir = nodo8;
    nodo2->esq = nodo1;
    nodo2->dir = nodo4;

    //Exercicio 1 adicionando o no 10 como filho para a direita
    Nodo *nodo10 = criarNodo(10);
    nodo8->dir = nodo10;

    //Exercico 2 aqui imprime valor do nodo4 a partir do nodo5
    printf("%d\n", nodo5->esq->dir->valor);

    //Exercicio 3 funçao void imprimir e seu uso no main
    imprimir(nodo5);

    //Exercicio 4 aqui estamos verificando se possui filjo a esquerda
    if (nodo8->esq == NULL) {
        printf("Vazio\n");
    }

    return 0;
}
