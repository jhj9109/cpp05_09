#include "Group.hpp"
#include <sstream>
#include <iostream>

Group::Group() {}

Group::Group(int val)
{
    _c.push_back(val);
}

Group::Group(int smaller, int bigger)
{
    _c.push_back(smaller);
    _c.push_back(bigger);
}

Group::Group(const std::vector<int> &v1, const std::vector<int> &v2)
{
    _c.insert(_c.end(), v1.begin(), v1.end());
    _c.insert(_c.end(), v2.begin(), v2.end());
}

Group::Group(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
    _c.insert(_c.end(), begin, end);
}

Group::Group(const Group &other)
{
    *this = other;
}

Group::Group(const Group &smaller, const Group &bigger)
{
    _c.insert(_c.end(), smaller._c.begin(), smaller._c.end());
    _c.insert(_c.end(), bigger._c.begin(), bigger._c.end());
}

Group &Group::operator=(const Group &other)
{
    if (this != &other)
    {
        _c = other._c;
    }
    return *this;
}
Group::~Group() {}

bool Group::operator>(const Group &other) const
{
    if (_c.size() != other._c.size())
    {
        return !!_c.size();
    }
    return _c.back() > other._c.back();
}

bool Group::operator<(const Group &other) const
{
    if (_c.size() != other._c.size())
    {
        return !other._c.size();
    }
    return _c.back() < other._c.back();
}

void Group::swap(Group &other)
{
    if (this == &other)
        return; // 자기 자신과의 스왑은 무시

    std::vector<int> temp = _c; // 복사 생성자를 사용하여 임시 벡터를 생성
    _c = other._c;              // 복사 대입 연산자를 사용하여 값 교체
    other._c = temp;            // 복사 대입 연산자를 사용하여 값 교체
}

void    Group::divide(Group &bigger, Group &smaller)
{
    size_t half = _c.size() / 2;

    bigger._c = std::vector<int>(_c.begin() + half, _c.end());
    smaller._c = std::vector<int>(_c.begin(), _c.begin() + half);
}

void Group::extractNumber(int &smaller, int &bigger)
{
    smaller = _c[0];
    bigger = _c[1];
}

int Group::getNumber(int idx) { return _c[idx]; }

const std::vector<int> &Group::getC() { return _c; }

void Group::print()
{
    std::cout << "    Group: ";
    for (size_t i = 0; i < _c.size(); i++)
        std::cout << _c[i] << " ";
    std::cout << std::endl;
}