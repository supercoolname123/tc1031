#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};


template<class T>
class FLinked
{
public:
	node<T>* first;
	FLinked<T>() {
		first = NULL;
	}

	void update(int pos, T data)
	{
		node<T>* temp = first;
		for (int i = 0; i < pos; i++)
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

	void create(T data, int pos)
	{
		node<T>* newNode = new node<T>;
		newNode->data = data;
		newNode->next = NULL;

		if (first == NULL) {
			first = newNode;
			return;
		}
		else if (pos == 0) {
			newNode->next = first;
			first = newNode;
			return;
		}

		node<T>* prev = first;
		node<T>* curr = first->next;

		int i = 1;
		while (curr != NULL && i < pos) {
			i++;
			prev = curr;
			curr = curr->next;
		}

		prev->next = newNode;
		newNode->next = curr;
	}

	T operator[](int index)
	{
		return read(index);
	}

	void del(int pos) {
		node<T>* curr = first;

		if (curr == NULL) {
			cout << "Lista vacia" << endl;
			return;
		}

		if (pos == 0) {
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

		while (nx->next != NULL && i < pos) {
			curr = nx;
			nx = nx->next;
			i++;
		}
		curr->next = nx->next;
		delete nx;
		return;
	}
};



