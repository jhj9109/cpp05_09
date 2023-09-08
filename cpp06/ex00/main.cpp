// #include <iostream>
// #include <limits>

// #include <cctype>
// #include <cstdlib>
// #include <stdlib.h> /* strtod */
// #include <cstring>
#include <iomanip>
#include <iostream>
// #include <limits>

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

int main(int argc, char *argv[])
{
    // float n1 = 5.4;
    // int n2 = static_cast<int>(n1);
    // float n3 = static_cast<float>(n2);
    // std::cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << std::endl;
    // std::cout << "n1: " << n1 << ", n2: " << static_cast<int>(5.4) << ", n3: " << static_cast<float>(static_cast<int>(5.4)) << std::endl;

    if (argc != 2)
    {
        std::cout << RED << std::endl;
        std::cout << "올바르지 않은 인자 갯수 입니다. 단 1개의 인자만 넣어주세요!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << YELLOW << std::endl;
    const char *target = argv[1];
    char *endPtr = NULL;
    char *endPtrLong = NULL;
    double val = std::strtod(target, &endPtr); // 계산할수 없는 부분부터 endPtr이 가르킴
    long lVal = std::strtol(target, &endPtrLong, 10);

    if (std::strcmp(endPtr, "f") == 0 || std::strcmp(endPtr, "F") == 0)
    {
        val = static_cast<double>(static_cast<float>(val));
    }
    else if (std::strlen(endPtr) != 0)
    {
        std::cout << "parse error near `" << endPtr << "'" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << std::fixed << std::setprecision(1);

    char c[4] = "\'\0\'";
    std::cout << "char: "
              << ((target == endPtrLong || lVal < -128 || lVal > 127)
                      ? "impossible"
                      : (std::isprint(c[1] = static_cast<char>(lVal)) ? c : "Non displayable"))
              << std::endl;
    if (target == endPtrLong || lVal < -2147483648 || lVal > 2147483647)
    {
        std::cout << "int: "
                  << "impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(lVal) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << val << std::endl;

    std::cout << DEFAULT << std::endl;
    /*
    echo "./convert 0"
    ./convert 0
    echo "./convert nan"
    ./convert nan
    echo "./convert 42.0f"
    ./convert 42.0f
    */
    return EXIT_SUCCESS;
}