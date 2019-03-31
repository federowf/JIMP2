#ifndef ENVIROMENT_GAME_OF_LIFE_H
#define ENVIROMENT_GAME_OF_LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include "upload.h"

/*istereg*/

void blank_gamespace (game_struct* main_game_data);

void randomize_gamespace(game_struct* temp);

void forced_by_user_gamespace(coordinates_list* head, game_struct* game);

#endif