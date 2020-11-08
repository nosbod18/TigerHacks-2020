#pragma once

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "player.h"
#include "main.h"

void navMini(struct Player *player);
void answers(int x, int y, int* total, struct Player *player);
