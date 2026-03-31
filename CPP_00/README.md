# CPP00 — Introduction to C++

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP00** is the very first module of the C++ series at 42.  
Its goal: make the leap from **C to C++**, diving headfirst into the fundamentals of **Object-Oriented Programming**.

This module introduces the core building blocks of C++ — classes, member functions, encapsulation, and the quirks that make C++ a whole different beast from C.  

---

## 🧠 What I Learned

- Understanding the **key differences between C and C++**.
- Writing and structuring **classes** with attributes and member functions.
- Applying **encapsulation**: public vs private access, getters and setters.
- Working with `std::string` and `std::cout` instead of raw C counterparts.
- Understanding constructors/destructors.
- Writing clean, readable C++ code.
- Getting comfortable with **namespaces** and `std::cin` / `std::cout` I/O.
- Understanding **static members** and their role in a class.
- Understanding Streams and their concept.

---

## ⚙️ Exercises

### ex00 — Megaphone
> A warm-up to C++ I/O.

A simple program that takes command-line arguments and outputs them in **uppercase**.  
Focuses on using `std::cout` and string manipulation in C++.

```bash
./megaphone "hello world"
# Output: HELLO WORLD
```

---

### ex01 — My Awesome PhoneBook 📒
> First real dive into classes and OOP.

A mini **phonebook application** built using two classes: `PhoneBook` and `Contact`.  
Supports three commands at runtime:

| Command | Description |
|---------|-------------|
| `ADD`   | Saves a new contact (up to 8 stored) |
| `SEARCH`| Displays contacts and lets you look one up |
| `EXIT`  | Closes the phonebook |

Key concepts practiced:
- Class design with **private attributes** and **public methods**
- Managing a fixed-size array of objects
- Formatted output with column alignment using `std::setw`

---

### ex02 — The Job Of Your Dreams 💼
> Reconstructing a lost file from a header and main.

Given a broken `Account.cpp` implementation, the task was to **reconstruct it entirely** from scratch using only:
- A provided `Account.hpp` header
- A reference log output to match

This exercise sharpens your ability to **read and understand class interfaces** and translate them into correct implementations — a crucial real-world skill.

---

## 🖥️ How to Use

Clone the repository and navigate to any exercise:

```bash
git clone https://github.com/PedroLouzada/CPP00.git
cd CPP00/ex01
make
./phonebook
```

Each exercise has its own `Makefile` for compilation.

---

## 🔍 Rules & Constraints

- No use of `printf`, `malloc`, or `free` — **C++ I/O and memory management only**.
- No use of the STL (Standard Template Library) in this module.
- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.

---

## 🚀 Future Improvements

- Improve the PhoneBook with persistent storage (file I/O).
- Add input validation and better error messages.
- Revisit with deeper understanding after completing later CPP modules.

---

## 💡 Final Thoughts

CPP00 felt like learning to walk again after running in C.  
Everything looks familiar at first — and then you realize the entire **philosophy** has shifted.

It's not just new syntax. It's a new way of **thinking about code**: encapsulating data, designing objects, and structuring programs around responsibility and abstraction.

A humbling, eye-opening start to the C++ series. 
If you're just beginning — embrace the confusion. It clicks eventually. 

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
