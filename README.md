# linear-algebra-engine-cpp
Simple and lightweight 2D vector space visualizer built in C++ using raylib.

---

To build and run this project, you need:
* A C++17 compliant compiler (GCC/MinGW, Clang, or MSVC)
* [Raylib](https://www.raylib.com/) installed on your system

---

```c++
// Fill Plot class with pixels
Plot plot({500, 500}, {500, 500}, 60);

Vector2 i = {1, 0}; // basis vector i
Vector2 j = {0, 1}; // basis vector j
Vector2 v = {1, 2};

// Draw the space
drawGrid(plot, 1, GRAY, i, j);
drawAxes(plot, 3, WHITE, i, j);
drawBorder(plot, 3, WHITE, i, j);
drawVector(plot, 3, YELLOW, i, j, v);
drawFunction(plot, 3, RED, i, j, [] (float x) {return x*x;});

```
