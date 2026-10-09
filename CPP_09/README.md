# CPP09 — STL

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP09** is the tenth module of the C++ series at 42.

This module introduces the **Standard Template Library (STL)** through practical exercises involving data processing, container selection, and algorithmic problem-solving.

The goal is to understand how to choose appropriate data structures for different problems, process large amounts of data efficiently, and use the STL to simplify common operations.

The exercises cover three distinct challenges: identifying the exchange rate of a given date, implementing a sorting algorithm known as the Ford–Johnson algorithm, and calculating the value of a mathematical expression written in Reverse Polish Notation (RPN).

Each exercise focuses on a different aspect of C++ programming, from working with associative containers and parsing input files to implementing sorting algorithms and evaluating expressions with a stack.

One important aspect of this module is that **the implementation must follow the restrictions imposed by the subject**. In particular, the sorting algorithm in `ex02` must use the permitted STL containers without relying on templates or generic functions to share the implementation between different container types. As a result, some code is repeated intentionally.

---

## 🧠 What I Learned

* Working with STL containers to solve practical problems.
* Choosing appropriate data structures based on their properties and intended use.
* Using `std::map` to store and retrieve values associated with specific keys.
* Parsing dates, validating input, and handling malformed data.
* Processing CSV files and matching records by date.
* Using `std::lower_bound` to find the closest preceding date in an ordered associative container.
* Understanding the importance of input validation and error handling.
* Implementing the Ford–Johnson merge-insertion sorting algorithm.
* Understanding the role of insertion order and comparison efficiency in sorting algorithms.
* Using `std::vector` and `std::deque` to store and manipulate sequences of integers.
* Comparing the behavior and performance of different STL containers.
* Understanding why container operations can have different costs depending on the underlying data structure.
* Evaluating Reverse Polish Notation expressions using a stack.
* Handling arithmetic operators, operand order, and invalid expressions.
* Detecting division by zero and integer overflow where required by the implementation.
* Respecting the C++98 standard and the restrictions imposed by the subject.
* Understanding that code reuse must sometimes be balanced against explicit implementation constraints.

---

## ⚙️ Exercises

### ex00 — Bitcoin Exchange ₿

> Calculating the value of Bitcoin on a given date using historical exchange-rate data.

This exercise implements a program that reads dates and Bitcoin amounts from an input file and calculates their equivalent values using historical exchange rates.

The program uses a CSV database containing dates and corresponding Bitcoin prices.

A typical database entry looks like this:

```text
date,exchange_rate
2009-01-02,0
2010-07-18,0.05
2011-01-01,0.30
```

The actual database supplied with the project contains the data used by the program.

The input file contains entries with dates and values that must be validated before calculating their equivalent prices.

A typical input looks like this:

```text
date | value
2011-01-03 | 3
2011-01-09 | 1
2012-01-11 | 2
```

For each valid entry, the program retrieves the appropriate exchange rate and multiplies it by the supplied Bitcoin amount.

The main functionality includes:

* Reading and parsing the historical exchange-rate database.
* Storing exchange rates in an associative container.
* Reading and parsing the user's input file.
* Validating dates and numeric values.
* Finding the exchange rate associated with a given date.
* Using the closest preceding available date when an exact match does not exist.
* Multiplying the exchange rate by the requested amount.
* Handling invalid input and reporting meaningful errors.

The `std::map` container is particularly useful because its keys are maintained in sorted order.

This allows the program to use `lower_bound()` to locate the first date that is not less than the requested date. If there is no exact match, the iterator can be adjusted to retrieve the preceding available date, provided that such a date exists.

Special cases must be handled carefully, including dates earlier than the first database entry, malformed dates, negative values, values exceeding the permitted maximum, and invalid database records.

This exercise demonstrates how associative containers can simplify date-based lookups and how careful validation is essential when processing external data.

---

### ex01 — Reverse Polish Notation 🧮

> Evaluating mathematical expressions using Reverse Polish Notation and a stack.

This exercise implements a program that evaluates mathematical expressions written in Reverse Polish Notation (RPN).

Unlike conventional mathematical notation, RPN places operators after their operands.

For example, the expression:

```text
8 9 * 9 - 9 - 9 - 4 - 1 +
```

represents a sequence of arithmetic operations evaluated from left to right.

