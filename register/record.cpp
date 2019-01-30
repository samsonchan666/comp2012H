#include "record.h"

void Record::saveDatabase()
{
	string a;
	cout << "Enter the filename: " ;
	getline(cin, a);

    myfile = fopen(a.c_str(), "w");

    Deque<Student>* stu_q = s_hs->getDeque();
	for (int i = 0; i < STUDENT_BUCKETS; i++){
		if (stu_q[i].isEmpty()) continue;
		else {
			Deque<Student>::Iterator itr = stu_q[i].iterator();
			for (int j = 0 ; j < stu_q[i].size(); j++){
				Student tmp = *itr;
				const char* id = tmp.getId().c_str();
				const char* name = tmp.getName().c_str();
				int year = tmp.getYear();
				const char* gender = tmp.getGender().c_str();
				fprintf(myfile, "%s\t%s\t%d\t%s\n", id, name, year, gender);
				++itr;
			}
		}
	}

	/* separation indicator */
	fprintf(myfile, "separating\tseparating\tseparating\tseparating\n");

	Deque<Course>* crs_q = c_hs->getDeque();
	for (int i = 0; i < COURSE_BUCKETS; i++){
		if (crs_q[i].isEmpty()) continue;
		else {
			Deque<Course>::Iterator itr = crs_q[i].iterator();
			for (int j = 0 ; j < crs_q[i].size(); j++){
				Course tmp = *itr;
				const char* code = tmp.getCode().c_str();
				const char* name = tmp.getName().c_str();
				const char* credit = tmp.getCredit().c_str();
				fprintf(myfile, "%s\t%s\t%s\n", code, name, credit);
				++itr;
			}
		}
	}

	/* separation indicator */
	fprintf(myfile, "separating\tseparating\tseparating\n");

	Deque<CourseSelect>::Iterator itr = c_list->iterator();
	for (int i = 0; i < c_list->size(); i++){	
		CourseSelect tmp = *itr;
		const char* id = tmp.getId().c_str();
		const char* code = tmp.getCode().c_str();
		const char* mark = tmp.getMark().c_str();
		fprintf(myfile, "%s\t%s\t%s\n", id, code, mark);
		++itr;	
	}

	/* separation indicator */
	fprintf(myfile, "separating\tseparating\tseparating\n");

	fclose (myfile);

   	cout << "Saving Successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	     	
}

void Record::loadDatabase(HashTable<Student>* _s_hs, HashTable<Course>* _c_hs, Deque<CourseSelect>* _c_list)
{

	string a;
	cout << "Enter the filename: " ;
	getline(cin, a);
	bool separate = false;
	string line;
	ifstream myfile(a.c_str());

	while (true)
	{
		if (!(myfile.is_open())){
		   	cout << "Error: Load File Error";
		   	cout << "(File not exist / File Corrupted / Incorrect Format)"  << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();
			break;			
		}
			
		bool correct = true;

		string id, name, year, gender;

		while(true){
			myfile >> id; myfile >> name; myfile >> year; myfile >> gender;
			if (id == "separating") break;
			Student student;	
			student.setId(id);
			student.setName(name);
			student.setYear(atoi(year.c_str()));
			student.setGender(gender);

			_s_hs->hashFunc(id);
			_s_hs->pushStu(student);

			if (myfile.eof()) {correct = false; break;}

		}

		if (!(correct))  {
		   	cout << "Error: Load File Error";
		   	cout << "(File not exist / File Corrupted / Incorrect Format)"  << endl << endl;
			cout << "Hit ENTER to continue..." << endl;
			getchar();
			break;			
		}

		string code, crsName, credit;

		while(true){
			myfile >> code; myfile >> crsName; myfile >> credit;
			if (code == "separating") break;
			Course course;	
			course.setCode(code);
			course.setName(crsName);
			course.setCredit(credit);

			_c_hs->hashFuncCrs(code);
			_c_hs->pushCrs(course);

			
			
		} 		

		string _id, _code, mark;				
		while(true){
			myfile >> _id; myfile >> _code; myfile >> mark;	
			if (_id == "separating") break;
			CourseSelect courseSelect;	
			courseSelect.setId(_id);
			courseSelect.setCode(_code);
			courseSelect.setMark(mark);

			_c_list->addLast(courseSelect);


		} 		

	
		myfile.close();
	   	cout << "Loading Successful" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();
		break;	     					
	}


}