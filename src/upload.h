#ifndef UPLOAD_GAME_OF_LIFE_H
#define UPLOAD_GAME_OF_LIFE_H


typedef struct base_struct{
char** table;
int width;
int length;
int iteration;
int max_iteration;
int organism_count;
}game_struct;

#endif