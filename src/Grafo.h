#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo {

	Aresta arestas[100][100];
	std::map<int, Vertice> vertices;
	int avaliacao;

public:
	Grafo();
	void adicionaVertice(int, int);
	void adicionaAresta(int, int);
	Aresta getAresta(int, int);
	int calculaAvaliacao();
};

#endif
