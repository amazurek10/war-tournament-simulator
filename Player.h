#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <deque>

#include "Card.h"

class Player {
public:
	Player();
	Player(std::string name);

	std::string getName() const;


private:
	std::string name;
};



#endif
