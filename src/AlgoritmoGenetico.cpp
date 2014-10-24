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

	cromossomoMaisAdaptado = populacao[0];
}

bool AlgoritmoGenetico::criterioDeParada() {
	return !cromossomoMaisAdaptado.getGrafo().calculaAvaliacao() == 0; // TODO && tempoExcedido()
}

void AlgoritmoGenetico::executaAlgoritmo() {
	while(criterioDeParada()) {

	}
}
