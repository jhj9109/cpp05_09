#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
    std::cout << GREEN << std::endl;
    Bureaucrat hyeonjan = Bureaucrat("hyeonjan", 1);
    Intern someRandomIntern;

    std::cout << BLUE << std::endl;
    AForm *prf = someRandomIntern.makeForm("presidential pardon", "target1");
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "target2");
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "target3");

    std::cout << YELLOW << std::endl;
    hyeonjan.signForm(*prf);
    hyeonjan.executeForm(*prf);

    std::cout << RED << std::endl;
    hyeonjan.signForm(*rrf);
    hyeonjan.executeForm(*rrf);

    std::cout << MAGENTA << std::endl;
    hyeonjan.signForm(*scf);
    hyeonjan.executeForm(*scf);

    delete prf;
    delete rrf;
    delete scf;

    std::cout << CYAN << std::endl;
    AForm *failed = someRandomIntern.makeForm("good", "target");
    std::cout << "MakeForm with Illegal Form name: " << failed << std::endl;

    std::cout << WHITE << std::endl;
    system("leaks test");
}