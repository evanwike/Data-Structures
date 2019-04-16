#ifndef HEAPTOBST_H
#define HEAPTOBST_H

struct Node {
  int data;
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

Node* createBST(const vector<int> &heap, Node* root, int i) {
  if (i < heap.size()) {
    Node* temp = newNode(heap[i]);
    root = temp;

    // Insert left child
    root->left = createBST(heap, root->left, 2 * i + 1);

    // Insert right child
    root->right = createBST(heap, root->right, 2 * i + 2);
  }

  return root;
}

#endif
