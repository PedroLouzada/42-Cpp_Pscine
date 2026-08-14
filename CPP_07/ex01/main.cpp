/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:47:56 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/14 23:05:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

static void multiplyByTwo(int& n)
{
    n *= 2;
}

static void printNum(int& n)
{
    std::cout << n << std::endl;
}

int main(void)
{
    int array[3] = {1, 2, 3};

    ::iter(array, 3, multiplyByTwo);
    ::iter(array, 3, printNum);

    
}