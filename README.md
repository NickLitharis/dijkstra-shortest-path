# 🚀 Dijkstra's Shortest Path Algorithm in C

This is a simple C program that finds the shortest path from a starting point (called the source vertex) to all other points in a graph using Dijkstra’s algorithm.

You can also set a maximum path distance (radius) to limit how far you want to search a feature that's useful in areas like navigation, network routing, and games.

## 💡 What This Program Does

This program uses Dijkstra's algorithm to figure out the shortest path from one vertex (your chosen starting point) to all others in a randomly generated graph.

You can also set a "radius" — which is just the maximum allowed distance so the program only shows paths within that range.

## 🛠 How to Use It
1. Compile the Code

Use a C compiler like gcc to compile the program:
```bash
gcc -o dijkstra_shortest_path dijkstra_shortest_path.c
```
2. Run the Program
```bash
./dijkstra_shortest_path
```

3. Follow the Prompts

- The program will ask you for a few inputs:

- Maximum edge weight (how large the weights between points can be)

- Number of vertices (how many points in your graph)

- Radius (maximum path length to consider)

- Source vertex (where to start from)

Then it generates a graph and runs Dijkstra’s algorithm for you.

## 🧱 How It Works (Under the Hood)

This version uses a 2D array to represent the graph, and standard arrays to track:

- Distances from the source

- Whether a node has been visited

- The path taken (via a parent array)

No fancy data structures like heaps are used it’s written to be clear and beginner-friendly.

## 🎮 What You’ll Be Asked To Input

- Maximum edge weight: The largest number that can appear as a weight between two vertices.

- Number of vertices: How many points your graph should have.

- Radius: The farthest distance you care about.

- Source vertex: The starting point for Dijkstra’s algorithm.

## 📤 What You’ll See as Output

For each vertex, the program shows:

- The shortest distance from the source.

- The path taken to get there.

- If a vertex is too far (outside the radius), or can’t be reached at all, it will tell you that too.

Example output:

| Vertex | Distance from Source | Used Path |
|--------|:----------------------:|:-----------:|
| 1 -> 3 |           3          |   1 2 3   |
| 1 -> 5 |      Unreachable     |           |


## ⏱ Performance Info

After it runs, the program will show you how long it took to calculate all paths in milliseconds.

This helps you understand how the algorithm performs as the graph gets bigger.

## 📦 Requirements

No external libraries needed, just standard C and a compiler like gcc.