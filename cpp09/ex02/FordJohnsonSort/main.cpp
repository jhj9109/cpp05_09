#include "Group.hpp"
#include "FordJohnsonSort.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av)
{
    const std::string RED = "\033[31m";
    const std::string DEFAULT = "\033[39m";
    int K = 3;

    if (ac < 2)
    {
        std::cout << RED << "Error: Invalid argument." << DEFAULT << std::endl;
        return 1;
    }

    try
    {
        FordJohnsonSort inst;
        inst.parse(ac, av);
        std::vector<int> c = inst.getC();
        std::vector<int> answer = inst.getC();
        
        std::vector<int> my = inst.sort(c);
        
        std::sort(answer.begin(), answer.end());


        // std::cout << my.size() << ", " << answer.size() << std::endl;
        if (my == answer)
        {
            std::cout << "Both sorts give the same result.\n";
        }
        else
        {
            std::cout << "The sorts give different results.\n";
            for (size_t i = 0; i < my.size(); i += 10)
            {
                for (size_t j = 0; j < 10 && i+j < my.size(); j++)
                    std::cout << c[i+j] << " ";
                std::cout << std::endl;
                
                for (size_t j = 0; j < 10 && i+j < my.size(); j++)
                    std::cout << RED << my[i+j] << " ";
                std::cout << DEFAULT << std::endl;
                
                for (size_t j = 0; j < 10 && i+j < answer.size(); j++)
                    std::cout << answer[i+j] << " ";
                std::cout << std::endl;
                
                std::cout << " === === === === === === ===" << std::endl;
            }
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << RED << e.what() << DEFAULT << std::endl;
    }
    catch (const char *errorMessage)
    {
        std::cout << RED << errorMessage << DEFAULT << std::endl;
    }

    // system("leaks PmergeMe");
    return 0;
}
