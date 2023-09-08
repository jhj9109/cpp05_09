#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <string>

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

static void print_int(int &i)
{
    std::cout << "Int: " << i << std::endl;
}

static void print_str(const std::string &s)
{
    std::cout << "String: " << s << std::endl;
}

int main()
{
    std::size_t len = 10;

    int *arr = new int[len];
    std::string *str_arr = new std::string[len];
    for (std::size_t i = 0; i < len; i++)
    {
        arr[i] = i * i;
        std::stringstream ss;
        ss << "str<" << (i * i) << ">";
        str_arr[i] = ss.str();
    }
    std::cout << GREEN << std::endl;
    iter(arr, len, print_int);
    std::cout << RED << std::endl;
    iter(str_arr, len, print_str);

    std::cout << DEFAULT << std::endl;
    delete[] str_arr;
    delete[] arr;

    system("leaks test");
    return 0;
}
