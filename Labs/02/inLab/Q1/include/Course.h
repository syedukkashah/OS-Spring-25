#ifndef COURSE_H
#define COURSE_H
#include "iostream"
#include "vector"
#include "string"
using namespace std;
class Student;
class Teacher;
class Course{
string name;
vector<Student*> students;
vector<Teacher*> teachers;
public:
Course(string name);
string getName();
void addStudent(Student* student);
void addTeacher(Teacher* teacher);
void displayParticipants();
};
#endif
