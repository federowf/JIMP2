#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

void unpack_the_data(FILE* in, game_struct* result){

    int org_count;
    int len;
    int wid;
    int max_it;
    int frames;
    int ifMoore;

    fscanf(in,"%d %d %d %d %d %d", &len, &wid, &org_count, &max_it, &frames, &ifMoore); //dimensions

    result->length = len;
    result->width = wid;
    result->organism_count = org_count;
    result->max_iteration = max_it;
    result->iteration = 0;
    result->ifMoore = ifMoore;
    result->frames_skip = frames;
    result->table = malloc(result->length * sizeof(char*));
    for(int i = 0; i < result->length; i++){
        result->table[i] = malloc(result->width * sizeof(char));
    }
    fclose(in);
}

void upack_the_coordinates(FILE* in_2, coordinates_list* head){

    coordinates_list* temp = malloc(sizeof(coordinates_list));

    temp = head;

     int width;
     int length;

     while (fscanf(in_2, "%d %d", &width, &length) != EOF){
         temp->width = width;
         temp->length = length;
         temp->next = malloc(sizeof(coordinates_list));
         temp = temp->next;
         temp->next = NULL;
     }

}

void unpack_frames(frames* head, FILE* in_3){

    frames* temp = malloc(sizeof(frames));

    temp = head;

    int frame;

    while (fscanf(in_3,"%d",&frame)!= EOF){
        temp->frame = frame;
        temp->next = malloc(sizeof(frames));
        temp = temp->next;
        temp->next = NULL;
    }

}