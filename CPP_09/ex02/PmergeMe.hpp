/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:36:46 by pbongiov          #+#    #+#             */
/*   Updated: 2026/10/01 20:00:11 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMEGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <queue>

class PmergeMe
{
    private:
        std::list<int> _list;
        std::deque<int> _deque;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        bool parse(std::string& arg);
};

#endif