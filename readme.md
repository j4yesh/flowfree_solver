# Flow Free Solver

This repository contains a C++ implementation of a solver for the puzzle game "Flow Free". The solution uses Standard Template Library (STL) features and the backtracking algorithm to find solutions to Flow Free grids. The approach is conceptually similar to the "rat in a maze" problem.


## Introduction
Flow Free is a popular puzzle game where the objective is to connect pairs of colored dots on a grid with paths that cover the entire grid. This C++ program provides a solution for the Flow Free game using a backtracking approach.
For more details about the game, you can check out the official Flow Free game on the Google Play Store: [Flow Free on Google Play](https://play.google.com/store/apps/details?id=com.bigduckgames.flow&hl=en_IN)

## Features
- Solves Flow Free puzzles of varying grid sizes (e.g., 5x5, 6x6, 8x8, etc.).
- Uses backtracking to explore all possible paths and find a valid solution takes too much time for big grid sizes.
- Implementation leverages the C++ Standard Template Library (STL) for efficient data handling.

## Input Notation
- Our intuition is to map the grid into a 2D vector.
- While mapping, a dot should be represented by a capital letter, corresponding to the first letter of its color. The letter must be uppercase.
 ![img](https://i.imghippo.com/files/LRLkD1723842213.png)
- An underscore (_) should be used to represent blank spaces.
- The solution will place the corresponding lowercase letter on the appropriate positions in the grid.
![img](https://i.imghippo.com/files/qLOaa1723842146.png)

![img](https://github.com/j4yesh/flowfree_solver/raw/main/Screenshot%202024-04-22%20074357.png)


## Installation
To compile and run the program, ensure you have a C++ compiler installed on your system (e.g., g++). 

