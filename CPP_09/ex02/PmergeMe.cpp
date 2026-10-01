#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _list(other._list), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _list = other._list;
        _deque = other._deque;
    }

    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parse(const std::string& arg)
{
    
}