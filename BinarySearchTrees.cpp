#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int data) {
  struct Node* Node = (struct Node*)malloc(sizeof(struct Node));

  Node->data = data;

  Node->left = NULL;
  Node->right = NULL;

  return Node;
}

void showStack(stack<struct Node*> s) {
  while (!s.empty()) {
    cout << s.top()->data << endl;
    s.pop();
  }
  cout << endl;
}

// Postfix expression -> Binary Search Tree
void postfix(stack<struct Node*> &s, string e) {
  if (e.length() == 0) return;
  char c = e[0];

  // If current character in postfix expression is an operator,
  // pop off last two nodes and create a new subtree.  Push new
  // subtree back onto the stack.
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    struct Node *root = newNode(c);

    // Add left leaf
    root->right = s.top();
    s.pop();

    // Add right leaf
    root->left = s.top();
    s.pop();

    // Add back to stack
    s.push(root);
  }
  // Else, if the character is an operand, push it onto the stack.
  else {
    s.push(newNode(c));
  }

  showStack(s);
  return postfix(s, e.substr(1));
}

// Inorder traversal of tree
void inorder(struct Node* node) {
  if (!node) return;

  inorder(node->left);
  cout << node->data << " ";
  inorder(node->right);
}

// Postorder traversal of tree
void postorder(struct Node* node) {
  if (!node) return;

  postorder(node->left);
  postorder(node->right);
  cout << node->data << " ";
}

// Preorder traversal of tree
void preorder(struct Node* node) {
  if (!node) return;

  cout << node->data << " ";
  preorder(node->left);
  preorder(node->right);
}

int main() {
  stack<struct Node*> s;
  string expression = "xy+ab+c/*";

  postfix(s, expression);
  inorder(s.top());
  cout << endl;
  postorder(s.top());
}
