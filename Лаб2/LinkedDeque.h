#pragma once
#include "InterfacesAndNode.h"
template<class T>
class LinkedDeque :
	public Deque<T>
{
private:
	node<T> *head, *tail;
	int size;
public:
	LinkedDeque();
	LinkedDeque(T value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	void push_front(T value);
	void push_back(T value);
	T pop_front();
	T pop_back();
	const T peek_front();
	const T peek_back();
	~LinkedDeque();
};

template<class T>
inline LinkedDeque<T>::LinkedDeque()
{
	head = tail = NULL;
	size = 0;
}

template<class T>
inline LinkedDeque<T>::LinkedDeque(T value)
{
	node<T> *tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
inline const int LinkedDeque<T>::get_size() { return size; }

template<class T>
inline const bool LinkedDeque<T>::is_empty() { return !size; }

template<class T>
const std::string LinkedDeque<T>::to_string()
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
void LinkedDeque<T>::push_front(T value)
{
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = head;
	if (is_empty())
		tail = tmp;
	else
		head->prev = tmp;
	head = tmp;
	size++;
}

template<class T>
void LinkedDeque<T>::push_back(T value)
{
	node<T> *tmp = new node<T>;
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
T LinkedDeque<T>::pop_front()
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
T LinkedDeque<T>::pop_back()
{
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = tail->prev;
	T tmp_value = tail->value;
	delete tail;
	tail = tmp_for_del;
	if (tail)
		tail->next = NULL;
	else
		head = NULL;
	size--;
	return tmp_value;
}

template<class T>
inline const T LinkedDeque<T>::peek_front() { return head->value; }

template<class T>
inline const T LinkedDeque<T>::peek_back() { return tail->value; }

template<class T>
LinkedDeque<T>::~LinkedDeque()
{
	node<T> * tmp;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
