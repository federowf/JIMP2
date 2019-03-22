#include <stdio.h>
#include <stdlib.h>
#include "upload.h"



game_struct* blank_gamespace (game_struct* list_t);

void forced_by_user_gamespace(user_coordinates_t* coordinates, game_struct* temp);

void randomize_gamespace(game_struct* temp);

