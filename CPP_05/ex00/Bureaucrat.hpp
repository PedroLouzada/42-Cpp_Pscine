#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        int _grade;
        const std::string _name;

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName(void) const;
        int getGrade(void) const;
        void incrementGrade(int value);
        void decrementGrade(int value);

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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureau);

#endif