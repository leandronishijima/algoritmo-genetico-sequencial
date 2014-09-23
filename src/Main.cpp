#include <iostream>
#include "Cromossomo.h"

using namespace std;

int main() {

	Cromossomo cromossomo = Cromossomo();
	cromossomo.adicionaNovoVertice(1, 1);
	cromossomo.adicionaNovoVertice(2, 1);

	cromossomo.adicionaNovaAresta(1, 2);
	Aresta i = cromossomo.getAresta(1, 2);
	return 0;
}

