#include <stdio.h>
#include <stdlib.h>
#include "pngexample.h"
#include "createenviroment.h"
#include "managestate.h"
#include "upload.h"
#include "get_screenshot.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <png.h>
#include "true_png.h"


int main(int argc, char** argv){

    if(argc < 2){
        printf("Please attach only your data file, which should contain in order: length, width, organism count, max iteration, how many frames would u like to skip and 0 if you want to simulate by Moores rules or 1 otherwise");
        EXIT_FAILURE;
    }

    frames* forced_by_user_screenshot = malloc(sizeof(frames));

    FILE* in = fopen(argv[1], "r");

    game_struct* main_game_data = malloc(sizeof(game_struct));

    unpack_the_data(in, main_game_data);

    fclose(in);

    blank_gamespace(main_game_data);

    if (argc > 2){

        FILE* in_2 = fopen(argv[2], "r");

        coordinates_list* cords_input = malloc(sizeof(coordinates_list));

        upack_the_coordinates(in_2,cords_input);

        forced_by_user_gamespace(cords_input,main_game_data);

        fclose(in_2);
    }

    else{
        randomize_gamespace(main_game_data);
    }

    if(argc > 3){

        FILE* in_3 = fopen(argv[3],"r");

        unpack_frames(forced_by_user_screenshot,in_3);

        fclose(in_3);
    }

    else{
        free(forced_by_user_screenshot);
    }


    /*printf("\nStarting order");

    for(int i = 0; i < main_game_data->width; i++){
        printf("\n");
        for(int j = 0; j < main_game_data->length; j++){
            printf("%d",main_game_data->table[i][j]);
        }
    }*/



    screenshots* result = malloc(sizeof(screenshots));

    game_struct* main_game_data_head = malloc(sizeof(main_game_data));

    main_game_data_head = main_game_data;


    if(argc < 4) {

        int i = 0;

        while (i <= main_game_data->max_iteration) {

            //printf("\n\nIteration no. %d", i + 1);
            managestate(main_game_data, i);
            i += main_game_data->frames_skip;


            /*for (int k = 0; k < main_game_data->width; k++) {
                printf("\n");
                for (int j = 0; j < main_game_data->length; j++) {
                    printf("%d", main_game_data->table[k][j]);
                }
            }
            printf("\n");*/


        }
    }


    if (argc > 3){

        main_game_data = main_game_data_head;

        while (forced_by_user_screenshot->next != NULL) {

            managestate(main_game_data, forced_by_user_screenshot->frame);

            printf("ROZMIARY %d %d\n",main_game_data->width,main_game_data->length);

            /*char filename[20];

            sprintf(filename, "bin/frame%d.png", forced_by_user_screenshot->frame);

            write_png_file("frame.png");

            process_file(main_game_data);*/

            forced_by_user_screenshot = forced_by_user_screenshot->next;
        }
    }





    return 0;
}
