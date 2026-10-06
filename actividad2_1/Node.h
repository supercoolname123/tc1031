#pragma once
template <class T>
class Node
{

public:
	Node(T data);
	Node(T data, node<T>* next);
	T getData();
	Node<T>* getNext();
	void setData(T data);
	void setNext(node<T>* next);
private:
	T data;
	Node<T>* next;
};

