# OpenFrameworks OpenGLES 2.0 Shader Template

This is a OpenGL ES 2.0 project using C++/openFrameworks.

The app is highly adapted from the openFrameworks shader examples, where I learned how to load a shader and how to set uniforms.
The shader is based on a [former experiment](https://terabaud.github.io/hello-webgl/fractal/) in WebGL. I made it run smooth by replacing the colorization (lots of conditionals in the former algorithm), and reducing the number of iterations, while ensuring it still looks great.

I used a Raspberry PI 4 for development and had a lot of fun, although the overall dev experience was a bit different from what I'm used to (haven't found my optimal C++ IDE yet, I can't get back to vim yet although I was once very used to it).

Will try if I also get it to run on my Mac and my Windows machine later.

# Installation instructions

Change the paths in `config.make` to your needs, compile via `make`, run via `make run`

