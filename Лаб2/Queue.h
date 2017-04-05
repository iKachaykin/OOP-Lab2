#pragma once
#include "InterfacesAndNode.h"

template<class T>
class Queue : public PushPopContainer<T>
{
private:
	node<T> *head, *tail;
	int size;
public:
	Queue();
	Queue(T value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	void push(T value);
	T pop();
	const T peek();
	~Queue();
};

template<class T>
Queue<T>::Queue()
{
	head = tail = NULL;
	size = 0;
}

template<class T>
Queue<T>::Queue(T value)
{
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
inline const int Queue<T>::get_size() { return size; }

template<class T>
inline const bool Queue<T>::is_empty() { return !size; }

template<class T>
const std::string Queue<T>::to_string()
{
	std::string res = "[";
	node<T> * tmp = head;
	while (tmp)
	{
		res += std::to_string(tmp->value) + ", ";
		tmp = tmp->next;
	}
	if (!is_empty())
	{
		res.pop_back();
		res.pop_back();
	}
	res += "]";
	return res;
}

template<class T>
void Queue<T>::push(T value)
{
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = tail;
	if (is_empty())
		head = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	size++;
}

template<class T>
T Queue<T>::pop()
{
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = head->next;
	T tmp_value = head->value;
	delete head;
	head = tmp_for_del;
	if (head)
		head->prev = NULL;
	else
		tail = NULL;
	size--;
	return tmp_value;
}

template<class T>
inline const T Queue<T>::peek() { return head->value; }

template<class T>
Queue<T>::~Queue()
{
	node<T> * tmp;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}