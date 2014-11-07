#include "Aresta.h"
#include "Vertice.h"

Aresta::Aresta() {
	arestaReal = false;
}

Aresta::Aresta(Vertice v1, Vertice v2) {
	setVertice1(v1);
	setVertice2(v2);
	marcaArestaReal();
}

void Aresta::setVertice1(Vertice v1) {
	this->v1 = v1;
}

void Aresta::setVertice2(Vertice v2) {
	this->v2 = v2;
}

bool Aresta::isCoresDiferentesEntreVertices() {
	return v1.getCor() != v2.getCor();
}

int Aresta::getCorOutroVertice(Vertice vertice) {
	return vertice.equals(v1) ? v2.getCor() : v1.getCor();
}

void Aresta::marcaArestaReal() {
	arestaReal = true;
}

bool Aresta::isArestaReal() {
	return arestaReal;
}
