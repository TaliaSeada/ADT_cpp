#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>

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
    PAdptArray array = (PAdptArray) malloc (sizeof(AdptArray));
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

void DeleteAdptArray(PAdptArray array){
    if(array == NULL){
        return;
    }
    if(array->elements != NULL){
        for(int i = 0; i < array -> size; i++){
            if(array->elements[i]){
                array->del_func(array->elements[i]);
            }
        }
        free(array->elements);
        array->elements = NULL;
    }  
    free(array);
    array = NULL;
}

Result SetAdptArrayAt(PAdptArray array, int i, PElement new_element){
    if(array == NULL){
        return FAIL;
    }
    if(i >= array->size){
        PElement* tmp = (PElement*) calloc(i+1, sizeof(PElement));
        if (tmp == NULL) {
            return FAIL; // Error: unable to allocate memory
        }
        for(int j = 0; j < array->size; j++){
            tmp[j] = array->elements[j];
        }
        free(array->elements);
        array->elements = tmp;
        array->size = i + 1; // update size of array
    }
    if(array->elements[i]){
        array->del_func((array->elements)[i]); // delete the previous element
    }
    (array->elements)[i] = array->copy_func(new_element);
    return SUCCESS;
}


PElement GetAdptArrayAt(PAdptArray array, int i){
    if(array->size < i || array->elements[i] == NULL){
        return NULL;
    }
    return array->copy_func(array->elements[i]);
}

int GetAdptArraySize(PAdptArray array){
    return array->size;
}

void PrintDB(PAdptArray array){
    if(array == NULL){
        return;
    }
    for(int i = 0; i < array->size; i++){
        if(array->elements[i]){
            array->print_func(array->elements[i]);
        }
    }
}
