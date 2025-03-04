#include "Student.h"
#include "Teacher.h"
#include "Course.h"
int main(){
Course math("MAthematics");
Course physics("Physics");
Student s1("Alice");
Student s2("Bob");
Teacher t1("Dr.Smith");
Teacher t2("Prof. Johnson");
s1.enroll(&math);
s1.enroll(&physics);
s2.enroll(&physics);
t1.assignCourse(&math);
t2.assignCourse(&physics);
math.addStudent(&s1);
physics.addStudent(&s1);
physics.addStudent(&s2);
math.addTeacher(&t1);
physics.addTeacher(&t2);
s1.displayCourses();
s2.displayCourses();
t1.displayCourses();
t2.displayCourses();
math.displayParticipants();
physics.displayParticipants();
return 0;
}
