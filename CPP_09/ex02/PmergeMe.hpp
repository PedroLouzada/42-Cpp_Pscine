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

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        void insertLosersVector(std::vector<int>& sorted, std::vector<std::pair<int, int> >& pairs,
                bool hasStraggler, int straggler);
        void insertLosersDeque(std::deque<int>& sorted, std::deque<std::pair<int, int> >& pairs,
                bool hasStraggler, int straggler);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        bool parse(const std::string& arg);
        std::vector<int> fordJhonsonVector(std::vector<int>& values);
        std::deque<int> fordJhonsonDeque(std::deque<int>& values);

        const std::vector<int>& getVector() const;
        const std::deque<int>& getDeque() const;

        template <typename Container>
        void print_container(const Container& values)
        {
            typename Container::const_iterator it = values.begin();
            while (it != values.end())
            {
                std::cout << *it;
                if (it + 1 != values.end())
                    std::cout << " ";

                ++it;
            }
            std::cout << std::endl;
        }

};

#endif