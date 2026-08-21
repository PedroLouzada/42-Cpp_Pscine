#include "Span.hpp"
#include <list>
#include <cstdlib>
#include <iostream>

static void testBasicAddNumber()
{
    std::cout << "--- basic addNumber ---" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printContainer();

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

static void testAddNumberOverflow()
{
    std::cout << "\n--- addNumber overflow ---" << std::endl;

    Span sp(2);
    try
    {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "KO: should have thrown" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "OK: caught overflow exception" << std::endl;
    }
}

static void testAddRangeOverflow()
{
    std::cout << "\n--- addRange overflow ---" << std::endl;

    std::vector<int> nums;
    for (int i = 0; i < 5; ++i)
        nums.push_back(i);

    Span sp(3);
    try
    {
        sp.addRange(nums.begin(), nums.end());
        std::cout << "KO: should have thrown" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "OK: caught addRange overflow exception" << std::endl;
    }
}

static void testLargeSpan()
{
    std::cout << "\n--- stress test: 10000 numbers ---" << std::endl;

    Span big(10000);
    std::srand(42);
    for (int i = 0; i < 10000; ++i)
        big.addNumber(std::rand());

    std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << big.longestSpan() << std::endl;
}

int main()
{
    testBasicAddNumber();
    testAddNumberOverflow();
    testAddRangeOverflow();
    testLargeSpan();

    return 0;
}
