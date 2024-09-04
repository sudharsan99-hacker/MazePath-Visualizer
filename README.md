# MazePath-Visualizer

# Maze Pathfinding with Graphics

This repository features a C++ program that uses the `graphics.h` library to visualize and solve a maze. The program employs a breadth-first search (BFS) algorithm to find the shortest path from the maze's starting point (top-left corner) to the ending point (bottom-right corner).

# Key Features

Maze Creation: Users input the maze's dimensions and specify walls and paths. The maze is then graphically represented using the `graphics.h` library.
Pathfinding Algorithm: A BFS algorithm is used to explore the maze and determine the shortest path from the start to the end. The maze is updated to show the path found.
Graphical Visualization: The `graphics.h` library is used to draw the maze and visually differentiate between walls and paths.

# How It Works

Initialization:
   - Initializes graphics mode using `graphics.h`.
   - Prompts users for maze dimensions and wall/path input.

Maze Drawing:
   - Draws the maze grid using rectangles.
   - Fills walls with a dark gray color based on user input.

User Input:
   - Users enter whether each cell in the maze is a wall (1) or a path (0).
   - The graphical representation is updated accordingly.

Pathfinding:
   - BFS algorithm explores the maze, marking cells with distance values.
   - Maintains a queue to track cells for exploration.
   - Updates the maze to highlight the shortest path from the start to the destination.

Output:
   - Displays the shortest path and its length.

# Usage

1. Compile the code with a C++ compiler that supports `graphics.h`. Ensure graphics library files are properly configured.
2. Run the program and input maze dimensions and cell types.
3. Observe the graphical maze and the calculated shortest path.

# Requirements

- `graphics.h` library (typically used with Turbo C++ or compatible setups).
- C++ development environment that supports `graphics.h`.

This program provides a visual and algorithmic approach to solving mazes, showcasing practical applications of BFS and graphical programming.
