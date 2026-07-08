#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
   
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _grade(other._grade), _name(other._name) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;

    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return("Bureaucrat grade too High!"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return("Bureaucrat grade too Low!"); }

const std::string& Bureaucrat::getName(void) const { return(_name); }

int Bureaucrat::getGrade(void) const { return(_grade); }

void Bureaucrat::incrementGrade(int value)
{
    if ((_grade - value) < 0)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(int value)
{
    if ((_grade + value) < 0)
        throw Bureaucrat::GradeTooLowException();
}