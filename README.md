# Interval Scheduling Project

This is a simple terminal-based C++ program that implements the **Interval Scheduling** algorithm using a **Greedy Approach**.

The goal of the project is to find the maximum number of non-overlapping intervals or calculate the minimum number of rooms needed for overlapping intervals.

---

## 💡 Features

- Add intervals (start and end time)
- Display sorted intervals
- Run Greedy Interval Scheduling
- Interval Partitioning (minimum rooms)
- Colored terminal interface (Windows only)

---

## 📁 Project Structure

interval-scheduler/
├── src/
│ ├── main.cpp
│ ├── interval.cpp
│ ├── interval.hpp
├── README.md



---

## ⚙️ How to Compile & Run

### 1. Open terminal inside the project folder.

### 2. Compile using `g++`:

g++ main.cpp interval.cpp -o scheduler.exe



> ✅ Make sure you are inside the `src` folder when you run this.

### 3. Run the executable:

./scheduler.exe



---

## 🖥️ Requirements

- Windows OS (for colored terminal)
- MinGW or any C++ compiler with `g++`
- VS Code (recommended)

---

## 📌 Notes

- The terminal interface uses `SetConsoleTextAttribute`, which is specific to Windows.
- Make sure `interval.hpp` is included properly in both `.cpp` files.

---

## 📜 License

This project is licensed for educational purposes.