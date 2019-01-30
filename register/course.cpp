#include "course.h"

bool Course::checkValidCode(string _code)
{
	if ( _code.empty()) return false;

	int length = strlen(_code.c_str());
	//cout << "length is " << length << endl;
	if ( length > 8 || length < 7 )  return false;
	char tmp[length];
	char c;
	strcpy(tmp,_code.c_str());

	for (int i = 0; i < 4; i++)
	{
		c = tmp[i];
		if (isupper(c))  continue ;
		else return false;
	}

	for (int i = 0; i < 7; i++)
	{
		c = tmp[i];
		if (isupper(c) || isdigit(c))  continue ;
		else return false;
	}

	if ( length == 8)
	{
		c = tmp[7];
		if (isupper(c) || isdigit(c)) return true;
		else return false;
	}
	return true;

}

bool Course::checkValidName(string _name)
{
	if (_name.empty()) return false;
	if (strlen(_name.c_str())<=50) return true;
	else return false;	
}

bool Course::checkValidCredit(string _credit)
{
	if (_credit.empty()) return false;

	char* p;
	strtol(_credit.c_str(), &p, 10);
	if (*p != 0) return false;

	int tmp = atoi(_credit.c_str());
	if ( tmp >=0 && tmp <=5) return true;
	else return false;
}

bool Course::operator<(Course c)
{
	const char* c_1 = (getCode()).c_str();
	const char* c_2 = (c.getCode()).c_str();
	int i = 0;
	do {
		i = strcmp(c_1, c_2);
	} while(i == 0);
	if (i < 0) return true;
	return false;

}