/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:48:03 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/14 23:03:24 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Iter, typename T>
void iter(Iter* array, const size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

#endif