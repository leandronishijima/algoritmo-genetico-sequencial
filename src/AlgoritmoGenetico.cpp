#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "AlgoritmoGenetico.h"
#include "Cromossomo.h"
#include "Grafo.h"

AlgoritmoGenetico::AlgoritmoGenetico() {
}

void AlgoritmoGenetico::adicionaGrafoAPopulacao(Grafo grafo) {
	populacao.push_back(Cromossomo(grafo));
}

AlgoritmoGenetico::AlgoritmoGenetico(vector<Grafo> populacaoInicial) {
	for(vector<Grafo>::iterator it = populacaoInicial.begin() ; it != populacaoInicial.end(); ++it) {
		Grafo grafo = *it;
		adicionaGrafoAPopulacao(grafo);
	}

	cromossomoMaisAdaptado = populacao.front();
}

bool AlgoritmoGenetico::criterioDeParada() {
	return cromossomoMaisAdaptado.getAvaliacao() != 0; // TODO || tempoExcedido()
}

void AlgoritmoGenetico::validaNovoCromossomoMaisAdaptado() {
	for(vector<Cromossomo>::iterator it = populacao.begin() ; it != populacao.end(); ++it) {
		Cromossomo cromossomo = *it;

		if (cromossomo.getAvaliacao() > cromossomoMaisAdaptado.getAvaliacao())
			cromossomoMaisAdaptado = cromossomo;
	}
}

void AlgoritmoGenetico::executaAlgoritmo() {
	while(criterioDeParada()) {
		// cruzamento de cromossomos!

		for(vector<Cromossomo>::iterator it = populacao.begin() ; it != populacao.end(); ++it) {
			Cromossomo cromossomo = *it;
			cromossomo.randomizaCorVertice();
		}

		validaNovoCromossomoMaisAdaptado();
	}

	printf("Cromossomo mais adaptado: %d", cromossomoMaisAdaptado.getAvaliacao());
}
