#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#define PRESIDENT_NAME "Zaphod Beeblebrox"

// 대통령사면
class PresidentialPardonForm : public AForm
{
private:
    const std::string target_;
    static const int REQUIRED_SIGN_GRADE = 25;
    static const int REQUIRED_EXCUTE_GRADE = 5;

    PresidentialPardonForm(void);

public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    virtual ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    virtual void execute(Bureaucrat const &bureaucrat) const;
    // Informs that <target> has been pardoned by Zaphod Beeblebrox.
    // 자포드 비블브락스는 더글러스 애덤스가 쓴 코믹 과학 소설인 《은하수를 여행하는 히치하이커를 위한 안내서》에 나오는 가상의 등장인물이다.
};

#endif