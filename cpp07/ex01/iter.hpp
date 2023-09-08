/*
Implement a function template iter that takes 3 parameters and returns nothing.
	• The first parameter is the address of an array.
	• The second one is the length of the array.
	• The third one is a function that will be call on every element of the array.

Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
*/

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(const T *arr, std::size_t len, void (*f)(const T &))
{
	if (!arr || len == 0 || !f)
	{
		return;
	}
	for (std::size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T &))
{
	if (!arr || len == 0 || !f)
	{
		return;
	}
	for (std::size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif