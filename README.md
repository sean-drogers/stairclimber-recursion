# Stairclimber Recursion

**Language:** C++  
**Purpose:** Calculates and lists all unique ways to climb a staircase of *n* steps, moving up 1, 2, or 3 stairs at a time.

---

## 🧠 How It Works
- Uses **recursion** to generate all possible combinations of steps.
- Stores combinations in a **vector of vectors** (`vector<vector<int>>`).
- Displays the number of combinations and formats each path neatly.

---

## 🧰 Build & Run
```bash
g++ -O2 -std=c++17 -o stairclimber stairclimber.cpp
./stairclimber <number_of_stairs>
