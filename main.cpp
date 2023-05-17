
#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <random>

#include "War.h"
#include "Player.h"
#include "Card.h"

template <typename T>
std::string remove_at(std::vector<T>& v, typename std::vector<T>::size_type n)
{
	std::swap(v[n], v.back());
	T name = v.back();
	v.pop_back();
	return name;
}

int main(int argc, char* argv[]) {
	
	std::ifstream file(argv[1]);

	std::vector<std::string> players;

	std::string playerName;
	while (file >> playerName) {
		players.push_back(playerName);
	}


	int gameRound = 0;
	while (players.size() > 1) {
		++gameRound;
		srand(time(NULL));
		std::string playerOne = remove_at(players, rand() % players.size());
		std::string playerTwo = remove_at(players, rand() % players.size());

		std::cout << std::endl;
		std::cout << "Game " << gameRound << ": ";

		Player p1(playerOne);
		Player p2(playerTwo);
		War game(p1, p2);

		std::string winner = game.playGame().getName();
		players.push_back(winner);

		std::cout << std::endl;
	}

	std::string tournamentWinner = players[0];
	std::cout << tournamentWinner << " has won the tournament!" << std::endl;

	system("pause");
	return 0;
}
