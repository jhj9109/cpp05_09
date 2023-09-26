#include <iostream>
#include <vector>
#include <algorithm>

void test(const std::vector<int> &v, int target)
{
    std::cout << "target: " << target << std::endl;
    
    // lower_bound를 사용하여 target 값 이상의 첫 번째 원소 위치를 찾습니다.
    auto lower = std::lower_bound(v.begin(), v.end(), target);
    if (lower != v.end()) {
        std::cout << "Lower bound of " << target << " is at index: " << (lower - v.begin()) << '\n';
    } else {
        std::cout << "Lower bound of " << target << " not found.\n";
    }

    // upper_bound를 사용하여 target 값 초과의 첫 번째 원소 위치를 찾습니다.
    auto upper = std::upper_bound(v.begin(), v.end(), target);
    if (upper != v.end()) {
        std::cout << "Upper bound of " << target << " is at index: " << (upper - v.begin()) << '\n';
    } else {
        std::cout << "Upper bound of " << target << " not found.\n";
    }
}

int main() {
    std::vector<int> v;
    v.push_back(1); // 0, lower(1), lower(0), upper(0)
    v.push_back(2); // 1, lower(1)
    v.push_back(3);
    v.push_back(4); // 3, lower(4), 이상인값
    v.push_back(4); 
    v.push_back(4);
    v.push_back(5); // 6, upper(4), 초과인값
    v.push_back(6);
    v.push_back(7); // 8. lower(7)
    // 9. lower(0)

    std::cout << "v.size(): " << v.size() << std::endl; // 9

    // bound에서 v.end() == v.begin() + v.size()

    // test(v, 4);

    // test(v, 1);

    // test(v, 0);

    // test(v, 7);

    // test(v, 10);

    int target = 7;

    auto lower = std::lower_bound(v.begin(), v.begin() + 7, target);
    v.insert(lower, target);

    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // upper_bound를 사용하여 target 값 초과의 첫 번째 원소 위치를 찾습니다.
    // auto upper = std::upper_bound(v.begin(), v.end(), target);
    // v.insert(upper, target);
    // if (upper != v.end()) {
    //     std::cout << "Upper bound of " << target << " is at index: " << (upper - v.begin()) << '\n';
    // } else {
    //     std::cout << "Upper bound of " << target << " not found.\n";
    // }


    return 0;
}
