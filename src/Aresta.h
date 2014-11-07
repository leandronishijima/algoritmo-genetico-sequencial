#ifndef ARESTA_H_
#define ARESTA_H_

#include "Vertice.h"

class Aresta {

	Vertice v1;
	Vertice v2;
	bool arestaReal;

public:
	Aresta();
	Aresta(Vertice, Vertice);
	bool isCoresDiferentesEntreVertices();
	int getCorOutroVertice(Vertice vertice);
	void marcaArestaReal();
	bool isArestaReal();

private:
	void setVertice1(Vertice);
	void setVertice2(Vertice);

};

#endif
