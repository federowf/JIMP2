#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

void unpack_the_data(FILE* in, game_struct* result){

    int org_count;
    int len;
    int wid;
    int max_it;
    int frames;
    int ifMoore;

    fscanf(in,"%d %d %d %d %d %d", &len, &wid, &org_count, &max_it, &frames, &ifMoore); //dimensions

    result->length = len;
    result->width = wid;
    result->organism_count = org_count;
    result->max_iteration = max_it;
    result->iteration = 0;
    result->ifMoore = ifMoore;
    result->frames_skip = frames;
    result->table = malloc(result->length * sizeof(char*));
    for(int i = 0; i < result->length; i++){
        result->table[i] = malloc(result->width * sizeof(char));
    }
    fclose(in);
}