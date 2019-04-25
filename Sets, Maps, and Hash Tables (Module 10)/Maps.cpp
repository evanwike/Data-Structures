#include <map>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

template<typename T1, typename T2>
void display(const map<T1, T2> &m) {
    for (typename map<T1, T2>::const_iterator itr = m.begin(); itr != m.end(); ++itr)
        cout << itr->first << " : " << itr->second << endl;
}

int main() {
    map<int, string> m;

    m.insert(pair<int, string>(1234, "sam"));
    m.insert(pair<int, string>(2456, "bill"));
    m[2222] = "hal";
    m[1234] = "sally";
    cout << m[1111];

    display(m);
}
