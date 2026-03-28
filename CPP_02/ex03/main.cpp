/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:16:48 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/28 20:57:38 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    std::cout << "--- Constructors ---" << std::endl;
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 4.0f);
    std::cout << "A: " << a.getX() << ", " << a.getY() << std::endl;
    std::cout << "B: " << b.getX() << ", " << b.getY() << std::endl;
    std::cout << "C: " << c.getX() << ", " << c.getY() << std::endl;

    std::cout << std::endl << "--- BSP Test Inside ---" << std::endl;
    
    Point inside(1.0f, 1.0f);
    std::cout << "Point (1,1) inside triangle: " << std::endl;
    
    if (bsp(a, b, c, inside))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    std::cout << std::endl << "--- BSP Test outside ---" << std::endl;
    Point outside(5.0f, 5.0f);
    std::cout << "Point (5,5) inside triangle: \n";
    if (bsp(a, b, c, outside))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    std::cout << std::endl << "--- BSP on an edge ---" << std::endl;
    Point onEdge(2.0f, 0.0f);
    std::cout << "Point (2,0) on edge: \n";
    if (bsp(a, b, c, onEdge))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    std::cout << std::endl << "--- BSP on a vertex ---" << std::endl;
    Point onVertex(0.0f, 0.0f);
    std::cout << "Point (0,0) on vertex: \n";
    if (bsp(a, b, c, onVertex))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    std::cout << std::endl << "--- BSP negative coordinates ---" << std::endl;
    Point neg(-1.0f, -1.0f);
    std::cout << "Point (-1,-1) inside triangle: \n";
    if (bsp(a, b, c, neg))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    std::cout << std::endl << "--- BSP in the middle ---" << std::endl;
    Point middle(1.0f, 1.0f);
    std::cout << "Point (1,1) in middle of triangle: \n";
    if (bsp(a, b, c, middle))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    return 0;
}