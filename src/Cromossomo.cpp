#include "Cromossomo.h"
#include "Vertice.h"
#include "Aresta.h"


Cromossomo::Cromossomo() {
	avaliacao = 0l;
}

Cromossomo::Cromossomo(Grafo grafo) {
	this->grafo = grafo;
	avaliacao = 0l;
}

