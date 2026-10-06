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

	void deleteAtStart() {
		node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}

	node<T>* walkToIndexOrLast(int index) {
		validateIndexIsNotNegative(index);

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
		bool whitinSize = index >= 0 && index < size;
		if (!whitinSize) {
			throw "(FLinked): Indice Invalido. i no esta dentro de la lista.";
		}
	}

	void validateListIsNotEmpty() {
		if (isEmpty()) {
			throw "(FLinked): Lista vacia.";
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
		validateListIsNotEmpty();
		validateIndexIsWhitinSize(index);

		node<T>* temp = walkToIndexOrLast(index);
		temp->data = data;
	}

	T read(int index)
	{
		validateListIsNotEmpty();
		validateIndexIsWhitinSize(index);

		node<T>* temp = walkToIndexOrLast(index);
		return temp->data;
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
		validateListIsNotEmpty();
		validateIndexIsWhitinSize(index);
		
		if (index == 0) {
			deleteAtStart();
			return;
		}

		node<T>* prev = walkToIndexOrLast(index - 1);
		node<T>* curr = prev->next;
		node<T>* next = curr->next;
		
		prev->next = next;
		delete curr;
		size--;
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



