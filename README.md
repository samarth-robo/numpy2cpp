# numpy2cpp
Minimal code to access data in a numpy ndarray in c++

This code uses boost::python to import a small Python module (python/mod.py) in C++ code.

Then it uses [Boost.NumPy](https://github.com/ndarray/Boost.NumPy) to copy the data in the numpy ndarray returned by the Python module, to a C++ std::vector<double>.

You can change the dtype and dimensions of the ndarray at will, this code is intended to point you in the right direction. You will find tons of articles on the Internet about accessing C++ data in a Python module, but IMO it is difficult to find resources to do the opposite.

# installation
1. Compile and install [Boost.NumPy](https://github.com/ndarray/Boost.NumPy)
2. Edit CMakeLists.txt to specify the library and header installation locations of Boost.NumPy
3. `mkdir build && cd build && make && ./test`
