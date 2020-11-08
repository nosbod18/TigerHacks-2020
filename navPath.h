#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "player.h"
#include "fightScenes.h"
#include "enginePath.h"
#include "navMinigame.h"

void goNav(struct Player *player);
void pathNavigation();
void printNavComputer();
void exitNavigation(struct Player *player);

void goKitchen();
void pathKitchen();
void inspectKitchen(struct Player *player, int decision);
void exitKitchen(struct Player *player);

void changeCourse(struct Player *player);
void waiting();