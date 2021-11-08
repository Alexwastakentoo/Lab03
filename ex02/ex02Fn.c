//
// Created by skyle on 06/11/2021.
//

#include "ex02Fn.h"

void freeMyMem(rectangle_t** rectangle_vector){

    if(rectangle_vector != NULL){
        free(rectangle_vector);
        rectangle_vector = NULL;
    }
}


void areaBubbleSort(rectangle_t* array, size_t size){

    float temp;
    rectangle_t tempt;
    char flag;

    flag = 1;
    for(int j = 0; j < size-1 && flag == 1; j++){
       // printf("Checking: Array[%d]: %f against Array[%d]: %f\n", j, array[j].area, j+1,array[j+1].area);
       // fflush(stdout);
        flag = 0;
        for(int i = 0; i<(size-1-j); i++){
            if(array[i].area > array[i+1].area){
                flag = 1;
               // printf("Swapping: Array[%d]: %f with Array[%d]: %f\n", i, array[i].area, i+1,array[i+1].area);
               // fflush(stdout);
                /*temp = array[i+1].area;
                array[i+1].area = array[i].area;
                array[i].area = temp;*/

                tempt = array[i+1];
                array[i+1] = array[i];
                array[i] = tempt;
            }
        }
    }
}

void perBubbleSort(rectangle_t* array, size_t size){

    float temp;
    rectangle_t tempt;
    char flag;

    flag = 1;
    for(int j = 0; j < size-1 && flag == 1; j++){
       // printf("\nChecking: Array[%d]: %f against Array[%d]: %f\n", j, array[j].perimeter, j+1,array[j+1].perimeter);
       // fflush(stdout);
        flag = 0;
        for(int i = 0; i<(size-1-j); i++){
            if(array[i].perimeter > array[i+1].perimeter){
                flag = 1;
              //  printf("Swapping: Array[%d]: %f with Array[%d]: %f\n", i, array[i].perimeter, i+1,array[i+1].perimeter);
              //  fflush(stdout);
                /*temp = array[i+1].perimeter;
                array[i+1].perimeter = array[i].perimeter;
                array[i].perimeter = temp;*/

                tempt = array[i+1];
                array[i+1] = array[i];
                array[i] = tempt;
            }
        }
    }
}

void apCalc(rectangle_t* rectArray_t, size_t rectNum){ // on the second iteration it's not reading the next rectArray_t[i+1] but garbage ??????????

    float s1, s2;

    for(int i = 0; i < rectNum; i++){

        s1 = fabsf(rectArray_t[i].xb - rectArray_t[i].xa);
        s2 = fabsf(rectArray_t[i].yb - rectArray_t[i].ya);

        printf("\n|Rectangle name: %s | side 1: %f | side 2: %f |", rectArray_t[i].name, s1, s2);
        fflush(stdout);

        rectArray_t[i].area = s1*s2;
        rectArray_t[i].perimeter = 2 * (s1 + s2);

        printf(" area : %f | perimeter : %f |", rectArray_t[i].area, rectArray_t[i].perimeter );
        fflush(stdout);
    }

}
