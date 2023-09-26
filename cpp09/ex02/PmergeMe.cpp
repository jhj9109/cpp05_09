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

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _c = other._c;
    }
    return *this;
}
PmergeMe::~PmergeMe(void) {}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> arr)
{
    std::vector<Group> newArr;

    for (size_t i = 0; i < arr.size(); i++)
    {
        Group temp(arr[i]);
        newArr.push_back(temp);
    }

    std::vector<Group> sorted = recur(newArr);

    std::vector<int> result;
    for (size_t i = 0; i < sorted.size(); i++)
    {
        result.push_back(sorted[i].getNumber(0));
    }
    return result;
}

std::vector<Group> PmergeMe::recur(std::vector<Group> arr)
{
    // 1. 머지 소트 => 분할과정에서 최종적으로 사이즈 1개가 되며 정렬 상태가 됨
    if (arr.size() == 1)
        return arr;

    // 홀수 => 나중에 
    bool odd = (arr.size() % 2 == 1);
    size_t half = arr.size() / 2;

    // 2. 짝을 짓고 smaller vs bigger 그룹으로 분리
    std::vector<Group> newArr;
    size_t smallerIndex, biggerIndex;
    for (size_t i = 0; i < half; i++)
    {
        if (arr[2 * i] > arr[2 * i + 1])
        {
            smallerIndex = 2 * i + 1;
            biggerIndex = 2 * i;
        }
        else
        {
            smallerIndex = 2 * i;
            biggerIndex = 2 * i + 1;
        }
        Group g(arr[smallerIndex], arr[biggerIndex]);
        newArr.push_back(g);
    }

    // 3. bigger 그룹에 대해서 재귀호출을 통해 정렬
    std::vector<Group> sorted = recur(newArr);
    std::vector<Group> dest, bigger, smaller;

    // 4. 짝지었던것을 활용, b1 b2 b3 .... s1 s2 s3 그룹을 만든다.
    for (size_t i = 0; i < sorted.size(); i++)
    {
        Group tempBigger, tempSmaller;
        sorted[i].divide(tempBigger, tempSmaller);
        dest.push_back(tempBigger);
        bigger.push_back(tempBigger);
        smaller.push_back(tempSmaller);
    }

    // 5. 홀수여서 짝지어지지 못했던것은 smaller의 마지막 요소로 포함한다.
    if (odd)
        smaller.push_back(arr.back());
    
    if (DEBUG)
    {
        std::cout << "bigger: " << std::endl;
        for (size_t i = 0; i < bigger.size(); i++)
            bigger[i].print();
        std::cout << std::endl;

        std::cout << "smaller: " << std::endl;
        for (size_t i = 0; i < smaller.size(); i++)
            smaller[i].print();
    }

    // 6. 합쳐질 사이즈 미리 확보하여 주소 변경되지 않도록 함
    dest.reserve(dest.size() + smaller.size());

    // 7. s1 < b1 이므로, 비교 없이 가장 앞에 넣으면 된다.
    dest.insert(dest.begin(), smaller[1 - 1]);

    // 8. 삽입할 smaller 원소의 차례와 이진탐색 범위 결정에 사용될 변수들.
    size_t n = 3;
    size_t curJacobN = jacobsthal(n);
    size_t prevJacobN = jacobsthal(n - 1);
    // 0, 1, => 1, 3, 5, 11, 21, ... => 인접 수의 합은 2의 제곱 수

    std::vector<Group>::iterator pos;

    while (prevJacobN < smaller.size())
    {
        // std::min(dest.size(), curJacobN - 1 + prevJacobN)
        // 현재 대상 bi
        // 이진탐색 대상
        // - bi < ai를 이용하여 => a(1) ~ a(i-1)
        // - 이전에 삽입된 b 원소들 => b(1) ~ b (prevJacobN)
        // - i == 현재 curJacobN
        // - 총합: curJacobN - 1 + prevJacobN
        //   - 여기서 i == 현재 JacobN
        //   - 인접 자코브숫자의 합은 2^n
        //   - (2 ** n-1) ~ (2 ** n) - 1 까지는 최악의 이진 탐색 필요 수가 같다!
        std::vector<Group>::iterator endBoundary = dest.begin() + std::min(dest.size(), curJacobN - 1 + prevJacobN);
        for (size_t i = std::min(smaller.size(), curJacobN);
             i > prevJacobN; --i)
        {
            pos = std::lower_bound(dest.begin(), endBoundary, smaller[i - 1]);
            dest.insert(pos, smaller[i - 1]);
        }

        n += 1;
        prevJacobN = curJacobN;
        curJacobN = jacobsthal(n);
    }

    if (DEBUG)
    {
        std::cout << "dest: " << std::endl;
        for (size_t i = 0; i < dest.size(); i++)
            dest[i].print();
    }

    return dest;
}

std::deque<int> PmergeMe::fordJohnsonSort(std::deque<int> arr)
{
    std::deque<Group> newArr;

    for (size_t i = 0; i < arr.size(); i++)
    {
        Group temp(arr[i]);
        newArr.push_back(temp);
    }

    std::deque<Group> sorted = recur(newArr);

    std::deque<int> result;
    for (size_t i = 0; i < sorted.size(); i++)
    {
        result.push_back(sorted[i].getNumber(0));
    }
    return result;
}

