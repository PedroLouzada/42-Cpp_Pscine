/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:45:31 by pbongiov          #+#    #+#             */
/*   Updated: 2026/08/26 14:13:39 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack(other) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);

    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return (this->c.begin()); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return (this->c.end()); }