### ADT 
This program demonstrates the use of an Adaptive Array data structure. </br>
The Adaptive Array is implemented as a dynamic array that can resize itself as new elements are added to it. </br>

The program creates two Adaptive Arrays, one for storing books and one for storing people. It then adds some elements to each array, prints the size of each array, and prints the contents of each array.

The Adaptive Array is implemented as a struct named AdptArray. The struct has four fields:

    elements - an array of pointers to elements of the array.
    size - the current size of the array.
    copy_func - a function pointer to a function that makes a copy of an element.
    del_func - a function pointer to a function that deletes an element.

The program uses function pointers to allow for the Adaptive Array to store elements of any type. The copy_func and del_func functions are used to make a copy of an element and to delete an element, respectively.

Results: </br>
![WhatsApp Image 2023-03-17 at 14 47 45](https://user-images.githubusercontent.com/78349342/225912938-3d85b044-f1bd-42ee-83a7-8b149eb04e87.jpeg)
