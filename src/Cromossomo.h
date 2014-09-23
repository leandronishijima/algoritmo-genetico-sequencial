#ifndef CROMOSSOMO_H_
#define CROMOSSOMO_H_

#include "Vertice.h"
#include "Aresta.h"
#include <map>

using namespace std;

class Cromossomo {

	map<Vertice, map<Vertice, Aresta> > grafoMatriz;
	long avaliacao;

public:
	Cromossomo();
	void adicionaNovoVertice(int vertice, int corDoVertice);
};

#endif
