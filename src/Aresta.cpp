/*
 * Aresta.cpp
 *
 *  Created on: 22/09/2014
 *      Author: Leandro
 */

#include "Aresta.h"

void Aresta::setVertice1(Vertice v1) {
	this->v1 = v1;
}

void Aresta::setVertice2(Vertice v2) {
	this->v2 = v2;
}

bool Aresta::validaCorDiferenteVertices() {
	return v1.getCor() != v2.getCor();
}

