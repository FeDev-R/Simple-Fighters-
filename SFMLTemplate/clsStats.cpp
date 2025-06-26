#include "clsStats.h"


Stats::Stats()
{

	this->timeSurvived = 0.0f;
	this->timesWinPj1 = 0;
	this->timesWinPj2 = 0;
	this->timesDraw = 0;
	this->timesPlayed = 0;
	this->timesPlayedElf = 0;
	this->timesPlayedMafalda = 0;
	this->timesPlayedNecromancer = 0;
	this->timesPlayedKnight = 0;
}

Stats::Stats(float timeSurvived, int timesWinPj1, int timesWinPj2, int timesDraw, int timesPlayed,
	int timesPlayedElf, int timesPlayedMafalda, int timesPlayedNecromancer, int timesPlayedKnight)
{
	this->timeSurvived = timeSurvived;
	this->timesWinPj1 = timesWinPj1;
	this->timesWinPj2 = timesWinPj2;
	this->timesDraw = timesDraw;
	this->timesPlayed = timesPlayed;
	this->timesPlayedElf = timesPlayedElf;
	this->timesPlayedMafalda = timesPlayedMafalda;
	this->timesPlayedNecromancer = timesPlayedNecromancer;
	this->timesPlayedKnight = timesPlayedKnight;
}

Stats Stats::operator+=(Stats& other)
{
	this->timeSurvived += other.timeSurvived;
	this->timesWinPj1 += other.timesWinPj1;
	this->timesWinPj2 += other.timesWinPj2;
	this->timesDraw += other.timesDraw;
	this->timesPlayed += other.timesPlayed;
	this->timesPlayedElf += other.timesPlayedElf;
	this->timesPlayedMafalda += other.timesPlayedMafalda;
	this->timesPlayedNecromancer += other.timesPlayedNecromancer;
	this->timesPlayedKnight += other.timesPlayedKnight;

	return *this;
}

void Stats::coutStats(Stats Stats)
{
	std::cout << "timeSurvived:        " << Stats.timeSurvived << std::endl;
	std::cout << "timesWinPj1:         " << Stats.timesWinPj1 << std::endl;
	std::cout << "timesWinPj2:         " << Stats.timesWinPj2 << std::endl;
	std::cout << "timesDraw:           " << Stats.timesDraw << std::endl;
	std::cout << "timesPlayed:         " << Stats.timesPlayed << std::endl;
	std::cout << "timesPlayedElf:      " << Stats.timesPlayedElf << std::endl;
	std::cout << "timesPlayedMafalda:  " << Stats.timesPlayedMafalda << std::endl;
	std::cout << "timesPlayedNecro:    " << Stats.timesPlayedNecromancer << std::endl;
	std::cout << "timesPlayedKnight:   " << Stats.timesPlayedKnight << std::endl;
}
