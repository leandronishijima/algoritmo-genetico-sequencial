#include "GeradorDeGrafo.h"

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void GeradorDeGrafo::iteraArquivoGerandoGrafoComCorUnica() {
	int numeroVertice1 = 0;
	int numeroVertice2 = 0;

	while(feof(arquivo)) {
		fscanf(arquivo, "%d %d", numeroVertice1, numeroVertice2);
		grafo.adicionaArestaComCor1(numeroVertice1, numeroVertice2);
	}

	fclose(arquivo);
}

GeradorDeGrafo::GeradorDeGrafo(const char* nomeDoArquivo) {
	arquivo = fopen(nomeDoArquivo, "r");
}

Grafo GeradorDeGrafo::getGrafo() {
	return grafo;
}

