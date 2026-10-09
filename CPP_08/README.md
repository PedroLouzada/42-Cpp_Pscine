# CPP08 — Templated Containers, Iterators and Algorithms

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP08** is the ninth module of the C++ series at 42.

This module introduces **templated containers, iterators, and algorithms**, building on the concepts of generic programming introduced in CPP07.

The goal is to understand how containers can store and organize data, how iterators provide a uniform way to access elements, and how algorithms can operate on different data structures without depending on their internal implementation.

The exercises progress from implementing a generic function that searches through containers to creating a container that calculates spans between numbers and extending an existing STL container adapter with iterator support.

---

## 🧠 What I Learned

* Understanding the role of STL containers in organizing and storing data.
* Implementing generic functions that work with different STL containers.
* Using iterators to traverse containers without exposing their internal representation.
* Understanding the relationship between containers, iterators, and algorithms.
* Working with standard containers such as `std::vector`, `std::list`, and `std::deque`.
* Applying STL algorithms to existing containers.
* Using `std::find` to search for elements in a sequence.
* Understanding iterator types and how they determine which operations are available.
* Implementing a `Span` class that stores integers and calculates the shortest and longest spans between elements.
* Managing container capacity and preventing invalid insertions.
* Using exceptions to report invalid operations and insufficient data.
* Implementing a container adapter based on `std::stack` and extending its functionality.
* Understanding how inheritance can extend existing STL containers.
* Accessing the underlying container of an STL container adapter.
* Providing iterator support for a class that normally does not expose iterators.
* Respecting the C++98 standard and the restrictions imposed by the subject.

---

## ⚙️ Exercises

### ex00 — Easy find 🔎

> Searching for a value inside a container using iterators.

Implements the function template:

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value);
```

The function searches for the first occurrence of an integer in a container using `std::find`.

If the value is found, the function returns an iterator pointing to the matching element.

If the value does not exist, the returned iterator equals the container's `end()` iterator.

The function works with compatible STL containers that provide the required iterator interface, such as `std::vector`, `std::list`, and `std::deque`.

The implementation demonstrates how iterators and standard algorithms allow the same function to operate on different container types.

Rather than implementing a separate search function for every container, `easyfind()` delegates the search to a reusable STL algorithm.

This exercise introduces the separation between the data structure and the algorithm used to process its elements.

---

### ex01 — Span 📏

> A container that stores integers and calculates the shortest and longest spans between them.

Implements the `Span` class, which stores a limited number of integers and provides operations for calculating distances between stored values.

The class provides:

* A constructor that specifies the maximum number of integers the container can hold.
* An `addNumber()` member function that inserts an integer.
* A `shortestSpan()` member function that returns the smallest difference between two stored numbers.
* A `longestSpan()` member function that returns the largest difference between two stored numbers.

The container must reject insertions when its capacity has been reached.

Both span-calculation functions must throw an exception if there are fewer than two stored numbers, since a span requires at least two values.

For the shortest span, the values can be sorted or otherwise examined to identify the smallest difference between neighboring values in sorted order.

For the longest span, the difference between the maximum and minimum stored values provides the result.

The exercise also introduces the challenge of inserting multiple values efficiently. A range-based insertion function can allow a large number of integers to be added without repeatedly calling `addNumber()` manually.

Care must be taken to ensure that bulk insertion does not exceed the container's maximum capacity.

This exercise combines STL containers, algorithms, exception handling, and basic complexity considerations.

---

### ex02 — MutantStack 🥞

> Extending `std::stack` to expose iterator functionality.

Implements the `MutantStack` class template, which extends the functionality of `std::stack`.

The standard stack interface provides operations such as:

* `push()` to insert an element.
* `pop()` to remove the top element.
* `top()` to access the top element.
* `size()` to retrieve the number of stored elements.
* `empty()` to check whether the stack contains elements.

However, `std::stack` is a container adapter and does not expose iterators through its public interface.

The goal of `MutantStack` is to make it possible to iterate through its underlying container while preserving the usual stack operations.

A typical declaration is:

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
};
```

The underlying container can be accessed through the protected member `c` inherited from `std::stack`.

The iterator functions expose the beginning and end of that container, allowing the stack's elements to be traversed using ordinary iterator-based loops.

The implementation should also preserve the standard stack interface and support copying the container.

The exercise demonstrates how inheritance can extend an existing STL abstraction without reimplementing its fundamental storage and stack operations.

It also highlights an important distinction: a stack defines a restricted interface for accessing elements, whereas its underlying container may support additional operations such as iteration.

---

## 🖥️ How to Use

Clone the repository and navigate to the desired exercise:

```bash
git clone https://github.com/PedroLouzada/42-Cpp_Pscine.git
cd 42-Cpp_Pscine/CPP_08/ex00
make
./easyfind
```

Executables generated by each exercise depend on the names defined in their respective `Makefile` files.

For example:

```bash
# ex00 — Search for an integer in a container
./easyfind

# ex01 — Calculate the shortest and longest spans
./span

# ex02 — Stack with iterator support
./mutantstack
```

These executable names assume that the corresponding Makefiles use the same names. Check each exercise's Makefile if the generated executable differs.

Each exercise has its own `Makefile` and produces an independent executable.

Useful Makefile targets:

```bash
make        # Compile the exercise
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Rebuild everything
```

---

## 🔍 Rules & Constraints

* All code is compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
* Templates must work with the compatible types and containers required by each exercise.
* `easyfind()` must search for the specified integer using iterators and an appropriate STL algorithm.
* A failed search must be distinguishable by comparing the returned iterator with `end()`.
* `Span` must enforce its maximum storage capacity.
* `shortestSpan()` and `longestSpan()` must throw an exception when fewer than two elements are stored.
* Span calculations must return the correct minimum and maximum differences between stored integers.
* Bulk insertion must respect the container's capacity.
* `MutantStack` must preserve the normal stack interface while exposing iterator functionality.
* The implementation must follow the exercise specifications concerning inheritance, templates, and STL usage.
* Only the STL components permitted by the subject may be used.
* All allocated resources must be managed correctly.
* No memory leaks.

---

## 🚀 Future Improvements

* Expand `easyfind()` tests to cover empty containers, missing values, duplicate values, and different STL container types.
* Test `Span` with negative integers, duplicate values, extreme integer values, and large collections.
* Improve the efficiency of `Span` calculations for large datasets.
* Test capacity limits, empty spans, single-element spans, and bulk insertion failures.
* Add tests for copying and assigning `Span` objects.
* Verify that `MutantStack` supports both mutable and const iteration.
* Test `MutantStack` with different underlying container types where supported.
* Compare the behavior of `MutantStack` with a regular `std::stack`.
* Explore reverse iterators and additional iterator operations where compatible with the underlying container.
* Revisit these implementations using modern C++ features such as range-based loops, type inference, and move semantics.

---

## 💡 Final Thoughts

CPP08 moves from writing generic functions and classes to understanding how generic components work together.

The first exercise demonstrates that a standard algorithm can search different containers through a shared iterator interface.

The second combines container management and algorithms to calculate spans between stored values while respecting capacity and error conditions.

The final exercise extends a familiar STL abstraction to provide additional functionality without rebuilding its underlying data structure.

Together, these exercises show how containers, iterators, and algorithms form the foundation of reusable and flexible C++ programming.

They also demonstrate that understanding the interfaces and guarantees of the STL is just as important as knowing how to use its individual components.

---

## 📬 Contact

Feel free to reach out:

[GitHub](https://github.com/PedroLouzada)
