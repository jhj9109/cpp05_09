/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:01:51 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 18:01:53 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid arguments." << std::endl;
        return 1;
    }
    try
    {
        std::string expr(av[1]);
        RPN rpn(expr);
        rpn.cal();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
}
