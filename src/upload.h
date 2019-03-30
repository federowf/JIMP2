#ifndef UPLOAD_GAME_OF_LIFE_H
#define UPLOAD_GAME_OF_LIFE_H


typedef struct base_struct{
char** table;
int width; //wczytana
int length; // wczytana
int iteration;
int ifMoore;
int max_iteration; //wczytana
int organism_count; // wczytana
}game_struct;

void unpack_the_data(FILE *in, game_struct *pStruct);

#endif