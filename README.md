# oops-supermart
Console-based supermarket system in C++11 — demonstrates OOP pillars,  Singleton pattern, function templates, STL, exception handling &amp; file I/O.
# OOP's Super Mart
A console-based retail management system in C++11.

## Features
- Admin & Customer roles with password login
- Live inventory tracking — stock deducted/restored in real time
- Singleton design pattern for admin session
- Function templates for type-safe search
- Full exception handling
- File I/O persistence via inventory.txt

## How to compile
g++ -std=c++11 main.cpp item.cpp inventory.cpp cart.cpp admin.cpp customer.cpp -o supermart.exe

## Concepts demonstrated
Encapsulation | Inheritance | Polymorphism | Abstraction |
Friend class | Templates | STL vector | Singleton pattern | File I/O
