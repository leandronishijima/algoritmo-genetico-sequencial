#ifndef VERTICE_H_
#define VERTICE_H_

class Vertice {

	int valor;
	int cor;

public:
	Vertice();
	void setValor(int);
	void setCor(int);
	int getCor(void);
	int getValor(void);
	bool equals(Vertice other);
};

#endif
