#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span& other) : _size(other._size) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
        _size = other._size;

    return *this;
}

Span::~Span() {}