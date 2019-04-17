#ifndef PROJECT1_UTILS_H
#define PROJECT1_UTILS_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int getUserInput(const int &min, const int &max) {
    int option;

    cout << "==> ";
    cin >> option;
    cout << endl;

    // Validate user input
    if (!cin || option < 1 || option > max) {
        cin.clear();                    // Clears input buffer, restores cin to usable state.
        cin.ignore(INT_MAX, '\n');      // Ignores last input.
        cout << "Please select from the above menu options.\n" << endl;
        return false;
    }

    return option;
}

#endif //PROJECT1_UTILS_H
