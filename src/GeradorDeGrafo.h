#ifndef GERADORDEGRAFO_H_
#define GERADORDEGRAFO_H_

#include <fstream>
#include <iostream>

#include "Grafo.h"

class GeradorDeGrafo {

	Grafo grafo;
	FILE *arquivo;

public:
	GeradorDeGrafo(const char* nomeDoArquivo);
	Grafo getGrafo();
	void iteraArquivoGerandoGrafoComCorUnica();
	void iteraArquivoGerandoGrafoComCoresRandom();
};

#endif
