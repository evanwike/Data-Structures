#ifndef PROJECT1_WAITLIST_H
#define PROJECT1_WAITLIST_H

#include "Course.h"
#include <vector>

using std::vector;

class WaitList {
private:
    vector<Course *> courses;

    void run() {
        outputMenu();

        int option = getUserInput(1, 4);

        if (!option)
            return run();

        switch (option) {
            case 1: addCourse(); break;
            case 2: {
                if (courses.empty()) {
                    cout << "Course list is currently empty. Consider adding one from the main menu first.\n" << endl;
                    return run();
                }
                selectCourse()->run();
                break;
            }
            case 3: removeCourse(); break;
            default: return;
        }

        return run();
    }

    static void outputMenu() {
        cout << "Course Menu" << endl;
        cout << "\t1. Add course" << endl;
        cout << "\t2. Select course" << endl;
        cout << "\t3. Remove course" << endl;
        cout << "\t4. Quit" << endl;
    }

    void addCourse() {
        cin.ignore();     // Flush input buffer
        string name;

        cout << "Add course:" << endl;
        cout << "Enter name of course: ";
        getline(cin, name);

        auto *course = new Course(name);
        courses.push_back(course);

        cout << "Course successfully added.\n" << endl;
    }

    Course *selectCourse() {
        cout << "Select course:" << endl;

        for (int i = 0; i < courses.size(); i++)
            printf("\t%d. %s\n", i + 1, courses[i]->getCourseName().c_str());

        int option = getUserInput(1, courses.size());

        if (!option)
            return selectCourse();

        return courses[option - 1];
    }

    void removeCourse() {
        if (courses.empty()) {
            cout << "Course list is currently empty. Consider adding one from the main menu first.\n" << endl;
            return;
        }

        cout << "Remove course:" << endl;

        for (int i = 0; i < courses.size(); i++)
            printf("\t%d. %s\n", i + 1, courses[i]->getCourseName().c_str());

        int option = getUserInput(1, courses.size());

        if (!option)
            return removeCourse();

        delete courses[option];
        courses.erase(courses.begin() + option - 1);
    }

public:
    explicit WaitList() {
        cout << "Welcome to the UMKC Wait List System" << endl;
        run();
    }
};

#endif //PROJECT1_WAITLIST_H