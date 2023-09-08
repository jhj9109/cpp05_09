#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : grade_() {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : name_(name), grade_(grade)
{
    std::cout << "Bureaucrat 생성자 실행 (name: " << name << ", grade: " << grade << ")" << std::endl;
    if (grade > MIN_GRADE)
    {
        throw GradeTooLowException();
    }
    if (grade < MAX_GRADE)
    {
        throw GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.name_), grade_(bureaucrat.grade_)
{
    std::cout << "Bureaucrat 복사 생성자 실행" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "Bureaucrat 할당 연산자 오버로딩 실행" << std::endl;
    if (this != &bureaucrat)
    {
        const_cast<std::string &>(name_) = bureaucrat.name_;
        grade_ = bureaucrat.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat 기본 소멸자 실행" << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
    return name_;
}

unsigned int Bureaucrat::getGrade(void) const
{
    return grade_;
}

void Bureaucrat::increaseGrade(void)
{
    if (grade_ == MAX_GRADE)
    {
        throw GradeTooHighException();
    }
    grade_--;
}

void Bureaucrat::decreaseGrade(void)
{
    if (grade_ == MIN_GRADE)
    {
        throw GradeTooLowException();
    }
    grade_++;
}

void Bureaucrat::signForm(AForm &form)
{
    // TODO: 이미 사인 여부를 체크할 필요가 있을까?

    try
    {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << *this << " couldn’t sign " << form << " because "
                  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "bureaucrat grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "bureaucrat grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}
