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

int Grafo::calculaAvaliacao() {
	return avaliacao;
}
