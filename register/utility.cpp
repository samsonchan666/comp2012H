#include "utility.h"

void Utility::outputStu()
{
    ofstream myfile;
    myfile.open("Students.html");
    myfile << "<HTML>\n<HEAD>\n<HEAD>\n"; //starting html
    myfile << "<TITLE>All Students List</TITLE>\n";
    myfile << "</HEAD>\n";
    myfile << "<BODY bgColor=#ffffcc>\n";
    myfile << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n";
    myfile << "<H2>All Students List</H2>\n";

    myfile << "<P>\n";
    if (!(s_hs->isEmpty(STUDENT_BUCKETS))){

      	myfile << "<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n";
    	myfile << "<TR>\n<TD>Student ID</TD>\n<TD>Student Name</TD>\n";
    	myfile << "<TD>Year</TD>\n<TD>Gender</TD>\n</TR>\n\n"; 

    	Deque<Student>* q = s_hs->getDeque(); 
    	Student s_arry[s_hs->size(STUDENT_BUCKETS)+1];
    	int count = 0;

    	for (int i = 0; i < STUDENT_BUCKETS; i++){
		if (q[i].isEmpty()) continue;
		else {
			Deque<Student>::Iterator itr = q[i].iterator();
			for (int j = 0 ; j < q[i].size(); j++){
				s_arry[count] = (*itr);
				count++;	
				++itr;
			}
		}
		}
		sort(s_arry, s_arry+count+1, IdComp);
		for (int k = 1; k < count+1; k++)
		{
			myfile << "<TR>\n";
			myfile << "<TD>" << s_arry[k].getId() << "</TD>\n";
			myfile << "<TD>" << s_arry[k].getName() << "</TD>\n";
			myfile << "<TD>" << s_arry[k].getYear() << "</TD>\n";
			myfile << "<TD>" << s_arry[k].getGender() << "</TD>\n";
			myfile << "</TR>\n\n";	
		}		
		myfile << "</TABLE>\n";    		
    }
    else myfile << "No student found\n";
	myfile << "</P>\n";

   //ending html
    myfile << "</BODY>\n</HTML>\n";
    myfile.close();	

   	cout << "Output Successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	 
}

void Utility::outputCrs()
{
    ofstream myfile;
    myfile.open("Courses.html");
    myfile << "<HTML>\n<HEAD>\n<HEAD>\n"; //starting html
    myfile << "<TITLE>All Course List</TITLE>\n";
    myfile << "</HEAD>\n";
    myfile << "<BODY bgColor=#ffffcc>\n";
    myfile << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n";
    myfile << "<H2>All Course List</H2>\n";

    myfile << "<P>\n";
    if (!(c_hs->isEmpty(COURSE_BUCKETS))){

      	myfile << "<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n";
    	myfile << "<TR>\n<TD>Course Code</TD>\n<TD>Course Name</TD>\n";
    	myfile << "<TD>Credit</TD>\n</TR>\n\n"; 

    	Deque<Course>* q = c_hs->getDeque(); 
    	Course c_arry[c_hs->size(COURSE_BUCKETS)+1];
    	int count = 0;

    	for (int i = 0; i < COURSE_BUCKETS; i++){
		if (q[i].isEmpty()) continue;
		else {
			Deque<Course>::Iterator itr = q[i].iterator();
			for (int j = 0 ; j < q[i].size(); j++){
				c_arry[count] = (*itr);
				count++;	
				++itr;
			}
		}
		}
		sort(c_arry, c_arry+count+1, CrsComp);
		for (int k = 1; k < count+1; k++)
		{
			myfile << "<TR>\n";
			myfile << "<TD>" << c_arry[k].getCode() << "</TD>\n";
			myfile << "<TD>" << c_arry[k].getName() << "</TD>\n";
			myfile << "<TD>" << c_arry[k].getCredit() << "</TD>\n";
			myfile << "</TR>\n\n";	
		}		
		myfile << "</TABLE>\n";    		
    }
    else myfile << "No course found\n";
	myfile << "</P>\n";

   //ending html
    myfile << "</BODY>\n</HTML>\n";
    myfile.close();	

	cout << "Output Successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();		       			
		
}

