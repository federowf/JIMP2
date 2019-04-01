#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "upload.h"
#include <time.h>


/*do przejrzenia*/

void blank_gamespace (game_struct* main_game_data) {
    int i;
    int j;
    game_struct* temp;

    temp = main_game_data;

    temp->table = malloc(temp->width * sizeof(int*));
    for(i = 0; i < temp->width; i++){
        temp->table[i] = malloc(temp->length * sizeof(int));
    }


    for( i = 0; i < temp->width; i++){
        for( j = 0; j < temp->length; j++){
            temp->table[i][j] = 1;
        }
    }


    main_game_data = temp;
}



void randomize_gamespace(game_struct* temp) {

    srand(time(NULL));

    int rand1;
    int rand2;
    int i = temp->organism_count;

        while(i > 0){
            rand1 = rand() % (temp->width);
            rand2 = rand() % (temp->length);

            if(temp->table[rand1][rand2] == 1){

                temp->table[rand1][rand2] = 0;
                i--;
            }
        }
}

void forced_by_user_gamespace(coordinates_list* head, game_struct* game){

    coordinates_list* temp = malloc(sizeof(coordinates_list));

    temp = head;

    while (temp->next!=NULL){
        game->table[temp->width][temp->length] = 0;
        temp = temp->next;
    }
}
