# CPP05 — Repetition, Exceptions & Bureaucracy

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width="150" />

## 🧩 About the Project

**CPP05** is the sixth module of the C++ series at 42.  
This is where error handling becomes part of the architecture instead of an afterthought.

The module revolves around **exceptions** — separating the code that detects an invalid state from the code responsible for recovering from it. Through a deliberately bureaucratic system of grades, forms, permissions, and approvals, the exercises explore how `throw`, `try`, and `catch` can keep class invariants safe while allowing failures to propagate clearly.

The most bureaucratic module so far. 📋

---

## 🧠 What I Learned

- How to use `try`, `catch`, and `throw` to handle exceptional situations without mixing error recovery into the main logic.
- Creating custom exception classes derived from `std::exception` and overriding `what()` with meaningful error messages.
- Protecting **class invariants**, such as keeping a bureaucrat's grade between `1` and `150`.
- How exceptions propagate across interactions between objects — from bureaucrats to forms and back again.
- Designing an abstract `AForm` base class with shared validation and polymorphic execution.
- Separating authorization rules from the concrete action performed by each derived form.
- Implementing factory-style object creation through the `Intern` class.
- Managing ownership correctly when factory methods return dynamically allocated objects.

---

## ⚙️ Exercises

### ex00 — Mommy, when I grow up, I want to be a bureaucrat! 🏛️
> Custom exceptions and protected class invariants.

Implements a `Bureaucrat` class with a constant name and a grade ranging from `1` — the highest possible rank — to `150`, the lowest.

Invalid construction and attempts to promote or demote a bureaucrat beyond those limits throw `GradeTooHighException` or `GradeTooLowException`. The stream insertion operator is also overloaded to provide a clear textual representation of each bureaucrat.

This exercise turns invalid states into explicit, recoverable errors.

---

### ex01 — Form up, maggots! 📝
> Exception-driven interactions between objects.

Introduces a `Form` with a name, a signed state, and immutable grades required for signing and execution.

A bureaucrat can attempt to sign a form through `signForm()`, while `Form::beSigned()` verifies whether the bureaucrat has enough authority. Successful and failed operations are reported clearly, with exceptions carrying the reason for failure.

The focus shifts from validating one object to coordinating rules safely across multiple classes.

---

### ex02 — No, you need form 28B, not 28C... ⚙️
> Abstract forms, authorization, and polymorphic execution.

Replaces `Form` with the abstract base class `AForm` and introduces three concrete forms:

- `ShrubberyCreationForm` creates a `<target>_shrubbery` file containing ASCII trees.
- `RobotomyRequestForm` makes drilling noises and has a 50% chance of successfully robotomizing its target.
- `PresidentialPardonForm` announces that its target was pardoned by Zaphod Beeblebrox.

Every form has its own signing and execution requirements, while `AForm` centralizes the checks that ensure the form is signed and the executor has a sufficient grade.

The same execution contract now drives three completely different behaviours.

---

### ex03 — At least this beats coffee-making ☕
> Factory-style object creation with the `Intern` class.

Adds an `Intern` capable of creating forms dynamically through `makeForm()`. The method receives a form name and a target, then returns the corresponding concrete `AForm` through a base-class pointer.

Supported form names are matched to `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`. Unknown names trigger a custom parsing exception instead of silently returning an invalid object.

This exercise isolates creation logic from the code that uses the forms — a compact introduction to the Factory pattern.

---

## 🖥️ How to Use

Clone the repository and navigate to any exercise:

```bash
git clone https://github.com/PedroLouzada/42-Cpp_Pscine.git
cd 42-Cpp_Pscine/CPP_05/ex03
make
./intern
```

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

- All code compiled with `-Wall -Wextra -Werror` and the `-std=c++98` flag.
- All required classes follow the **Orthodox Canonical Form**.
- No STL containers or algorithms.
- Bureaucrat grades must remain between `1` and `150` at all times.
- Form names and required grades are immutable after construction.
- Invalid operations must be reported through exceptions rather than ignored.
- Every dynamically allocated form must be properly deleted — no memory leaks.

---

## 🚀 Future Improvements

- Add an automated test suite covering every grade boundary, signing state, execution requirement, and invalid form name.
- Revisit the factory with modern C++ using `std::unique_ptr` and a lookup table once the C++98 restriction no longer applies.

---

## 💡 Final Thoughts

CPP05 makes failure paths impossible to ignore.

The form system feels like a small authorization workflow — immutable requirements, signed state, role-based execution, specialized actions, and errors that must cross several class boundaries without losing their meaning. The `Intern` completes that system by separating object creation from object usage and forcing ownership to be handled deliberately.

If CPP04 teaches you to think in **contracts**, CPP05 teaches you to think in **failure paths**.

---

## 📬 Contact

Feel free to reach out:  
[GitHub](https://github.com/PedroLouzada)
