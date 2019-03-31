#include <stdio.h>
#include <stdlib.h>
#include "pngexample.h"
#include "createenviroment.h"
#include "managestate.h"
#include "upload.h"

int main(int argc, char** argv){

    if(argc < 2){
        printf("Please attach only your data file, which should contain in order: length, width, organism count, max iteration, how many frames would u like to skip and 0 if you want to simulate by Moores rules or 1 otherwise");
        EXIT_FAILURE;
    }

    FILE* in = fopen(argv[1], "r");

    game_struct* main_game_data = malloc(sizeof(game_struct));

    unpack_the_data(in, main_game_data);

    fclose(in);

    blank_gamespace(main_game_data);

    if (argc == 3){

        FILE* in_2 = fopen(argv[2], "r");

        coordinates_list* cords_input = malloc(sizeof(coordinates_list));

        upack_the_coordinates(in_2,cords_input);

        forced_by_user_gamespace(cords_input,main_game_data);

      /*  coordinates_list* temp = malloc(sizeof(coordinates_list));

        temp = cords_input;

        while (temp->next!=NULL){
            printf("%d % d \n", temp->width,temp->length);
            temp = temp->next;
        }*/

    }

    else{
        randomize_gamespace(main_game_data);
    }


    printf("\nStarting order");

    for(int i = 0; i < main_game_data->width; i++){
        printf("\n");
        for(int j = 0; j < main_game_data->length; j++){
            printf("%d",main_game_data->table[i][j]);
        }
    }

    int i = 0;

    while(i <= main_game_data->max_iteration){
        printf("\n\nIteration no. %d", i + 1);
        managestate(main_game_data, i);
        i += main_game_data->frames_skip;




        for(int i = 0; i < main_game_data->width; i++){
            printf("\n");
            for(int j = 0; j < main_game_data->length; j++){
                printf("%d",main_game_data->table[i][j]);
            }
        }
        printf("\n");




    }


   // zapis_png(main_game_data);


    return 0;
}
