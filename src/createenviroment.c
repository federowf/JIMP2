#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "upload.h"

void blank_gamespace (game_struct* main_game_data) {
    int i;
    int j;
    game_struct* temp = malloc(sizeof(game_struct));

    temp = main_game_data;

    temp->table = malloc(temp->length * sizeof(char*));
    for(i = 0; i < temp->length; i++){
        temp->table[i] = malloc(temp->width * sizeof(char));
    }




    for(i = 0; i < temp->width; i++){
        for(j = 0; j < temp->length; j++){
            temp->table[i][j] = '#';
        }
    }

    main_game_data = temp;
}



void randomize_gamespace(game_struct* temp) {

    int rand1;
    int rand2;
    int i;

        for (i = 0; i < temp->organism_count; i++) {

            rand1 = rand() % temp->width;
            rand2 = rand() % temp->length;

            if(temp->table[rand1][rand2] == '0') i--;

            else{
            temp->table[rand1][rand2] = '0';
            }
        }
}


