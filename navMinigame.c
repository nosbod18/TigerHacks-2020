#include "navMinigame.h"

/* 
	This is a little minigame the player has to play in navigation if they are not the pilot.
   	The rational was a pilot would already know all this stuff, and to make sure no one else could mess with the current course,
   	the questions were designed to be to hard for the average person to answer. (Correct answers are b, d, a)
*/

void navMini(struct Player* player)
{
  int total = 0; // Used to keep track of how many questions the player got right
  char x;

  printf("\nError: Unauthorized Personel\n");
  sleep(SLEEP_SHORT);
  printf("\nSecurity Check Required to Access Navigation Controls\n");
  sleep(SLEEP_SHORT);
  printf("\nWhat is an ascending node?\n\nA) An object leaving a planet's atmosphere.\nB) The point at which an orbit crosses a reference plane going north.\nC) An asteriod falling into orbit.\nD) A modulation scheme in which data symbols are represented by a shift from one phase to another.\n");
  scanf(" %c", &x);

  if (x=='B' || x=='b')
    answers(1, 0, &total, player);

  sleep(SLEEP_SHORT);
  printf("\nWhat is declination?\n\nA) The effect on frequency imposed by relative motion between transmitter and receiver.\nB) The distance between the foci of an ellipse divided by the major axis.\nC) Unit of gravity field measurement corresponding to a gravitational acceleration of 1 cm/sec^2.\nD) The measure of a celestial body's apparent height above or below the celestial equator.\n");
  scanf(" %c", &x);

  if (x=='D' || x=='d')
    answers(1, 0, &total, player);

  sleep(SLEEP_SHORT);
  printf("\nWhat does nadir mean?\n\nA) The direction from a spacecraft directly down toward the center of a planet.\nB) The boundary theorized to be roughly circular or teardrop-shaped, marking the edge of the sun's influence, perhaps 100 AU from the sun.\nC) The process of modifying a radio frequency by shifting its phase, frequency, or amplitude to carry information.\nD) A small nodding motion in a rotating body.\n");
  scanf(" %c", &x);

  if (x=='a' || x=='A')
    answers(1, 1, &total, player);
  else
    answers(0, 1, &total, player);
}

void answers(int x, int y, int* total, struct Player *player)
{
  *total += x;

  if (y == 1)
  {
    if (*total == 3)
    {
      sleep(SLEEP_TINY);
      printf("Access Granted\n");
      player->gainedAuthorization = 1;

    } else {
      sleep(SLEEP_TINY);
      printf("Access Denied\n");
      player->gainedAuthorization = 0;
    }
  }
}
