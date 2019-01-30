#include "courseSelect.h"

bool CourseSelect::checkValidMark(string _mark)
{
	if(_mark.empty()) return false;

	char* p;
	strtol(_mark.c_str(), &p, 10);
	if (*p != 0) return false;

	int i = atoi(_mark.c_str());
	if ( i >= 0 && i <= 100) return true;
	else return false;
}

bool CourseSelect::operator==(CourseSelect cs)
{
	return ( getId()==cs.getId() && getCode() == cs.getCode() );
}

bool CourseSelect::operator<(CourseSelect cs)
{

	if (atoi((getId()).c_str()) < atoi((cs.getId()).c_str())){
		return true;
	}
	else if ((atoi((getId()).c_str()) == atoi((cs.getId()).c_str()))){
		const char* c_1 = (getCode()).c_str();
		const char* c_2 = (cs.getCode()).c_str();
		int i = 0;
		do {
			i = strcmp(c_1, c_2);
		} while(i == 0);
		if (i < 0) return true;
		return false;
	}
	else return false;

}