
README.md


---



# Frequency Distribution Table Generator

📊 This program solves the *Frequency Distribution Table* problem, commonly found in *Probability and Statistics 1*.  
I studied this subject during the *second semester of the first year of college*, and built this project to solidify my understanding.

---

## 🧠 Problem Overview

Given a dataset of numerical values, the program automatically:

1. **Calculates the number of classes (k)** using:

2^k > n

Example:  
For n = 20  
⇒ 2^5 = 32 > 20  
⇒ So, k = 5

2. *Computes the data range*:

range = max - min = 18 - 1 = 17

3. *Determines the class width*:
- If (range / k) is *an integer, it is **not accepted*.
- In that case, use:
  
  width = (range + 1) / k = (17 + 1) / 5 = 3.6
  

4. *Generates a frequency distribution table* including:
- Class Intervals
- Frequency
- Relative Frequency (RF)
- Cumulative Frequency (CF)

---

## 📌 Sample Input Used:

12  7   6   2   1
5   9   6   2   13
15 15  3   7   18
5  14  1   17  4

➡ Total number of values: *20*

---

## 📁 Output: Frequency Table Example

| Interval # | Range     | Frequency | RF   | CF |
|------------|-----------|-----------|------|----|
| 1          | [1 - 4]   |     X     | 0.X  | XX |
| 2          | [4 - 7]   |     X     | 0.X  | XX |
| ...        | ...       |   ...     | ...  | ... |

> Values in the table are computed based on the logic explained above.

---

## 🛠 Technologies Used

- *Language:* C++
- *Bash Script:* For snapshots, Git automation, and version control
- *Version Control:* Git + GitHub

---

## 🚀 How to Run

You can compile and run the C++ program using any C++ compiler like g++.

Example:

```bash
g++ main.cpp -o freq_table
./freq_table


---
by : osama-mohamoud