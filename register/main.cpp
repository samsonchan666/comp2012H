#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <limits>
#include "HashTable.h"
#include "Student.h"
#include "course.h"
#include "courseSelect.h"
#include "utility.h"
#include "record.h"
#include "deque.h"
using namespace std;

/* error message */
void error_msg(const char* msg)
{
	printf("Invalid input, re-enter again %s: ",msg);
}

bool checkValid(string i, int size)
{
	if (i.empty()) return false;
	char* p;
	strtol(i.c_str(), &p, 10);
	if (*p != 0) return false;
	else {
		int tmp = atoi(i.c_str());
		if ( tmp > 0 && tmp <= size) return true;
		else return false;
		}

}


void insert_Std(HashTable<Student>* hs)
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	s.setId(id.c_str());
	hs->hashFunc(id);	//set the hashtable index
	if (hs->isExist(s))		//check whether student is exist
	{
		cout << "Student already exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	} 
	cout << "Enter the student name: ";
	string name;
	do{
		getline(cin, name);
		if (!(s.checkValidName(name))) error_msg("[student name]");
	} while (!(s.checkValidName(name)))	;
	s.setName(name);
	cout << "Enter the student year [1-3]: ";
	string year;
	do{
		getline(cin, year);
		if (!(checkValid(year,3))) error_msg("[student year]");
	} while (!(checkValid(year,3)))	;
	s.setYear(atoi(year.c_str()));
	cout << "Enter the student gender [M,F]: ";
	string gender;
	do{
		getline(cin, gender);
		if (!(s.checkValidGender(gender))) error_msg("[M,F]");
	} while (!(s.checkValidGender(gender)));
	s.setGender(gender);
	hs->pushStu(s);
	//hs->print();
	cout << "Creation of student record successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();
	break;
	}
}

void modify_Std(HashTable<Student>* hs)
{
	Student s;
	string id;
	cout << "Enter the student ID: " ;	
	while (true)
	{
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	hs->hashFunc(id);
	s.setId(id.c_str());
	if (!(hs->isExist(s)))	////check whether student is exist
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}
	else 
	{
	Deque<Student>* q = hs->getDeque();
	int index = hs->getIndex();
	Deque<Student>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++)
	{
        if ( s == *itr){
	 	printf("Enter the student name [%s]: ",(*itr).getName().c_str());
		string name;
		do{
			getline(cin, name);
			if (!(s.checkValidName(name))) error_msg("[student name]");
		} while (!(s.checkValidName(name)))	;
		(*itr).setName(name);
		printf("Enter the student year [%d]: ",(*itr).getYear());
		string year;
		do{
			getline(cin, year);
			if (!(checkValid(year,3))) error_msg("[student year]");
		} while (!(checkValid(year,3)))	;
		(*itr).setYear(atoi(year.c_str()));
		printf("Enter the student year [%s]: ",(*itr).getGender().c_str());
		string gender;
		do{
			getline(cin, gender);
			if (!(s.checkValidGender(gender))) error_msg("[M,F]");
		} while (!(s.checkValidGender(gender)));
		(*itr).setGender(gender);      	 	
    	printf("Modification of student record successful\n\n");
    	printf("Hit ENTER to continue...");
    	getchar();
    	break;
    	}
    	else ++itr;
	}		
	}
	break;	
	}
}

