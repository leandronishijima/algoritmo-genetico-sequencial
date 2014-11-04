#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo {

//	Aresta arestas[5566][5566]; // grafo real
	Aresta arestas[6][6]; // grafo testes
	map<int, Vertice> vertices;
	int avaliacao;

public:
	Grafo();
	Vertice adicionaVertice(int numeroVertice, int corVertice);
	void adicionaArestaComCor1(int verticeValor1, int verticeValor2);
	void adicionaArestaComCorAleatoria(int verticeValor1, int verticeValor2);
	void calculaAvaliacao();
	int getAvaliacao();
	void randomizaCorVerticeSeguindoHeuristica(int verticeNumero, int cor);
	int getQuantidadeVertices();

private:
	bool existeAdjacenteComCor(Vertice vertice, int cor);
	Vertice buscaOuAdicionaVerticeComCor1(int valorVertice);
	Vertice buscaOuAdicionaVerticeComCorRandom(int valorVertice);
};

#endif
