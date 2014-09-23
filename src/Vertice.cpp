#include "Vertice.h"

Vertice::Vertice() {
	valor = 0l;
	cor = 0;
}

void Vertice::setValor(int valor) {
	this->valor = valor;
}

void Vertice::setCor(int cor) {
	this->cor = cor;
}

int Vertice::getValor() {
	return valor;
}

int Vertice::getCor() {
	return cor;
}
