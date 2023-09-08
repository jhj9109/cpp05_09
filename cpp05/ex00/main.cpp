#include "Bureaucrat.hpp"

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

int main(void)
{
    /*
        increaseGrade();
        GradeTooHighException
    */
    std::cout << BLUE << std::endl;
    Bureaucrat tom = Bureaucrat("tom", 2);
    try
    {
        tom.increaseGrade(); // 2 -> 1
        std::cout << "tom.increaseGrade() 호출후: " << tom << std::endl;
        tom.increaseGrade(); // 1 -> 에러
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }

    /*
        decreaseGrade();
        GradeTooLowException
    */
    std::cout << GREEN << std::endl;
    Bureaucrat bob = Bureaucrat("bob", 149);
    try
    {
        bob.decreaseGrade(); // 2 -> 1
        std::cout << "bob.decreaseGrade() 호출후: " << bob << std::endl;
        bob.decreaseGrade(); // 1 -> 에러
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }

    /*
        생성자 & exception
    */
    std::cout << YELLOW << std::endl;
    try
    {
        Bureaucrat temp1 = Bureaucrat("temp1", 0);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }
    std::cout << YELLOW << std::endl;
    try
    {
        Bureaucrat temp2 = Bureaucrat("temp2", 151);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }

    std::cout << DEFAULT << std::endl;
    system("leaks test");
}