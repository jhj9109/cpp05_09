#include "Data.hpp"
#include <iostream>

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

int main()
{
    Data data;

    std::cout << YELLOW << std::endl;

    std::cout << "변환전: " << &data << "변환후: " << deserialize((serialize(&data))) << std::endl;

    std::cout << DEFAULT << std::endl;
    system("leaks test");
}