The program uses a stack to store operands and intermediate results.

When a number is encountered, it is pushed onto the stack.

When an operator is encountered, the program retrieves the required operands, performs the operation, and pushes the result back onto the stack.

A simplified example:

```text
Input:  3 4 +
Stack:  [3]
Stack:  [3, 4]
Apply +: 3 + 4 = 7
Result: 7
```

The implementation supports the arithmetic operators required by the subject:

* `+` — Addition.
* `-` — Subtraction.
* `*` — Multiplication.
* `/` — Division.

The order of operands is particularly important for subtraction and division.

For example:

```text
8 2 -
```

must evaluate to:

```text
8 - 2 = 6
```

The implementation must also detect invalid expressions, including:

* Missing operands.
* Invalid characters or tokens.
* Operators appearing before enough operands are available.
* Expressions containing too many operands.
* Division by zero.

At the end of evaluation, a valid expression must leave exactly one result on the stack.

This exercise demonstrates how a stack can be used to evaluate expressions without needing to implement a conventional operator-precedence parser.

It also reinforces the importance of input validation, arithmetic correctness, and handling invalid operations.

---

### ex02 — PmergeMe 🔀

> Implementing the Ford–Johnson merge-insertion sorting algorithm using different STL containers.

This exercise implements the **Ford–Johnson algorithm**, also known as merge-insertion sort, to sort a sequence of positive integers.

The program receives a sequence of integers as command-line arguments, validates the input, sorts the sequence, and displays the original and sorted values along with the execution time.

The implementation must use the STL containers permitted by the subject, typically:

* `std::vector`
* `std::deque`

The objective is to implement the required sorting algorithm while demonstrating the differences between container implementations and measuring their performance.

#### The Ford–Johnson Algorithm

The Ford–Johnson algorithm is a comparison-based sorting algorithm designed to minimize the number of comparisons needed to sort a sequence.

Its general approach consists of several stages:

1. **Pairing elements:** Divide the input into pairs and compare the elements of each pair.
2. **Ordering pairs:** Place the larger element of each pair in the main sequence and retain the relationship with its smaller partner.
3. **Recursively sorting:** Sort the larger elements using the same general approach.
4. **Building the main chain:** Start with the sorted larger elements and an initial smaller element.
5. **Inserting pending elements:** Insert the remaining smaller elements into the main chain using binary insertion.
6. **Following the insertion order:** Use the prescribed insertion sequence, based on Jacobsthal numbers, to control the order in which pending elements are inserted.
7. **Handling an unpaired element:** If the input contains an odd number of elements, insert the remaining unpaired element at the appropriate stage.

The insertion process is designed to reduce the number of comparisons required to sort the sequence.

Implementing the algorithm correctly requires careful management of element relationships and insertion positions.

#### Container Implementations

The program implements the sorting process for both `std::vector` and `std::deque`.

Although both containers can store the same sequence of integers, their underlying structures differ.

`std::vector` stores elements contiguously in memory and provides efficient random access. Inserting elements in the middle, however, can require shifting existing elements.

`std::deque` supports efficient insertion and removal at both ends and provides random access, but its storage is not necessarily contiguous.

These differences can affect the performance of the algorithm's insertion operations.

The program measures the execution time for each container separately, allowing the results to be compared using the same input sequence.

#### An Important Implementation Constraint

**In my `ex02` implementation, I could not use templates or generic functions to share the sorting logic between `std::vector` and `std::deque`, so some of the code is repeated intentionally.**

Normally, templates would be a natural solution for implementing the Ford–Johnson algorithm once and reusing it with different container types.

However, the implementation follows the restrictions imposed by the subject, which prevent this approach in the relevant exercise.

As a result, the sorting logic must be implemented separately for each container.

This means that parts of the code responsible for pairing elements, recursively sorting sequences, managing pending elements, and performing binary insertion may appear more than once.

Although this repetition would normally be a candidate for refactoring, removing it through templates or generic functions would violate the applicable constraints.

The repeated code is therefore a consequence of the exercise's requirements rather than an attempt to introduce unnecessary duplication.

#### Input Validation

The program must also validate its command-line arguments.

Typical requirements include:

* Accepting positive integer values.
* Rejecting negative numbers.
* Rejecting non-numeric input.
* Rejecting zero if the subject requires strictly positive integers.
* Detecting integer overflow during conversion.
* Handling invalid or missing arguments appropriately.

