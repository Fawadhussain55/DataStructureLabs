Student Performance Analytics System
-----------------------------------

This project is developed in C++ for analyzing student academic performance
using dynamic memory allocation and singly linked lists.

The program reads student records from a text file, stores them in a linked list,
applies different sorting techniques, and generates multiple analysis reports
as output files.

--------------------------------------------------
Files Included
--------------------------------------------------
1. main.cpp
   - Main C++ source file
   - Implements linked list, sorting, and file handling

2. students_data.txt
   - Input file containing student records
   - First line contains total number of students
   - Each next line contains:
     StudentID Name Department Semester CGPA Credits EnrollmentYear

--------------------------------------------------
Sorting Algorithms Used
--------------------------------------------------
1. Bubble Sort
   - Used for ranking students by CGPA
   - Suitable for linked lists using adjacent comparisons

2. Selection Sort
   - Used for sorting students by enrollment year and ID
   - Simple and effective for linked list traversal

--------------------------------------------------
Output Files Generated
--------------------------------------------------
1. ranked_by_cgpa.txt
   - Students sorted in descending order of CGPA
   - Tie-breaker: credit hours
   - Includes ranking numbers

2. sorted_by_enrollment.txt
   - Students sorted by enrollment year (ascending)
   - Displays average CGPA for each enrollment year

3. performance_tiers.txt
   - Students categorized into performance tiers based on CGPA

--------------------------------------------------
How to Compile (Windows)
--------------------------------------------------
Make sure g++ (MinGW) is installed.

Command:
g++ main.cpp -o project

--------------------------------------------------
How to Run
--------------------------------------------------
Command:
project

The program will automatically read students_data.txt
and generate all output files in the same folder.

--------------------------------------------------
Assumptions
--------------------------------------------------
- All student records are stored using dynamic memory
- No arrays or vectors are used for primary storage
- Input file format is correct
- Names consist of first and last name

--------------------------------------------------
Time Complexity
--------------------------------------------------
Bubble Sort: O(n^2)
Selection Sort: O(n^2)

--------------------------------------------------
Author
--------------------------------------------------
Name: Fawad
Project: Data Structures (Linked List & Sorting)
