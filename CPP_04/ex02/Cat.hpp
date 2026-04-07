/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:46 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 21:02:36 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal
{
    private:
        Brain* _brain;

    public:
        Cat(void);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat(void);

        void makeSound(void) const;
};

#endif