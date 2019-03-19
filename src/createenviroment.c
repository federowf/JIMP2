#include <stdio.h>
#include <stdlib.h>
#include "createenviroment.h"
#include "upload.h"

char** creation (int length, int width, int organism_count, coordinates* head) {

    int r1;
    int r2;

    int i;
    int j;

    char** table = (char**)malloc(length * sizeof(char*));
    for(i = 0; i++; i < length){
        table[i]=(char*)malloc(width * sizeof(char));
    }

    for(i = 0; i < width; i++){
        for(j = 0; j < length; j++){
            table[i][j] = '0'; //fillup
        }
    }

    if (organism_count == NULL) organism_count = rand() % (length * width);

    if (head == NULL) {
        for(i = 0;i < organism_count;i++){
            r1 = rand() % width;
            r2 = rand() % length ;
            table[r1][r2] = '#';
        }

    } //generacja randomowa
    else{
        coordinates* temp = malloc(sizeof(coordinates));
        temp = head;

        if (organism_count == NULL){
            while (temp != NULL){

                table[temp->x][temp->y] = '#';
                temp = temp->next;
            }
        }

        else {
            int organisms_temp_counter = organism_count;
            while (organisms_temp_counter != 0){

                table[temp->x][temp->y] = '#';
                temp = temp->next;

                organisms_temp_counter--;
            }
        }

    }
}


