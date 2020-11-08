#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "player.h"

// Symbolic constants for the weapon damages and robot stats
#define ROBOT_HEALTH 50
#define ROBOT_DAMAGE 10
#define REVOLVER 10
#define WRENCH 8
#define DRILL 12
#define RIFLE 15
#define CROWBAR 12
#define DOCTOR_HEALTH_BONUS 20

void fight(struct Player *player, int steam);