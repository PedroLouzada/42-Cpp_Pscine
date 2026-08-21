#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <numeric>
# include <iostream>
# include <algorithm>
# include <iterator>

class Span
{
    private:
        std::vector<int> _v;
        unsigned int _size;
        size_t _filled;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(const int& n);
        void printContainer();

        int shortestSpan() const;
        int longestSpan() const;

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end)
        {
            size_t count = static_cast<size_t>(std::distance(begin, end));

            if (_filled + count > _size)
                throw std::exception();

            _v.insert(_v.end(), begin, end);
            _filled += count;
        }
};

#endif