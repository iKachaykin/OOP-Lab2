#pragma once
#include "InterfacesAndNode.h"

template<class T>
class LinkedList :
	public PushPopContainer<T>, InsertableContainer<T>
{
private:
	node<T> *head, *tail;
	int size;
public:
	LinkedList();
	LinkedList(T value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	void push(T value);
	T pop();
	const T peek();
	const T get(int index);
	void set(int index, T value);
	void insert_at(int index, T value);
	void remove_at(int index);
	~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList()
{
	head = tail = NULL;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(T value)
{
	node<T> *tmp = new node<T>;
	tmp->value = value;
	tmp->prev = tmp->next = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
inline const int LinkedList<T>::get_size() { return size; }

template<class T>
inline const bool LinkedList<T>::is_empty() { return !size; }

template<class T>
const std::string LinkedList<T>::to_string()
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
void LinkedList<T>::push(T value)
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
T LinkedList<T>::pop()
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
inline const T LinkedList<T>::peek() { return tail->value; }

template<class T>
const T LinkedList<T>::get(int index)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	node<T> *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	return tmp->value;
}

template<class T>
void LinkedList<T>::set(int index, T value)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	node<T> *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	tmp->value = value;
}

template<class T>
void LinkedList<T>::insert_at(int index, T value)
{
	if (index > size || index < 0 || is_empty() && index)
		throw 2;
	T tmp_value;
	node<T> *tmp_node = new node<T>;
	tmp_node->value = value;
	tmp_node->next = head;
	tmp_node->prev = NULL;
	if (is_empty())
		tail = tmp_node;
	else
		head->prev = tmp_node;
	head = tmp_node;
	size++;
	for (int i = 0; i < index; i++)
	{
		tmp_value = get(i);
		set(i, get(i + 1));
		set(i + 1, tmp_value);
	}
}

template<class T>
void LinkedList<T>::remove_at(int index)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	T tmp_head_val = head->value, tmp_val;
	node<T> *tmp_node = head->next;
	delete head;
	head = tmp_node;
	if (head)
		head->prev = NULL;
	else
		tail = NULL;
	size--;
	for (int i = index - 1; i > 0; i--)
		set(i, get(i - 1));
	if(index)
		set(0, tmp_head_val);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	node<T> *tmp;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
