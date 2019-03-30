#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "managestate.h"
#include "upload.h"

int main(int argc, char** argv){

    if(argc != 2){
        printf("Please attach only your data file, which should contain in order: length, width, organism count and max iteration");
        EXIT_FAILURE;
    }

    FILE* in = fopen(argv[1], "r");

    game_struct* main_game_data = malloc(sizeof(game_struct));

    unpack_the_data(in, main_game_data);

    blank_gamespace(main_game_data);



    return 0;
}
