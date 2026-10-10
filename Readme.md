# Mini C Vector Library

A simple dynamic array implementation in C, inspired by C++ `std::vector`.  
Includes memory management, dynamic resizing, and a small benchmark to measure performance improvements using `reserve()`.

---

## Features

- Dynamic resizing with `resize()`  
- `append()` for adding elements  
- `reserve()` to pre-allocate memory and speed up multiple inserts  
- `fillVec()` to populate the vector easily  
- `printVector()` for simple display  
- Memory-safe with `calloc()`

---

## Files

- `vector.h` – Header file containing typedef and function prototypes  
- `vector.c` – Implementation of all vector functions  
- `main.c` – Benchmark and test usage

---

## Usage

Include the header in your project:

```c
#include "vector.h"

int main() {
    vector* v = initVector();
    append(v, 10);
    append(v, 20);
    printVector(v); // Output: [10, 20]

    free(v->data);
    free(v);
    return 0;
}
