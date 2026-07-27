
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool		_signed;
		const	int _signGrade;
		const	int _execGrade;


	public:
		Form(std::string name, int sGrade, int eGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName(void) const;
		bool 	  getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void  beSigned(Bureaucrat& bur);


		class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

		class FormAlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
