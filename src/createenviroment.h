#ifndef ENVIROMENT_GAME_OF_LIFE_H
#define ENVIROMENT_GAME_OF_LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include "upload.h"



game_struct* blank_gamespace (game_struct* list_t);

void randomize_gamespace(game_struct* temp);

#endif