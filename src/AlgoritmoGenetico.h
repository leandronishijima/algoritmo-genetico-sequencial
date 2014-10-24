#ifndef ALGORITMOGENETICO_H_
#define ALGORITMOGENETICO_H_

#include "Grafo.h"
#include "Cromossomo.h"

class AlgoritmoGenetico {

	Cromossomo populacao[2];

public:
	AlgoritmoGenetico();
	AlgoritmoGenetico(Grafo populacaoInicial[]);
	void executaAlgoritmo();

private:
	void adicionaGrafoAPopulacao(int index, Grafo grafo);
	Cromossomo cruzaIndividuos();
	Cromossomo cruza(int indexReferencia);

};

#endif
