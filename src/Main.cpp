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
	GeradorDeGrafo gerador = GeradorDeGrafo("grafo5.txt");
	gerador.iteraArquivoGerandoGrafoComCorUnica();
	Grafo grafo = gerador.getGrafo();
}

int main() {
//	testeComArquivo();
	return 0;
}
