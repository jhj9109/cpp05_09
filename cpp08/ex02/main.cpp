#include "MutantStack.hpp"

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << RED << "mstack.top(): " << mstack.top() << DEFAULT << std::endl;
		mstack.pop();
		std::cout << BLUE << "mstack.size(): " << mstack.size() << DEFAULT << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << YELLOW << "원소: " << *it << DEFAULT << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

	}

	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << RED << "l.back(): " << l.back() << DEFAULT << std::endl;
		l.pop_back();
		std::cout << BLUE << "l.size(): " << l.size() << DEFAULT << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		//[...]
		l.push_back(0);
		std::list<int>::iterator it2 = l.begin();
		std::list<int>::iterator ite2 = l.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << YELLOW << "원소: " << *it2<< DEFAULT  << std::endl;
			++it2;
		}

	}
	
	system("leaks test");
	return 0;
}