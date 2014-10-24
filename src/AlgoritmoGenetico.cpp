#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AlgoritmoGenetico.h"
#include "Cromossomo.h"
#include "Grafo.h"

AlgoritmoGenetico::AlgoritmoGenetico() {
	srand(time(NULL));
}

void AlgoritmoGenetico::adicionaGrafoAPopulacao(int index, Grafo grafo) {
	populacao[index] = Cromossomo(grafo);
}

AlgoritmoGenetico::AlgoritmoGenetico(Grafo populacaoInicial[]) {
	for (unsigned int i = 0; i < sizeof(populacaoInicial); ++i)
		adicionaGrafoAPopulacao(i, populacaoInicial[i]);
}

bool criterioDeParada() {
	return true; // TODO criar outro criterio de parada!
}

Cromossomo AlgoritmoGenetico::cruza(int indexReferencia) {
	Cromossomo cromossomoPai = populacao[0];
	Cromossomo cromossomoMae = populacao[1];

	Cromossomo(cromossomoPai.getGrafo(), indexReferencia);

	return NULL;
}

Cromossomo AlgoritmoGenetico::cruzaIndividuos() {
	int qtdVertices = populacao[0].getQuantidadeDeVertices() + 1;
	int index = rand() % qtdVertices;

	return cruza(index);
}

void AlgoritmoGenetico::executaAlgoritmo() {
	while(criterioDeParada()) {
		Cromossomo filho = cruzaIndividuos();
	}
}
