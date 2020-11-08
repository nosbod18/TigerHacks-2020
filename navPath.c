#include "navPath.h"

void goNav(struct Player *player) 
{
	sleep(SLEEP_SHORT);
	printf("\nYou head towards navigation.\n");
	sleep(SLEEP_SHORT);
	printf("\nOn the right, you notice a hallway labeled 'Kitchen.'\n");
	
	player->hasDiscoveredKitchen = 1;
	sleep(SLEEP_SHORT);

	goKitchen(player);
}

//Decide to go to into the kitchen or continue to navigation.
void goKitchen(struct Player* player) 
{
	int decisionKit;
	
	printf("\nWould you like to investigate the kitchen(1) or continue to navigation(2)? ");
	sleep(SLEEP_SHORT);

	while (decisionKit != 1 || decisionKit != 2) 
	{
		scanf("%d", &decisionKit);

		if (decisionKit == 1)
		{
			printf("\nYou decided to go to the kitchen.\n");
			sleep(SLEEP_SHORT);

			if (player->hasFixedEngines != 1) 
				pathKitchen(player);
			else 
			{
				printf("\nThe kitchen was locked so you walk back into the hallway.\n");
				sleep(SLEEP_SHORT);
				exitKitchen(player);
			}

			break;

		} else if (decisionKit == 2)
		{
			printf("\nYou decided not to go to the kichen and continued on to navigation.\n");
			sleep(SLEEP_SHORT);

			pathNavigation(player);
			break;

		} else 
			printf("\nPlease enter a 1 or 2 to make a decision. ");
	}
}

void pathKitchen(struct Player *player) 
{
	int kitDecision =0;
	printf("\nYou enter the kitchen and see two dead corpses leaning on one of the walls.\n");
	sleep(SLEEP_SHORT);
	printf("\nWould you like to search the kitchen(1), investigate the corpses(2), or leave(3)? ");
	sleep(SLEEP_SHORT);
  
  	while (kitDecision != 3) 
	{
    	scanf("%d",&kitDecision);

	  	if (kitDecision > 3 || kitDecision < 0)
	  		printf("\nPlease enter a 1, 2 or 3 to make a decision. ");
    	else
	  		inspectKitchen(player, kitDecision);
  	}	
}

void inspectKitchen(struct Player *player, int decision) 
{
    if (decision == 1)
	{
      	printf("\nYou investigated the kitchen but found nothing.\n");
		sleep(SLEEP_SHORT);

	} else if (decision == 2)
	{
      	if (player->hasKey != 1 && player->hasFixedEngines != 1) // If the player hasn't found the key yet, they find it on the corpses
	  	{
        	printf("\nYou investigate the corpses and find a unmarked key hanging around one of their necks.\n");
			sleep(SLEEP_SHORT);
        	player->hasKey = 1;

      	} else // The player already found the key, so they can't find it again
		{
        	printf("\nYou find nothing new on the corpses.\n");
			sleep(SLEEP_SHORT);
		}

    } else if (decision == 3)
	{
      	printf("\nYou leave the kitchen.\n");
        exitKitchen(player);
		return;
	}

	// This is here because when the function ends, it goes back to pathKitchen() and it's still in the while loop which is waiting for user input.
  	printf("\nWould you like to investigate the kitchen(1), investigate the corpses(2), or leave(3)? ");
}

void pathNavigation(struct Player *player) 
{
  	printf("\nYou open the doors and enter the navigation room.\n");
  	sleep(SLEEP_SHORT);
  	printf("\nYou notice that the computers are flashing and you walk up to them.\n");
  	sleep(SLEEP_SHORT);
  
  	if (strcmp(player->role, "Pilot") == 0)
	{
		player->gainedAuthorization = 1;
		printf("\nYou open the computer and enter your authorization.\n");
		sleep(SLEEP_SHORT);
		printNavComputer();
		sleep(SLEEP_SHORT);
		changeCourse(player);

    	if (player->hasKilledRobot2 != 1) {
			printf("\nYou now remember the objective of your ship: a colonization mission to Vesta as a future home for humanity.\n");
			sleep(SLEEP_SHORT);
			printf("\nYou leave the computer and turn to find a robot emerging from a dark corner.\n");
			sleep(SLEEP_SHORT);
			printf("\nThe malfunctioning robot exclaims that you have made unauthorized modifications to the charted course.\n");
			
			fight(player, 0);
			player->hasKilledRobot2 = 1;
    	}
    

		if (player->hasFixedEngines == 1)
		{
			printf("\nYou go back to the starting room and go back into cryosleep.\n");
			waiting();

			if(player->hasChartedCourse == 1)
				printf("\nYou wake up and your ship is approching the mysterious jungle planet Vesta. You will be a new start for humanity.\n");
			else 
			{
				printf("\nYou wake up and see that Earth has disappeared.\n");
				sleep(SLEEP_LONG);
				printf("\nYou are alone.");
			}

			exit(0);

		} else 
		{
			printf("\nYour course has been charted but you're not done yet. You exit the navigation room.\n");
			exitNavigation(player);
		}
    } else 
    {
    	printf("\nYou open the computer, but do not have authorization.\n");
    	sleep(SLEEP_SHORT);
    	printf("\nIn order to access the navigation controls, you must complete a navigation quiz.\n");

    	navMini(player); // Navigation minigame
    	printNavComputer();
    	changeCourse(player);

    	if (player->hasKilledRobot2 != 1)
		{
        	printf("\nYou now remember the objective of your ship: a colonization mission to Vesta as a future home for humanity\n");
        	sleep(SLEEP_SHORT);
        	printf("\nYou leave the computer and turn to find a robot emerging from a dark corner.\n");
        	sleep(SLEEP_SHORT);
        	printf("\nThe robot exclaims that you have made unauthorized modifications to the charted course.\n");

        	fight(player, 0);
        	player->hasKilledRobot2 = 1;
    	}
	
    	if (player->hasFixedEngines == 1){
      		printf("\nYou go back to the starting room and go back into cryosleep.\n");
      		waiting();

      		if(player->hasChartedCourse == 1)
			{
        		printf("\nYou wake up and your ship is approching the mysterious jungle planet Vesta. You will be a new start for humanity.\n");
				sleep(SLEEP_LONG);
				printf("************ Congradulations, you won! ************\n");
			}
      		else 
			  {
        		printf("\nYou wake up and see that Earth has disappeared.\n");
        		sleep(SLEEP_LONG);
        		printf("You are alone\n");
      		}

        	exit(0);
    	} else 
		{
      		printf("\nYour course has been charted but you're not done yet. You exit the navigation room.\n");
      		exitNavigation(player);
    	}
  	}
}

