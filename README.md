# OpenFrameworks OpenGLES 2.0 Shader Template

This is a OpenGL ES 2.0 project using C++/openFrameworks. It loads a random shader and runs it.
For the random shader, the app consumes the public GitHub API and looks into this repo:

https://github.com/terabaud/bunch-of-shaders/

As a fallback, there's also a shader included, showing an animated julia set.

The julia set shader is based on a [former experiment](https://terabaud.github.io/hello-webgl/fractal/) in WebGL. I made it run smooth by replacing the colorization (lots of conditionals in the former algorithm), and reducing the number of iterations, while ensuring it still looks great.

I used a Raspberry PI 4 for development and had a lot of fun, although the overall dev experience was a 
bit different from what I'm used to. The raspberry Pi version of openframeworks doesn't make use of the 
`projectGenerator`. The workflow is to copy an example instead.

So, the app is adapted from the openFrameworks shader examples.

# Installation instructions

Change the paths in `config.make` to your needs, compile via `make`, run via `make run`
Also, the [ofxJSON](https://github.com/jeffcrouse/ofxJSON) extension is needed. I made a git clone into `openframeworks/addons`.

