/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:58:05 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/25 17:58:06 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
static void test(const std::string& name, const T& container, int n)
{
    std::cout << "-- " << name << ", looking for " << n << " -- ";
    try
    {
        typename T::const_iterator it = easyFind(container, n);
        std::cout << "found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "not found (caught: " << e.what() << ")" << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i * 10);

    std::list<int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i * 100);

    std::deque<int> dq;
    for (int i = 1; i <= 5; i++)
        dq.push_back(i * 1000);

    test("vector", vec, 30);
    test("vector", vec, 999);

    test("list", lst, 300);
    test("list", lst, 999);
    
    test("deque", dq, 3000);
    test("deque", dq, 999);

    return 0;
}