The program must display the input sequence, the sorted sequence, and the execution time for each container.

This exercise combines algorithm design, STL container usage, input validation, performance measurement, and careful adherence to implementation constraints.

---

## 🖥️ How to Use

Clone the repository and navigate to the desired exercise:

```bash
git clone https://github.com/PedroLouzada/42-Cpp_Pscine.git
cd 42-Cpp_Pscine/CPP_09
```

Each exercise has its own directory and `Makefile`.

### ex00 — Bitcoin Exchange

```bash
cd ex00
make
./btc input.txt
```

The program expects an input file containing dates and Bitcoin amounts in the format specified by the subject.

The historical exchange-rate database must also be available at the path expected by the implementation.

### ex01 — Reverse Polish Notation

```bash
cd ../ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

The expression is passed as a command-line argument and evaluated using a stack.

### ex02 — PmergeMe

```bash
cd ../ex02
make
./PmergeMe 3 5 9 7 4
```

The program sorts the supplied sequence using the Ford–Johnson algorithm and displays the results and execution times for the supported containers.

The executable names shown above are examples and should match the names configured in each exercise's `Makefile`.

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
* The implementation must follow the restrictions defined by the CPP09 subject.
* Only the permitted STL containers and algorithms may be used.
* Input must be validated before processing.
* Invalid input must be handled without undefined behavior.
* `ex00` must process dates and exchange rates correctly.
* `ex00` must use the appropriate historical exchange rate for each valid date.
* `ex00` must reject invalid dates and values outside the permitted range.
* `ex01` must evaluate valid Reverse Polish Notation expressions correctly.
* `ex01` must detect invalid expressions and division by zero.
* `ex02` must implement the Ford–Johnson merge-insertion sorting algorithm.
* `ex02` must sort the input sequence correctly using the required containers.
* `ex02` must report execution times for the supported container implementations.
* **In `ex02`, templates and generic functions cannot be used to share the sorting implementation between the required containers, so some code repetition is necessary.**
* The implementation must respect the required input constraints, including the handling of invalid or duplicate values as specified by the subject.
* No memory leaks.
* The code must compile cleanly under the required compiler flags.

---

## 🚀 Future Improvements

* Expand `ex00` tests to cover leap years, invalid dates, missing dates, and malformed database records.
* Improve error reporting when processing invalid exchange-rate data.
* Test `ex00` with larger input files and dates at the boundaries of the available database.
* Expand `ex01` tests to cover deeply nested operations, invalid expressions, and arithmetic edge cases.
* Add comprehensive tests for division by zero and integer overflow.
* Verify the correctness of the Ford–Johnson algorithm using sequences of different lengths.
* Test `ex02` with odd and even input sizes, already sorted sequences, reverse-sorted sequences, and duplicate values.
* Compare the number of comparisons performed by the sorting algorithm against other sorting algorithms.
* Investigate the performance differences between `std::vector` and `std::deque`.
* Improve the organization of the repeated code in `ex02` without violating the subject's restrictions.
* Add automated tests to compare both container implementations and ensure that they always produce identical sorted sequences.
* Explore alternative implementations of the Ford–Johnson algorithm outside the constraints of the subject.
* Revisit the code using modern C++ features after completing the required C++98 implementation.

---

## 💡 Final Thoughts

CPP09 brings together several important C++ concepts through practical programming challenges.

The first exercise demonstrates how associative containers can be used to store historical data and perform efficient date-based lookups.

The second shows how a stack can simplify the evaluation of mathematical expressions written in Reverse Polish Notation.

The final exercise focuses on the Ford–Johnson algorithm, combining algorithmic reasoning, container management, and performance measurement.

**One of the main lessons from `ex02` is that implementation constraints can influence code structure.** Although templates and generic functions would normally reduce duplication between the `std::vector` and `std::deque` implementations, the subject's restrictions require the sorting logic to be repeated.

This is a useful reminder that good software design must account for both maintainability and the technical requirements of a project.

Together, these exercises reinforce the importance of choosing appropriate data structures, understanding algorithms, validating input, and writing code that respects explicit constraints.

---

## 📬 Contact

Feel free to reach out:

[GitHub](https://github.com/PedroLouzada)
