#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

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

	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	executaAlgoritmoGenetico(populacao);

	end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

	cout << "Tempo de processamento (Sequencial): " << elapsed_seconds.count() << endl;
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

	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	thread t1(executaAlgoritmoGenetico, populacaoComCorUnica);
	thread t2(executaAlgoritmoGenetico, populacaoComCoresAleatorias);

	t1.join();
	t2.join();
	end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

	cout << "Tempo de processamento (2 threads): " << elapsed_seconds.count() << endl;
}

int main() {
	executaAlgoritmoSequencial();
	return 0;
}
