#pragma once

struct Player
{
	int health;
	char role[16];
	char weapon[16];

	int hasFixedEngines;
	int hasChartedCourse; // 0 - hasn't charted course, 1 - charted course to other planet, 2 - charted couse to Earth
	int hasKey;
	int gainedAuthorization;
	int hasDiscoveredKitchen;
	int hasKilledRobot1;
	int hasKilledRobot2;
};