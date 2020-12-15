#pragma once
/*	Player.h
	Alex Van Heel
	December 9th
	Class used to record player data */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 

class Player {
public:
	string name;			//Name of player
	int games,				//Games Played
		wins,				//Number of wins
		losses,				//Number of losses
		ties;				//Number of ties
	Player(string, int = 0, int = 0, int = 0, int = 0);		//Constructor
	~Player();		//Destructor

	inline void incrementWins() {
		wins++;
		games++;
	}
	inline void incrementLosses() {
		games++;
		losses++;
	}
	inline void incrementTies() {
		games++;
		ties++;
	}
	/*	void operator=(player)
		Sets two player to an equal value
		Sets current player value to the new player */
	void operator = (Player);
};
