#include <stdio.h>
#include <stdlib.h>
#include "managestate.h"
#include "upload.h"

void managestate(game_struct* temp, int ifMoore, int end_iteration){
    int i;
    int j;
    int countneightbours = 0;

    int** lifetable = (int**)malloc(temp->length * sizeof(int*));
    for(i = 0; i < temp->length; i++){
        lifetable[i]=(int*)malloc(temp->width * sizeof(int));
    }

    if (end_iteration > temp->max_iteration){
        printf("No, can do babydoll");
    }

    while (temp->iteration <= end_iteration) {

        for (i = 0; i < temp->width; i++) {

            for (j = 0; j < temp->length; j++) {


                if (temp->table[i][j - 1] == '#' && j > 0) countneightbours++;
                if (temp->table[i - 1][j] == '#' && i > 0 && j > 0) countneightbours++;
                if (temp->table[i + 1][j] == '#' && j > 0 && i < temp->width - 1) countneightbours++;
                if (temp->table[i][j + 1] == '#' && j < temp->length - 1) countneightbours++;


                if(ifMoore == 0){
                    if (temp->table[i - 1][j - 1] == '#' && i > 0 && j > 0) countneightbours++;
                    if (temp->table[i - 1][j + 1] == '#' && i > 0 && j < temp->length - 1) countneightbours++;
                    if (temp->table[i + 1][j + 1] == '#' && j < temp->length - 1 && i < temp->width - 1) countneightbours++;
                    if (temp->table[i + 1][j - 1] == '#' && j > 0 && i < temp->width - 1) countneightbours++;
                }

                lifetable[i][j] = countneightbours;
                countneightbours = 0;


            }
        }
        for (i = 0; i < temp->width; i++) {

            for (j = 0; j < temp->length; j++) {

                if(lifetable[i][j]==3){
                    temp->table[i][j] = '#';
                }
                else if(lifetable[i][j] != 2){
                    temp->table[i][j] = '-';
                }
            }
        }
        temp->iteration++;
    }
}