/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:16:55 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/28 20:59:22 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float crossEdge(Point const a, Point const b, Point const p)
{
    Fixed resX;
    Fixed resY;
    Fixed res;
    
    resX = (b.getX() - a.getX()) * (p.getY() - a.getY());
    resY = (b.getY() - a.getY()) * (p.getX() - a.getX());
    res = resX - resY;
    
    return (res.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float edges[3];

    edges[0] = crossEdge(a, b, point);
    edges[1] = crossEdge(b, c, point);
    edges[2] = crossEdge(c, a, point);
    
    if (edges[0] == 0 || edges[1] == 0 || edges[2] == 0)
        return (false);
    
    bool hasNeg = (edges[0] < 0 || edges[1] < 0 || edges[2] < 0);
    bool hasPos = (edges[0] > 0 || edges[1] > 0 || edges[2] > 0);

    return !(hasNeg && hasPos);
}