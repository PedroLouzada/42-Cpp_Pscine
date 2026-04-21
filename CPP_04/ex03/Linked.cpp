/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linked.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:24:02 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/21 15:24:05 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Linked.hpp"

int s_linked::_index = 0;

void    s_linked::pushBack(AMateria* m)
{
    if (_index == 0)
    {
        _trash = m;
        _head = this;
    }
    else
    {
        t_linked* current = _head;
        for(int i = 0; i < _index; i++)
            current = current->_next;
        current->_next = this;
    }
    _next = NULL;
    _index++;
}

AMateria* s_linked::getTrash(void) { return (_trash); }

int s_linked::getIndex(void) { return(_index); }