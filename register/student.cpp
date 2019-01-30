#include "Student.h"

using namespace std;

string Student::getGender() const 
{ 
	if ( gender == "m" || gender == "M" || gender == "Male" ) return "Male";
	else return "Female";
}

bool Student::checkValidId(string _id)
{
	int counter = 0;
	if (_id.empty()) return false;
	char* p;
	strtol(_id.c_str(), &p, 10);
	if (*p != 0) return false;
	else counter = strlen(_id.c_str());

	if (counter == 8) return true;
	else return false;	
}


bool Student::checkValidName(string _name)
{
	if (_name.empty()) return false;
	if (strlen(_name.c_str())<=32) return true;
	else return false;
}

bool Student::checkValidGender(string _gender)
{
	if(_gender.empty()) return false;
	if (_gender=="M"|| _gender=="F"||_gender=="m"||_gender=="f") return true;
	else return false;
}

bool Student::operator<(Student s)
{
	return (atoi((getId()).c_str()) < atoi((s.getId()).c_str()));
}