typedef struct base_struct{
char** table;
int width;
int length;
int iteration;
int max_iteration;
int organism_count;
}game_struct;

typedef struct user_coordinates{
    int x;
    int y;
    struct user_coordinates* next;
}user_coordinates_t;
