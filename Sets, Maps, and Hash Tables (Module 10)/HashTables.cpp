#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::cout;
using std::endl;

int hash(const string &key) {
    int n = key.length();
    int val = 0;

    for (int i = 0; i < key.length(); i++)
        val += key[i] * pow(31, n - (i + 1));

    return val;
}

void insert(int hashVal, const string &key, const std::vector<string> &table) {
    if (table[hashVal] != NULL) {

    }
}

int main() {
    std::vector<string> table(10);

    cout << hash("Cat") << endl;
}