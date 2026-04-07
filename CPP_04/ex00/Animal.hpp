/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:39 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:29:00 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal(void);

        virtual void makeSound(void) const;
        const std::string getType(void) const;
};

#endif