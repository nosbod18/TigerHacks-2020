#include "enginePath.h"

void goEngine(struct Player* player)
{
    int decision;

    printf("\nAs you walk the hallway toward the Engine Room, you see that the walls and ceiling are in various stages of destruction, with the lights in emergency mode.\n");
    sleep(SLEEP_SHORT);
    printf("\nJust before you enter the room, you come across a robot.\n");
    sleep(SLEEP_SHORT);
    printf("\nSomething about this robot triggers a memory of yours, before you went into cryo sleep.\n");
    sleep(SLEEP_SHORT);
    printf("\nThese robots are helpers, designed to repair the ship when needed and make sure the trip goes as smoothly as possible.\n");
    sleep(SLEEP_SHORT);
    printf("\nHowever, this robot looks broken. Laying against the wall, sparks flying from frayed wires.\n");
    sleep(SLEEP_SHORT);
    printf("\nDo you inspect the robot(1) or ignore it and go into the engine room(2)? ");

    while (decision != 1 || decision != 2)
    {
        scanf("%d", &decision);

        if (decision == 1)
        {
            inspectRobot(player);
            break;

        } else if (decision == 2)
        {
            player->health -= ROBOT_DAMAGE * 2;
            printf("\nThe robot is not as broken as it looks, as it gets up and attacks you from behind!\n");
			sleep(SLEEP_SHORT);

            fight(player, 0);
            player->hasKilledRobot1 = 1;
            enterRoom(player);
            break;

        } else
            printf("\nEnter a 1 or 2 to make a decision: ");
    }
}

void inspectRobot(struct Player* player)
{
    printf("\nThe robot jerks suddenly and looks straight up at you. It's not as broken as it seems, although something has definitely gone haywire.\n");
    sleep(SLEEP_SHORT);
    printf("\nIt gets up and starts charging you!\n");

    if (strcmp(player->role, "Mechanic") == 0) 
	{
        printf("\nLuckily, you are a mechanic. You are able to use your skills to deactivate the robot before it is able to do any damage to you.\n");
        player->hasKilledRobot1 = 1;
		enterRoom(player);
    }
    else
    {
        printf("\nQuick! Do you ");
		fight(player, 0);
        player->hasKilledRobot1 = 1;
    	enterRoom(player);
    }
}

