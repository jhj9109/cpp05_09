#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("temp", 150, 150) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", REQUIRED_SIGN_GRADE, REQUIRED_EXCUTE_GRADE), target_(target)
{
    std::cout << "PresidentialPardonForm 생성자 실행 (target: " << target << ")" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
    : AForm(form), target_(form.target_)
{
    std::cout << "PresidentialPardonForm 복사 생성자 실행" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
    this->AForm::operator=(form);
    const_cast<std::string &>(target_) = form.target_;
    std::cout << "PresidentialPardonForm 할당 연산자 오버로딩" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm 기본 소멸자 실행" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    try
    {
        checkExecute(bureaucrat);
        std::cout << target_ << " has been pardoned by " << PRESIDENT_NAME << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Fail to excute, because " << e.what() << std::endl;
    }
}