/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:44:56 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 11:44:59 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool			  _signed;
		const	int 	  _signGrade;
		const	int 	  _execGrade;
		virtual void poliExecute(void) const = 0;


	public:
		AForm(std::string name, int sGrade, int eGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

		const std::string& getName(void) const;
		bool 	  		   getSigned(void) const;
		int 			   getSignGrade(void) const;
		int 			   getExecGrade(void) const;

		virtual void  beSigned(Bureaucrat& bur);
		
		void execute(Bureaucrat const & executor) const;

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

		class ExecuteTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw(); 
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
