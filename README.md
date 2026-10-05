# Student Record & Performance Management System

A lightweight, object-oriented console application built in **C++** to manage student academic records, automate GPA computation, and provide persistent disk storage.

---

## 📌 Features
- **Object-Oriented Architecture**: Encapsulates student entities and core business logic into clean classes (`Student` and `StudentManagementSystem`).
- **Automated GPA Calculation**: Computes 10-point scale GPA dynamically upon record entry.
- **Persistent Storage**: Utilizes file input/output streams (`std::ifstream`, `std::ofstream`) with CSV serialization to preserve records across executions.
- **Dynamic In-Memory Management**: Implements `std::vector` for dynamic array expansion.
- **Formatted Terminal UI**: Employs `std::setw` formatting for structured tabular data presentation.

---

## 🛠️ Tech Stack
- **Language**: C++ (C++17 standard)
- **Concepts**: OOPs (Encapsulation, Data Abstraction), Standard Template Library (STL Vectors), File Handling (Streams)

---

## 🚀 How to Run Locally

### Prerequisites
A C++ compiler (`g++` or MinGW) installed on your system.

### Build and Run
```bash
# Clone the repository
git clone [https://github.com/harshpareek/student-record-cpp.git](https://github.com/harshpareek/student-record-cpp.git)
cd student-record-cpp

# Compile
g++ -std=c++17 main.cpp -o student_manager

# Execute (Linux/macOS)
./student_manager

# Execute (Windows)
student_manager.exe
