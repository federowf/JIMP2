#ifndef UPLOAD_GAME_OF_LIFE_H
#define UPLOAD_GAME_OF_LIFE_H

typedef struct user_cord_t{
    int width;
    int length;
    struct user_cord_t* next;
}coordinates_list;


typedef struct outcome{
    int** table;
    int iteration;
    struct outcome* next;
}screenshots;


typedef struct frames_t{
    int frame;
    int skip_frames_as_well;
    struct frames_t* next;
}frames;



typedef struct base_struct{
int** table;
int width;
int length;
int iteration;
int frames_skip;
int ifMoore;
int max_iteration;
int organism_count;
}game_struct;

void unpack_the_data(FILE *in, game_struct *pStruct);
void upack_the_coordinates(FILE* in, coordinates_list* head);
void unpack_frames(frames* head, FILE* in_3);
#endif