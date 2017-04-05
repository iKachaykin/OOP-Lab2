#pragma once
#include <iostream>

template<class T>
struct node
{
	T value;
	node *next, *prev;
};

class Container 
{
public:
	virtual const int get_size() = 0;
	virtual const bool is_empty() = 0;
	virtual const std::string to_string() = 0;
};

template<class T>
class PushPopContainer : public Container
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual const T peek() = 0;
};

template<class T>
class Deque : public Container
{
public:
	virtual void push_front(T value) = 0;
	virtual void push_back(T value) = 0;
	virtual T pop_front() = 0;
	virtual T pop_back() = 0;
	virtual const T peek_front() = 0;
	virtual const T peek_back() = 0;
};

template<class T>
class IndexedContainer : public Container
{
public:
	virtual const T get(int index) = 0;
	virtual void set(int index, T value) = 0;
};

template<class T>
class InsertableContainer :	public IndexedContainer<T>
{
public:
	virtual void insert_at(int index, T value) = 0;
	virtual void remove_at(int index) = 0;
};