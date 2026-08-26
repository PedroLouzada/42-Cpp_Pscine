/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:36:37 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/26 14:05:29 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== MutantStack basic stack behavior ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;
    std::cout << "=== Iteration ===" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;
    std::cout << "=== Copy to std::stack ===" << std::endl;

    std::stack<int> s(mstack);

    std::cout << "Copied stack size: " << s.size() << std::endl;
    std::cout << "Copied stack top: " << s.top() << std::endl;

    std::cout << std::endl;

    std::cout << "=== Comparison with std::list ===" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "std::list:   ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}