#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("temp", 150, 150) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", REQUIRED_SIGN_GRADE, REQUIRED_EXCUTE_GRADE), target_(target)
{
    std::cout << "ShrubberyCreationForm 생성자 실행 (target: " << target << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : AForm(form), target_(form.target_)
{
    std::cout << "ShrubberyCreationForm 복사 생성자 실행" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    this->AForm::operator=(form);
    const_cast<std::string &>(target_) = form.target_;
    std::cout << "ShrubberyCreationForm 할당 연산자 오버로딩" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm 기본 소멸자 실행" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    try
    {
        checkExecute(bureaucrat);
        std::cout << " * A tree has been planted on " << target_ << ". * " << std::endl;
        std::string fileName = target_ + "_shrubbery";
        std::ofstream ofs(fileName, std::ios::out);
        ofs << ASCII_TREES << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Fail to excute, because " << e.what() << std::endl;
    }
}
