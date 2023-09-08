#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <set>

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
    std::list<int> l;
    std::set<int> s;

    for (int i = 0; i < 10; i++)
    {
        l.insert(l.end(), i * i);
        s.insert(s.end(), i * i);
    }

    const std::set<int> sc = s; 

    std::list<int>::iterator it;
    std::set<int>::const_iterator cit;
    
    it = easyfind(l, 16);
    cit = easyfind(sc, 81);


    std::cout << GREEN << std::endl;
    std::cout << "it: 16 " << (it != l.end() ? "O" : "X") << std::endl;
    std::cout << "cit: 81 " << (cit != sc.end() ? "O" : "X") << std::endl;


    it = easyfind(l, 17);
    cit = easyfind(sc, 82);
    std::cout << BLUE << std::endl;
    std::cout << "it: 17 " << (it != l.end() ? "O" : "X") << std::endl;
    std::cout << "cit: 82 " << (cit != sc.end() ? "O" : "X") << std::endl;

    std::cout << DEFAULT << std::endl;
    system("leaks test");
    return 0;
}