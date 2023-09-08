#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern(void);
    Intern(const Intern &intern);
    virtual ~Intern(void);
    Intern &operator=(const Intern &intern);

    AForm *makeForm(const std::string &name, const std::string &target) const;

    // exception
    class IllegalInputException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif