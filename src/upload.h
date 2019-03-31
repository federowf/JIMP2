#ifndef UPLOAD_GAME_OF_LIFE_H
#define UPLOAD_GAME_OF_LIFE_H

typedef struct user_cord_t{
    int width;
    int length;
    struct user_cord_t* next;
}user_coordinates;



typedef struct base_struct{
int** table;
int width; //wczytana
int length; // wczytana
int iteration;
int frames_skip;
int ifMoore;
int max_iteration; //wczytana
int organism_count; // wczytana
}game_struct;

void unpack_the_data(FILE *in, game_struct *pStruct);
void upack_the_coordinates(FILE* in, user_coordinates* head);

#endif