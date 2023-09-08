#include "AForm.hpp"

#include <iostream>

AForm::AForm(void) : requiredSignGrade_(), requiredExcuteGrade_() {}

AForm::AForm(const std::string &name,
             const unsigned int requiredSignGrade,
             const unsigned int requiredExcuteGrade) : name_(name), requiredSignGrade_(requiredSignGrade), requiredExcuteGrade_(requiredExcuteGrade)
{
    std::cout << "AForm 생성자 실행 (name: " << name << ", grade: <"
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

AForm::AForm(const AForm &form) : name_(form.name_),
                                  requiredSignGrade_(form.requiredSignGrade_),
                                  requiredExcuteGrade_(form.requiredExcuteGrade_)
{
    std::cout << "AForm 복사 생성자 실행" << std::endl;
}

AForm &AForm::operator=(const AForm &form)
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

AForm::~AForm(void)
{
    std::cout << "AForm 기본 소멸자 실행" << std::endl;
}

const std::string &AForm::getName(void) const
{
    return name_;
}

unsigned int AForm::getRequiredSignGrade(void) const
{
    return requiredSignGrade_;
}

unsigned int AForm::getRequiredExcuteGrade(void) const
{
    return requiredExcuteGrade_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    unsigned int targetGrade = bureaucrat.getGrade();
    if (requiredSignGrade_ < targetGrade)
    {
        // PDF에서 명시적으로 요구.
        throw GradeTooLowException();
    }
    isSigned_ = true;
}

void AForm::checkExecute(Bureaucrat const &bureaucrat) const
{
    if (!isSigned_)
    {
        throw NotSignedException();
    }
    unsigned int targetGrade = bureaucrat.getGrade();
    if (requiredExcuteGrade_ < targetGrade)
    {
        throw GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    return os << form.getName()
              << ", form require grade to sign <" << form.getRequiredSignGrade() << ">"
              << ", form require grade to excute <" << form.getRequiredExcuteGrade() << ">" << std::endl;
}
