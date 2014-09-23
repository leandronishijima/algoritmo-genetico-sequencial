#include "Cromossomo.h"
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

Cromossomo::Cromossomo() {
	avaliacao = 0l;
}

void Cromossomo::adicionaNovoVertice(int vertice, int corDoVertice) {
	Vertice novo = Vertice();
	novo.setValor(vertice);
	novo.setCor(corDoVertice);

	vertices[vertice] = novo;
}

void Cromossomo::adicionaNovaAresta(int verticeA, int verticeB) {
	Vertice vertice1 = vertices[verticeA];
	Vertice vertice2 = vertices[verticeB];

	Aresta aresta = Aresta();
	aresta.setVertice1(vertice1);
	aresta.setVertice2(vertice2);

	grafoMatriz[vertice1.getValor()][vertice2.getValor()] = aresta;
}

Aresta Cromossomo::getAresta(int vertice1, int vertice2) {
	return grafoMatriz[vertice1][vertice2];
}