void enterRoom(struct Player* player)
{
  if(player->hasFixedEngines == 1)
  {
    printf("\nThe engines still appear to be in a stable condition\n");
    exitEngine(player);

  } else if (player->hasFixedEngines == 0) 
  {
  	int decision = 0;

	sleep(SLEEP_SHORT);
    printf("\nYou enter the large engine room. The first thing that you notice the incredible heat, which gets worse the closer you get to the main engine, \nwhich itself is hidden behind a wall of boiling steam.\n");
	sleep(SLEEP_SHORT);
	printf("\nThe switch to enable backup power is on the far wall. To your immediate right is a closed door labled 'Maintainence'\n");
	sleep(SLEEP_SHORT);
    printf("\nWould you like to try and walk through the steam(1), investigate the door(2), or leave the engine room(3)? ");
    
    while (decision != 1 && decision != 2 && decision != 3)
    {
      scanf("%d", &decision);
      
      if (decision == 1 && strcmp(player->role,"Soldier") != 0) 
      {
        player->health -= STEAM_DAMAGE;
        printf("\nYou try to make your way through, but the heat burns you and you are forced to turn around.\n");
        fight(player, 1); // This isn't actually a fight, the player just takes damage because of the steam and then their health is printed

      } else if (decision == 1 && strcmp(player->role, "Soldier") == 0) // The soldier is able to make it through the steam because he is tougher
      {
        printf("\nYou make your way through the steam, getting burned in the proccess but as a hardened soldier you ignore the pain and are able to reach the lever on the other side\n");
        sleep(SLEEP_LONG);
        printf("\nYou find a switch on the other side of the room labled. Pulling it stops the alarms, and the room starts to cool\n");
        sleep(SLEEP_SHORT);
        printf("\nYou exit the engine room.\n");

        fight(player, 1);
        player->hasFixedEngines = 1;

        if (player->hasChartedCourse == 1 || player->hasChartedCourse == 2) // If the player has already fixed the error on navigation, the game ends
          endgame(player);
        else
          exitEngine(player);
        
      } else if (decision == 2 && strcmp(player->role, "Prisoner") != 0 && player->hasKey != 1) // The player doesn't have the key and isn't a prisoner
      {
        printf("\nThe door is locked\n");
        decision = 0;
        sleep(SLEEP_SHORT);
        printf("\nWould you like to try and walk through the steam(1), investigate the door(2), or leave the engine room(3)? ");

      } else if (decision == 2 && strcmp(player->role, "Prisoner") != 0 && player->hasKey == 1) // The player isn't a prisoner but has the key
      {
        printf("\nThe key you found earlier on the corpse opens the door. In the room you find the controls to a sprinkler system on the inside, pulling it cools off the engine room enough to cross.");
        sleep(SLEEP_SHORT);
        printf("\nYou find a switch on the other side of the room labled. Pulling it stops the alarms, and the room starts to cool.\n");
		sleep(SLEEP_SHORT);
        printf("\nYou exit the engine room.\n");
        
        player->hasFixedEngines = 1;

        if (player->hasChartedCourse == 1 || player->hasChartedCourse == 2)
          endgame(player);
    	else
          exitEngine(player);
      }
      else if (decision == 2 && strcmp(player->role, "Prisoner") == 0) // The prisoner is skilled at picking locks, so he doesn't need the key
      {
        printf("\nYou manage to pick the lock on the door, finding the controls to a sprinkler system on the inside; pulling it cools off the engine room enough to cross\n");
        sleep(SLEEP_SHORT);
        printf("\nYou find a switch on the other side of the room labled. Pulling it stops the alarms, and the room starts to cool\n");

        player->hasFixedEngines = 1;

        printf("\nYou exit the engine room.\n");

        if (player->hasChartedCourse == 1 ||player->hasChartedCourse == 2)
          endgame(player);
        else
          exitEngine(player);
      }
      else if (decision == 3)
      {
        exitEngine(player);
      }
      else {
        printf("\nPlease eneter a 1, 2 or 3 to make a decision.\n)");
      }
    }
  }

  exitEngine(player);
}
void exitEngine(struct Player *player)
{
  if (player->hasDiscoveredKitchen != 1)
  {
    int decision;

    printf("\nWould you like to go back into engine room(1) or go to navigation(2)? ");

    while (decision != 1 || decision != 2){
      scanf("%d",&decision);
      if (decision == 1)
	  {
        printf("\nYou go back into the engine room.\n");
        enterRoom(player);
        break;

      } else if (decision == 2)
	  {
        printf("\nYou go to navigation.\n");
        goNav(player);
        break;

      } else
        printf("\nPlease enter a 1 or 2 to make a decision. ");
    }
  }

  if (player->hasDiscoveredKitchen == 1) 
  {
    int decision;

    printf("\nWould you like to go back into engine room(1), go to navigation(2) or go to kitchen(3)? ");

    while (decision != 1 || decision != 2 || decision != 3) 
	{
      scanf("%d",&decision);

      if (decision == 1)
	  {
        printf("\nYou go back into the engine room.\n");
        enterRoom(player);
        break;

      } else if (decision == 2) 
	  {
        printf("\nYou go to navigation.\n");
        pathNavigation(player);
        break;

      } else if (decision == 3) {
        printf("\nYou go to kitchen.\n");
        pathKitchen(player);
        break;

      } else
        printf("\nPlease enter a 1, 2 or 3 to make a decision. ");
    }  
  }
}

void endgame(struct Player* player)
{
	printf("\nYou go back to the starting room and go back into cryosleep.\n");

	if (player->hasChartedCourse == 1) // If the player has charted a course to Vesta, they win
	{
		waiting();
		printf("\nYou wake up and your ship is approching the mysterious jungle planet Vesta. You will be a new start for humanity.\n");
		sleep(SLEEP_LONG);
		printf("\n************ Congradulations, you won! ************\n");

	} else 
	{
		waiting();
		printf("\nYou wake up and see that Earth has disappeared.\n");
		sleep(SLEEP_LONG);
		printf("\nYou are alone.\n");
	}

	exit(0);
}