// This function is supposed to print out a single period at a time,
// but instead it waits for the sum of the times then prints out all the periods at once. We're not sure why
void waiting() 
{
	printf(".\t.\t.\t");
	sleep(SLEEP_TINY);
	printf(".\t.\t.\t");
	sleep(SLEEP_TINY);
	printf(".\t.\t.\t");
	sleep(SLEEP_TINY);
}

void changeCourse(struct Player *player){
  	int courseDecsision;

  	printf("\nWould you like to maintain current course(1) or revert course back to Earth(2)? ");  

  	while (courseDecsision != 1 || courseDecsision != 2){
   	 	scanf("%d",&courseDecsision);
   		if (courseDecsision==1)
		{
      		printf("\nYou kept the current destintation.\n");
      		player->hasChartedCourse = 1;
      		break;
		
    	} else if (courseDecsision == 2)
		{
     		printf("\nYou changed the course to Earth.\n");
      		player->hasChartedCourse = 2;
      		break;

    	} else
			printf("\nEnter a 1 or 2 to make a decision: ");
  	}
}

void printNavComputer() 
{
  printf("\n /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\\n");
  printf(" |  /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\  |\n");
  printf(" |  | **CHART YOUR COURSE** |  |\n");
  printf(" |  |  *CURRENT COURSE =>*  |  |\n");
  printf(" |  |        -VESTA-        |  |\n"); 
  printf(" |  |                       |  |\n"); 
  printf(" |  |  ***CHANGE COURSE***  |  |\n");
  printf(" |  |        -EARTH-        |  |\n");
  printf(" |  \\_______________________/  |\n");
  printf(" \\_____________________________/\n");
}

void exitNavigation(struct Player *player)
{
  	int choice;
  	printf("\nWould you like to go back into the navigation room(1), go to the engine room(2), or go to the kitchen(3)? ");

  	while (choice != 1 || choice != 2 || choice != 3)
  	{
    	scanf("%d", &choice);

    	if (choice == 1)
    	{
      		printf("\nYou go back into the navigation room\n");
      		pathNavigation(player);
      		break;

    	} else if (choice == 2  && player->hasKilledRobot1 == 0) 
		{
      		printf("\nYou go to the engine room\n");
      		goEngine(player);
      		break;

    	} else if (choice == 2 && player->hasKilledRobot1 == 1) 
		{
      		printf("\nYou go to the engine room\n");
      		enterRoom(player);
      		break;

    	} else if (choice == 3) 
		{
      		printf("\nYou go to the kitchen\n");
      		pathKitchen(player);
      		break;

    	} else
      		printf("\nPlease enter 1, 2, or 3 to make a decision ");
  }
}
void exitKitchen(struct Player *player)
{
  	int choice = 0;
  	printf("\nWould you like to go back into the kitchen(1), go to the engine room(2), or go to the navigation room(3)? ");

	while (choice != 1 || choice != 2 || choice != 3)
  	{
    	scanf("%d", &choice);

    	if (choice == 1)
    	{
      		printf("\nYou go back into the kitchen\n");
      		pathKitchen(player);
      		break;

    	} else if (choice == 2  && player->hasKilledRobot1 != 1) 
		{
      		printf("\nYou go to the engine room\n");
      		goEngine(player);
      		break;

    	} else if (choice == 2 && player->hasKilledRobot1 == 1) 
		{
      		printf("\nYou go to the engine room\n");
      		enterRoom(player);
      		break;

    	} else if (choice == 3) 
		{
      		printf("\nYou go to navigation\n");
      		pathNavigation(player);
      		break;

    	} else
			printf("\nPlease enter 1, 2, or 3 to make a decision ");
  	}
}