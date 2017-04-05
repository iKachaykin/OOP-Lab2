#pragma once
#include "InterfacesAndNode.h"
#include <string>

template<class T>
class Stack : public PushPopContainer<T>
{
private:
	node<T> *head;
	int size;
public:
	Stack();
	Stack(T value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	void push(T value);
	T pop();
	const T peek();
	~Stack();
};

template<class T>
Stack<T>::Stack()
{
	head = NULL;
	size = 0;
}

template<class T>
Stack<T>::Stack(T value)
{
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tmp;
	size = 1;
}

template<class T>
inline const bool Stack<T>::is_empty() { return !size; }

template<class T>
inline const int Stack<T>::get_size() { return size; }

template<class T>
const std::string Stack<T>::to_string()
{
	std::string res = "[";
	node<T> * tmp = head;
	while (tmp)
	{
		res += std::to_string(tmp->value) + ", ";
		tmp = tmp->next;
	}
	res.pop_back();
	res.pop_back();
	res += "]";
	return res;
}

template<class T>
void Stack<T>::push(T value)
{
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = head;
	if (!is_empty())
		head->prev = tmp;
	head = tmp;
	size++;
}

template<class T>
T Stack<T>::pop()
{
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = head->next;
	T tmp_value = head->value;
	delete head;
	head = tmp_for_del;
	if (head)
		head->prev = NULL;
	size--;
	return tmp_value;
}

template<class T>
inline const T Stack<T>::peek() { return head->value; }

template<class T>
Stack<T>::~Stack()
{
	node<T> * tmp;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}