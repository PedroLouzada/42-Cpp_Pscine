# CPP04 — Subtype Polymorphism, Abstract Classes & Interfaces

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP04** is the fifth module of the C++ series at 42.  
This is where object-oriented programming clicks into its final form.

The module revolves around **subtype polymorphism** — the ability to treat derived objects through a base class pointer, letting the program decide at runtime which method to call. Combined with **abstract classes** and **interfaces**, this module defines how real object-oriented architecture is structured.

The hardest and most rewarding module so far. 🔷

---

## 🧠 What I Learned

- The difference between **compile-time** and **runtime polymorphism**.
- How **virtual functions** enable dynamic dispatch — the correct method is resolved at runtime based on the actual object type, not the pointer type.
- Why destructors must be **virtual** in polymorphic base classes to avoid undefined behaviour.
- **Pure virtual functions** and how they turn a class into an **abstract class** that cannot be instantiated.
- Designing **interfaces** in C++98 — classes with nothing but pure virtual functions, defining a contract without any implementation.
- How to manage collections of polymorphic objects safely.
- Building a custom **linked list** to handle dynamic object storage without relying on the STL.

---

## ⚙️ Exercises

### ex00 — Polymorphism 🐾
> Virtual functions and runtime dispatch.

Implements an `Animal` base class with a `makeSound()` virtual method, and derived classes `Dog` and `Cat` that override it.

This exercise makes the mechanics of dynamic dispatch immediately tangible — the same pointer, different behaviour depending on the actual object behind it.

---

### ex01 — I don't want to set the world on fire 🧠
> Deep copy and memory management in polymorphic hierarchies.

Expands the animal hierarchy by giving `Dog` and `Cat` a `Brain` object — stored as a pointer, requiring proper deep copy handling in the copy constructor and assignment operator.

A focused reminder that polymorphism and memory management are inseparable concerns.

---

### ex02 — Abstract class 🚫
> Preventing instantiation.

Makes `Animal` a proper **abstract class** by turning `makeSound()` into a pure virtual function.

Simple change — profound consequence. A class that exists only to be inherited, never instantiated.

---

### ex03 — Interface & recap ⚙️
> Interfaces, AMateria, and a custom linked list.

The most complex exercise of the module. Introduces `AMateria`, an abstract base, alongside `Ice` and `Cure` concrete types, an `ICharacter` interface, and an `IMateriaSource` interface.

Characters equip and use materias, sources learn and create them — all managed through interface pointers with no knowledge of concrete types.

To handle the floor — materias that get dropped or unequipped — a custom **linked list** was implemented to track and properly free them, avoiding memory leaks without the STL.

---

## 🖥️ How to Use

Clone the repository and navigate to any exercise:

```bash
git clone https://github.com/PedroLouzada/CPP04.git
cd CPP04/ex03
make
./materia
```

Each exercise has its own `Makefile` for compilation.

---

## 🔍 Rules & Constraints

- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
- No use of the STL.
- All classes must follow the **Orthodox Canonical Form**.
- No memory leaks — including dropped materias on the floor.

---

## 🚀 Future Improvements

- Revisit ex03 with STL containers after completing CPP08.
- Explore more complex interface hierarchies with multiple inheritance.

---

## 💡 Final Thoughts

CPP04 is where everything from the previous modules converges.

The interfaces exercise in particular felt like building a small system — multiple abstract layers, concrete implementations, dynamic dispatch at every level, and memory that needed careful tracking. Solving the floor problem with a linked list instead of reaching for the STL made it more demanding, but also more instructive.

If CPP03 taught you to think in hierarchies, CPP04 teaches you to think in **contracts**.

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
