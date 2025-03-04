#include "Student.h"
using namespace std;
Student::Student(string name):name(name){}
void Student::enroll(Course* course){courses.push_back(course);}
void Student::displayCourses(){
cout<<name<<" is enrolled in:\n";
for(auto course : courses)
     cout<<"- "<<course->getName()<<endl;
}

