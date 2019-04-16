#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
using namespace std;

class priorityQueue {
private:
  vector<int> v;

public:
  int size() { return v.size(); }
  bool empty() { return v.size() == 0; }
  vector<int> get_queue() const { return v; }
  void show_queue() {
    for (const auto &d : v)
      cout << d << " ";
    cout << endl;
  }

  void insert(const int& i) {
    v.push_back(i);

    int child = size() - 1;
    int parent = (child - 1) / 2;

    while (parent >= 0 && v[parent] < v[child]) {
      swap(v[parent], v[child]);
      child = parent;
      parent = (child - 1) / 2;
    }
  }

  void pop() {
    if (size() == 1) {
      v.pop_back();
      return;
    }

    swap(v[0], v[size() - 1]);
    v.pop_back();
    int parent = 0;

    while (true) {
      int left = 2 * parent + 1;

      if (left >= size()) {
        break;
      }

      int right = left + 1;
      int max = left;

      if (right < size() && v[left] < v[right]) {
        max = right;
      }

      if (v[parent] < v[max]) {
        swap(v[max], v[parent]);
        parent = max;
      }
      else {
        break;
      }
    }
  }
};

#endif
