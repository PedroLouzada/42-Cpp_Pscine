# CPP03 — Inheritance

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP03** is the fourth module of the C++ series at 42.  
This is where object-oriented programming starts to feel like a real design tool.

The module revolves around one of the most fundamental pillars of OOP: **inheritance** — the ability to build new classes on top of existing ones, extending and specialising behaviour without rewriting what already works.

---

## 🧠 What I Learned

- Understanding **base and derived classes**: how a child class inherits attributes and methods from its parent.
- Using **access specifiers** (`public`, `protected`, `private`) to control what gets inherited and how.
- Overriding methods in derived classes to **specialise behaviour**.
- Understanding **constructor and destructor chaining** — how they are called up and down the hierarchy.
- The problem of **diamond inheritance** and why it exists.
- Using **virtual inheritance** as a solution to the diamond problem.
- Thinking about class hierarchies as **design decisions**, not just syntax.

---

## ⚙️ Exercises

### ex00 — ClapTrap 🤖
> The foundation: your first base class.

Implements a `ClapTrap` class with attributes like hit points, energy points, and attack damage — along with methods for attacking, taking damage, and repairing itself.

This exercise establishes the base that all subsequent exercises build upon.

---

### ex01 — Serena, my love 💥
> First derived class.

Introduces `ScavTrap`, a class that **inherits from ClapTrap** and overrides its attack method with a new behaviour.

This is where the constructor/destructor chain becomes tangible — watching the order of calls makes the inheritance mechanics immediately clear.

---

### ex02 — Repetitive work 🔧
> Stacking inheritance.

Adds `FragTrap`, another class inheriting from `ClapTrap` with its own unique method.

The focus here is on solidifying the inheritance pattern and understanding how multiple derived classes can extend the same base differently.

---

### ex03 — Now it's weird ⚠️
> The diamond problem.

Introduces `DiamondTrap`, a class that inherits from **both** `ScavTrap` and `FragTrap` — which both inherit from `ClapTrap`.

This creates the classic **diamond inheritance** ambiguity: which `ClapTrap` does `DiamondTrap` inherit? The exercise forces a direct confrontation with **virtual inheritance** as the solution.

---

## 🔍 Rules & Constraints

- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
- No use of the STL.
- All classes must follow the **Orthodox Canonical Form** where required.

---

## 🚀 Future Improvements

- Revisit the diamond problem after studying virtual functions in CPP04.
- Explore deeper class hierarchy designs with more complex attribute chains.

---

## 💡 Final Thoughts

CPP03 is deceptively straightforward at first — and then ex03 hits.

The diamond problem is one of those moments where the language forces you to stop and think about **what inheritance actually means** at a structural level. It's not just syntax anymore — it's a design question with real consequences.

If CPP02 taught you to think in bits, CPP03 teaches you to think in **hierarchies**.

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
