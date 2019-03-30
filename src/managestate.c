#include <stdio.h>
#include <stdlib.h>
#include "managestate.h"
#include "upload.h"

void managestate(game_struct* temp, int end_iteration){
    int i;
    int j;
    int countneightbours = 0;

    int** lifetable = malloc(temp->width * sizeof(int*));
    for(i = 0; i < temp->width; i++){
        lifetable[i] = malloc(temp->length * sizeof(int));
    }

    if (end_iteration > temp->max_iteration){
        printf("No, can do babydoll");
    }

    while (temp->iteration <= end_iteration) {

        for (i = 0; i < temp->width; i++) {

            for (j = 0; j < temp->length; j++) {


                if (j > 0 && temp->table[i][j - 1] == 0) countneightbours++;//po lewo
                if (i > 0 && j > 0 && temp->table[i - 1][j] == 0) countneightbours++; //gora
                if (i < temp->width - 1 && temp->table[i + 1][j] == 0) countneightbours++; //dol
                if (j < temp->length - 1 && temp->table[i][j + 1] == 0) countneightbours++;// po prawo


                if(temp->ifMoore == 0){
                    if (i > 0 && j > 0 && temp->table[i - 1][j - 1] == 0) countneightbours++;
                    if (i > 0 && j < temp->length - 1 && temp->table[i - 1][j + 1] == 0) countneightbours++;
                    if (j < temp->length - 1 && i < temp->width - 1 && temp->table[i + 1][j + 1] == 0) countneightbours++;
                    if (i < temp->width - 1 && temp->table[i + 1][j - 1] == 0 && j > 0) countneightbours++; //prawy dol
                }

                lifetable[i][j] = countneightbours;
                countneightbours = 0;


            }
        }
        for (i = 0; i < temp->width; i++) {
            for (j = 0; j < temp->length; j++) {

                if(lifetable[i][j]==3){
                    temp->table[i][j] = 0;
                }
                else if(lifetable[i][j] != 2){
                    temp->table[i][j] = 1;
                }
            }
        }
        temp->iteration++;
    }
}