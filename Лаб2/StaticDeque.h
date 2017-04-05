#pragma once
#include "InterfacesAndNode.h"
template<class T>
class StaticDeque :
	public Deque<T>
{
private:
	T *arr;
	inr size;
public:

	StaticDeque(int size, T default_value);
	const int get_size();
	const bool is_empty();
	const std::string to_string();
	void push_front(T value);
	void push_back(T value);
	T pop_front();
	T pop_back();
	const T peek_front();
	const T peek_back();
	~StaticDeque();
};

template<class T>
StaticDeque<T>::StaticDeque(int size, T default_value)
{
	if (size <= 0)
		throw 4;
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
inline const int StaticDeque<T>::get_size() { return size; }

template<class T>
inline const bool StaticDeque<T>::is_empty() { return !size; }

template<class T>
const std::string StaticDeque<T>::to_string()
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
void StaticDeque<T>::push_front(T value)
{
	T *tmp_arr = new T[size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i + 1] = arr[i];
	tmp_arr[0] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
void StaticDeque<T>::push_back(T value)
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
T StaticDeque<T>::pop_front()
{
	if (is_empty())
		throw 1;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1], res_val = arr[0];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i + 1];
	delete[] arr;
	arr = tmp_arr;
	size--;
	return res_val;
}

template<class T>
T StaticDeque<T>::pop_back()
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
inline const T StaticDeque<T>::peek_front()
{
	return arr[0];
}

template<class T>
inline const T StaticDeque<T>::peek_back()
{
	return arr[size - 1];
}

template<class T>
inline StaticDeque<T>::~StaticDeque() { delete[]arr; }