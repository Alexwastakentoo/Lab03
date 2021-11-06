//
// Created by skyle on 06/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex02Fn.h"

#define ERR_ARGC_NUM -1
#define ERR_MALLOC_FAIL -2

#define NAME_SIZE 4 + 1
#define MAX_RECT_NUM 100




int main(int argc, char** argv){

    rectangle_t *rect_vector = NULL;
    int rectCount;
    char temp_name[NAME_SIZE], stored;

    if(argc != 4){
        fprintf(stderr, "%s: Error wrong invalid argument number.", argv[0]);
        return ERR_ARGC_NUM;
    }

    rect_vector = malloc(MAX_RECT_NUM * sizeof(rectangle_t));
    if(rect_vector == NULL){
        fprintf(stderr, "%s: Error allocating memory.", argv[0]);
        freeMyMem(&rect_vector);
        return ERR_MALLOC_FAIL;
    }

    FILE * inputFile = fopen(argv[1], "r");

    rectCount = 0;
    while(fscanf(inputFile, "%s " , temp_name) != EOF){

        stored = 0;
        for(int i = 0; i < rectCount && stored == 0; i++){
            if(!strcmp(rect_vector[i].name, temp_name)){
                fscanf(inputFile, "%f %f", &rect_vector[i].xb, &rect_vector[i].yb);
                stored = 1;
            }
        }

        if(stored == 0){
            strcpy(rect_vector[rectCount].name, temp_name);
            fscanf(inputFile,"%f %f", &rect_vector[rectCount].xa, &rect_vector[rectCount].ya);
            rectCount++;
        }
    }
    fclose(inputFile);

    rect_vector = (rectangle_t *) realloc(rect_vector, rectCount * sizeof(rectangle_t));
    if(rect_vector == NULL){
        fprintf(stderr, "%s: Error allocating memory.", argv[0]);
        freeMyMem(&rect_vector);
        return ERR_MALLOC_FAIL;
    }


    for(int i = 0; i < rectCount; i++){
        printf("|Rectangle name: %s | xa: %f  ya: %f | xb = %f  yb = %f |\n", rect_vector[i].name, rect_vector[i].xa,
               rect_vector[i].ya, rect_vector[i].xb, rect_vector[i].yb);
        fflush(stdout);
    }

    apCalc(&rect_vector, rectCount);


    areaBubbleSort(&rect_vector, rectCount);
    perBubbleSort(&rect_vector, rectCount);

    for(int i = 0; i < rectCount; i++){
        printf("\n|| area[%d]: %f |  perimeter[%d]: %f ||", i, rect_vector[i].area, i, rect_vector[i].perimeter);
        fflush(stdout);
    }

    return 0;
}