#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>

#include "Grafo.h"
#include "Vertice.h"
#include "Aresta.h"

Grafo::Grafo() {
	srand(time(NULL));
	avaliacao = -1;
}

Vertice Grafo::adicionaVertice(int numeroVertice, int corVertice) {
	Vertice v = Vertice();
	v.setValor(numeroVertice);
	v.setCor(corVertice);

	vertices[numeroVertice] = v;

	return v;
}

Vertice Grafo::buscaOuAdicionaVerticeComCor1(int valorVertice) {
	Vertice vertice = vertices[valorVertice];

	if (vertice.isReal())
		return vertice;
	else
		return adicionaVertice(valorVertice, 1);
}

void Grafo::adicionaArestaNaListaDeAdjacencia(Vertice vertice, const Aresta& aresta) {
	listaDeAdjacencia[vertice.getValor()].push_back(aresta);
}

void Grafo::criaAresta(Vertice vertice1, Vertice vertice2) {
	Aresta aresta = Aresta(vertice1, vertice2);

	arestas.push_back(aresta);

	adicionaArestaNaListaDeAdjacencia(vertice1, aresta);
	adicionaArestaNaListaDeAdjacencia(vertice2, aresta);
}

void Grafo::adicionaArestaComCor1(int verticeValor1, int verticeValor2) {
	Vertice vertice1 = buscaOuAdicionaVerticeComCor1(verticeValor1);
	Vertice vertice2 = buscaOuAdicionaVerticeComCor1(verticeValor2);

	criaAresta(vertice1, vertice2);
}

Vertice Grafo::buscaOuAdicionaVerticeComCorRandom(int valorVertice) {
	Vertice vertice = vertices[valorVertice];

	if (vertice.isReal())
		return vertice;
	else
		return adicionaVertice(valorVertice, rand() % 4);
}

void Grafo::adicionaArestaComCorAleatoria(int verticeValor1, int verticeValor2) {
	Vertice vertice1 = buscaOuAdicionaVerticeComCorRandom(verticeValor1);
	Vertice vertice2 = buscaOuAdicionaVerticeComCorRandom(verticeValor2);

	criaAresta(vertice1, vertice2);
}

int Grafo::getQuantidadeVertices() {
	return vertices.size();
}

bool Grafo::existeAdjacenteComCor(Vertice vertice, int novaCor) {
	vector<Aresta> adjacentes = listaDeAdjacencia[vertice.getValor()];

	for(vector<Aresta>::iterator it = adjacentes.begin() ; it != adjacentes.end(); ++it) {
		Aresta aresta = *it;
		int corAdjacente = aresta.getCorOutroVertice(vertice);

		if (corAdjacente == novaCor)
			return false;
	}

	return true;
}

void Grafo::randomizaCorVerticeSeguindoHeuristica(int verticeNumero, int cor) {
	Vertice vertice = vertices.at(verticeNumero);

	if (!existeAdjacenteComCor(vertice, cor)) {
		vertice.setCor(cor);
		calculaAvaliacao();
	}
}

void Grafo::calculaAvaliacao() {
	int novaAvaliacao = 0;

	for(vector<Aresta>::iterator it = arestas.begin() ; it != arestas.end(); ++it) {
		Aresta aresta = *it;

		if(aresta.isCoresDiferentesEntreVertices())
			novaAvaliacao++;
	}

	avaliacao = novaAvaliacao;
}

int Grafo::getAvaliacao() {
	if(avaliacao == -1)
		calculaAvaliacao();

	return avaliacao;
}

