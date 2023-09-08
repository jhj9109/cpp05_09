#include "Form.hpp"

#include <iostream>

Form::Form(void) : requiredSignGrade_(), requiredExcuteGrade_() {}

Form::Form(const std::string &name,
           const unsigned int requiredSignGrade,
           const unsigned int requiredExcuteGrade) : name_(name), requiredSignGrade_(requiredSignGrade), requiredExcuteGrade_(requiredExcuteGrade)
{
    std::cout << "Form 생성자 실행 (name: " << name << ", grade: <"
              << requiredSignGrade << ", " << requiredExcuteGrade << ">)" << std::endl;

    if (requiredSignGrade > MIN_GRADE || requiredExcuteGrade > MIN_GRADE)
    {
        throw GradeTooLowException();
    }
    if (requiredSignGrade < MAX_GRADE || requiredExcuteGrade < MAX_GRADE)
    {
        throw GradeTooHighException();
    }
}

Form::Form(const Form &form) : name_(form.name_),
                               requiredSignGrade_(form.requiredSignGrade_),
                               requiredExcuteGrade_(form.requiredExcuteGrade_)
{
    std::cout << "Form 복사 생성자 실행" << std::endl;
}

Form &Form::operator=(const Form &form)
{
    if (this != &form)
    {
        const_cast<std::string &>(name_) = form.name_;
        const_cast<unsigned int &>(requiredSignGrade_) = form.requiredSignGrade_;
        const_cast<unsigned int &>(requiredExcuteGrade_) = form.requiredExcuteGrade_;
        isSigned_ = form.isSigned_;
    }
    return *this;
}

Form::~Form(void)
{
    std::cout << "Form 기본 소멸자 실행" << std::endl;
}

const std::string &Form::getName(void) const
{
    return name_;
}

unsigned int Form::getRequiredSignGrade(void) const
{
    return requiredSignGrade_;
}

unsigned int Form::getRequiredExcuteGrade(void) const
{
    return requiredExcuteGrade_;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    unsigned int targetGrade = bureaucrat.getGrade();
    if (requiredSignGrade_ < targetGrade)
    {
        // PDF에서 명시적으로 요구.
        throw GradeTooLowException();
    }
    isSigned_ = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    return os << form.getName()
              << ", form require grade to sign <" << form.getRequiredSignGrade() << ">"
              << ", form require grade to excute <" << form.getRequiredExcuteGrade() << ">" << std::endl;
}
