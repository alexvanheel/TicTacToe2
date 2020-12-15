/*	FileIO.cpp
	Alex Van Heel
	December 9th
	File input and output */

#include "FileIO.h"

//Constructor
FileIO::FileIO(string name) {
	ifstream input;
	Player player("player");
	fileBase = name;
	mainFile = fileBase + ".txt";
	backFile = fileBase + ".bak";
	input.open(mainFile);						//Opens the user scores file
	if (input) {								//Checks if file exists
		ofstream output;
		output.open(backFile);
		playerList.clear();						//Makes sure the list is empty
		while (input >> player.name >> player.games >> player.wins >> player.losses >> player.ties) {
			playerList.push_back(player);		//Adds all names to a vector
			//Adds to a backup file:
			output << player.name << ' ' << player.games << ' ' << player.wins
				<< ' ' << player.losses << ' ' << player.ties << endl;
		}
	}

}

//Destructor:
FileIO::~FileIO() {
	ofstream output;
	Player player("player");
	output.open(mainFile);
	for (int i = 0; i < (int)playerList.size(); i++) {
		player = playerList[i];
		output << player.name << ' ' << player.games << ' ' << player.wins
			<< ' ' << player.losses << ' ' << player.ties << endl;
	}
}

/*	Player findPlayer(string);
	Finds the player's statistics given a name*/
Player FileIO::findPlayer(string n) {
	Player retVal(n);
	for (int i = 0; i < (int)playerList.size(); i++) {
		if (n == playerList[i].name) retVal = playerList[i];
	}
	return retVal;
}

/*	Player void updatePlayer(Player p);
	Adds or updates a player to the internal vector */
void FileIO::updatePlayer(Player p) {
	bool playerFound = false;
	for (int i = 0; i < (int)playerList.size(); i++) {
		if (p.name == playerList[i].name) {
			playerList[i] = p;
			playerFound = true;
		}
	}
	if (!playerFound) playerList.push_back(p);		//Puts the new player into a vector
}

/*	Player void printPlayers();
	Prints a list of players stored in a vector */
void FileIO::printPlayers() {
	Player player("player");
	for (int i = 0; i < (int)playerList.size(); i++) {
		player = playerList[i];
		cout << player.name << ' ' << player.games << ' ' << player.wins
			<< ' ' << player.losses << ' ' << player.ties << endl;
	}
}