#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <cstdlib>
#include <iostream>

/*
    Develop a class template Array that contains elements of type T and that implements the following behavior and functions:
    • Construction with no parameter: Creates an empty array.
    • Construction with an unsigned int n as a parameter: Creates an array of n elements
    initialized by default.
    Tip: Try to compile int * a = new int(); then display *a.
    • Construction by copy and assignment operator. In both cases, modifying either the

    original array or its copy after copying musn’t affect the other array.
    •   You MUST use the operator new[] to allocate memory.
        Preventive allocation (allocating memory in advance) is forbidden.
        Your program must never access nonallocated memory.
    •   Elements can be accessed through the subscript operator: [ ].
    •   When accessing an element with the [ ] operator, if its index is out of bounds, an

    std::exception is thrown.
    •   A member function size() that returns the number of elements in the array.
        This member function takes no parameter and musn’t modify the current instance.
        As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
*/

template <typename T>
class Array
{
private:
    unsigned int _size;
    T *_arr;

public:
    Array<T>(void): _size(0), _arr(NULL) {}
    Array<T>(unsigned int n): _size(n), _arr(new T[n]()) {}
    Array<T>(const Array &array): _size(0), _arr(NULL)
    {
        *this = array;
    }
    Array<T> &operator=(const Array &array)
    {
        if (this != &array)
        {
            delete[] _arr;
            _size = array._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                _arr[i] = array._arr[i];
            }
        }
        return *this;
    }
    virtual ~Array<T>(void)
    {
        delete[] _arr;
    }

    T &operator[](const int idx)
    {
        if (idx < 0 || (unsigned int)idx >= _size)
        {
            throw Array::IndexOutOfRangeException();
        }
        return _arr[idx];
    }

    // 값을 변경하지 않음을 명시
    const T &operator[](const int idx) const
    {
        if (idx < 0 || (unsigned int)idx >= _size)
        {
            throw Array::IndexOutOfRangeException();
        }
        return _arr[idx];
    }

    unsigned int size(void) const { return _size; }

    class IndexOutOfRangeException : public std::exception
    {
    public:
        IndexOutOfRangeException() throw() {}
        virtual ~IndexOutOfRangeException() throw(){};
        virtual const char *what() const throw() { return "array index out of range"; };
    };
};

#endif