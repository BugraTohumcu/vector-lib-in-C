#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vechor.h"

vector* initVector(){
    vector* v = malloc(sizeof(vector));
    v->capacity = 1;
    v->size = 0;
    v->data = calloc(v->capacity, sizeof(int));
    return v;
}

void resize(vector *v){ 
    size_t new_capacity = v->capacity * 2;
    int* tmp = realloc(v->data, new_capacity * sizeof(int));
    if(!tmp){
        printf("Reallocation failed while resizing!");
        return;
    }
    v->capacity = new_capacity;
    v->data = tmp;
}

void append(vector *v, int value){
    if(v->size == v->capacity) resize(v);
    v->data[v->size++] = value;
}

void appendArr(vector *v, int* arr){
    if(v->size == v->capacity) resize(v);
    size_t arrLength = sizeof(arr) / sizeof(int) + 1;
    for(int i = 0; i < arrLength; i++){
        append(v,arr[i]);
    }
}

void reserve(vector* v, size_t size){
    if(v->capacity >= size) return;
    int* tmp = realloc(v->data, size * sizeof(int));
    if(!tmp){
        printf("Reallocation failed while reserving!");
        return;
    }
    v->capacity = size;
    v->data = tmp;
}

void printVector(vector *v){
    printf("[");
    for(size_t i = 0; i < v->size; i++){
        if(i == v->size-1) printf("%d", v->data[i]);
        else printf("%d, ", v->data[i]);
    }
    printf("]\n");
}


int main(){

    size_t n = 1000000000;
    vector *v1 = initVector();
    size_t start, end;
    double cpu_time;

    start = clock();
    for (size_t i = 0; i < n; i++)
    {
        append(v1,i);
    }

    end = clock();
    cpu_time = (double)(end-start) / CLOCKS_PER_SEC;

    printf("Without reserve: %f seconds\n", cpu_time);

    vector *v2 = initVector();
    reserve(v2,n);

    start = clock();
    for (size_t i = 0; i < n; i++)
    {
        append(v2,i);
    }

    end = clock();
    cpu_time = (double)(end-start) / CLOCKS_PER_SEC;
    printf("With reserve: %f seconds\n", cpu_time);

    return 0;
}