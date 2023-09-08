/*
Implement the following function templates:

    • swap: Swaps the values of two given arguments. Does not return anything.
    • min:  Compares the two values passed in its arguments and returns the smallest one.
            If the two of them are equal, then it returns the second one.
    • max:  Compares the two values passed in its arguments and returns the greatest one.
            If the two of them are equal, then it returns the second one.
These functions can be called with any type of argument.
The only requirement is that the two arguments must have the same type and must support all the comparison operators.

Templates must be defined in the header files.
*/

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    if (&a != &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return a < b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

#endif