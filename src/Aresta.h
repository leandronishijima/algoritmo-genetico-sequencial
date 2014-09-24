#ifndef ARESTA_H_
#define ARESTA_H_

#include "Vertice.h"

class Aresta {

	Vertice v1;
	Vertice v2;

public:
	Aresta();
	Aresta(Vertice, Vertice);
	bool validaCorDiferenteVertices(void);

private:
	void setVertice1(Vertice);
	void setVertice2(Vertice);

};

#endif
