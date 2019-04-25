#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

// Union
template<typename T, typename C>
set<T, C> operator+(const set<T, C> &left, const set<T, C> &right) {
    typename std::set<T, C> result(left);
    result.insert(right.begin(), right.end());
    return result;
}

// Difference
template<typename T, typename C>
set<T, C> operator-(const set<T, C> &left, const set<T, C> &right) {
    typename std::set<T, C> result(left);
    for (typename set<T, C>::const_iterator itr = right.begin(); itr != right.end(); ++itr)
        result.erase(*itr);
    return result;
}

// Membership
template<typename T, typename C>
bool contains(const set<T, C> &s, const T &k) {
    return s.find(k) != s.end();
}

// Intersection
template <typename T, typename C>
set<T, C> operator * (const set<T, C> &left, const set<T, C> &right) {
    return left - (left - right);
}

// Printing
template<typename T>
ostream& operator << (ostream& os, const set<T> &s) {
    os << "{";
    bool first = true;

    for (typename set<T>::const_iterator itr = s.begin(); itr != s.end(); ++itr) {
        if (first) os << *itr;
        else os << ", " << *itr;
        first = false;
    }
    return os << "}";
}

int main() {
    set<string> s;
    s.insert("hello");
    s.insert("bye");
    // s = {bye, hello}
    set<string> u(s);
    // u = {bye, hello}, creating a new set u from set s
    set<string> t;
    t.insert("123");
    cout << t << endl;
    // t = {123}
    cout << (t - s) << endl;
    // (t - s) = {123}, elements t has but s doesn't
    cout << (s - t) << endl;
    // (s - t) = {bye, hello}, elements s has but t doesn't
    cout << boolalpha;
    cout << contains(s, string("ace")) << endl;
    // false, s does not contain the element "ace"
    cout << contains(s, string("123")) << endl;
    // false, s does not contain the element "123"
    s = s * t;
    cout << s << endl;
    // {}, empty set, s and t share no common elements
    t = t * s;
    cout << t << endl;
    // {}, empty set, t and s share no common elements
}