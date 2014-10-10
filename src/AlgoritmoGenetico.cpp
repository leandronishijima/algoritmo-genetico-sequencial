#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico() {
}

void AlgoritmoGenetico::adicionaGrafoAPopulacao(int index, Grafo grafo) {
	populacao[index] = Cromossomo(grafo);
}

AlgoritmoGenetico::AlgoritmoGenetico(Grafo populacaoInicial[]) {
	for (int i = 0; i < sizeof(populacaoInicial); ++i)
		adicionaGrafoAPopulacao(i, populacaoInicial[i]);
}

bool criterioDeParada() {
	return true; // TODO criar outro criterio de parada!
}

void AlgoritmoGenetico::executaAlgoritmo() {
	while(criterioDeParada()) {

	}
}
