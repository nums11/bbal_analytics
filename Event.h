#ifndef _PERSON_H_INCLUDED // is person.h already included?
#define _PERSON_H_INCLUDED // define this so we know it's included

#include "Person.h"

class Event
{
public:
	Event() {}
	Event(int en, int emt, int p, int wct, int pct, int at, int op1,
		int op2, int op3, std::string tid, Person p1, Person p2, int
		tidtype){
		event_number = en;
		event_msg_type = emt;
		period = p;
		wc_time = wct;
		pc_time = pct;
		action_type = at;
		option_1 = op1;
		option_2 = op2;
		option_3 = op3;
		team_id = tid;
		person_1 = p1;
		person_2 = p2;
		team_id_type = tidtype;
	}
	
	int event_number, event_msg_type, period, wc_time,
	pc_time, action_type, option_1, option_2, option_3, team_id_type;
	Person person_1, person_2;
	std::string team_id;

	void printEvent(){
		std::cout << "Event Number: " << event_number << std::endl;
		std::cout << "Event Message Type: " << event_msg_type << std::endl;
		std::cout << "Period: " << period << std::endl;
		std::cout << "WC Time: " << wc_time << std::endl;
		std::cout << "PC Time: " << pc_time << std::endl;
		std::cout << "Action Type: " << action_type << std::endl;
		std::cout << "Option 1: " << option_1 << std::endl;
		std::cout << "Option 2: " << option_2 << std::endl;
		std::cout << "option_3: " << option_3 << std::endl;
		std::cout << "Team ID: " << team_id << std::endl;
		std::cout << "Person 1: " << person_1.person_id << std::endl;
		std::cout << "Person 2: " << person_2.person_id << std::endl;
		std::cout << "Team ID Type: " << team_id_type << std::endl;
	}

};

#endif