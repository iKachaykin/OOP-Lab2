#pragma once
#include "InterfacesAndNode.h"
template<class T>
class ArrayList :
	public PushPopContainer<T>, public InsertableContainer<T>
{
private:
	const int DEFAULT_ARRAY_SIZE = 10;
	int size;
	T *arr;
public:
	ArrayList();	
	ArrayList(T default_value);
	ArrayList(int array_size, T default_value);
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
	~ArrayList();
};

template<class T>
ArrayList<T>::ArrayList()
{
	size = DEFAULT_ARRAY_SIZE;
	arr = new T[size];
}

template<class T>
ArrayList<T>::ArrayList(T default_value)
{
	size = DEFAULT_ARRAY_SIZE;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
ArrayList<T>::ArrayList(int array_size, T default_value)
{
	if (size <= 0)
		throw 4;
	size = array_size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
inline const int ArrayList<T>::get_size() { return size; }

template<class T>
inline const bool ArrayList<T>::is_empty() { return !size; }

template<class T>
const std::string ArrayList<T>::to_string()
{
	std::string res = "[";
	for(int i = 0; i < size; i++)
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
void ArrayList<T>::push(T value)
{
	T *tmp_arr = new T[size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i] = arr[i];
	tmp_arr[size] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
T ArrayList<T>::pop()
{
	if (is_empty())
		throw 1;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1], res_val = arr[size - 1];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i];
	delete[] arr;
	arr = tmp_arr;
	size--;
	return res_val;
}

template<class T>
inline const T ArrayList<T>::peek() { return arr[size - 1]; }

template<class T>
inline const T ArrayList<T>::get(int index)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	return arr[index];
}

template<class T>
inline void ArrayList<T>::set(int index, T value)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	arr[index] = value;
}

template<class T>
void ArrayList<T>::insert_at(int index, T value)
{
	if (index > size || index < 0)
		throw 2;
	T *tmp_arr = new T[size + 1], tmp_val;
	tmp_arr[0] = value;
	for (int i = 0; i < size; i++)
		tmp_arr[i + 1] = arr[i];
	for (int i = 0; i < index; i++)
	{
		tmp_val = tmp_arr[i];
		tmp_arr[i] = tmp_arr[i + 1];
		tmp_arr[i + 1] = tmp_val;
	}
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
void ArrayList<T>::remove_at(int index)
{
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1], tmp_val;
	for (int i = 0; i < index; i++)
		tmp_arr[i] = arr[i];
	for (int i = index + 1; i < size; i++)
		tmp_arr[i - 1] = arr[i];
	delete[] arr;
	arr = tmp_arr;
	size--;
}

template<class T>
inline ArrayList<T>::~ArrayList() { delete[] arr; }