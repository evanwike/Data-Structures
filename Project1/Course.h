#ifndef PROJECT1_COURSE_H
#define PROJECT1_COURSE_H

#include "Student.h"
#include "utils.h"
using std::cin;
using std::cout;
using std::endl;

class Course {
private:
    string courseName;
    Student *head = nullptr;
    static Student* newStudent(const string &name) { return new Student(name); }

public:
    explicit Course(const string &courseName) { this->courseName = courseName; }
    string getCourseName() { return courseName; }

    void run() {
        printf("%s Wait List Menu\n", courseName.c_str());
        outputMenu();

        int option = getUserInput(1, 6);

        if (!option)
            return run();

        switch (option) {
            case 1: addToFront(); break;
            case 2: addToBack(); break;
            case 3: removeFromFront(); break;
            case 4: removeByName(); break;
            case 5: printWaitList(); break;
            default: return;
        }

        return run();
    }

    static void outputMenu() {
        cout << "\t1. Add student to front" << endl;
        cout << "\t2. Add student to back" << endl;
        cout << "\t3. Remove student from front" << endl;
        cout << "\t4. Remove student by name" << endl;
        cout << "\t5. View" << endl;
        cout << "\t6. Go back" << endl;
    }

    void addToFront() {
        cin.ignore();   // Flush input buffer

        string name;

        cout << "Enter student name: ";
        getline(cin, name);

        Student *student = newStudent(name);

        student->name = name;
        student->next = head;
        head = student;

        cout << "Student successfully added to the front of the wait list.\n" << endl;
    }

    void addToBack() {
        cin.ignore();   // Flush input buffer

        string name;

        cout << "\nEnter student name: ";
        getline(cin, name);

        Student *student = newStudent(name);
        student->name = name;
        student->next = nullptr;

        if (head == nullptr) {
            student->next = head;
            head = student;
        }
        else {
            Student *last = head;

            while (last->next != nullptr)
                last = last->next;

            last->next = student;
        }

        cout << "Student successfully added to the back of the wait list.\n" << endl;
    }

    void removeFromFront() {
        if (!head) {
            cout << "Wait list currently empty.\n" << endl;
            return;
        }

        Student* temp = head;
        string name = temp->name;
        head = head->next;
        free(temp);

        printf("%s successfully removed from the front of the wait list.\n", name.c_str());
        cout << endl;
    }

    void removeByName() {
        if (!head) {
            cout << "Wait list currently empty.\n" << endl;
            return;
        }

        cin.ignore();   // Flush input buffer
        string name;

        cout << "Enter student name: ";
        getline(cin, name);

        Student *before = head;

        while (before->next != nullptr && before->next->name != name)
            before = before->next;

        // Student not found
        if (!before->next) {
            cout << "No student by that name was found in the course list.\n" << endl;
            return;
        }

        Student *after = before->next->next;    // Student after student to be deleted
        free(before->next);                     // Free up memory of deleted student
        before->next = after;                   // Unlink deleted student

        printf("%s successfully removed from the wait list.\n", name.c_str());
    }

    void printWaitList() {
        if (!head) {
            cout << "Wait list currently empty.\n" << endl;
            return;
        }

        printf("%s Wait List", courseName.c_str());
        cout << endl;

        Student *student = head;
        int i = 1;

        while (student != nullptr) {
            printf("\t%d. %s\n", i++, student->name.c_str());
            student = student->next;
        }

        cout << endl;
    }
};

#endif //PROJECT1_COURSE_H