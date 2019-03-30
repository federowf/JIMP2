#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "managestate.h"
#include "upload.h"

int main(int argc, char** argv){

    if(argc != 2){
        printf("Please attach only your data file, which should contain in order: length, width, organism count, max iteration and 0 if you want to simulate by Moores rules or 1 otherwise");
        EXIT_FAILURE;
    }

    FILE* in = fopen(argv[1], "r");

    game_struct* main_game_data = malloc(sizeof(game_struct));

    unpack_the_data(in, main_game_data);

    fclose(in);

    blank_gamespace(main_game_data);



    for(int i = 0; i < main_game_data->width; i++){
        printf("\n");
        for(int j = 0; j < main_game_data->length; j++){
            printf("%c",main_game_data->table[i][j]);
        }
    }
    printf("\n");



    randomize_gamespace(main_game_data);

    int i = 0;






    for(int i = 0; i < main_game_data->width; i++){
        printf("\n");
        for(int j = 0; j < main_game_data->length; j++){
            printf("%c",main_game_data->table[i][j]);
        }
    }
    printf("\n");






    while(i < main_game_data->max_iteration){
    managestate(main_game_data,i);
    i++;
    }






    return 0;
}
