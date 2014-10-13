#include <iostream>
#include <stdlib.h>
#include "Grafo.h"
#include "Cromossomo.h"

using namespace std;

Cromossomo populacaoInicial[2];

int arraySize(int array[]) {
	return sizeof(array) / sizeof(int);
}

void adicionaVerticesComMesmaCor(Grafo grafo, int corDosVertices, int valores[]) {
	for (int i=0; i < arraySize(valores); ++i)
		grafo.adicionaVertice(valores[i], corDosVertices);
}

void adicionaVerticesComCoresRandomicas(Grafo grafo, int valores[]) {
	for (int i=0; i < arraySize(valores); ++i)
		grafo.adicionaVertice(valores[i], rand() % 4);
}

void adicionaArestasTeste(Grafo& grafo) {
	grafo.adicionaAresta(0, 1);
	grafo.adicionaAresta(0, 2);
	grafo.adicionaAresta(0, 3);
	grafo.adicionaAresta(1, 0);
	grafo.adicionaAresta(1, 2);
	grafo.adicionaAresta(1, 4);
	grafo.adicionaAresta(2, 0);
	grafo.adicionaAresta(2, 1);
	grafo.adicionaAresta(2, 5);
	grafo.adicionaAresta(3, 0);
	grafo.adicionaAresta(3, 5);
	grafo.adicionaAresta(4, 1);
	grafo.adicionaAresta(4, 5);
	grafo.adicionaAresta(5, 3);
	grafo.adicionaAresta(5, 4);
	grafo.adicionaAresta(5, 2);
}

Grafo geraPrimeiroGrafoTeste() {
	Grafo grafo = Grafo();
	int vertices[] = { 0, 1, 2, 3, 4, 5 };
	adicionaVerticesComMesmaCor(grafo, 0, vertices);
	adicionaArestasTeste(grafo);
	return grafo;
}

Grafo geraSegundoGrafoTeste() {
	Grafo grafo = Grafo();
	int vertices[] = { 0, 1, 2, 3, 4, 5 };
	adicionaVerticesComCoresRandomicas(grafo, vertices);
	adicionaArestasTeste(grafo);
	return grafo;
}

void criaPopulacaoInicial() {
	Cromossomo primeiroCromossomo = Cromossomo(geraPrimeiroGrafoTeste());
	Cromossomo segundoCromossomo = Cromossomo(geraSegundoGrafoTeste());
}

int main() {
	criaPopulacaoInicial();
	return 0;
}