std::deque<Group> PmergeMe::recur(std::deque<Group> arr)
{
    if (arr.size() == 1)
        return arr;

    // 홀수 => 나중에 
    bool odd = (arr.size() % 2 == 1);
    size_t half = arr.size() / 2;

    std::deque<Group> newArr;
    size_t smallerIndex, biggerIndex;
    for (size_t i = 0; i < half; i++)
    {
        if (arr[2 * i] > arr[2 * i + 1])
        {
            smallerIndex = 2 * i + 1;
            biggerIndex = 2 * i;
        }
        else
        {
            smallerIndex = 2 * i;
            biggerIndex = 2 * i + 1;
        }
        Group g(arr[smallerIndex], arr[biggerIndex]);
        newArr.push_back(g);
    }

    std::deque<Group> sorted = recur(newArr);
    std::deque<Group> dest, bigger, smaller;

    for (size_t i = 0; i < sorted.size(); i++)
    {
        Group tempBigger, tempSmaller;
        sorted[i].divide(tempBigger, tempSmaller);
        dest.push_back(tempBigger);
        bigger.push_back(tempBigger);
        smaller.push_back(tempSmaller);
    }

    if (odd)
        smaller.push_back(arr.back());
    
    if (DEBUG)
    {
        std::cout << "bigger: " << std::endl;
        for (size_t i = 0; i < bigger.size(); i++)
            bigger[i].print();
        std::cout << std::endl;

        std::cout << "smaller: " << std::endl;
        for (size_t i = 0; i < smaller.size(); i++)
            smaller[i].print();
    }

    // vector처럼 reserve로 사이즈 미리 지정이 불가
    // dest.reserve(dest.size() + smaller.size());

    dest.insert(dest.begin(), smaller[1 - 1]);

    size_t n = 3;
    size_t curJacobN = jacobsthal(n);
    size_t prevJacobN = jacobsthal(n - 1);
    
    std::deque<Group>::iterator pos;

    while (prevJacobN < smaller.size())
    {
        // vector처럼 reserve로 사이즈 미리 지정이 불가 => begin() 부터 거리를 활용
        size_t endBoundary = std::min(dest.size(), curJacobN - 1 + prevJacobN);
        for (size_t i = std::min(smaller.size(), curJacobN);
             i > prevJacobN; --i)
        {
            pos = std::lower_bound(dest.begin(), dest.begin() + endBoundary, smaller[i - 1]);
            dest.insert(pos, smaller[i - 1]);
        }

        n += 1;
        prevJacobN = curJacobN;
        curJacobN = jacobsthal(n);
    }

    if (DEBUG)
    {
        std::cout << "dest: " << std::endl;
        for (size_t i = 0; i < dest.size(); i++)
            dest[i].print();
    }

    return dest;
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

    // std::vector<int> copyed = _c;
    ;
    std::deque<int> copyed;
    std::copy(_c.begin(), _c.end(), std::back_inserter(copyed));
    clock_t start, end;

    
    std::cout << RED << std::endl;
    printVec2(std::string("Before"), _c);
    
    // 미리 시간 재기
    start = clock();
    std::vector<int> vectorResult = fordJohnsonSort(_c);
    end = clock();
    
    printVec2(std::string("After"), vectorResult);
    
    std::cout << YELLOW << "TEST1" << std::endl;
    printDuration(start, end, vectorResult.size(), "std::vector<int>"); // 여기 테스트는 미리 재두었던것 사용

    std::cout << MAGENTA << "TEST2" << std::endl;
    
    start = clock();
    std::deque<int> dequeResult = fordJohnsonSort(copyed);
    end = clock();
    printDuration(start, end, dequeResult.size(), "std::vector<int>");

    std::cout << GREEN << "===== std::sort와 비교 ======" << std::endl;
    
    std::sort(_c.begin(), _c.end());
    std::sort(copyed.begin(), copyed.end());

    if (_c == vectorResult && copyed == dequeResult)
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "KO" << std::endl;
    }
    
    std::cout << DEFAULT << std::endl;
}


int PmergeMe::jacobsthal(int n)
{
    while (_dp.size() <= 1)
        _dp.push_back(static_cast<int>(_dp.size()));

    int s = _dp.size();

    if (s <= n)
    {
        for (int i = s; i <= n; i++)
            _dp.push_back(_dp[i - 1] + 2 * _dp[i - 2]);
    }

    return _dp[n];
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



void PmergeMe::printDuration(clock_t start, clock_t end, size_t n, const char *data)
{
    clock_t duration = end - start;
    clock_t CLOCKS_PER_MILLI_SEC = 1000;
    std::cout << "Time to process a range of "
              << n << " elements with " << data << " : "
              << (duration / CLOCKS_PER_MILLI_SEC) << "ms " << (duration % CLOCKS_PER_MILLI_SEC) << "us"
              << std::endl;
}