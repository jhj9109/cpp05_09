#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>
#include <stdexcept>

class Group
{
private:

private:
    std::vector<int> _c;

public:
    Group();
    Group(int val);
    Group(int smaller, int bigger);
    
    Group(const std::vector<int>& v1, const std::vector<int>& v2);

    Group(const std::vector<int>::iterator &begin, const std::vector<int>::iterator& end);
    
    Group(const Group &other);
    Group(const Group &other1, const Group &other2);
    Group& operator=(const Group &other);
    virtual ~Group();
    
    bool operator>(const Group &other) const;
    bool operator<(const Group &other) const;

    void swap(Group &other);
    
    // Group& divide();
    void    divide(Group &bigger, Group &smaller);
    void extractNumber(int &smaller, int &bigger);
    int getNumber(int idx);

    const std::vector<int>& getC();

    void print();
};

#endif