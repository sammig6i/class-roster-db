#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

#include "degree.h"
#include "roster.h"
#include "student.h"

// student data table
const vector<string> studentData =
    {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Sammi,Ghazzawi,sghazza@wgu.edu,26,10,45,50,NETWORK"};

// parse Student Data table
vector<Student*> parseStudentData(const vector<string>& studentData) {
    vector<Student*> students;

    for (const auto& student : studentData) {
        stringstream ss(student);
        string token;
        vector<string> result;

        while (getline(ss, token, ',')) {
            result.push_back(token);
        }

        string studentID = result[0];
        string firstName = result[1];
        string lastName = result[2];
        string emailAddress = result[3];
        int age = stoi(result[4]);
        array<int, 3> daysToCompleteCourses = {stoi(result[5]),
                                               stoi(result[6]),
                                               stoi(result[7])};
        DegreeProgram degreeProgram = NONE;
        if (result[8] == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (result[8] == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        } else if (result[8] == "NETWORK") {
            degreeProgram = NETWORK;
        } else {
            cerr << "Invalid degree program: " << result[8] << endl;
        }

        Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);
        students.push_back(newStudent);
    }

    return students;
}

Roster addToRoster(const vector<Student*> students) {
    Roster classRoster(students.size());
    for (const auto& studentPtr : students) {
        classRoster.addStudent(studentPtr);
    }

    return classRoster;
}

int main() {
    cout << "Course Title: Scripting and Pogramming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Name: Sammi Ghazzawi" << endl;
    cout << "Student ID: 011669483" << endl
         << endl;

    vector<Student*> students = parseStudentData(studentData);
    Roster classRoster = addToRoster(students);

    classRoster.printAll();
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << "\n";

    for (Student* ptr : classRoster.classRosterArray) {
        classRoster.printAvgDaysInCourse(ptr->getStudentID());
    }
    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "\n";
    classRoster.remove("A3");
    classRoster.printAll();
    cout << "\n";
    classRoster.remove("A3");

    return 0;
}