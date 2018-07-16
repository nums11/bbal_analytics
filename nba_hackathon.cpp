#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Event.h"
#include "Person.h"
using namespace std;


int main(int argc, char const *argv[])
{
	vector<Person> people;
	vector<Event> events;
	vector<Game> games;
	vector<string> data, team_ids;
	vector<Game>::iterator game;
	string str, line, game_id;
	//For Reading in Events
	int event_number, event_msg_type, period, wc_time,
	pc_time, action_type, option_1, option_2, option_3, team_id_type;
	Person person_1, person_2;
	string team_id;
	ifstream file;

	//Reading Game Lineup Data Sample----------------------------------------------------

	file.open("NBA Hackathon - Game Lineup Data Sample (50 Games).txt");
	//Reading Game Lineup Data Sample
	int count = 0;
	int num_columns = 5;
	while(file >> str){
		//Getting Game ids
		if(count == 0 && find(games.begin(), games.end(), str) == games.end()){
			games.push_back(str);
		}

		//Getting Person ids
		if(count == 2 && find(people.begin(), people.end(), Person(str)) == people.end()){
			people.push_back(Person(str));
		}

		//Getting Team ids
		// if(count == 3 && find(team_ids.begin(), team_ids.end(), str) == team_ids.end()){
		// 	team_ids.push_back(str);
		// }		

		count++;
		line += str;
		line += " ";
		if(count == num_columns){
			data.push_back(line);
			count = 0;
			line = "";
		}
	}


	// for(int i = 0; i < data.size(); i += 5){
	// 	cout << i;
	// }

	// for(int i = 0; i < people.size(); i++){
	// 	cout << people[i].person_id << endl;
	// }

	file.close();
	

	//Reading Play by Play-------------------------------------------------

	file.open("NBA Hackathon - Play by Play Data Sample (50 Games).txt");

	//Skipping column names
	for(int i = 0; i < 14; i++){
		file >> str;
	}

	count = 0;
	num_columns = 14;
	while(file >> str){

		game = (find(games.begin(), games.end(), Game(str)));
		// game_id = str;

		//reading event data
		file >> event_number;
		file >> event_msg_type;
		file >> period;
		file >> wc_time;
		file >> pc_time;
		file >> action_type;
		file >> option_1;
		file >> option_2;
		file >> option_3;
		file >> team_id;
		file >> str;
		person_1.person_id = str;
		file >> str;
		person_2.person_id = str;
		file >> team_id_type;

		//creating event
		events.push_back(Event(event_number, event_msg_type, period, wc_time, pc_time, action_type,
			option_1, option_2, option_3, team_id, person_1, person_2, team_id_type));

		// find(games.begin(), games.end(), Game(str))->addEvent(Event(event_number, event_msg_type, period, wc_time, pc_time, action_type,
		// 	option_1, option_2, option_3, team_id, person_1, person_2, team_id_type));

		game->addEvent(Event(event_number, event_msg_type, period, wc_time, pc_time, action_type,
			option_1, option_2, option_3, team_id, person_1, person_2, team_id_type));
	}

	//TEST! PRINTING EVERY GAME TO MAKE SURE THE EVENTS WERE ADDED CORRECTLY
	//EVENTS STILL NEED TO BE SORTED (SEE PAGE 2 OF BASKETBALL ANALYTICS PROMPT.PDF UNDER PLAY
	//BY PLAY SAMPLE.TXT)
	for(int i = 0; i < games.size(); i++){
		sort(games[i].events.begin(), games[i].events.end(), sortEvents);
		games[i].printGame();
	}


	file.close();

	return 0;
}