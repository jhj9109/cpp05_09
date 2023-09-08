#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#define ASCII_TREES "               ,@@@@@@@,\n"                  \
                    "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"      \
                    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"    \
                    "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
                    "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"  \
                    "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"   \
                    "   `&%\\ ` /%&'    |.|        \\ '|8'\n"     \
                    "       |o|        | |         | |\n"         \
                    "       |.|        | |         | |\n"         \
                    "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"

// 관목숲 생성 폼
class ShrubberyCreationForm : public AForm
{
private:
    const std::string target_;
    static const int REQUIRED_SIGN_GRADE = 25;
    static const int REQUIRED_EXCUTE_GRADE = 5;

    ShrubberyCreationForm(void);

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    virtual void execute(Bureaucrat const &bureaucrat) const;
    // Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
};

#endif