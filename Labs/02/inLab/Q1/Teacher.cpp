#include "Teacher.h"
using namespace std;
Teacher::Teacher(string name):name(name){}
void Teacher::assignCourse(Course* course){courses.push_back(course);}
void Teacher::displayCourses(){
cout<<name<<" teaches:\n";
for (auto course:courses)
    cout<<"- "<<course->getName()<<endl;
}
