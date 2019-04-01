#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

void get_screenshot(game_struct * main_game_data, int* iterations, screenshots* first_screen){

    screenshots* result = malloc(sizeof(screenshots));

    result->table = malloc(main_game_data->width * sizeof(int*));
    for(int i = 0; i < main_game_data->width; i++){
        result->table[i] = malloc(main_game_data->length * sizeof(int));
    }

    result = first_screen;

    while(result->next!=NULL){

        result = result->next;

    }

    result->table = main_game_data->table;
    result->iteration = iterations;
    result->next = NULL;
}