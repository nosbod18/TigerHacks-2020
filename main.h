#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <math.h>
#include <time.h>
#include <unistd.h>

#include "enginePath.h"
#include "navPath.h"
#include "player.h"

// Variables that can be used to easily adjust the amount of time the sleep() functions sleep for.
// Very useful for debuging
#define SLEEP_TINY 1 // 1
#define SLEEP_SHORT 2 // 2
#define SLEEP_LONG 4 // 4

void chooseRole(struct Player* player);
void startPath(struct Player* player);
void printComputer();
void chooseDirection();
void printMap();