/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08                                        #+#    #+#   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double getTime(clock_t start, clock_t end)
{
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

    return (time);
}


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "No numbers to sort" << std::endl;
        return 1;
    }

    PmergeMe input;
    for (int i = 1; i < ac; ++i)
    {
        if (input.parse(av[i]))
            return 1;
    }
   
    std::cout << "Before: ";
    input.print_container(input.getVector());

    std::vector<int> vec = input.getVector();
    std::deque<int> deq = input.getDeque();

    std::clock_t startVec = std::clock();
    vec = input.fordJhonsonVector(vec);
    std::clock_t endVec = std::clock();

    double vecTime = getTime(startVec, endVec);

    std::clock_t startDeq = std::clock();
    deq = input.fordJhonsonDeque(deq);
    std::clock_t endDeq = std::clock();

    double deqTime = getTime(startDeq, endDeq);

    std::cout << "After: ";
    input.print_container(vec);

    std::cout << std::fixed << std::setprecision(3)
              << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime 
              << " us" << std::endl;

    std::cout << std::fixed << std::setprecision(3)
              << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << deqTime
              << " us" << std::endl;
}
