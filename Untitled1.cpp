#include <iostream>

//Exercicio 1- Ordem exata impressa ao adicionar 7, 3, 9
//A impressao em ordem fica
  //1 2 3 4 5 6 7 8 9
  
  //Exercicio 2- Se mover o printf para antes de imprimir(n->esq)
//Ou seja, vira um percurso pré-ordem (pre-order). Então os valores não sairiam mais ordenados.  

// Exercicio 3- Estrutura da árvore com as chamadas add(5, 2, 1, 8, 4)
   	//	  6
   //    / \
   //   5   8
   //  /
  //  2
 //  / \
  	1   4
//Filhos
	//5 é filho à esquerda de 6
	//2 é filho à esquerda de 5	
	//1 é filho à esquerda de 2
	//8 é filho à direita de 6
	//4 é filho à direita de 2
	
// Exercicio 4- O que acontece se executar add(root, 5) de novo?
//Como o 5 já existe, ele vai seguir a regra da função add, então o novo 5 será inserido à direita do 5 já existente.

//Exercicio 6- Por que verificar if(n->esq == NULL) antes da recursão?
//quando n->esq for NULL, a função tentará acessar um ponteiro nulo e isso pode causar erro.


using namespace std;

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

void add(Nodo *n, int valor) {
    if (valor < n->valor) {
        if (n->esq == NULL) {
            n->esq = criarNodo(valor);
        } else {
            add(n->esq, valor);
        }
    } else {
        if (n->dir == NULL) {
            n->dir = criarNodo(valor);
        } else {
            add(n->dir, valor);
        }
    }
}

void imprimir(Nodo *n) {
    if (n != NULL) {
        imprimir(n->esq);
        cout << n->valor << " ";
        imprimir(n->dir);
    }
}

void imprimirDecrescente(Nodo *n) {
    if (n != NULL) {
        imprimirDecrescente(n->dir);
        cout << n->valor << " ";
        imprimirDecrescente(n->esq);
    }
}

//exercicio 7
int existe(Nodo *n, int valor) {
    if (n == NULL) return 0;
    if (n->valor == valor) return 1;

    if (valor < n->valor) {
        return existe(n->esq, valor);
    } else {
        return existe(n->dir, valor);
    }
}

//exercicio 8
int quantidadeNodos(Nodo *n) {
    if (n == NULL) return 0;
    return 1 + quantidadeNodos(n->esq) + quantidadeNodos(n->dir);
}

//exercicio 9
int maiorValor(Nodo *n) {
    if (n == NULL) return -1;
    if (n->dir == NULL) return n->valor;
    return maiorValor(n->dir);
}

//exercicio 10
int soma(Nodo *n) {
    if (n == NULL) return 0;
    return n->valor + soma(n->esq) + soma(n->dir);
}

int main() {
    Nodo *root = criarNodo(6);

    add(root, 5);
    add(root, 2);
    add(root, 1);
    add(root, 8);
    add(root, 4);

    add(root, 7);
    add(root, 3);
    add(root, 9);

    cout << "Imprimir crescente: ";
    imprimir(root);

    cout << "\nImprimir decrescente: ";
    imprimirDecrescente(root);

    cout << "\nExiste 4? " << existe(root, 4);
    cout << "\nExiste 10? " << existe(root, 10);

    cout << "\nQuantidade de nodos: " << quantidadeNodos(root);
    cout << "\nMaior valor: " << maiorValor(root);
    cout << "\nSoma dos valores: " << soma(root) << endl;

    return 0;
}
