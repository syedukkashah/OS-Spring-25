#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "vector"
#include "string"
#include "Course.h"
using namespace std;
class Student{
string name;
vector<Course*> courses;
public:
Student(string name);
void enroll(Course* course);
void displayCourses();
string getName(){return name;}
};
#endif

