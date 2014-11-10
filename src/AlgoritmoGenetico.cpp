#include <iostream>
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

bool AlgoritmoGenetico::verificaAvaliacaoMaxima() {
	int avaliacao = cromossomoMaisAdaptado.getAvaliacao();
	int quantidadeDeArestas = cromossomoMaisAdaptado.getQuantidadeDeArestas();
	bool predicado = avaliacao < quantidadeDeArestas;
	return predicado;
}

bool AlgoritmoGenetico::criterioDeParada() {
	return verificaAvaliacaoMaxima(); // TODO || tempoExcedido()
}

void AlgoritmoGenetico::validaNovoCromossomoMaisAdaptado() {
	for(vector<Cromossomo>::iterator it = populacao.begin() ; it != populacao.end(); ++it) {
		Cromossomo cromossomo = *it;

		int avaliacaoCromossomo = cromossomo.getAvaliacao();
		int avaliacaoCromossomoMaisAdaptado = cromossomoMaisAdaptado.getAvaliacao();

		if (avaliacaoCromossomo > avaliacaoCromossomoMaisAdaptado)
			cromossomoMaisAdaptado = cromossomo;
	}
}

void AlgoritmoGenetico::executaAlgoritmo() {
	while(criterioDeParada()) {
		// cruzamento de cromossomos!

		for(vector<Cromossomo>::iterator it = populacao.begin() ; it != populacao.end(); ++it) {
			Cromossomo cromossomo = *it;
			cromossomo.randomizaCorVertice();

			vector<Cromossomo>::iterator it2 = populacao.erase(it);
			populacao.insert(it2, cromossomo);
		}

		validaNovoCromossomoMaisAdaptado();
	}

	cout << "Avaliação do cromossomo mais adaptado: " << cromossomoMaisAdaptado.getAvaliacao() << endl;
}
