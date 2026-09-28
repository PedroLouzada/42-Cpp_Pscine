/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:12:40 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/28 19:54:15 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class Rpn : public std::stack<int>
{
    public:
        // Rpn();
        // Rpn(const Rpn& other);
        // Rpn& operator=(const Rpn& other);
        // ~Rpn();
    
        bool resolve(const std::string& arg);
};

#endif