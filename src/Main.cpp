#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"
#include "Cromossomo.h"
#include "AlgoritmoGenetico.h"
#include "Vertice.h"
#include "GeradorDeGrafo.h"

using namespace std;

Grafo populacaoInicial[2];
vector<int> numeroVertices;

int arraySize() {
	return numeroVertices.size();
}

void adicionaVerticesComMesmaCor(Grafo grafo, int corDosVertices) {
	for (int i=0; i < arraySize(); ++i)
		grafo.adicionaVertice(numeroVertices[i], corDosVertices);
}

void adicionaVerticesComCoresRandomicas(Grafo grafo) {
	for (int i=0; i < arraySize(); ++i)
		grafo.adicionaVertice(numeroVertices[i], rand() % 4);
}

void adicionaArestasTeste(Grafo grafo) {
	grafo.adicionaArestaComCor1(0, 1);
	grafo.adicionaArestaComCor1(0, 2);
	grafo.adicionaArestaComCor1(0, 3);
	grafo.adicionaArestaComCor1(1, 0);
	grafo.adicionaArestaComCor1(1, 2);
	grafo.adicionaArestaComCor1(1, 4);
	grafo.adicionaArestaComCor1(2, 0);
	grafo.adicionaArestaComCor1(2, 1);
	grafo.adicionaArestaComCor1(2, 5);
	grafo.adicionaArestaComCor1(3, 0);
	grafo.adicionaArestaComCor1(3, 5);
	grafo.adicionaArestaComCor1(4, 1);
	grafo.adicionaArestaComCor1(4, 5);
	grafo.adicionaArestaComCor1(5, 3);
	grafo.adicionaArestaComCor1(5, 4);
	grafo.adicionaArestaComCor1(5, 2);
}

Grafo geraPrimeiroGrafoTeste() {
	Grafo grafo = Grafo();
	adicionaArestasTeste(grafo);
	return grafo;
}

Grafo geraSegundoGrafoTeste() {
	Grafo grafo = Grafo();
	adicionaVerticesComCoresRandomicas(grafo);
	adicionaArestasTeste(grafo);
	return grafo;
}

void criaPopulacaoInicial() {
	populacaoInicial[0] = geraPrimeiroGrafoTeste();
	populacaoInicial[1] = geraSegundoGrafoTeste();
}

void testeSemArquivo() {
	numeroVertices.push_back(0);
	numeroVertices.push_back(1);
	numeroVertices.push_back(2);
	numeroVertices.push_back(3);
	numeroVertices.push_back(4);
	numeroVertices.push_back(5);
	criaPopulacaoInicial();
	AlgoritmoGenetico algoritmo = AlgoritmoGenetico(populacaoInicial);
	algoritmo.executaAlgoritmo();
}

void testeComArquivo() {
	GeradorDeGrafo gerador = GeradorDeGrafo("grafo5.txt");
	Grafo grafo = gerador.getGrafo();
}

int main() {
//	testeSemArquivo();
	testeComArquivo();
	return 0;
}
