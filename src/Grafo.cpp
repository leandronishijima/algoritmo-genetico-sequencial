#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Grafo.h"
#include "Vertice.h"
#include "Aresta.h"

Grafo::Grafo() {
	avaliacao = 0;
	srand(time(NULL));
}

void Grafo::adicionaVertice(int numeroVertice, int corVertice) {
	Vertice v = Vertice();
	v.setValor(numeroVertice);
	v.setCor(corVertice);

	vertices[numeroVertice] = v;
}

void Grafo::adicionaAresta(int verticeValor1, int verticeValor2) {
	Vertice vertice1 = vertices[verticeValor1];
	Vertice vertice2 = vertices[verticeValor2];

	arestas[verticeValor1][verticeValor2] = Aresta(vertice1, vertice2);
}

bool Grafo::existeAdjacenteComCor(Vertice vertice, int novaCor) {
	for (int i = 0; i < sizeof(vertices) - 1; ++i) {
		Aresta aresta = arestas[vertice.getValor()][i];

		if(aresta == 0)
			continue;

		int corAdjacente = aresta.getCorOutroVertice(vertice);

		if(corAdjacente == novaCor)
			return false;
	}

	return true;
}

void Grafo::randomizaCorVerticeSeguindoHeuristica(int verticeNumero) {
	Vertice vertice = vertices[verticeNumero];

	int corRandom = rand() % 4;

	if(!existeAdjacenteComCor(vertice, corRandom))
		vertice.setCor(corRandom);
}


int Grafo::calculaAvaliacao() {
	return avaliacao;
}
