#include "FordJohnsonSort.hpp"
#include <iostream>
// 1 * 11 => 2 * 5 + 1
// 2 * 5 => 4 * 2 + 2
// ====================
// 11

FordJohnsonSort::FordJohnsonSort() {}

FordJohnsonSort::~FordJohnsonSort() {}

// 재귀돌리는 구조에 맞추기 위해 선 작업 후, 재귀 함수 호출.
std::vector<int> FordJohnsonSort::sort(std::vector<int> arr)
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

std::vector<Group> FordJohnsonSort::recur(std::vector<Group> arr)
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

int FordJohnsonSort::jacobsthal(int n)
{
    while (_dp.size() <= 1)
        _dp.push_back(static_cast<int>(_dp.size()));

    size_t s = _dp.size();

    if (s <= n)
    {
        for (size_t i = s; i <= n; i++)
            _dp.push_back(_dp[i - 1] + 2 * _dp[i - 2]);
    }

    return _dp[n];
}

void FordJohnsonSort::parse(int ac, char **av)
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

int FordJohnsonSort::atoiPositive(const std::string &str)
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

std::vector<int> FordJohnsonSort::getC() { return _c; }