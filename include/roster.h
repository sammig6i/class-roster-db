#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
   public:
    std::vector<Student*> classRosterArray;

    Roster(int size) {
        classRosterArray.reserve(size);
    }

    ~Roster() {
        for (Student* studentptr : classRosterArray) {
            delete studentptr;
        }
    }
};

#endif