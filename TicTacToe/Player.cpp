/*	Player.cpp
	Alex Van Heel
	December 10th
	Records player data */

#include "Player.h"

Player::Player(string n, int g, int w, int l, int t) {
	name = n;
	games = g;
	wins = w;	
	losses = l;
	ties = t;
}

Player::~Player() {}

/*	void operator=(player)
		Sets two player to an equal value
		Sets current player value to the new player */
void Player::operator = (Player p) {
	name = p.name;
	games = p.games;
	wins = p.wins;
	losses = p.losses;
	ties = p.ties;
}