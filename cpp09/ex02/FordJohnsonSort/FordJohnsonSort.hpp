#ifndef FORD_JOHNSON_SORT_HPP
#define FORD_JOHNSON_SORT_HPP

#include "Group.hpp"
#define DEBUG false

class FordJohnsonSort
{
private:
    std::vector<int> _dp;
    std::vector<int> _c;

public:
    FordJohnsonSort();
    ~FordJohnsonSort();

    std::vector<int>    sort(std::vector<int> arr);
    std::vector<Group>  recur(std::vector<Group> arr);
    int                 jacobsthal(int n);

    void                parse(int ac, char **av);
    int                 atoiPositive(const std::string &str);

    std::vector<int>    getC();
};

#endif
