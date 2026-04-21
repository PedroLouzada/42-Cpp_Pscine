/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linked.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:24:25 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/21 15:24:28 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_HPP
# define LINKED_HPP

# include "AMateria.hpp"

typedef struct s_linked
{
    private:
        static int _index;
        AMateria*  _trash;
        s_linked*  _head;
        s_linked*  _next;

    public:
        void        pushBack(AMateria* m);
        AMateria*   getTrash();
        static int  getIndex();
} t_linked;

#endif