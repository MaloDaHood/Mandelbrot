# Mandelbrot

<a href="https://en.wikipedia.org/wiki/Mandelbrot_set">Mandelbrot set</a> visualizer using SFML library.
<br />
<img href="https://upload.wikimedia.org/wikipedia/commons/a/a4/Mandelbrot_sequence_new.gif">

***

**Prerequisites :**

- <a href="https://gcc.gnu.org/">G++</a>
- <a href="https://www.sfml-dev.org/index.php">SFML</a>
- <a href="https://www.gnu.org/software/make/">make</a> (optional)

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
