#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"
#include "Cromossomo.h"
#include "AlgoritmoGenetico.h"
#include "Vertice.h"
#include "GeradorDeGrafo.h"

using namespace std;

void testeComArquivo() {
	GeradorDeGrafo gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCorUnica();
	Grafo grafoComCorUnica = gerador.getGrafo();

	gerador = GeradorDeGrafo("grafo6.txt");
	gerador.iteraArquivoGerandoGrafoComCoresRandom();
	Grafo grafoComCoresAleatorias = gerador.getGrafo();

	vector<Grafo> populacao;
	populacao.push_back(grafoComCorUnica);
	populacao.push_back(grafoComCoresAleatorias);

	AlgoritmoGenetico algoritmo = AlgoritmoGenetico(populacao);
	algoritmo.executaAlgoritmo();
}

int main() {
	testeComArquivo();
	return 0;
}
