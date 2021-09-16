# Mandelbrot

Mandelbrot's fractal visualizer using SFML library.

***

**Prerequisites :**

- g++
- SFML
- make (optional)

***

**Compile and Run :**

``$ make run`` <br />
or <br />
``$ g++ src/main.cpp -std=c++2a -lsfml-graphics -lsfml-window -lsfml-system -o mandelbrot`` <br />
``$ ./mandelbrot``

***

**Usage :**

- Left click : Zoom in
- Right click : Zoom out
- Scrollwheel up : Increase iterations
- Scrollwheel down : Decrease iterations
- Arrow keys : Move camera