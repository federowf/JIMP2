#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

game_struct* unpack_the_data(FILE* in, FILE* in2 ){

    game_struct *result;

    result= malloc(sizeof(game_struct);
    in=fopen(in, "r");
    in2=fopen(in2,"r");
    fscanf(in,"%d%d%d", &(result->length), &(result->width)); //dimensions
    fscanf(in2,"%d%d%d", &(result->length), &(result->width)); //musimy okreslic, ktore parametry maja byc zczytane

    fclose(in);
    fclose(in2);
    return result;
}