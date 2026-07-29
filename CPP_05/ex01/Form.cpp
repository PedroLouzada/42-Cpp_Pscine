/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:44:38 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 11:44:39 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(std::string name, int sGrade, int eGrade) 
	: _name(name), _signGrade(sGrade), _execGrade(eGrade)
{
	if (sGrade < 1 || eGrade < 1)
		throw Form::GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName(void) const { return (_name); }

bool	Form::getSigned(void) const { return (_signed); }

int Form::getSignGrade(void) const { return(_signGrade); }

int Form::getExecGrade(void) const { return(_execGrade); }

const char* Form::GradeTooHighException::what() const throw() { return("Bureaucrat grade too High!"); }

const char* Form::GradeTooLowException::what() const throw() { return("Bureaucrat grade too Low!"); }

const char* Form::FormAlreadySignedException::what() const throw() { return("This Form was already signed!"); }

std::ostream& operator<<(std::ostream& out, const Form& form)
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

void Form::beSigned(Bureaucrat& bur)
{
	if (_signed)
		throw Form::FormAlreadySignedException();
	else if (bur.getGrade() >= _signGrade)
		throw Form::GradeTooLowException();

	_signed = true;
}