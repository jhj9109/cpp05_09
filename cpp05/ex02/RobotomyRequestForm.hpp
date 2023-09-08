#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

// 로봇화
class RobotomyRequestForm : public AForm
{
private:
    const std::string target_;
    static const int REQUIRED_SIGN_GRADE = 72;
    static const int REQUIRED_EXCUTE_GRADE = 45;
    RobotomyRequestForm(void);

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &form);
    virtual ~RobotomyRequestForm(void);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    virtual void execute(Bureaucrat const &bureaucrat) const;
    // Makes some drilling noises.
    // Then, informs that <target> has been robotomized successfully 50 % of the time.
    // Otherwise, informs that the robotomy failed.
};
#endif