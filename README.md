# Mandelbrot

[Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set) visualizer using SFML library.

![Wikipedia](Mandelbrot_sequence.gif)

***

## Prerequisites

- [G++](https://gcc.gnu.org/)
- [SFML](https://www.sfml-dev.org/index.php)
- [Make](https://www.gnu.org/software/make/) (optional)

***

## Compile and Run

``$ make run``

or

``$ g++ src/main.cpp -o3 -std=c++2a -lsfml-graphics -lsfml-window -lsfml-system -o mandelbrot``

``$ ./mandelbrot``

***

## Usage

- Left click : Zoom in
- Right click : Zoom out
- Scrollwheel up : Increase iterations
- Scrollwheel down : Decrease iterations
- Arrow keys : Move camera
