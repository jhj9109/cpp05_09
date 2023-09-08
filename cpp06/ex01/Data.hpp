#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
    int data1;
    int data2;
};

uintptr_t serialize(Data *data);
Data *deserialize(uintptr_t u);

#endif