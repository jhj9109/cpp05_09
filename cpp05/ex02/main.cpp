#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    // std::cout << YELLOW << std::endl;
    // try
    // {
    //     AForm a = AForm();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << RED << std::endl;
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << YELLOW << std::endl;
    // try
    // {
    //     AForm a = AForm("yaha", 75, 75);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << RED << std::endl;
    //     std::cerr << e.what() << std::endl;
    // }

    std::cout << DEFAULT << std::endl;
    Bureaucrat one = Bureaucrat("one", 1);
    PresidentialPardonForm ppf = PresidentialPardonForm("target1");
    RobotomyRequestForm rrf = RobotomyRequestForm("target2");
    ShrubberyCreationForm scf = ShrubberyCreationForm("target3");

    Bureaucrat two = Bureaucrat("two", 150);
    std::cout << YELLOW << std::endl;
    two.signForm(ppf);
    two.executeForm(ppf);

    std::cout << CYAN << std::endl;
    two.signForm(rrf);
    two.executeForm(rrf);

    std::cout << YELLOW << std::endl;
    two.signForm(scf);
    two.executeForm(scf);

    /* 동작 테스트 */

    std::cout << BLUE << std::endl;
    one.signForm(ppf);
    one.executeForm(ppf);

    std::cout << RED << std::endl;
    one.signForm(rrf);
    one.executeForm(rrf);

    std::cout << BLUE << std::endl;
    one.signForm(scf);
    one.executeForm(scf);

    /* 동작 테스트 끝*/

    std::cout << YELLOW << std::endl;
    two.signForm(ppf);
    two.executeForm(ppf);

    std::cout << CYAN << std::endl;
    two.signForm(rrf);
    two.executeForm(rrf);

    std::cout << YELLOW << std::endl;
    two.signForm(scf);
    two.executeForm(scf);

    std::cout << MAGENTA << std::endl;
}