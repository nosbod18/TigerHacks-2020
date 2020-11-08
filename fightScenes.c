#include "fightScenes.h"

void fight(struct Player* player, int steam)
{
	static int health = 100; // Static because for some reason we were getting weird bugs when we tried to use the player health member variable, so we hardcoded 100 as the health value
	int damage = 0;
	int combatChoice = 0;
	int robotHealth = ROBOT_HEALTH;

	if (steam == 1)
	{
		health -= 10;
		
		if (health <= 0)
			goto dead;
		else
			return;
	}

	while (health > 0 && robotHealth > 0)
	{
		printf("Fight(1) or Flee(2)? ");
		scanf("%d", &combatChoice);

		// If the player chooses to fight, the robot deals 10 damage, and the player deals an amount of damage in a range 
        // based on the designation they chose in the beginning
		if (combatChoice == 1) 
		{
			if (strcmp(player->weapon, "Revolver") == 0)
			{
				int damage = REVOLVER + (rand() % 6);
				robotHealth -= damage;

			} else if (strcmp(player->weapon, "Wrench") == 0)
			{
				int damage = WRENCH + (rand() % 8);
				robotHealth -= damage;

			} else if (strcmp(player->weapon, "Drill") == 0)
			{
				int damage = DRILL + (rand() % 6);
				robotHealth -= damage;

			} else if (strcmp(player->weapon, "Rifle") == 0)
			{
				int damage = RIFLE + (rand() % 2);
				robotHealth -= damage;

			} else if (strcmp(player->weapon, "Crowbar") == 0)
			{
				int damage = CROWBAR + (rand() % 8);
				robotHealth -= damage;
			}

			if (robotHealth > 0)
			{
				printf("Robot health = %d\n", robotHealth);

				int damage = ROBOT_DAMAGE + rand() % 3;
				health -= damage;

				printf("The robot attacks, dealing %d damage to you\n", damage);

				if (health >= 0)
					printf("You have %d health left\n", health);
			}
		} else if (combatChoice == 2) // If the player chooses to flee, the robot attacks anyways and deals 20 damage. Theres no way to not fight
		{
			damage = ROBOT_DAMAGE * 2;
			health -= damage;
			printf("The robot chases you and attacks from behind, dealing %d damage to you\n", damage);
			printf("You have %d health left\n", health);

		} else
			printf("Enter a 1 or 2 to make your choice\n");
	}

	if (health > 0)
	{
		printf("\nYou've defeated the robot, its lifeless metal corpse crumples to the ground\n");

		if (strcmp(player->role,"Doctor") == 0) // If the player chose doctor, they get a little health bonus
		{
			health += DOCTOR_HEALTH_BONUS;
			printf("You heal %d health\n", DOCTOR_HEALTH_BONUS);
		}

	} else 
	{
dead:   printf("You died\n\n******* Game Over *******\n");
		exit(0);
	}
}