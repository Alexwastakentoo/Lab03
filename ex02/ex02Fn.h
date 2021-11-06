//
// Created by skyle on 06/11/2021.
//

#ifndef LAB03_EX02FN_H
#define LAB03_EX02FN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NAME_SIZE 4 + 1
struct rectangle_s{

    char name[NAME_SIZE];
    float xb, yb;
    float xa, ya;

    float area, perimeter;

}
typedef rectangle_t;


void freeMyMem(rectangle_t**);
void areaBubbleSort(rectangle_t** array, size_t size); // bubble sort starting from a completely non-ordered array of floats
void perBubbleSort(rectangle_t** array, size_t size);
void apCalc(rectangle_t** rectArray_t, size_t rectNum); // compute areas of rectangles defined by two opposite vertexes


#endif //LAB03_EX02FN_H
