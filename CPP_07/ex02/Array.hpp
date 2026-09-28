/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:57:03 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/25 17:57:04 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array
{
    private:
        T* _value;
        unsigned int _size;

    public:
        Array(void);
        Array(const unsigned int& n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array(void);

        T& operator[](const int& n);
        const T& operator[](const int& n) const;

        const unsigned int& size(void) const;
};

# include "Array.tpp"

#endif