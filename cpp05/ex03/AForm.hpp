#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
private:
    static const unsigned int MAX_GRADE = 1;
    static const unsigned int MIN_GRADE = 150;

    // 아래는 private 선언은 명식적으로 요구
    const std::string name_; // const 명시적으로 요구
    bool isSigned_;
    const unsigned int requiredSignGrade_;   // const 명시적으로 요구
    const unsigned int requiredExcuteGrade_; // const 명시적으로 요구

    AForm(void);

public:
    // orthodox
    AForm(const std::string &name,
          const unsigned int requiredSignGrade,
          const unsigned int requiredExcuteGrade);
    AForm(const AForm &form);
    AForm &operator=(const AForm &form);
    virtual ~AForm(void);

    // getter
    const std::string &getName(void) const;
    unsigned int getRequiredSignGrade(void) const;
    unsigned int getRequiredExcuteGrade(void) const;

    // 동작(?)
    void beSigned(const Bureaucrat &bureaucrat);

    // ex02에서 추가되는 동작
    // sign 여부 & excute 점수 만족하는지, 객체 멤버르 변경 안한다 == const 함수
    virtual void execute(Bureaucrat const &bureaucrat) const = 0;
    void checkExecute(Bureaucrat const &bureaucrat) const;

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

    class NotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif