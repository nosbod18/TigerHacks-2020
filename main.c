#include "main.h"

// Alone: A Text-Based Adventure Game
// November 2020 TigerHacks Program
// Creators: Abby Hynes, Evan Dobson, Drew Clutes, Alex Wears
// Written on repl.t

// Main
//-------------------------------------------------
int main(void) 
{
    struct Player player;
	srand(time(NULL)); // Seeds the random number generator

	// Initializes all the player member variables
    player.health = 100;
	player.hasKey = 0;
	player.hasChartedCourse = 0;
	player.hasFixedEngines = 0;
  	player.gainedAuthorization = 0;
    player.hasDiscoveredKitchen = 0;
    player.hasKilledRobot1 = 0;
    player.hasKilledRobot2 = 0;

    chooseRole(&player);
    startPath(&player);
    chooseDirection(&player);

    return 0;
}
//-------------------------------------------------

// Starting functions
//-------------------------------------------------
void chooseRole(struct Player* player)
{
    char role[16];

    printf("Alert: You have been awakened from cryosleep early. What is your designation?\n");
    usleep(500000);
    printf("(Pilot, Mechanic, Doctor, Soldier, or Prisoner?)\n");
    scanf("%15s", role);

	role[0] = toupper(role[0]); // Capitalizes the first letter of the word so the program doesn't get confused on what you entered

    strcpy(player->role, role);

    if (strcmp(role, "Pilot") == 0)
        strcpy(player->weapon, "Revolver");
    else if (strcmp(role, "Mechanic") == 0)
        strcpy(player->weapon, "Wrench");
    else if (strcmp(role, "Doctor") == 0)
        strcpy(player->weapon, "Drill");
    else if (strcmp(role, "Soldier") == 0)
        strcpy(player->weapon, "Rifle");
    else if (strcmp(role, "Prisoner") == 0)
        strcpy(player->weapon, "Crowbar");
}

void startPath(struct Player* player)
{
    printf("\nDisoriented, you start to slowly take in your surroundings.\n");
    sleep(SLEEP_SHORT);
    printf("\nYou're in a room aboard a spaceship. Metal floor, metal walls, metal celing.\n"); 
    sleep(SLEEP_SHORT);
    printf("\nYour cryo chamber is behind you, and in front of you are a few hallways.\n");
    sleep(SLEEP_SHORT);
    printf("\nIn your hand is a %s.\n", player->weapon);
    sleep(SLEEP_SHORT);
    printf("\nTo your left is a door with a computer next to it. The screen is on, with muliple error-like mesasges flashing across it.\n");
    sleep(SLEEP_SHORT);
    printf("\nCurious, and slightly wary, you walk over to the computer.\n");
    sleep(SLEEP_SHORT);
	
    printComputer();

	sleep(SLEEP_LONG);
}

void chooseDirection(struct Player* player){
    int direction;
    
    printf("\nYou walk away from the computer and exit the room into the hallway.\n");
    sleep(SLEEP_SHORT);
    printf("\nThere is a map on the opposite wall, and the hallway goes 2 directions.\n");
    sleep(SLEEP_SHORT);
    printf("\nYou can't remember where things are located, so you inspect the map\n");
    sleep(SLEEP_SHORT);

    printMap();

	sleep(SLEEP_LONG);
    printf("\nYou see that the right leads to the engine room and the left leads to navigation.\n");
    sleep(SLEEP_SHORT);
    printf("\nDo you want to go right(1) or left(2)? ");

    while (direction != 1 || direction != 2)
    {
        scanf("%d",&direction);

        if (direction == 1)
		{
        	printf("\nYou decided to go to engine room.\n");
        	player->hasDiscoveredKitchen = 0;
			sleep(SLEEP_SHORT);
        	goEngine(player);
        	break;

        } else if (direction == 2) 
		{
        	printf("\nYou decided to go to navigation.\n");
        	player->hasDiscoveredKitchen = 1;
			sleep(SLEEP_SHORT);
        	goNav(player);
        	break;

        } else
        	printf("\nEnter a 1 or 2 to pick a direction: ");
    }
}
//-------------------------------------------------

// Printing functions
//-------------------------------------------------
void printComputer()
{
    printf("\n /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\\n");
    printf(" |  /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\  |\n");
    printf(" |  |   **** ERROR IN ****  |  |\n");
    printf(" |  |  **** NAVIGATION **** |  |\n");
    printf(" |  |                       |  |\n"); 
    printf(" |  |   **** ERROR IN ****  |  |\n");
    printf(" |  | **** ENGINE ROOM **** |  |\n");
    printf(" |  \\_______________________/  |\n");
    printf(" \\_____________________________/\n");
}

void printMap(){
printf("\n ––––––––––––––––––––––––––––––\n");
printf("|  ___  [  ]              ___  |\n");
printf("| | N |__||______________| E | |\n");
printf("| | A  ______ *__________  N | |\n");
printf("| |_V_|     _||_         |_G_| |\n");
printf("|          |    |              |\n");
printf("|          |____|              |\n");
printf("|       You are here = *       |\n");
printf(" ––––––––––––––––––––––––––––––\n");
}
//-------------------------------------------------