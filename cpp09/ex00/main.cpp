/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:24:44 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 17:24:45 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <sstream>

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
    if (ac == 1)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (ac != 2)
    {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }
    const std::string CSV_FILE_PATH = "./data.csv";
    const std::string inputFilePath(av[1]);
    try
    {
        BitcoinExchange datas(CSV_FILE_PATH);
        datas.convertToRecord(inputFilePath);
    }
    catch (const char *err)
    {
        std::cout << RED;
        std::cout << err << std::endl;
        std::cout << DEFAULT;
    }
    catch (const std::exception &e)
    {
        std::cout << RED;
        std::cout << e.what() << std::endl;
        std::cout << DEFAULT;
    }
    return 0;
}
