# C - Data Structures

A comprehensive study repository for learning **Data Structures in C**, including exercises, previous exams, and practical implementations.

## 📚 Repository Overview

This repository contains:
- **Exercise Sets** - Organized by topic with progressive difficulty
- **Previous Exams** - Past exam problems for practice
- **Implementations** - Practical C code examples
- **Study Materials** - Resources and guides for learning

## 🎯 Purpose

This project is designed to support:
- University coursework in Data Structures
- Preparation for sufficiency exams
- Practical understanding of C programming concepts
- Interview preparation

## 📁 Folder Structure

```
C - DATA STRUCTURES/
├── exercicios_ponteiros/          # Pointer exercises
│   ├── exercicio_1_1.c
│   ├── exercicio_1_2.c
│   ├── ... (15 exercises total)
│   ├── topicos_pesquisa.txt      # Research topics guide
│   └── README.md                  # Pointers exercise instructions
├── run.bat                         # Script to compile and run C files
├── .gitignore                      # Git ignore file
├── main.c                          # Example file
└── README.md                       # This file
```

## 🚀 Quick Start

### Prerequisites
- GCC compiler installed
- PowerShell or Command Prompt
- VS Code (optional, but recommended)

### Setup

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd "C - DATA STRUCTURES"
   ```

2. **Compile and Run Exercises**
   ```powershell
   .\run exercicio_1_1
   .\run exercicios_ponteiros\exercicio_2_1
   ```

## 📖 Exercise Sets

### Pointers (`exercicios_ponteiros/`)
**15 exercises organized in 5 sections:**

1. **Basic Concepts** (3 exercises)
   - Declaration and initialization
   - Address-of and dereference operators
   - Pointers and arrays

2. **Functions** (3 exercises)
   - Pass by reference
   - Returning pointers
   - Pointers as parameters

3. **Dynamic Allocation** (3 exercises)
   - `malloc` and `free`
   - Allocating structures
   - Dynamic arrays

4. **Advanced Topics** (3 exercises)
   - Pointer to pointer
   - Dynamic matrices
   - Structures with pointers

5. **Practical Challenges** (5 exercises)
   - Array manipulation
   - Element counting
   - Array copying and reversal
   - Search operations

## 🛠️ Tools

### run.bat Script
Simplifies compilation and execution:

```powershell
# Basic usage
.\run exercicio_1_1

# With path
.\run exercicios_ponteiros\exercicio_1_1

# Works from any folder in the project
```

The script:
- ✅ Compiles with `-Wall -Wextra` flags
- ✅ Detects compilation errors
- ✅ Automatically executes the program
- ✅ Works with nested directories

## 📝 How to Use This Repository

### Solving Exercises

1. **Choose an exercise file** (e.g., `exercicio_1_1.c`)
2. **Read the objective** at the top of the file
3. **Implement your solution** in the provided space
4. **Compile and test** using the `run.bat` script
5. **Check your output** against the expected output

### If You Get Stuck

1. Consult [topicos_pesquisa.txt](exercicios_ponteiros/topicos_pesquisa.txt)
2. Research the suggested topics
3. **Don't ask for solutions, research the concepts!**
4. Implement your own solution

### Committing Your Work

```bash
git add exercicios_ponteiros/exercicio_1_1.c
git commit -m "Exercise 1.1 completed: Pointer declaration and initialization"
git push
```

## ✅ Pre-Commit Checklist

Before pushing your code:

- [ ] Code compiles without errors
- [ ] Code compiles without warnings
- [ ] Program runs correctly
- [ ] Output matches expected results
- [ ] Memory is properly freed (no memory leaks)
- [ ] No `.exe` files are included (.gitignore handles this)
- [ ] Code is well-commented

## 📚 Learning Path

**Recommended order:**

1. Start with `exercicios_ponteiros/`
2. Follow the exercise numbers (1.1 → 1.2 → 1.3 → 2.1 → ...)
3. Move to next section only after completing current section
4. Practice with different values
5. Review and refactor your code

## 🔍 Compilation Tips

### View All Warnings
```powershell
gcc -Wall -Wextra -pedantic exercicio_1_1.c -o exercicio_1_1
```

### Debug with Print Statements
```c
printf("Variable address: %p\n", &variable);
printf("Pointer value: %p\n", ptr);
printf("Dereferenced value: %d\n", *ptr);
```

### Check for Memory Leaks
Use tools like:
- Visual Studio debugger
- Dr. Memory
- Valgrind (on WSL)

## 📖 Recommended Resources

- **The C Programming Language** - Kernighan & Ritchie
- Official C Documentation
- Course Materials
- University Lecture Notes

## 🤝 Contributing

This is a personal study repository, but you can:
- Add more exercises
- Improve documentation
- Add solutions (in a separate branch if desired)
- Fix typos or unclear sections

## 📝 License

This repository is for educational purposes.

## 📧 Notes

- This repository is organized for Git commits
- Each exercise should be a separate commit
- Clear commit messages help track progress
- All executables and object files are ignored by Git

---

**Happy Learning!** 💪

Start with the basics, understand each concept thoroughly, and gradually work your way to more advanced topics. Consistency and practice are key! 🎯
