#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
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
	string str, line, game_id, event_msg_type_description;
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


	//TEST! MAKING SURE EVENTS ARE SORTED
	// for(int i = 0; i < games.size(); i++){
	// 	games[i].printGame();
	// }



	file.close();



	//READING EVENT CODES FILE----------------------------------------------
	file.open("NBA Hackathon - Event Codes.txt");

	//Read in column headers
	for(int i = 0; i < 4; i++){
		file >> str;
	}

	//The only event codes that matter for calculating plus/minus are the 
	//made shots, free throws, and subsitutions

	vector<pair<int,int> > made_shot_codes;
	vector<pair<int,int> > free_throw_codes;
	vector<pair<int,int> > substitution_codes;

	//reading in event codes file line by line and adding pairs
	//of codes to the correct vectors
	num_columns = 8;
	while(file >> event_msg_type){
		file >> action_type;

		event_msg_type_description = "";
		//read event_msg_type_description
		while(file >> str){
			event_msg_type_description += str;
			if(str == string(1,'"')) break;
		}

		//add pair to the correct event codes vector
		if(event_msg_type_description == "\"MadeShot\""){
			made_shot_codes.push_back(pair<int,int>(event_msg_type,action_type));
		} else if(event_msg_type_description == "\"FreeThrow\""){
			free_throw_codes.push_back(pair<int,int>(event_msg_type,action_type));
		} else if(event_msg_type_description == "\"Substitution\""){
			substitution_codes.push_back(pair<int,int>(event_msg_type,action_type));
		}

		//special cases where the rest of the file needs to be read in differently
		if(event_msg_type_description == "\"Substitution\"" || event_msg_type_description == "\"JumpBall\"" ||
			event_msg_type_description == "\"StartPeriod\"" || event_msg_type_description == "\"EndPeriod\""){
			//in this instance read in 2 quotes before breaking line
			int num_quotes = 0;
			while(file >> str){
				if(str == string(1,'"')){
					num_quotes++;
				} 
				if(num_quotes == 2) break;
			}		
		} else if(event_msg_type_description != "\"NoShot\""){
			//normal case - just read till end quote is found
			while(file >> str){
				if(str == string(1,'"')) break;
			}
		}


	}

	for(int i = 0; i < substitution_codes.size(); i++){
		cout << (substitution_codes[i]).first << " " << (substitution_codes[i]).second << endl;
	}

	// for(int i = 0; i < event_codes.size(); i++){
	// 	cout << event_codes[i] << endl;
 // 	}

	file.close();
	return 0;
}