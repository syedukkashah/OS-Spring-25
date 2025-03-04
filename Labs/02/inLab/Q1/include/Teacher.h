#ifndef TEACHER_H
#define TEACHER_H
#include "iostream"
#include "vector"
#include "string"
#include "Course.h"
class Teacher{
string name;
vector<Course*> courses;
public:
Teacher(string name);
void assignCourse(Course* course);
void displayCourses();
string getName(){return name;}
};
#endif

