#include "Span.hpp"
#include <iostream>

Span::Span(void): _capacity(0), _c() {}

Span::Span(unsigned int capacity): _capacity(capacity), _c() {}

Span::Span(const Span& span)
{
    *this = span;
}

Span& Span::operator=(const Span& span)
{
    if (this != &span)
    {
        _c = span._c;
        _capacity = span._capacity;
    }
    return *this;
}

Span::~Span() {}


void Span::addNumber(int number) {
    if (_c.size() >= _capacity) {
        throw Span::SizeLimitException();
    }
    _c.insert(number);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end){
    if (_capacity - _c.size() - static_cast<unsigned int>(std::distance(start, end)))
    {
        throw Span::SizeLimitException();
    }
    for ( ; start != end; start++){
        addNumber(*start);
    }
}

unsigned int Span::shortestSpan() const {
    if (_c.size() <= 1) {
        throw Span::TooShortException();
    }
    
    std::multiset<int>::iterator it = _c.begin();
    
    long prev = static_cast<long>(*it++);//c[0]
    long cur = static_cast<long>(*it);//c[1]
    long d = cur - prev;
    long shortest = cur - prev;
    // std::cout << cur << " - " << prev << " = " << cur - prev << ", shortest: " << shortest << std::endl;
    prev = cur;
    
    while (++it != _c.end()) {
        //c[2] ~
        cur = static_cast<long>(*it);
        d = cur - prev;
        shortest = (d < shortest) ? d : shortest;
        // std::cout << cur << " - " << prev << " = " << cur - prev << ", shortest: " << shortest << std::endl;
        prev = cur;
    }

    return static_cast<unsigned int>(shortest);
}

unsigned int Span::longestSpan() const {
    if (_c.size() <= 1) {
        throw Span::TooShortException();
    }
    return static_cast<unsigned int>(static_cast<long>(*_c.rbegin()) - static_cast<long>(*_c.begin()));
}

const char *Span::SizeLimitException::what() const throw() { return "사이즈 초과"; }
const char *Span::TooShortException::what() const throw() { return "사이즈 1이하"; }