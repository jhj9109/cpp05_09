/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:24:08 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 20:24:09 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *
 * 1. 크기 N 배열
 * 2. 크기 K 단위로 나눔 (K == 1이면 병합정렬, K == N이면 삽입정렬)
 * 3. K 배열에 대하여 삽입정렬 실행
 */
#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(void) : _K(5) {}
PmergeMe::PmergeMe(unsigned int K) : _K(K) {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _K = other._K;
        _c.clear();
        _c = other._c;
    }
    return *this;
}

void PmergeMe::parse(int ac, char **av)
{
    _c.clear();
    for (int i = 1; i < ac; ++i)
    {
        std::string str(av[i]);
        _c.push_back(atoiPositive(str));
    }
    if (_c.size() == 0)
        throw "Error: No element.";
}

int PmergeMe::atoiPositive(const std::string &str)
{
    int number = 0;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            throw "Error: Not Positive Nubmer";
        if ((number >= 214748365 || number == 214748364) && str[i] > '7')
            throw "Error: Out of range.";
        number = (number * 10) + (str[i] - '0');
    }
    return number;
}

void PmergeMe::printVec(std::vector<int> &vec)
{
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVec2(const std::string &head, std::vector<int> &vec)
{
    std::cout << head;
    for (std::string::size_type i = 0; i < vec.size() && i < 5; ++i)
    {
        if (i == 4 && vec.size() > 5)
            std::cout << " [...]";
        else
            std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}

std::vector<int> &PmergeMe::insertionSort(std::vector<int> &vec)
{
    int end = vec.size();
    int target;
    for (int i = 1; i < end; ++i)
    {
        target = vec[i];
        for (int j = i; j >= 0; --j)
        {
            if (j == 0 || vec[j - 1] <= target)
            {
                for (int k = i; k > j; --k)
                    vec[k] = vec[k - 1];
                vec[j] = target;
                break;
            }
        }
    }
    return vec;
}

std::vector<int> &PmergeMe::insertionSort2(std::vector<int> &vec, size_t start, size_t end)
{
    int target;
    for (size_t i = start + 1; i < end; ++i)
    {
        target = vec[i];
        for (size_t j = i; j >= 0; --j)
        {
            if (j == 0 || vec[j - 1] <= target)
            {
                for (size_t k = i; k > j; --k)
                    vec[k] = vec[k - 1];
                vec[j] = target;
                break;
            }
        }
    }
    return vec;
}

std::vector<int> &PmergeMe::mergeInsertionSort(std::vector<int> &vec)
{
    // 1. _K이하짜리 청크는 삽입 정렬
    if (vec.size() <= _K)
    {
        vec = insertionSort(vec);
        return vec;
    }

    // 2. _K 단위로 청크 나누기.
    int vSize = vec.size();
    int m = vSize / _K;
    int half = m % 2 ? ((m / 2) + 1) * _K : (m / 2) * _K;

    std::vector<int> a;
    std::vector<int> b;

    for (int i = 0; i < half; ++i)
        a.push_back(vec[i]);
    for (int i = half; i < vSize; ++i)
        b.push_back(vec[i]);

    // 3. 나누어진 청크에 대해서 재귀적으로 sort 요청
    mergeInsertionSort(a);
    mergeInsertionSort(b);

    // 4. 정렬된 두 청크를 입력으로 전달받은 벡터에 반영하기.

    std::vector<int>::size_type idx;
    for (std::vector<int>::size_type i = 0, j = 0; i < a.size() || j < b.size();)
    {
        idx = i + j;
        if (i == a.size())
            vec[idx] = b[j++];
        else if (j == b.size())
            vec[idx] = a[i++];
        else if (a[i] < b[j])
            vec[idx] = a[i++];
        else
            vec[idx] = b[j++];
    }

    return vec;
}

std::vector<int> &PmergeMe::mergeInsertionSort2(std::vector<int> &vec, size_t start, size_t end)
{
    std::vector<int>::size_type vSize = end - start;
    // 1. _K이하짜리 청크는 삽입 정렬
    if (vSize <= _K)
    {
        vec = insertionSort2(vec, start, end);
        return vec;
    }

    // 2. _K 단위로 청크 나누기.
    std::vector<int>::size_type m = vSize / _K;
    std::vector<int>::size_type half = m % 2 ? ((m / 2) + 1) * _K : (m / 2) * _K;

    // 3. 나누어진 청크에 대해서 재귀적으로 sort 요청
    mergeInsertionSort2(vec, start, start + half);
    mergeInsertionSort2(vec, start + half, end);

    std::vector<int> temp;
    for (size_t i = start, j = start + half; i < start + half || j < end;)
    {
        if (i == start + half)
            temp.push_back(vec[j++]);
        else if (j == end)
            temp.push_back(vec[i++]);
        else if (vec[i] < vec[j])
            temp.push_back(vec[i++]);
        else
            temp.push_back(vec[j++]);
    }
    for (size_t i = 0; start + i < end; ++i)
        vec[start + i] = temp[i];

    return vec;
}

std::list<int> &PmergeMe::insertionSort(std::list<int> &lst)
{
    std::list<int>::iterator it, jt, prev;
    for (it = ++lst.begin(); it != lst.end();)
    {
        int value = *it;
        jt = it;
        while (jt != lst.begin())
        {
            prev = jt;
            if (*--prev >= value)
                break;
            --jt;
        }
        if (it != jt)
        {
            it = lst.erase(it);
            lst.insert(jt, value);
        }
        else
            ++it;
    }
    return lst;
}

std::list<int> &PmergeMe::mergeInsertionSort(std::list<int> &lst)
{
    // 1. _K이하짜리 청크는 삽입 정렬
    if (lst.size() <= _K)
    {
        lst = insertionSort(lst);
        return lst;
    }

    // 2. _K 단위로 청크 나누기.
    int lSize = lst.size();
    int m = lSize / _K;
    int half = m % 2 ? ((m / 2) + 1) * _K : (m / 2) * _K;

    std::list<int> a;
    std::list<int> b;

    std::list<int>::iterator it = lst.begin();
    for (int i = 0; i < half; ++it, ++i)
        a.push_back(*it);
    for (; it != lst.end(); ++it)
        b.push_back(*it);

    // 3. 나누어진 청크에 대해서 재귀적으로 sort 요청
    mergeInsertionSort(a);
    mergeInsertionSort(b);

    // 4. 정렬된 두 청크를 입력으로 전달받은 리스트에 반영하기.
    for (std::list<int>::iterator at = a.begin(), bt = b.begin(), it = lst.begin(); it != lst.end(); ++it)
    {
        if (at == a.end())
        {
            *it = *bt;
            ++bt;
        }
        else if (bt == b.end())
        {
            *it = *at;
            ++at;
        }
        else if (*at < *bt)
        {
            *it = *at;
            ++at;
        }
        else
        {
            *it = *bt;
            ++bt;
        }
    }

    return lst;
}

void PmergeMe::sort(void)
{
    const std::string BLACK = "\033[30m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    const std::string DEFAULT = "\033[39m";

    if (_c.size() == 0)
    {
        throw "정렬할 컨테이너가 세팅되지 않았습니다.";
    }

    std::vector<int> copyed = _c;

    std::cout << RED;
    printVec2(std::string("Before"), copyed);
    mergeInsertionSort(copyed);
    std::cout << BLUE;
    printVec2(std::string("After"), copyed);
    std::cout << DEFAULT;

    clock_t start;
    clock_t end;

    std::cout << YELLOW << "TEST1" << std::endl;

    copyed = _c;

    start = clock();
    mergeInsertionSort(copyed);
    end = clock();
    printDuration(start, end, _c.size(), "std::vector<int>");

    copyed = _c;

    std::cout << MAGENTA << "TEST2" << std::endl;

    start = clock();
    mergeInsertionSort2(copyed, 0, copyed.size());
    end = clock();
    printDuration(start, end, _c.size(), "std::vector<int>");

    std::cout << CYAN << "TEST3" << std::endl;

    std::list<int> lst;
    std::copy(_c.begin(), _c.end(), std::back_inserter(lst));
    start = clock();
    mergeInsertionSort(lst);
    end = clock();
    printDuration(start, end, lst.size(), "std::list<int>");

    std::cout << DEFAULT;
}

void PmergeMe::printDuration(clock_t start, clock_t end, size_t n, const char *data)
{
    clock_t duration = end - start;
    clock_t CLOCKS_PER_MILLI_SEC = 1000;
    std::cout << "Time to process a range of "
              << n << " elements with " << data << " : "
              << (duration / CLOCKS_PER_MILLI_SEC) << "." << (duration % CLOCKS_PER_MILLI_SEC) << "ms"
              << std::endl;
}