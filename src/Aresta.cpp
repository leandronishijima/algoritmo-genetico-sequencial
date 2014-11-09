#include "Aresta.h"
#include "Vertice.h"

Aresta::Aresta() {
	arestaReal = false;
	v1 = 0;
	v2 = 0;
}

Aresta::Aresta(int v1, int v2) {
	setIndiceVertice1(v1);
	setIndiceVertice2(v2);
	marcaArestaReal();
}

void Aresta::setIndiceVertice1(int v1) {
	this->v1 = v1;
}

void Aresta::setIndiceVertice2(int v2) {
	this->v2 = v2;
}

int Aresta::getOutroVertice(int verticeNumero) {
	return verticeNumero == v1 ? v2 : v1;
}

void Aresta::marcaArestaReal() {
	arestaReal = true;
}

bool Aresta::isArestaReal() {
	return arestaReal;
}

int Aresta::getIndiceVertice1() {
	return v1;
}

int Aresta::getIndiceVertice2() {
	return v2;
}
