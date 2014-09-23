#ifndef CROMOSSOMO_H_
#define CROMOSSOMO_H_

#include "Vertice.h"
#include "Aresta.h"
#include <map>
#include <vector>

using namespace std;

class Cromossomo {

	std::vector<std::vector<Aresta> > grafoMatriz;
	std::map<int, Vertice> vertices;
	long avaliacao;

public:
	Cromossomo();
	void adicionaNovoVertice(int vertice, int corDoVertice);
	void adicionaNovaAresta(int verticeA, int verticeB);
	Aresta getAresta(int verticeA, int verticeB);
};

#endif
