#pragma once
#include "InterfacesAndNode.h"
template<class T>
class StaticArray :
	public IndexedContainer<T>
{
private:
	T *arr;
	int size;
public:
	StaticArray(int size, T default_value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	const T get(int index);
	void set(int index, T value);
	~StaticArray();
};

template<class T>
StaticArray<T>::StaticArray(int size, T default_value)
{
	if (size <= 0)
		throw 4;
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
inline const int StaticArray<T>::get_size() { return size; }

template<class T>
inline const bool StaticArray<T>::is_empty() { return !size; }

template<class T>
const std::string StaticArray<T>::to_string()
{
	std::string res = "[";
	for (int i = 0; i < size; i++)
		res += std::to_string(arr[i]) + ", ";
	if (!is_empty())
	{
		res.pop_back();
		res.pop_back();
	}
	res += "]";
	return res;
}

template<class T>
inline const T StaticArray<T>::get(int index)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	return arr[index];
}

template<class T>
inline void StaticArray<T>::set(int index, T value)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	arr[index] = value;
}

template<class T>
inline StaticArray<T>::~StaticArray() { delete[] arr; }