#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Cannot sort less then two numbers" << std::endl;
        return 1;
    }

    PmergeMe obj;

    for (int i = 1; i < ac; ++i)
    {
        if (obj.parse(av[i]))
            return 1;
    }
}