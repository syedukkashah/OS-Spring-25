#include "Course.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;
Course::Course(string name):name(name){}
string Course:: getName(){return name;}
void Course::addStudent(Student* student){students.push_back(student);}
void Course::addTeacher(Teacher* teacher){teachers.push_back(teacher);}
void Course::displayParticipants(){
cout<<"Course: "<<name<<"\nStudents:\n";
for(auto student: students)
	cout<<"- "<<student->getName()<<endl;
cout<<"Teachers:\n";
for(auto teacher:teachers)
	cout<<"- "<<teacher->getName()<<endl;
}
