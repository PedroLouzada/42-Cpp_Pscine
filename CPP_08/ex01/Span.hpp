#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
    private:
        unsigned int _size;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(const int& n);
        void addRange();
        int& shortestSpan() const;
        int& longestSpan() const;

};

#endif