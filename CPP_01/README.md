# CPP01 — Memory, Pointers & References

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP01** is the second module of the C++ series at 42.  
Building on the foundations of CPP00, this module goes deeper into one of the most critical aspects of C++: **memory management**, and the crucial distinction between **pointers and references**.

It also introduces **file streams**, **switch statements**, and a more nuanced understanding of how C++ handles objects in memory.  

---

## 🧠 What I Learned

- The fundamental difference between **pointers and references** — and when to use each.
- How to allocate and deallocate memory with **`new` and `delete`** in C++.
- Working with **references** as aliases and how they differ from pointers in practice.
- Using **file streams** (`std::ifstream`, `std::ofstream`) for reading and writing files.
- Applying **switch statements** as a cleaner alternative to chained `if/else`.
- Deepening understanding of **object lifetime** and what happens when objects go out of scope.
- Writing safer, more intentional code by choosing the right memory strategy.

---

## ⚙️ Exercises

### ex00 — BraiiiiiiinnnzzzZ 🧠
> Pointers and references side by side.

Introduction to the difference between a **pointer** and a **reference** through a `Zombie` class.  
Creates zombies on the stack and announces their presence — a fun way to internalize object lifetime.

---

### ex01 — Moar Brainz! 🧟
> Heap allocation and arrays of objects.

Dynamically allocates a **horde of zombies** using `new[]` and properly deallocates them with `delete[]`.  
Reinforces the importance of clean memory management when dealing with object arrays on the heap.

---

### ex02 — HI THIS IS BRAIN 🧬
> Pointers vs references — the core lesson.

A simple but eye-opening exercise that prints the **memory address and value** of a variable through both a pointer and a reference.  
Makes the relationship between the two crystal clear.

---

### ex03 — Unnecessary Violence 🗡️
> Pointers and references to objects.

Implements `Weapon`, `HumanA`, and `HumanB` classes.  
`HumanA` holds a weapon by **reference**, `HumanB` holds one by **pointer** — illustrating exactly when each approach is appropriate and why.

---

### ex04 — Sed is for Losers 📝
> File stream I/O.

Replicates a simplified version of the `sed` command:  
reads a file, replaces occurrences of a string with another, and writes the result to a new file.  
No use of `std::string::replace` allowed — builds real understanding of string manipulation and file streams.

```bash
./sed_is_for_losers filename find_str replace_str
```

---

### ex05 — Harl 2.0 😤
> Pointers to member functions.

Implements a `Harl` class that complains at different log levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`.  
Uses **pointers to member functions** to call the right method dynamically — a powerful C++ feature.

---

### ex06 — Harl Filter 🔇
> Switch statements with fall-through.

Extends Harl 2.0 with a filter: only messages **at or above** a given level are displayed.  
Demonstrates the elegance of **switch fall-through** as a control flow mechanism.

```bash
./harl_filter WARNING
# Displays WARNING, ERROR — and nothing below
```

---

## 🖥️ How to Use

Clone the repository and navigate to any exercise:

```bash
git clone https://github.com/PedroLouzada/CPP01.git
cd CPP01/ex06
make
./harlFilter
```

Each exercise has its own `Makefile` for compilation.

---

## 🔍 Rules & Constraints

- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
- No use of the STL (Standard Template Library).
- Strict memory management — every `new` must have its matching `delete`.
- No memory leaks allowed.

---

## 🚀 Future Improvements

- Explore smart pointers (`unique_ptr`, `shared_ptr`) in later modules as a safer alternative to raw `new/delete`.
- Add more complex use cases for pointers to member functions beyond Harl.

---

## 💡 Final Thoughts

CPP01 felt like the module where C++ started to **reveal its true nature**.

Pointers were already familiar from C — but references? That took a mental shift.  
Understanding *when* to use one over the other, and *why* it matters, is one of those things that quietly upgrades how you think about every line of code you write.

Tricky at moments, but never overwhelming.  
Each exercise builds on the last in a way that makes everything click by the end.

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
