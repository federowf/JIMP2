#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

game_struct* unpack_the_data(FILE* in, FILE* in2, user_coordinates_t* head){

    int cord_counter = 0;

    game_struct *result;
    result = malloc(sizeof(game_struct);


    user_coordinates_t *temp_cord_list;
    temp_cord_list = malloc(sizeof(user_coordinates_t));
    temp_cord_list = head;

    in = fopen(in, "r");
    in2 = fopen(in2,"r");

    fscanf(in,"%d %d %d", &(result->length), &(result->width)), &(result->organism_count)); //dimensions



    while(cord_counter < result->organism_count) {


        fscanf(in2, "%d %d", &(temp_cord_list->x), &(temp_cord_list->y)); //musimy okreslic, ktore parametry maja byc zczytane

        cord_counter++;
    }



    fclose(in);
    fclose(in2);
    return result;
}