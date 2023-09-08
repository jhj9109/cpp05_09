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
        생성자 & exception
    */
    try
    {
        std::cout << YELLOW << std::endl;
        Form temp1 = Form("sign grade MAX 초과", 0, 75);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << YELLOW << std::endl;
        Form temp1 = Form("sign grade MIN 초과", 151, 75);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << YELLOW << std::endl;
        Form temp3 = Form("Excute grade MAX 초과", 75, 0);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << YELLOW << std::endl;
        Form temp3 = Form("Excute grade MIN 초과", 75, 151);
    }
    catch (std::exception &e)
    {
        std::cout << RED << std::endl;
        std::cerr << e.what() << std::endl;
    }

    std::cout << WHITE << std::endl;
    Form form = Form("텐", 10, 100);
    Bureaucrat a = Bureaucrat("아무개", 5);
    Bureaucrat b = Bureaucrat("홍길동", 15);

    std::cout << BLUE << std::endl;
    std::cout << form << std::endl;

    std::cout << GREEN << std::endl;
    a.signForm(form);

    std::cout << CYAN << std::endl;
    b.signForm(form);

    std::cout << MAGENTA << std::endl;

    system("leaks test");
}