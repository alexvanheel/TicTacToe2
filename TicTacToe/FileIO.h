#pragma once
/*	FileIO.h
	Alex Van Heel
	December 9th
	File input/output class*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Player.h"					//Local player class

class FileIO {
private:
	string	fileBase,
			mainFile,
			backFile;
	vector <Player> playerList;
public:
	FileIO(string = "scores");		//Constructor
	~FileIO();						//Destructor

	/*	Player findPlayer(string);
		Finds a player's statistics given a name */
	Player findPlayer(string);

	/*	Player void updatePlayer(PLayer);
		Adds or updates a player to the internal vector */
	void updatePlayer(Player);

	/*	void printPlayers();
		Prints a list of players that are stored in the vector */
	void printPlayers();
};	