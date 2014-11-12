#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "Grafo.h"
#include "Cromossomo.h"
#include "AlgoritmoGenetico.h"
#include "Vertice.h"
#include "GeradorDeGrafo.h"

using namespace std;

void executaAlgoritmoGenetico(vector<Grafo> populacao) {
	AlgoritmoGenetico algoritmo = AlgoritmoGenetico(populacao);
	algoritmo.executaAlgoritmo();
}

void executaAlgoritmoSequencial() {
	GeradorDeGrafo gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCorUnica();
	Grafo grafoComCorUnica = gerador.getGrafo();

	gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCoresRandom();
	Grafo grafoComCoresAleatorias = gerador.getGrafo();

	vector<Grafo> populacao;
	populacao.push_back(grafoComCorUnica);
	populacao.push_back(grafoComCoresAleatorias);

	executaAlgoritmoGenetico(populacao);
}

void executaAlgoritmoComThreads() {
	GeradorDeGrafo gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCorUnica();
	Grafo grafoComCorUnica = gerador.getGrafo();

	gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCoresRandom();
	Grafo grafoComCoresAleatorias = gerador.getGrafo();

	vector<Grafo> populacaoComCorUnica;
	populacaoComCorUnica.push_back(grafoComCorUnica);

	vector<Grafo> populacaoComCoresAleatorias;
	populacaoComCoresAleatorias.push_back(grafoComCoresAleatorias);

	thread t1(executaAlgoritmoGenetico, populacaoComCorUnica);
	thread t2(executaAlgoritmoGenetico, populacaoComCoresAleatorias);

	t1.join();
	t2.join();
}

int main() {
	executaAlgoritmoComThreads();
	return 0;
}
