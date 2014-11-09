#ifndef ARESTA_H_
#define ARESTA_H_

#include "Vertice.h"

class Aresta {

	int v1;
	int v2;
	bool arestaReal;

public:
	Aresta();
	Aresta(int vertice1, int vertice2);
	int getOutroVertice(int vertice);
	void marcaArestaReal();
	bool isArestaReal();
	int getIndiceVertice1();
	int getIndiceVertice2();

private:
	void setIndiceVertice1(int);
	void setIndiceVertice2(int);
};

#endif
