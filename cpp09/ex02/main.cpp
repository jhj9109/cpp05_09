/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:23:58 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 20:23:59 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
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
        PmergeMe p(K);
        p.parse(ac, av);
        p.sort();
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
