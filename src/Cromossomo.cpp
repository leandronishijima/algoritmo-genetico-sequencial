#include "Cromossomo.h"
#include "Vertice.h"
#include "Grafo.h"


Cromossomo::Cromossomo() {
}

Cromossomo::Cromossomo(Grafo grafo) {
	this->grafo = grafo;
}

int Cromossomo::getQuantidadeDeVertices() {
	return grafo.getQuantidadeVertices();
}

Grafo Cromossomo::getGrafo() {
	return grafo;
}
