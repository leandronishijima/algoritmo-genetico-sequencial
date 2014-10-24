#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Grafo.h"
#include "Vertice.h"
#include "Aresta.h"

Grafo::Grafo() {
	avaliacao = 0;
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
	for (unsigned int i = 0; i < vertices.size(); ++i) {
		Aresta aresta = arestas[vertice.getValor()][i];

		if(!aresta.isArestaReal())
			continue;

		int corAdjacente = aresta.getCorOutroVertice(vertice);

		if(corAdjacente == novaCor)
			return false;
	}

	return true;
}

void Grafo::randomizaCorVerticeSeguindoHeuristica(int verticeNumero, int cor) {
	Vertice vertice = vertices[verticeNumero];

	if(!existeAdjacenteComCor(vertice, cor))
		vertice.setCor(cor);
}


int Grafo::calculaAvaliacao() {
	return avaliacao;
}

int Grafo::getQuantidadeVertices() {
	return vertices.size();
}
