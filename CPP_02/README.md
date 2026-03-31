# CPP02 — Ad-hoc Polymorphism, Operator Overloading & Orthodox Canonical Form

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP02** is the third module of the C++ series at 42.  
This is where things get significantly more demanding — and significantly more interesting.

The module revolves around three interconnected pillars: **ad-hoc polymorphism**, **operator overloading**, and the **Orthodox Canonical Form (OCF)**. But beneath all of that lies something deeper: a genuine dive into the **architecture of numbers** — how computers represent fractional values, and why fixed-point numbers exist as a bridge between integers and floating-point.

This was a substantial step up in complexity from CPP01. 🧠

---

## 🧠 What I Learned

- Understanding the **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator, and destructor.
- Implementing and overloading **operators** (`+`, `-`, `*`, `/`, `<<`, comparison operators, increment/decrement) to give classes natural, expressive behavior.
- The theory behind **floating-point representation** (IEEE 754): how bits are divided into sign, exponent, and mantissa — and why precision is limited.
- The concept of **fixed-point numbers**: a deterministic, predictable alternative to floating-point, critical in domains like embedded systems, finance, and graphics.
- The architectural trade-offs between **float**, **double**, and **fixed-point** representations.
- How to build a **fixed-point number class from scratch**, handling conversions, arithmetic, and comparisons entirely through overloaded operators.
- Writing cleaner, more expressive C++ by making objects behave intuitively through operator semantics.

---

## ⚙️ Exercises

### ex00 — My First Class in Orthodox Canonical Form 📐
> The foundation: OCF and fixed-point basics.

Implements a `Fixed` class representing a **fixed-point number** using a single private integer and a static constant for the fractional bits.  
The class strictly follows the **Orthodox Canonical Form**, introducing the four essential special member functions and their roles.

This exercise sets the tone for everything that follows — understanding *why* the OCF matters, not just *how* to write it.

---

### ex01 — Towards a More Useful Fixed-Point Number Class 🔢
> Conversions and stream output.

Expands the `Fixed` class with:
- Constructors accepting `int` and `float`, converting them into fixed-point representation.
- A `toFloat()` and `toInt()` method for converting back.
- Overloading of `operator<<` for clean output via `std::cout`.

This is where the theory of **fixed-point encoding** becomes tangible — manually shifting bits to encode and decode fractional values.

---

### ex02 — Now We're Talking 🔧
> Full operator overloading.

The `Fixed` class reaches its final form with a complete set of overloaded operators:

| Category | Operators |
|----------|-----------|
| Comparison | `>`, `<`, `>=`, `<=`, `==`, `!=` |
| Arithmetic | `+`, `-`, `*`, `/` |
| Increment/Decrement | `++` (pre & post), `--` (pre & post) |
| Static utility | `min()`, `max()` |

This exercise solidifies the understanding of **ad-hoc polymorphism** — giving the same operator symbol different behavior depending on the types involved, and making user-defined types feel as natural as built-ins.

---

## 🖥️ How to Use

Clone the repository and navigate to any exercise:

```bash
git clone https://github.com/PedroLouzada/CPP02.git
cd CPP02/ex02
make
./fixed
```

Each exercise has its own `Makefile` for compilation.

---

## 🔍 Rules & Constraints

- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
- No use of the STL (Standard Template Library).
- All classes that require it must strictly follow the **Orthodox Canonical Form**.
- No use of `float` or `double` in the final fixed-point implementation — the representation is built entirely from integers and bit shifting.

---

## 🚀 Future Improvements

- Implement a more precise fixed-point class with configurable fractional bit width.
- Compare performance benchmarks between fixed-point and floating-point arithmetic.
- Revisit operator overloading patterns after completing later CPP modules.

---

## 💡 Final Thoughts

CPP02 was a turning point.

Not just because of the syntax or the new C++ mechanics — but because it forced me to look **under the hood of numbers themselves**. Understanding how a `float` is actually stored in memory, why it loses precision, and how fixed-point arithmetic sidesteps those issues by trading flexibility for determinism — that kind of knowledge changes how you see code.

Operator overloading added another layer: suddenly, a class you designed could feel as natural and expressive as a primitive type. That's a powerful feeling.

Much harder than what came before — but the payoff in understanding was equally large.
If CPP00 taught you to think in objects, CPP02 teaches you to think in **bits**.

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
