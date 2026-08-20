#include "Array.hpp"
#include <cstddef>
#include <stdexcept>

template <class T>
Array<T>::Array(void)
{
    _value = NULL;
    _size = 0;
}

template <class T>
Array<T>::Array(const unsigned int& n)
{
    _value = new T[n]();
    _size = n;
}

template <class T>
Array<T>::Array(const Array& other) : _value(NULL), _size(0)
{
    *this = other;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        if (_value != NULL)
            delete[](_value);

        _size = other._size;
        _value = new T[_size];

        for (size_t i = 0; i < _size; ++i)
            _value[i] = other._value[i];
    }

    return *this;
}

template <class T>
Array<T>::~Array(void)
{
    if (_value != NULL)
        delete[](_value);
}

template <class T>
T& Array<T>::operator[](const int& n)
{
    if (n < 0 || static_cast<unsigned int>(n) >= _size)
        throw std::out_of_range("Index out of bounds");

    return (_value[n]);
}

template <class T>
const T& Array<T>::operator[](const int& n) const
{
    if (n < 0 || static_cast<unsigned int>(n) >= _size)
        throw std::out_of_range("Index out of bounds");

    return (_value[n]);
}

template <class T>
const unsigned int& Array<T>::size(void) const { return(_size); }