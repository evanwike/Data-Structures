#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next = nullptr;
};

struct Node* newNode(const string &data) {
    Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;

    return node;
}

void traverse(Node* head) {
    while (head != nullptr) {
        if (head->next)
            cout << head->data << " -> ";
        else
            cout << head->data;

        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    head = newNode("Tom");
    head->next = newNode("John");
    head->next->next = newNode("Harry");
    head->next->next->next = newNode("Sam");

    traverse(head); // Tom -> John -> Harry -> Sam

    // a. Insert "Bill" before "Tom" (You have a reference to the head (Tom)).
    Node* bill = newNode("Bill");
    bill->next = head;
    head = bill;

    traverse(head); // Bill -> Tom -> John -> Harry -> Sam

    // b. Insert "Sue" before "Sam" (You only have a reference to Sam and the head).
    Node* head1 = head;

    while (head1->next->data != "Sam")
        head1 = head1->next;

    Node* sue = newNode("Sue");
    Node* sam = head1->next;

    head1->next = sue;
    sue->next = sam;

    traverse(head); // Bill -> Tom -> John -> Harry -> Sue -> Sam

    // c. Remove "Bill".
    Node* temp = head;
    head = head->next;
    free(temp);

    traverse(head); // Tom -> John -> Harry -> Sue -> Sam

    // d. Remove "Sam" (You only have a reference to the head and Sam).
    Node* head2 = head;

    while (head2->next->data != "Sam")
        head2 = head2->next;

    Node* temp2 = head2;
    head2->next = nullptr;
    free(temp2);

    traverse(head); // Tom -> John -> Harry -> Sue
}