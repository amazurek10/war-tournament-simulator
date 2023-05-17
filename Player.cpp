#include "Player.h"

Player::Player() {
	name = "";
}

Player::Player(std::string name) {
	this->name = name;
}



std::string Player::getName() const {
	return name;
}

