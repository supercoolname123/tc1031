#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;

	node(T _data) {
		data = _data;
		next = NULL;
	}
};

template<class T>
class FLinked
{
private:
	bool isEmpty() { return first == NULL; }
	int size;

	void createAtStart(T data) {
		node<T>* temp = new node<T>(data);
		temp->next = first;
		first = temp;
		size++;
	}

	node<T>* walkToIndexOrLast(int index) {
		int i = 0;
		node<T>* temp = first;
		while (temp->next != NULL && i < index) {
			i++;
			temp = temp->next;
		}
		return temp;
	}

	void validateIndexIsNotNegative(int index) {
		if (index < 0) {
			throw "(FLinked): Indice Invalido. i es negativo.";
		}
	}

	void validateIndexIsWhitinSize(int index) {
		if (index >= 0 || index < size) {
			throw "(FLinked): Indice Invalido. i no esta dentro de la lista.";
		}
	}
	
public:
	node<T>* first;
	FLinked<T>() {
		first = NULL;
		size = 0;
	}

	void update(int index, T data)
	{
		node<T>* temp = first;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		temp->data = data;
	}

	T read(int index)
	{
		if (index < 0) { //indice fuera de rango
			throw ("Indice debe ser >= 0");
		}
		else if (index == 0) {
			if (first == NULL) { //checa si existe la lista
				throw ("La lista no existe");
			}
			return this->first->data;
		}

		node<T>* curr = first;
		for (int i = 0; i < index; i++) {
			curr = curr->next;

			if (curr == NULL) {
				throw ("Indice fuera de rango, intente un indice mas pequeño");
			}
		}
		return curr->data;

	}

	void create(int index, T data)
	{
		validateIndexIsNotNegative(index);

		if (isEmpty() || index == 0) {
			createAtStart(data);
			return;
		}

		node<T>* prev = walkToIndexOrLast(index - 1);
		node<T>* next = prev->next;

		node<T>* temp = new node<T>(data);
		prev->next = temp;
		temp->next = next;
		size++;
	}

	T operator[](int index)
	{
		return read(index);
	}

	void del(int index) {
		node<T>* curr = first;

		if (curr == NULL) {
			cout << "Lista vacia" << endl;
			return;
		}

		if (index == 0) {
			node<T>* temp = first;
			first = first->next;
			delete temp;
			return;
		}

		node<T>* nx = curr->next;
		int i = 1;

		if (nx == NULL) {
			delete curr;
			first = NULL;
			return;
		}

		while (nx->next != NULL && i < index) {
			curr = nx;
			nx = nx->next;
			i++;
		}
		curr->next = nx->next;
		delete nx;
		return;
	}

	void printList() {
		node<T>* curr = first;

		std::cout << "n: " << size << "\t";
		while (curr != NULL) {
			std::cout << curr->data << " -> ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}
};



