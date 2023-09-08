#ifndef SPAN_HPP
#define SPAN_HPP


#include <exception>
#include <vector>
#include <set>
#include <cstddef>

class Span
{
private:
    unsigned int _capacity;
    std::multiset<int> _c;

public:
    Span(void);
    Span(unsigned int n);
    Span(const Span& that);
    Span& operator=(const Span& that);
    ~Span();
    void addNumber(int n);
    void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SizeLimitException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return "사이즈 1이하"; };
    };

    class TooShortException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return "사이즈 1이하"; };
    };
};

#endif