/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:44:40 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/23 12:20:29 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
        
    public:
        void announce(void);
        
        Zombie(std::string name);
        ~Zombie();
        
};
    
void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif