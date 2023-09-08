#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
private:
    static const unsigned int MAX_GRADE = 1;
    static const unsigned int MIN_GRADE = 150;

    // 아래는 private 선언은 명식적으로 요구
    const std::string name_; // const 명시적으로 요구
    bool isSigned_;
    const unsigned int requiredSignGrade_;   // const 명시적으로 요구
    const unsigned int requiredExcuteGrade_; // const 명시적으로 요구

    Form(void);

public:
    // orthodox
    Form(const std::string &name,
         const unsigned int requiredSignGrade,
         const unsigned int requiredExcuteGrade);
    Form(const Form &form);
    Form &operator=(const Form &form);
    virtual ~Form(void);

    // getter
    const std::string &getName(void) const;
    unsigned int getRequiredSignGrade(void) const;
    unsigned int getRequiredExcuteGrade(void) const;

    // 동작(?)
    void beSigned(const Bureaucrat &bureaucrat);

    // 오류
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif