#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

game_struct* unpack_the_data(FILE* in){

    int cord_counter = 0;

    game_struct *result;
    result = malloc(sizeof(game_struct));



    in = fopen(in, "r");
    fscanf(in,"%d %d %d", &(result->length), &(result->width), &(result->organism_count)); //dimensions



    fclose(in);
    return result;
}