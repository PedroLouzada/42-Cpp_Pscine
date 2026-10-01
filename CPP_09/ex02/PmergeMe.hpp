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

        bool parse(const std::string& arg);
};

#endif