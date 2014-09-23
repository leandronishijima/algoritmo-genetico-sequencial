#ifndef ARESTA_H_
#define ARESTA_H_

#include "Vertice.h"

class Aresta {

	Vertice v1;
	Vertice v2;

public:
	void setVertice1(Vertice);
	void setVertice2(Vertice);
	bool validaCorDiferenteVertices(void);
};

#endif
