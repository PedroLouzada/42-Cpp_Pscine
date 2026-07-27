
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    try
    {
        AForm A1("A1", 1, 1);
        std::cout << A1 << std::endl;
        AForm A2("A2", 150, 150);
        std::cout << A2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        AForm A1("A1", 0, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-------------" << std::endl;

    try
    {
        AForm A1("A1", 151, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        AForm A1("A1", 10, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    try
    {
        AForm A1("A1", 10, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    Bureaucrat Denise("Denise", 15);

    try
    {
        AForm A1("Cheat", 10, 10);

        Denise.signAForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-------------" << std::endl;

    AForm A1("Cheat", 20, 10);

    try
    {
        Denise.signAForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << A1 << std::endl;
        Denise.signAForm(A1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "-------------" << std::endl;

    AForm A2("A2", 20, 10);
    Denise.signAForm(A2);

    AForm A3(A2);

    std::cout << A3 << std::endl;

    std::cout << "-------------" << std::endl;
}