#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

game_struct* unpack_the_data(FILE* in){

    int cord_counter = 0;

    game_struct *result;
    result = malloc(sizeof(game_struct));



    in = fopen(in, "r");
    fscanf(in,"%d %d %d", &(result->length), &(result->width), &(result->organism_count)); //dimensions


<<<<<<< HEAD
    result= malloc(sizeof(game_struct);
    in = fopen(in, "r");
    in2 = fopen(in2,"r");
    fscanf(in,"%d%d%d", &(result->length), &(result->width), &(max)); //dimensions
    fscanf(in2,"%d%d%d", &(result->length), &(result->width)); //musimy okreslic, ktore parametry maja byc zczytane
=======
>>>>>>> 25feb9c8543d893c2b2085647a681d88e9e5ccaf

    fclose(in);
    return result;
}