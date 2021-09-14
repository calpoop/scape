# Scape - OpenGL game engine

## Setup

Install `glfw`:

**Ubuntu Linux**:
`sudo apt install lib-glfw3-dev`


Install glad:

**Ubuntu Linux**:

Download from https://glad.dav1d.de/:

- Language: C/C++
- Specification: OpenGL:
- API: gl Version 3.3
- Profile: Core

Check "Generate a loader"

Everything else as default.

Download the generated zip file and under the "include" folder, there should be a file called `glad.h`; copy that file into `/usr/include/glad` (you need to create this directory)


## Build

Make sure you have cmake installed:

**Ubuntu Linux**:
`sudo apt-get install cmake`


In the root directory of this project, create a new directory called `build`

From the root directory of the project, run:

`cmake -S . -B build`

Then go to your build directory, make the executable and run it:

`cd build/`
`make`
`./scape`
