#include <iostream>
using namespace std;

class Celula {
public:
	int elemento;
	Celula* prox;
	Celula* ant;

	Celula() {
		Celula(0);
	}

	Celula(int elemento) {
		this->elemento = elemento;
		this->prox = NULL;
		this->ant = NULL;
	}
};

class Lista {
	Celula* primeiro;
	Celula* ultimo;

public:
	int tamanho;

	Lista() {
		primeiro = new Celula();
		ultimo = primeiro;
		tamanho = 0;
	}

	void inserirInicio(int x) {

		if (tamanho == 0) {
			primeiro->elemento = x;
		} else {
			Celula* novo = new Celula(x);
			novo->prox = primeiro;
			primeiro->ant = novo;
			primeiro = novo;
		}

		tamanho++;
	}

	void inserirFim(int x) {
		if (tamanho == 0) {
			inserirInicio(x);
		} else {
			Celula* novo = new Celula(x);
			novo->ant = ultimo;
			ultimo->prox = novo;
			ultimo = novo;
			tamanho++;
		}
	}

	void mostrar() {
		Celula* aux = primeiro;
		while (aux != NULL) {
			cout << aux->elemento << " ";
			aux = aux->prox;
		}
	}

	int mostrar(int n) {
		if (n > tamanho) {
			cout << "Indice maior que o tamanho" << endl;
			exit(0);
		}

		Celula* aux = primeiro;
		for (int i = 0; i < n; i++) {
			aux = aux->prox;
		}
		return aux->elemento;
	}

	Celula* getCelula(int indice) {
		if (indice > tamanho) {
			cout << "Indice maior que o tamanho" << endl;
			exit(0);
		}

		Celula* aux = primeiro;
		for (int i = 0; i < indice; i++) {
			aux = aux->prox;
		}
		return aux;
	}
};

int main() {

	Lista lista;

	for (int i = 1; i <= 5; i++) {
		lista.inserirInicio(i);
	}

	for (int i = 1; i <= 5; i++) {
		lista.inserirFim(i);
	}

	lista.mostrar();

	cout << endl;
	cout << "Tamanho: " << lista.tamanho << endl;

	cout << endl;
	cout << lista.mostrar(3) << endl;

	// Celula* temp = lista.getCelula(3);

	cout << lista.getCelula(3)->ant->elemento << endl;
	cout << lista.getCelula(3)->prox->elemento << endl;

	cout << "\nFIM DO PROGRAMA\n";
	return 0;
}