#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "upload.h"

game_struct* blank_gamespace (game_struct* list_t) {
    int i;
    int j;
    game_struct* temp = malloc(sizeof(game_struct));
    temp->table = (char**)malloc(temp->length * sizeof(char*));
    for(i = 0; i < temp->length; i++){
        temp->table[i]=(char*)malloc(temp->width * sizeof(char));
    }
    temp = list_t;



    for(i = 0; i < temp->width; i++){
        for(j = 0; j < temp->length; j++){
            temp->table[i][j] = '#';
        }
    }
    return temp;
}



void randomize_gamespace(game_struct* temp) {

    int rand1;
    int rand2;
    int i;

        for (int i = 0; i < temp->organism_count; i++) {

            rand1 = rand() % temp->width;
            rand2 = rand() % temp->length;

            if(temp->table[rand1][rand2] == '0') i--;

            else{
            temp->table[rand1][rand2] = '0';
            }
        }
}


