#include <cstdio>
#include <sstream>
#include <string>

#include "degree.h"
#include "roster.h"
#include "student.h"

// student data table
const std::string studentData[] =
    {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Sammi,Ghazzawi,sghazza@wgu.edu,26,10,45,50,NETWORK"};

int main() {
    std::vector<std::string> studentDataTable;
    // TODO parse each row of data in studentData to create each variable instance in Student class
    for (const std::string& studentString : studentData) {
        for (char c : studentString) {
            if (c != ',') {
                std::stringstream ss;
                ss << c;
                std::string str = ss.str();
                studentDataTable.push_back(str);
            }
        }
    }

    return 0;
}