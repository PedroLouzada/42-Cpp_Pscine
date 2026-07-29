/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:45:44 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 11:45:47 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int sGrade, int eGrade) 
	: _name(name), _signGrade(sGrade), _execGrade(eGrade)
{
	if (sGrade < 1 || eGrade < 1)
		throw AForm::GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName(void) const { return (_name); }

bool	AForm::getSigned(void) const { return (_signed); }

int AForm::getSignGrade(void) const { return(_signGrade); }

int AForm::getExecGrade(void) const { return(_execGrade); }

const char* AForm::GradeTooHighException::what() const throw() { return("Bureaucrat grade too High!"); }

const char* AForm::GradeTooLowException::what() const throw() { return("Bureaucrat grade too Low!"); }

const char* AForm::FormAlreadySignedException::what() const throw() { return("This AForm was already signed!"); }

const char* AForm::ExecuteTooLowException::what() const throw() { return("Bureaucrat grade too Low to execute this Form!"); }

const char* AForm::FormNotSignedException::what() const throw() { return("This Form is not signed and connot be executed!"); }

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName();

	if (form.getSigned())
		out << " is Signed";
	else
		out << " is not signed";
	
	out << " and the grades are \"" 
			<< form.getSignGrade() << "\" and \"" << form.getExecGrade() << "\"";

	return (out);
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (_signed)
		throw AForm::FormAlreadySignedException();
	else if (bur.getGrade() >= _signGrade)
		throw AForm::GradeTooLowException();

	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _execGrade)
		throw AForm::ExecuteTooLowException();
	
	if (!_signed)
		throw AForm::FormNotSignedException();

	this->poliExecute();
	std::cout << executor.getName() << " executed " << _name << std::endl;
}