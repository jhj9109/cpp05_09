#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern 기본 생성자 실행" << std::endl;
}

Intern::Intern(const Intern &intern)
{
    std::cout << "Intern 복사 생성자 실행" << std::endl;
    (void)intern;
}

Intern::~Intern(void)
{
    std::cout << "Intern 기본 소멸자 실행" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
    std::cout << "Intern 할당 연산자 오버로딩 실행" << std::endl;
    (void)intern;
    return *this;
}

static int getFormType(const std::string &name)
{
    static std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for (int i = 0; i < 3; i++)
    {
        if (!name.compare(formNames[i]))
        {
            return i;
        }
    }
    throw Intern::IllegalInputException();
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    static std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    try
    {
        int formType = getFormType(name);
        AForm *form;
        switch (formType)
        {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            form = NULL; // 도달 하면 안 됨.
            break;
        }
        std::cout << "Intern creates " << *form << std::endl;
        return form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return NULL;
    }
}

const char *Intern::IllegalInputException::what() const throw()
{
    return "Form name is Illegal Input.";
}
