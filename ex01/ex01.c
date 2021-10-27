#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 20 + 2 // +2 due to \n and \0 chars
#define MAX_LINE_SIZE 100 + 2
#define MAX_WORD_NUM 100

#define ERR_INVALID_ARG -1
#define ERR_MALLOC_FAIL -2

int main(int argc, char** argv) {

    char** list = NULL;
    char* token = NULL;
    char linebuffer[MAX_WORD_SIZE];
    int wordsStored = 0, found[MAX_WORD_NUM] = {0};


    if(argc != 3){
        fprintf(stderr, "%s: Error invalid number of arguments (%d instead of 3)",argv[0], argc);
        return ERR_INVALID_ARG;
    }


    FILE *listFile = fopen(argv[2], "r");
    // read the list line by line and store the words into a pointer of pointers

    // instead of allocating new memory each time we can allocate for the whole MAX_WORD_NUM and cut later the pointer
    // if not all the space is needed --> keep track of how many slots taken with a counter.

    list = (char **) malloc(MAX_WORD_NUM * sizeof(char*));
    if(list == NULL){
        fprintf(stderr,"%s: Error allocating memory", argv[0]);
        free(list);
        list = NULL;

        return ERR_MALLOC_FAIL;
    }

    int i = 0;
    while(fgets(linebuffer, MAX_WORD_SIZE, listFile) != NULL){

        list[i] = linebuffer;

        wordsStored++; // increase counter since we entered the while
        fprintf(stdout,"%s at address %p\n", list[i], &list[i]);
        i++;
    }


    // free the not utilized memory of list
    for(int j = wordsStored; j < MAX_WORD_NUM - wordsStored; j++){
        free(&list[j]);
    }

    fclose(listFile);



    FILE *textFile = fopen(argv[1], "r");
    // read file line by line and use strtok to look for keywords saved in list


    int j = 0;
    while(fgets(linebuffer, MAX_LINE_SIZE, textFile)){

        token = strtok(linebuffer, " ");
        while(token != NULL){
            if(strncasecmp(token, list[j], strlen(token)) == 0){ // segmentation fault --> ???
                found[j]++;
            }
            token = strtok(NULL, "");
            j++;
            list++;
        }
    }
    fclose(textFile);

    printf("\n");

    list = 0;
    for(int k = 0; k < wordsStored; k++){
        printf("%s was found %d times.\n", list[k], found[k]);
    }

    return 0;
}
