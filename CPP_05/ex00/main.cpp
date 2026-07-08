#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat inRange("In Range", 100);
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat highRange("High Range", 0);
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat lowRange("Low Range", 151);
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}