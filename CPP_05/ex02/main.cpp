
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    // try
    // {
    //     Bureaucrat b("Pedro", 1);
    //     ShrubberyCreationForm f("home");
    //     std::cout << f << std::endl;

    //     b.signAForm(f);
    //     f.execute(b);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << "-------------" << std::endl;

    try
    {
        Bureaucrat b("Pedro", 1);
        RobotomyRequestForm f("Bender");
        std::cout << f << std::endl;

        b.signAForm(f);
        f.execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;
}