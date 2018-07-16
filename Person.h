#ifndef _MYHEADER_H_INCLUDED // is myheader.h already included?
#define _MYHEADER_H_INCLUDED // define this so we know it's included

#include <string>

class Person
{
public:
	Person() {}
	Person(std::string id){
		person_id = id;
	}

	std::string person_id;
	
	bool operator==(const Person& b) {
		return person_id == b.person_id;
	}
};

#endif