#pragma once

#include <iostream>

class Stats
{

public:
	Stats();

	Stats(float timeSurvived, int timesWinPj1, int timesWinPj2, int timesDraw, int timesPlayed,
		int timesPlayedElf, int timesPlayedMafalda, int timesPlayedNecromancer, int timesPlayedKnight);

	Stats operator+=(Stats& other);

	void coutStats(Stats Stats);


	int getTimesWinPj1() { return timesWinPj1; }
	int getTimesWinPj2() { return timesWinPj2; }
	int getTimesDraw() { return timesDraw; }
	int getTimesPlayed() { return timesPlayed; }
	int getTimesPlayedElf() { return timesPlayedElf; }
	int getTimesPlayedMafalda() { return timesPlayedMafalda; }
	int getTimesPlayedNecromancer() { return timesPlayedNecromancer; }
	int getTimesPlayedKnight() { return timesPlayedKnight; }

private:
	float timeSurvived;

	int timesWinPj1;
	int timesWinPj2 ;
	int timesDraw ;
	int timesPlayed ;
	int timesPlayedElf;
	int timesPlayedMafalda;
	int timesPlayedNecromancer ;
	int timesPlayedKnight;
};



