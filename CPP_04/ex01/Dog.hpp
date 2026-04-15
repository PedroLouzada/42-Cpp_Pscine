/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:51 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:11:52 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;

    public:
        Dog(void);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog(void);

        void makeSound(void) const;
        std::string& getIdea(const int index) const;
};

#endif