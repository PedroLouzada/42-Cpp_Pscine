/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:55:27 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/16 20:49:12 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A Brain is beeing generated..." << std::endl;
	std::ostringstream str;

	for (int i = 0; i < 100; i++)
	{
		str << "I have " << i + 1 << " ideas!";
		ideas[i] = str.str();
		str.str("");
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "A Brain just contructed a copy" << std::endl;
	
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "The Brain is melting..." << std::endl;
}
