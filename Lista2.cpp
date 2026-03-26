// Exercicio 1 
//Se chamarmos rem(raiz, 10) e o nodo 10 não possui filhos, será executado o bloco de remoção de folha.
//O ponteiro do pai passa a apontar para NULL.
	//se 10 era filho da esquerda: pai->esq = NULL
	//se 10 era filho da direita: pai->dir = NULL
	
//Exercicio 2
//Se tentarmos remover o valor que está na raiz, essa função provavelmente não trata esse caso corretamente, porque ela costuma depender de um pai do nodo removido.
//Como a raiz não tem pai, o código pode: não remover a raiz corretamente, ou dar erro, dependendo de como foi escrito.

//Exercicio 3
//   20   se removermos o 20, quem ocupa o lugar dele no ponteiro do pai é o 15. Então o pai do 20 passaria a apontar para 15.
//   /
//  15

//Exerxcicio 4
//Se o nodo possui filho à esquerda e filho à direita, o código atual, pelo jeito do enunciado, não trata corretamente esse caso.
//Então ele provavelmente: não remove o nodo, ou entra num caso incompleto.

//Exercicio 5
//Se percorremos toda a árvore e o valor não é encontrado (filho == NULL), o código imprime uma mensagem de valor não encontrado. Vai aparecer a mensagem: não encontrou o valor

//Exercicio 6
//O comando essencial que falta para liberar memória
// free(filho);

//Exercicio 7
// filho != NULL && filho->valor != valor
//garantir que o ponteiro filho ainda aponta para um nodo válido evitar acessar filho->valor quando filho == NULL, o que causaria erro
//Primeiro ele testa se o nodo existe, depois verifica se o valor é diferente.

//Exercicio 8
//pai->dir = filho->dir;

//Exercicio 9
//    15
//   /
//  10
// /
//5
//Mensagem que aparece no console: 1 filho a esquerda


//Exercicio 10
//Não.
//Não é possível que pai->esq == filho e pai->dir == filho sejam verdadeiros ao mesmo tempo em uma árvore binária normal.
//Um pai não pode ter o mesmo nodo simultaneamente nos dois lados.
//Isso só aconteceria se a estrutura estivesse errada ou corrompida.
