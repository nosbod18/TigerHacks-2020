#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <time.h>
#include <unistd.h>

#include "fightScenes.h"
#include "player.h"
#include "main.h"

#define STEAM_DAMAGE 15

void goEngine(struct Player* player);
void inspectRobot(struct Player* player);
void enterRoom(struct Player* player);
void exitEngine(struct Player *player);
void endgame(struct Player* player);
void waiting(void);