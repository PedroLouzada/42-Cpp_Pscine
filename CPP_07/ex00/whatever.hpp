/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 19:34:27 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/14 22:45:22 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename Swap>
void swap(Swap& a, Swap& b)
{
    Swap c = a;
    a = b;
    b = c;
}

template <typename Min>
Min min(Min& a, Min& b)
{
    if (a < b)
        return a;

    return b;
}

template <typename Max>
Max max(Max& a, Max& b)
{
    if (a > b)
        return a;

    return b;
}

#endif