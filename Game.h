#ifndef _EVENT_H_INCLUDED // is event.h already included?
#define _EVENT_H_INCLUDED // define this so we know it's included

#include "Event.h"

class Game
{
public:
	Game() {}
	Game(std::string id){
		game_id = id;
	}

	std::string game_id;
	std::vector<Event> events;

	void addEvent(Event e){
		events.push_back(e);
	}

	void printNumEvents(){
		std::cout << events.size() << std::endl;
	}

	bool operator==(const Game& g){
		return game_id == g.game_id;
	}

	//Test function to make sure game has correct events
	void printGame(){
		std::cout << "Printing Game: " << game_id << std::endl;
		std::cout << std::endl;
		for(int i = 0; i < events.size(); i++){
			std::cout << "Printing Event " << i << std::endl; 
			events[i].printEvent();	
			std::cout << std::endl;
		}
		std::cout << "Game Printed" << std::endl;
		std::cout << std::endl;
	}
	
};

#endif