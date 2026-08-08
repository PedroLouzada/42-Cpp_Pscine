/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:05:22 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/08 15:10:19 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& other) { *this = other; }

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
        *this = other;

    return *this;
}

Serializer::~Serializer(void){}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    
    return (p);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* p = reinterpret_cast<Data*>(raw);
    
    return (p);
}