void Utility::outputListCrs()
{
	Student s;
	string id;
	while (true)
	{
	cout << "Enter the student ID: " ;
	do{
		getline(cin, id);
		if (!(s.checkValidId(id))) printf("Invalid input, re-enter again [student ID]: ");
	} while (!(s.checkValidId(id)));
	s.setId(id);
	s_hs->hashFunc(id);
	if (!(s_hs->isExist(s)))
	{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();		       			
		break;
	}

	Student student = s_hs->getStu(s);

    ofstream myfile;
    string filename = student.getId()+".html";
    myfile.open(filename.c_str());
    myfile << "<HTML>\n<HEAD>\n<HEAD>\n"; //starting html
    myfile << "<TITLE>Course Records for Student " << student.getId() << "</TITLE>\n";
    myfile << "</HEAD>\n";
    myfile << "<BODY bgColor=#ffffcc>\n";
    myfile << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n";
    myfile << "<H2>Course Records for Student: " ;
    myfile << student.getName() << " (" << student.getId() << ")" << "</H2>\n";
    myfile << "<P>\n";

    bool course_taken = false;
    Deque<CourseSelect>::Iterator itr = c_list->iterator();
    for (int i = 0; i < c_list->size(); i++)
    {   	
    	if (student.getId() == (*itr).getId()){
    		course_taken = true;
    		break;
    	}
    	++itr;
    }
    if (course_taken){
      	myfile << "<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n";
    	myfile << "<TR>\n<TD>Course Code</TD>\n<TD>Course Name</TD>\n";
    	myfile << "<TD>Credit</TD>\n<TD>Exam Mark</TD>\n</TR>\n\n"; 

    	Course tmp;

   		itr = c_list->iterator();
   		for (int j = 0; j < c_list->size(); j++){
   			if (student.getId() == (*itr).getId()){

  			myfile << "<TR>\n";
			myfile << "<TD>" << (*itr).getCode() << "</TD>\n";

			c_hs->hashFuncCrs((*itr).getCode());
			tmp.setCode((*itr).getCode());
			Course course = c_hs->getCrs(tmp);

			myfile << "<TD>" << course.getName() << "</TD>\n";
			myfile << "<TD>" << course.getCredit() << "</TD>\n";
			myfile << "<TD>" << (*itr).getMark() << "</TD>\n";			
			myfile << "</TR>\n\n";		
			 		  		
    		}
    		++itr;   			
   		}
 		myfile << "</TABLE>\n";   

    }    	
    else myfile << "No course taken\n";

	myfile << "</P>\n";

   //ending html
    myfile << "</BODY>\n</HTML>\n";
    myfile.close();	

	cout << "Output Successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;	       			

	}

}

void Utility::outputListStu() 
{
	Course c;
	string code;
	while (true)
	{
	cout << "Enter the course code: " ;
	do{
		getline(cin, code);
		if (!(c.checkValidCode(code))) printf("Invalid input, re-enter again [course code]: ");
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

	Course course = c_hs->getCrs(c);

    ofstream myfile;
    string filename = course.getCode()+".html";
    myfile.open(filename.c_str());
    myfile << "<HTML>\n<HEAD>\n<HEAD>\n"; //starting html
    myfile << "<TITLE>Student Records for Course " << course.getCode() << "</TITLE>\n";
    myfile << "</HEAD>\n";
    myfile << "<BODY bgColor=#ffffcc>\n";
    myfile << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n";
    myfile << "<H2>Student Records for Course: " ;
    myfile << course.getName() << " (" << course.getCode() << ")" << "</H2>\n";
    myfile << "<P>\n";

    bool student_taken = false;
    Deque<CourseSelect>::Iterator itr = c_list->iterator();
    for (int i = 0; i < c_list->size(); i++)
    {   	
    	if (course.getCode() == (*itr).getCode()){
    		student_taken = true;
    		break;
    	}
    	++itr;
    }
    if (student_taken){
      	myfile << "<TABLE cellSpacing=1 cellPadding=1 border=1>\n\n";
    	myfile << "<TR>\n<TD>Student ID</TD>\n<TD>Student Name</TD>\n";
    	myfile << "<TD>Year</TD>\n<TD>Gender</TD>\n<TD>Exam Mark</TD>\n</TR>\n\n"; 

    	Student tmp;

   		itr = c_list->iterator();
   		for (int j = 0; j < c_list->size(); j++){
   			if (course.getCode() == (*itr).getCode()){

  			myfile << "<TR>\n";
			myfile << "<TD>" << (*itr).getId() << "</TD>\n";

			s_hs->hashFunc((*itr).getId());
			tmp.setId((*itr).getId());
			Student student = s_hs->getStu(tmp);

			myfile << "<TD>" << student.getName() << "</TD>\n";
			myfile << "<TD>" << student.getYear() << "</TD>\n";
			myfile << "<TD>" << student.getGender() << "</TD>\n";
			myfile << "<TD>" << (*itr).getMark() << "</TD>\n";			
			myfile << "</TR>\n\n";		
			 		  		
    		}
    		++itr;   			
   		}
 		myfile << "</TABLE>\n";   

    }    	
    else myfile << "No student takes this course\n";

	myfile << "</P>\n";

   //ending html
    myfile << "</BODY>\n</HTML>\n";
    myfile.close();	

	cout << "Output Successful" << endl << endl;
	cout << "Hit ENTER to continue..." << endl;
	getchar();	
	break;	       			

	}	
}