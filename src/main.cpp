#include <cstdio>
#include <string>
using namespace std;

#include "degree.h"
#include "roster.h"
#include "student.h"

// student data table
const string studentData[] =
    {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Sammi,Ghazzawi,sghazza@wgu.edu,26,10,45,50,NETWORK"};

int main() {
    cout << "Course Title: Scripting and Pogramming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Name: Sammi Ghazzawi" << endl;
    cout << "Student ID: 011669483" << endl
         << endl;

    Roster classRoster(5);
    for (int i = 0; i < 5; i++) {
        classRoster.parseStudentData(studentData[i]);
    }
ß
    classRoster.printAll();
    classRoster.printInvalidEmails();
    printf("\n");

    for (const auto& student : classRoster) {
        classRoster.printAvgDaysInCourse(student->getStudentID());
    }

    printf("\n");
    classRoster.printByDegreeProgram(SOFTWARE);
    printf("\n");

    classRoster.remove("A3");
    printf("\n");
    classRoster.printAll();
    classRoster.remove("A3");

    classRoster.~Roster();

    return 0;
}
