#include "Cromossomo.h"
#include "Vertice.h"
#include "Grafo.h"


Cromossomo::Cromossomo() {
}

Cromossomo::Cromossomo(Grafo grafo) {
	this->grafo = grafo;
}

Cromossomo::Cromossomo(Grafo grafo, int index) {
	Grafo novo = Grafo();

	for (int i = 0; i < index; ++i) {
		
	}
}

int Cromossomo::getQuantidadeDeVertices() {
	return grafo.getQuantidadeVertices();
}

Grafo Cromossomo::getGrafo() {
	return grafo;
}
