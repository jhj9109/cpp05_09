#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack(void): std::stack<T>() {};
		MutantStack(const MutantStack & mutantStack): std::stack<T>(mutantStack) {};
		MutantStack & operator=(const MutantStack & mutantStack){
			if (this != &mutantStack){
				this->operator=(mutantStack);//this: std::stack<T>
			}
			return *this;
		}
		virtual ~MutantStack(void) {};

		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }

		const_iterator begin(void) const { return this->c.begin(); }
		const_iterator end(void) const { return this->c.end(); }

		reverse_iterator rbegin(void) { return this->c.rbegin();}
		reverse_iterator rend(void) { return this->c.rend(); }
		
		const_reverse_iterator rbegin(void) const { return this->c.rbegin();}
		const_reverse_iterator rend(void) const { return this->c.rend(); }
};

#endif