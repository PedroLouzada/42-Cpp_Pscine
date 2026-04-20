/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:30:15 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 01:37:25 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Linked.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _slots[4];
        t_linked*   _floor;

    public:
        Character(std::string name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif