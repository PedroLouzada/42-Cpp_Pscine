#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << std::endl << "=== constructor with size ===" << std::endl;
    Array<int> ar(5);
    std::cout << "ar.size() = " << ar.size() << std::endl;
    std::cout << "default values: ";
    for (unsigned int i = 0; i < ar.size(); ++i)
        std::cout << ar[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl << "=== operator[] write / read ===" << std::endl;
    for (unsigned int i = 0; i < ar.size(); ++i)
        ar[i] = i * 10;
    std::cout << "after writing: ";
    for (unsigned int i = 0; i < ar.size(); ++i)
        std::cout << ar[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl << "=== copy constructor (deep copy) ===" << std::endl;
    Array<int> copy(ar);
    copy[0] = 999;
    std::cout << "ar[0] = " << ar[0] << " (should be unchanged)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << std::endl;
    std::cout << "copy.size() = " << copy.size() << std::endl;

    std::cout << std::endl << "=== operator= (deep copy) ===" << std::endl;
    Array<int> assigned;
    assigned = ar;
    assigned[1] = 777;
    std::cout << "ar[1] = " << ar[1] << " (should be unchanged)" << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;
    std::cout << "assigned.size() = " << assigned.size() << std::endl;

    std::cout << std::endl << "=== const Array operator[] ===" << std::endl;
    const Array<int> constAr(ar);
    std::cout << "constAr[2] = " << constAr[2] << std::endl;

    std::cout << std::endl << "=== Array of std::string ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "foo";
    strArr[1] = "bar";
    strArr[2] = "baz";
    for (unsigned int i = 0; i < strArr.size(); ++i)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl << "=== out_of_range exception ===" << std::endl;
    try
    {
        std::cout << ar[ar.size()] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << ar[-1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}
