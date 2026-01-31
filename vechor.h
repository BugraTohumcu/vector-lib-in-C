#ifndef VECTOR_LIB
#define VECTOR_LIB

#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    int* data; 
    size_t size;
    size_t capacity;
} vector;

void resize(vector *v);
void append(vector *v, int value);
vector* initVector();
void printVector(vector *v);
void reserve(vector* v, size_t size);
void fillVec(vector *v, size_t size);

#endif