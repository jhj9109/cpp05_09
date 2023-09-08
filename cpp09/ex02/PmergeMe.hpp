/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:24:14 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 20:24:15 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe
{
private:
    unsigned int _K;
    std::vector<int> _c;
    PmergeMe(void);

public:
    PmergeMe(unsigned int K);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

public:
    void parse(int ac, char **av);
    int atoiPositive(const std::string &str);
    void printVec(std::vector<int> &vec);
    void printVec2(const std::string &head, std::vector<int> &vec);
    std::vector<int> &insertionSort(std::vector<int> &vec);
    std::vector<int> &insertionSort2(std::vector<int> &vec, size_t start, size_t end);

    std::vector<int> &mergeInsertionSort(std::vector<int> &vec);
    std::vector<int> &mergeInsertionSort2(std::vector<int> &vec, size_t start, size_t end);

    std::list<int> &insertionSort(std::list<int> &lst);
    std::list<int> &mergeInsertionSort(std::list<int> &lst);
    void sort(void);

    void printDuration(clock_t start, clock_t end, size_t n, const char *data);
};

#endif