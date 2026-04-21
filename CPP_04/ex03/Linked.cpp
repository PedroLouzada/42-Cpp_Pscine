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

void    s_linked::newLinked(void)
{
    _index = 0;
    _head = NULL;
}

void    s_linked::pushBack(AMateria* m)
{   
    t_linked* newNode = new t_linked();
    newNode->_trash = m;
    newNode->_next = NULL;

    if (_head == NULL)
        _head = newNode;
    else
    {
        t_linked* current = _head;
        while (current->_next != NULL)
            current = current->_next;
        current->_next = newNode;
    }
    _index++;
}

AMateria* s_linked::getTrash(void) { return (_trash); }

int s_linked::getIndex(void) { return(_index); }

s_linked* s_linked::getNext(void) { return(_next); }

s_linked* s_linked::getHead(void) { return (_head); }
