# Rush 01 - 42 School Project

📚 Project Overview
Rush 01 is a group project at 42 School where students collaborate to build a fully working program in a very short amount of time, usually within 48 hours.
The goal of this rush was to create a program that solves the Skyscrapers puzzle — a logic game where the player must place skyscrapers of different heights into a grid, following certain rules based on visibility from the edges.

This project was completed by:

zkarapet

🛠️ Files

File	Description
checker.c	Contains functions that check the validity of the grid according to the game rules.
common.c	Includes helper functions used across the project.
maincopy.c	Contains the main function and program execution flow.
parsing.c	Parses input arguments and prepares the game grid.
(Note: .DS_Store is an automatically generated macOS file and not related to the project.)

🎯 How to Use
Compile the project
Use the gcc compiler to compile all the .c files together:

bash
gcc checker.c common.c maincopy.c parsing.c -o rush01
Run the program
After compiling, run the executable:

bash
./rush01 "your input here"
Input format
The input should be a string of numbers separated by spaces, representing the clues around the grid.

Example:

bash
./rush01 "4 3 2 1 1 2 2 2 2 2 1 3 3 2 1 4"
🧩 Rules of Skyscrapers Puzzle
The grid is typically 4x4.

Each number in the grid represents a building of that height.

No two buildings in a row or column can have the same height.

Numbers around the grid indicate how many buildings are visible from that side, considering taller buildings hide smaller ones behind them.

📄 Notes
This was a Rush project, meaning the main focus was on completing a working solution under tight time constraints.

Code readability and modularity were kept in mind as much as possible during the rush.

The .DS_Store file should be ignored (add it to .gitignore if using Git).
