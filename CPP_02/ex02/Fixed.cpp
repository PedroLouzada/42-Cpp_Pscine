/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:17:11 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/29 23:53:06 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

const int Fixed::_rawBits = 8;

Fixed::Fixed()
{
    _number = 0;
}

Fixed::Fixed(const int n)
{
    _number = n << _rawBits;
}

Fixed::Fixed(const float f)
{
    _number = roundf(f * (1 << _rawBits));
}

Fixed::Fixed(const Fixed& other)
{
   _number = other._number; 
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_number = other._number;

    return (*this);
}

Fixed::~Fixed(void){ }

float Fixed::toFloat(void) const
{
    return ((float)_number / (1 << _rawBits));
}

int   Fixed::toInt(void) const
{
    return (_number >> _rawBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();

    return (out);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_number);
}

void Fixed::setRawBits(int const raw)
{
    _number = raw;
}   

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_number > other._number);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_number < other._number);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_number >= other._number);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_number <= other._number);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_number == other._number);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_number != other._number);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    res._number = this->_number + other._number;
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    res._number = this->_number - other._number;
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    res._number = (this->_number * other._number) >> _rawBits;
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed res;
    res._number = (this->_number << _rawBits) / other._number;
    return (res);
}

Fixed& Fixed::operator++(void)
{
    this->_number++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    
    this->_number++;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->_number--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    
    this->_number--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
     if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
     if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
     if (a > b)
        return (a);
    return (b);
}