#include <iostream>

struct lista {
	int num;
	lista* prox;
};

lista* criarL(int num) {
	lista *novo = new lista;
	novo->num = num;
	novo->prox = NULL;
	return novo;

}

void inserir_fim(lista*&list, int num) {
	lista *novo = criarL(num);
	if (list == NULL)
		list = novo;
	else {
		lista* aux = list;
		while (aux->prox != NULL) {
			aux = aux -> prox;
		}
		aux->prox = novo;
	}

}

void value(lista*&list) {
	int num = -1;
	while (num != 0) {
		std::cin >> num;
		if(num != 0)
			inserir_fim(list, num);
		
	}

}

void printar(lista* list) {
	
	if (list == NULL) {
		std::cout << "A lista esta vazia!!";
	}
	else {
		lista* aux = list;
		while (aux != NULL) {
			std::cout << list->num << " ";
			list = list->prox;
		}
	}
}

void concatenar(lista*& list1, lista*& list2) {
	lista* aux;
	if (list1 == NULL && list2 != NULL) {
		list1 = list2;
	}
	else{
		aux = list1;
		while (aux->prox != NULL)
			aux = aux->prox;
		aux->prox = list2;
	}


}


int main() {

	lista* list1 = NULL;
	lista* list2 = NULL;

	std::cout << "Digite os valores da lista 1:\n";
	value(list1);

	std::cout << "Digite os valores da lista 2:\n";
	value(list2);

	concatenar(list1, list2);

	printar(list1);
	




}