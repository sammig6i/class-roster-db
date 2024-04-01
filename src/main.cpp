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

int main() {
    vector<vector<string>> results;

    // TODO parse each row of data in studentData to create a variable instance for each object in Student class
    for (const auto& student : studentData) {
        stringstream ss(student);
        vector<string> result;

        string token;
        for (int i = 0; i < 9; i++) {
            getline(ss, token, ',');
            if (i >= 4 && i <= 7) {
                if (i == 5) {
                    token = "{" + token;
                } else if (i == 7) {
                    token = token + "}";
                } else if (i == 4) {
                    token = to_string(stoi(token));
                }
            }
            result.push_back(token);
        }

        results.push_back(result);
    }

    for

        for (const auto& row : results) {
            for (const auto& field : row) {
                cout << field << ", ";
            }
            cout << endl;
        }

    return 0;
}