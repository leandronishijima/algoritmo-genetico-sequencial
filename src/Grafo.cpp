#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Grafo.h"
#include "Vertice.h"
#include "Aresta.h"

Grafo::Grafo() {
	avaliacao = -1;
}

void Grafo::adicionaVertice(int numeroVertice, int corVertice) {
	Vertice v = Vertice();
	v.setValor(numeroVertice);
	v.setCor(corVertice);

	vertices[numeroVertice] = v;
}

Vertice Grafo::buscaOuAdicionaVerticeComCor1(int valorVertice) {
	Vertice vertice = vertices[valorVertice];

	if(vertice.isReal())
		return vertice;
	else {
		vertice = Vertice();
		vertice.setValor(valorVertice);
		vertice.setCor(1);

		vertices[valorVertice] = vertice;

		return vertice;
	}
}

void Grafo::adicionaArestaComCor1(int verticeValor1, int verticeValor2) {
	Vertice vertice1 = buscaOuAdicionaVerticeComCor1(verticeValor1);
	Vertice vertice2 = buscaOuAdicionaVerticeComCor1(verticeValor2);

	arestas[verticeValor1][verticeValor2] = Aresta(vertice1, vertice2);
}

bool Grafo::existeAdjacenteComCor(Vertice vertice, int novaCor) {
	for (unsigned int i = 0; i < sizeof(vertices); ++i) {
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

	if(!existeAdjacenteComCor(vertice, cor)) {
		vertice.setCor(cor);
		calculaAvaliacao();
	}
}

void Grafo::calculaAvaliacao() {
	int novaAvaliacao = 0;

	for (int i = 0; i < getQuantidadeVertices() - 1; ++i)
		for (int j = i + 1; j < getQuantidadeVertices() - 1; ++j)
			if(arestas[i][j].validaCorDiferenteVertices())
				novaAvaliacao++;

	avaliacao = novaAvaliacao;
}

int Grafo::getAvaliacao() {
	return avaliacao;
}

int Grafo::getQuantidadeVertices() {
	return sizeof(vertices);
}
