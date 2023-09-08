#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

/*
begin() 함수는 벡터의 데이터가 있는 리스트의 시작 주소를 리턴하는데, 첫 번째 값 위치입니다.
end() 함수는 리스트의 끝 주소를 리턴하는데, 마지막 값보다 한 칸 뒤 위치의 값을 리턴합니다.
find는 못 찾았다면 마지막 원소(== end())를 리턴
*/

template <typename T>
typename T::iterator easyfind(T &container, const int &val)
{
    return std::find(container.begin(), container.end(), val);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, const int &val)
{
    return std::find(container.begin(), container.end(), val);
}

#endif