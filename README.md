# C++ to MIPS Mini Compiler

This project is a simple **C++-like expression compiler** that translates basic arithmetic expressions into **MIPS assembly code**. 


It demonstrates how a compiler front-end works, including:
- Tokenizing input
- Parsing expressions
- Generating stack-based MIPS assembly
- Producing a final `.s` file that can run in QtSPIM or MARS


## 🚀 Features
- Supports integer expressions such as:
2 + 3 * 4
(5 + 10) * 2
7 + 9 * (3 - 1)

- Correct operator precedence (`*` before `+`)
- Stack-based MIPS code generation
- Outputs a complete `.s` file you can run in QtSPIM


## 📂 Project Structure

cpp-mips-compiler/

│

├── main.cpp # Compiler source code

├── out.s # Generated MIPS assembly output

└── README.md # Documentation


## 🛠️ How to Build

Make sure you have **g++** installed.

Compile using:

```bash
g++ -std=c++17 main.cpp -o compiler


▶️ How to Run
Run the compiler:
./compiler

Enter an arithmetic expression, for example:
2 + 3 * 4

The compiler will generate a file:
out.s

🧪 Example

Input:
2 + 3 * 4

Output MIPS Code (out.s):
.text
.globl main
main:
  addi $sp, $sp, -8
  sw $ra, 4($sp)
  sw $fp, 0($sp)
  addi $fp, $sp, 8

  # Computation happens here…

  lw $ra, 4($sp)
  lw $fp, 0($sp)
  addi $sp, $sp, 8
  jr $ra
You can run this file in QtSPIM.

🧰 Requirements
C++17 capable compiler (g++, clang++)

QtSPIM or MARS MIPS simulator

🎓 Educational Purpose
This compiler is designed for learning purposes, demonstrating:

Parsing

Expression evaluation

Stack management

Register usage

Assembly generation

It is NOT a full C++ compiler, but a teaching tool.


👤 Author
Krishna Verma (krishnavermac)
GitHub: https://github.com/krishnavermac
