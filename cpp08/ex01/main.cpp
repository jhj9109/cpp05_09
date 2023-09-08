#include "Span.hpp"
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

int main(void)
{
    Span s(3);
    s.addNumber(-2147483648);
    s.addNumber(2147483647);
    std::cout << RED << std::endl;
    std::cout << "short: " << s.shortestSpan() << std::endl;
    std::cout << "long: " << s.longestSpan() << std::endl;
    s.addNumber(0);
    std::cout << BLUE << std::endl;
    std::cout << "short: " << s.shortestSpan() << std::endl;
    std::cout << "long: " << s.longestSpan() << std::endl;
    
    
    // std::cout << "shortest: " << s.shortestSpan() << std::endl;
    // std::cout << "longestSpan: " << s.longestSpan() << std::endl;


    
    Span sp(5);
    
    int tmp[] = { 6, 3, 17, 9, 11};
    std::vector<int> v (tmp, tmp + sizeof(tmp) / sizeof(int) );
    
    sp.addNumber(v.begin(), v.end());
    
    std::cout << YELLOW << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    try
    {
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }

    std::cout << DEFAULT << std::endl;
    system("leaks test");
    return 0;
}