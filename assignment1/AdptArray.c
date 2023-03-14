#include "AdptArray.h"
#include <stdio.h>
typedef struct AdptArray_{
    // array and its size
    PElement* elements;
    int size;
    // functions
    COPY_FUNC copy_func;
    DEL_FUNC del_func;
    PRINT_FUNC print_func;
    
} AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC copy_func, DEL_FUNC del_func, PRINT_FUNC print_func) {
    PAdptArray array = (PAdptArray)malloc(sizeof(AdptArray));
    if (array == NULL) {
        return NULL; // Error: unable to allocate memory
    }
    // array and its size
    array->elements = NULL;
    array->size = 0;
    // functions
    array->copy_func = copy_func;
    array->del_func = del_func;
    array->print_func = print_func;
    
    return array;
}

void DeleteAdptArray(PAdptArray){

}

Result SetAdptArrayAt(PAdptArray, int, PElement){

}

PElement GetAdptArrayAt(PAdptArray, int){

}

int GetAdptArraySize(PAdptArray){

}

void PrintDB(PAdptArray){

}