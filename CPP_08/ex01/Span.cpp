/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:58:17 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/07 16:37:28 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _size(N), _filled(0)
{
    _v.reserve(N);
}

Span::Span(const Span& other) : _v(other._v), _size(other._size), _filled(other._filled) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _v = other._v;
        _size = other._size;
        _filled = other._filled;
    }

    return *this;
}

Span::~Span() {}

void Span::addNumber(const int& n)
{
    if (_filled >= _size)
        throw std::exception();

    _v.push_back(n);
    ++_filled;
}

int Span::shortestSpan() const
{
    if (_filled < 2)
        throw std::exception();

    std::vector<int> sorted(_v);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diff(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

    return (*std::min_element(diff.begin() + 1, diff.end()));
}

int Span::longestSpan() const
{
    return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

void Span::printContainer()
{
    for (size_t i = 0; i < _filled; ++i)
        std::cout << _v[i] << std::endl;
}