![C/C++ CI](https://github.com/StFreve/eevset/workflows/C/C++%20CI/badge.svg)
# eevset
Extended Environment Variables Setter


## Build instructions

Dependencies:

 - [**GoogleTest**](https://github.com/google/googletest) - used as unit tests' framework

**Linux and Mac OS**

    git clone https://github.com/StFreve/eevset
    cd eevset
    git submodule update --init
    mkdir build && cd build
    cmake ..
    make

**Windows**

