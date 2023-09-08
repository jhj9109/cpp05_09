#include "Data.hpp"

uintptr_t serialize(Data *data)
{
    return reinterpret_cast<uintptr_t>(data);
}

Data *deserialize(uintptr_t u)
{
    return reinterpret_cast<Data *>(u);
}