void delete_Std(HashTable<Student>* hs, Deque<CourseSelect>* c_list)
{
	Student s;
	string id;
	cout << "Enter the student ID: " ;
	while (true)
	{
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	hs->hashFunc(id);
	s.setId(id.c_str());
	if (!(hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	CourseSelect cs;
	cs.setId(id);
	//if (!(c_list->isEmpty())) c_list->removeNode(cs); 
	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	for (int i = 0; i<c_list->size(); i++)
	{
		if (*itr == cs) c_list->removeNode(cs);
	}

	hs->deleteStu(s);
	break;	
	}

}

void query_Std(HashTable<Student>* hs)
{
	Student s;
	string id;
	cout << "Enter the student ID: " ;
	while (true)
	{
		do{
			getline(cin, id);
			if (!(s.checkValidId(id))) error_msg("[student ID]");
		} while (!(s.checkValidId(id)));
		hs->hashFunc(id);
		s.setId(id.c_str());
		if (!(hs->isExist(s)))
		{
			cout << "Student not exist" << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();		       			
			break;
		}
		hs->hashFunc(id);
		s.setId(id.c_str());
		hs->queryStu(s);
		break;		
	}

}

void insert_Crs(HashTable<Course>* hs)
{
	Course c;
	string code;
	while (true)
	{
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	c.setCode(code);
	hs->hashFuncCrs(code);	// compute course hash index
	if (hs->isExist(c))		//check whether course is not exist
	{
		cout << "Course already exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	} 
	cout << "Enter the course name: ";
	string name;
	do{
		getline(cin, name);
		if (!(c.checkValidName(name))) error_msg("[course name]");
	} while (!(c.checkValidName(name)))	;
	c.setName(name);
	cout << "Enter the course credit [0-5]: ";
	string credit;
	do{
		getline(cin, credit);
		if (!(c.checkValidCredit(credit))) error_msg("[course credit]");
	} while (!(c.checkValidCredit(credit)))	;
	c.setCredit(credit);
	hs->pushCrs(c);
	// hs->print();
	cout << "Creation of course record successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();
	break;
	}
}

void modify_Crs(HashTable<Course>* hs)
{
	Course c;
	string code;
	cout << "Enter the course code: " ;	
	while (true)
	{
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	hs->hashFuncCrs(code);
	c.setCode(code.c_str());
	if (!(hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}
	else 
	{
	Deque<Course>* q = hs->getDeque();
	int index = hs->getIndex();
	Deque<Course>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++)
	{
        if ( c == *itr){
		printf("Enter the course name [%s]: ",(*itr).getName().c_str());
		string name;
		do{
			getline(cin, name);
			if (!(c.checkValidName(name))) error_msg("[course name]");
		} while (!(c.checkValidName(name)))	;
		(*itr).setName(name);
		printf("Enter the credit [%s]: ",(*itr).getCredit().c_str());
		string credit;
		do{
			getline(cin, credit);
			if (!(c.checkValidCredit(credit))) error_msg("course credit");
		} while (!(c.checkValidCredit(credit)));
		(*itr).setCredit(credit);      	 	
    	printf("Modification of course record successful\n\n");
    	printf("Hit ENTER to continue...");
    	getchar();
    	break;
    	}
    	else ++itr;
	}		
	}
	break;	
	}	
}

void delete_Crs(HashTable<Course>* hs, Deque<CourseSelect>* c_list)
{
	Course c;
	string code;
	cout << "Enter the course code: " ;
	while (true)
	{
	do{
		getline(cin, code);
		if (!c.checkValidCode(code)) error_msg("[course code]");
	} while (!c.checkValidCode(code));
	hs->hashFuncCrs(code);
	c.setCode(code.c_str());
	if (!(hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	} 

	bool registered = false;
	Deque<CourseSelect>::Iterator itr = c_list->iterator();
    for (int i = 0; i < c_list->size(); i++){
   		if (code == (*itr).getCode()) {
		cout << "Some students already registered in this course, deletion fail" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		registered = true;
		getchar();		       				
		break;
		}
		++itr;
    }

    if (registered) break;

	hs->deleteCrs(c);
	break;	
	}	
}

void query_Crs(HashTable<Course>* hs)
{
	Course c;
	string code;
	cout << "Enter the course code: " ;
	while(true)
	{
		do{
			getline(cin, code);
			if (!c.checkValidCode(code)) error_msg("[course code]");
		} while (!c.checkValidCode(code));
		hs->hashFuncCrs(code);
		c.setCode(code.c_str());
		if (!(hs->isExist(c)))
		{
			cout << "Course not exist" << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();		       			
			break;
		} 
		hs->queryCrs(c);	
		break;		
	}

}

static bool CsComp(CourseSelect a, CourseSelect b)
{
	return a < b;
}


void add_Crs(HashTable<Student>* s_hs, HashTable<Course>* c_hs, Deque<CourseSelect>* c_list)
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	s.setId(id.c_str());
	s_hs->hashFunc(id);
	if (!(s_hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	Course c;
	string code;	
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	c.setCode(code);
	c_hs->hashFuncCrs(code);
	if (!(c_hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	CourseSelect cs;
	cs.setId(id);
	cs.setCode(code);
	bool fail = false;

	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	for(int i = 0; i < c_list->size();i++){
        if ( cs == *itr) {
        	fail = true;
        	break;
        }
        ++itr;
	}	
	if (fail) {
		cout << "The student already registered the course" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	int z = 0;
	int count = c_list->size();
	CourseSelect cs_arry[count+1];
	if (c_list->isEmpty()) c_list->addLast(cs);
	else
	{
		while (!(c_list->isEmpty()))
		{
			cs_arry[z] = c_list->removeFirst();
			z++;
		}
		cs_arry[z] = cs;
		sort(cs_arry, cs_arry+count+1, CsComp);	//sorting
		for (int j = 0; j < count+1; j++)
		{
			c_list->addLast(cs_arry[j]);
		}		
	}

	cout << "Add course successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;
	}


}

void drop_Crs(HashTable<Student>* s_hs, HashTable<Course>* c_hs, Deque<CourseSelect>* c_list)
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	s.setId(id.c_str());
	s_hs->hashFunc(id);
	if (!(s_hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	Course c;
	string code;	
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	c.setCode(code);
	c_hs->hashFuncCrs(code);
	if (!(c_hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	CourseSelect cs;
	cs.setId(id);
	cs.setCode(code);
	bool success = false;	
	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	int size = c_list->size();
	for(int i = 0; i <size ;i++){
        if ( cs == *itr) {
        	success = true;
        	c_list->removeNode(*itr);
			cout << "Drop course successful" << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();	
			break;        	
        }
        ++itr;
	}
	if (success) break;
	cout << "The registration record not exist" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;
	}

}

void mod_Mrks(HashTable<Student>* s_hs, HashTable<Course>* c_hs, Deque<CourseSelect>* c_list)
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	s.setId(id.c_str());
	s_hs->hashFunc(id);
	if (!(s_hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	Course c;
	string code;	
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	c.setCode(code);
	c_hs->hashFuncCrs(code);
	if (!(c_hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	CourseSelect cs;
	cs.setId(id);
	cs.setCode(code);
	bool success = false;	
	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	for(int i = 0; i < c_list->size();i++){
        if ( cs == *itr) {
        	string mark;
 			printf("Enter the exam mark [%s]: ", (*itr).getMark().c_str());
		 	do{
				getline(cin, mark);
				if (!(cs.checkValidMark(mark))) error_msg("[exam mark]");
			} while (!(cs.checkValidMark(mark)));	
			(*itr).setMark(mark);
			success = true;
			cout << "Modification of exam mark successful" << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();					
			break;        	
        }
        else ++itr;
	}
	if (success) break;
	cout << "The registration record not exist" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;       	

	}

}

void query_Reg(HashTable<Student>* s_hs, HashTable<Course>* c_hs, Deque<CourseSelect>* c_list)
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) error_msg("[student ID]");
	} while (!(s.checkValidId(id)));
	s.setId(id.c_str());
	s_hs->hashFunc(id);
	if (!(s_hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	Course c;
	string code;	
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) error_msg("[course code]");
	} while (!(c.checkValidCode(code)));
	c.setCode(code);
	c_hs->hashFuncCrs(code);
	if (!(c_hs->isExist(c)))
	{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	CourseSelect cs;
	cs.setId(id);
	cs.setCode(code);
	bool success = false;	
	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	for(int i = 0; i < c_list->size();i++){
        if ( cs == *itr) {
 			printf("Student ID: %s\n", (*itr).getId().c_str());
 			printf("Course Code: %s\n", (*itr).getCode().c_str());
 			printf("Exam Mark: %s\n", (*itr).getMark().c_str());
			success = true;
			cout << "Hit ENTER to continue..." << endl;
			getchar();					
			break;        	
        }
        else ++itr;
	}
	if (success) break;
	cout << "The registration record not exist" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;       	

	}
}

int main()
{
	Student s;
	Course c;
	HashTable<Student>* s_hs = new HashTable<Student>(s);
	HashTable<Course>* c_hs = new HashTable<Course>(c);
	Deque<CourseSelect>* c_list = new Deque<CourseSelect>;

	string i;
	do {
		system("clear");
		cout << "HKUST Course Registration System" << endl;
		cout << "--------------------------------" << endl;
		cout << endl;
		cout << "1. Student Management" << endl;
		cout << "2. Course Management" << endl;
		cout << "3. Course Registration" << endl;
		cout << "4. Report Management" << endl;
		cout << "5. File Management" << endl;
		cout << "6. Exit" << endl;
		cout << endl;
		cout << "Enter your choice (1-6): " ;
		do{
			getline(cin, i);
			if(!(checkValid(i,6))) error_msg("(1-6)");
		} while(!(checkValid(i,6)));	//check the range of input

		if (i == "1"){
			system("clear");
			cout << "HKUST Course Registration System (Student Meau)" << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			cout << "1. Insert Student Record" << endl;
			cout << "2. Modify Student Record" << endl;
			cout << "3. Delete Student Record" << endl;
			cout << "4. Query Student Record" << endl;
			cout << "5. Go back to main menu" << endl;
			cout << endl;
			cout << "Enter your choice (1-5): " ;
			string a;
			do{
				getline(cin, a);
				if(!(checkValid(a,5))) error_msg("(1-5)");
			} while(!(checkValid(a,5)));			

			if (a == "1") insert_Std(s_hs); 	//Student operation
			else if (a == "2") modify_Std(s_hs);
			else if (a == "3") delete_Std(s_hs, c_list);
			else if (a == "4") query_Std(s_hs);
			else if (a == "5") system("clear"); 
		}
		else if (i == "2"){
			system("clear");
			cout << "HKUST Course Registration System (Course Meau)" << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			cout << "1. Insert Course Record" << endl;
			cout << "2. Modify Course Record" << endl;
			cout << "3. Delete Course Record" << endl;
			cout << "4. Query Course Record" << endl;
			cout << "5. Go back to main menu" << endl;
			cout << endl;
			cout << "Enter your choice (1-5): " ;
			string a;
			do{
				getline(cin, a);
				if(!(checkValid(a,5))) error_msg("(1-5)");
			} while(!(checkValid(a,5)));
			if (a == "1") insert_Crs(c_hs);		//Course operation
			else if (a == "2") modify_Crs(c_hs);
			else if (a == "3") delete_Crs(c_hs, c_list);
			else if (a == "4") query_Crs(c_hs);
			else if (a == "5") system("clear"); 								
		}
		else if (i == "3"){
			system("clear");
			cout << "HKUST Course Registration System (Registration Meau)" << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			cout << "1. Add Course" << endl;
			cout << "2. Drop Course" << endl;
			cout << "3. Modify Exam Mark" << endl;
			cout << "4. Query Registration" << endl;
			cout << "5. Go back to main menu" << endl;
			cout << endl;
			cout << "Enter your choice (1-5): " ;

			string a;
			do{
				getline(cin, a);
				if(!(checkValid(a,5))) error_msg("(1-5)");
			} while(!(checkValid(a,5)));
			if (a == "1") add_Crs(s_hs, c_hs,c_list);	//Course selection operation
			else if (a == "2") drop_Crs(s_hs, c_hs,c_list);
			else if (a == "3") mod_Mrks(s_hs, c_hs,c_list);
			else if (a == "4") query_Reg(s_hs, c_hs,c_list);
			else if (a == "5") system("clear"); 								
		}
		else if (i == "4"){
			system("clear");
			cout << "HKUST Course Registration System (Report Generation Meau)" << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			cout << "1. List all student information" << endl;
			cout << "2. List all course information" << endl;
			cout << "3. List all courses of a student" << endl;
			cout << "4. List all students of a course" << endl;
			cout << "5. Go back to main menu" << endl;
			cout << endl;
			cout << "Enter your choice (1-5): " ;	

			string a;
			do{
				getline(cin, a);
				if(!(checkValid(a,5))) error_msg("(1-5)");
			} while(!(checkValid(a,5)));
			if (a == "1")  { Utility u_shs(s_hs); u_shs.outputStu(); }	//Output html
			else if (a == "2") { Utility u_chs(c_hs); u_chs.outputCrs(); }
			else if (a == "3") { Utility u_clist(s_hs, c_hs, c_list); u_clist.outputListCrs(); }	
			else if (a == "4")  { Utility u_clist(s_hs, c_hs, c_list); u_clist.outputListStu(); }
			else if (a == "5") system("clear"); 		
		
		}
		else if (i == "5"){
			system("clear");
			cout << "HKUST Course Registration System (File Meau)" << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			cout << "1. Save Database" << endl;
			cout << "2. Load Database" << endl;
			cout << "3. Go back to main menu" << endl;
			cout << endl;
			cout << "Enter your choice (1-3): " ;

			string a;
			do{
				getline(cin, a);
				if(!(checkValid(a,3))) error_msg("(1-3)");
			} while(!(checkValid(a,3)));

			if (a == "1")  { Record save(s_hs, c_hs, c_list); save.saveDatabase(); }
			else if (a == "2") { Record load; load.loadDatabase(s_hs, c_hs, c_list); }
			else if (a == "3") system("clear");  //database saving, loading			
		}
		else if (i == "6") break;

	} while ( i != "6") ;

	return 0;
}
