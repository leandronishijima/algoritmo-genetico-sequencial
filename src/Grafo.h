#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo {

//	Aresta arestas[5566][5566]; // grafo real
	Aresta arestas[5][5]; // grafo testes
	std::map<int, Vertice> vertices;
	int avaliacao;

public:
	Grafo();
	void adicionaVertice(int, int);
	void adicionaAresta(int, int);
	Aresta getAresta(int, int);
	int calculaAvaliacao();
	void randomizaCorVerticeSeguindoHeuristica(int verticeNumero);

private:
	bool existeAdjacenteComCor(Vertice vertice, int cor);
};

#endif
