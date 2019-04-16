#include "priorityQueue.h"
#include "heapToBST.h"
#include "testHeap.h"

// Inorder traversal for testing max heap
void inOrder(Node* root) {
  if (root != NULL) {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

// For testing
const priorityQueue createTestQueue(int length, int max) {
  priorityQueue queue;

  for (int i = 0; i < length; i++)
    queue.insert(rand() % max);

  return queue;
}

const priorityQueue createQueueFromInput(int length) {
  priorityQueue queue;

  for (int i = 0; i < length; i++) {
    int n;

    cout << "Int@Pos" << i << "==> ";
    cin >> n;

    queue.insert(n);
  }

  return queue;
}

int main() {
  // priorityQueue queue = createTestQueue(20, 10000);
  priorityQueue queue = createQueueFromInput(20);
  Node* root = createBST(queue.get_queue(), root, 0);

  // Output vector representation of max heap
  cout << "Max heap => ";
  queue.show_queue();
  cout << endl;

  // Output inorder traversal of max heap
  cout << "Inorder traversal => ";
  inOrder(root);
  cout << '\n' << endl;

  // Test if binary tree fulfills properties of a max heap
  if (isHeap(root))
    printf("SUCCESS! - Given binary tree is a heap\n");
  else
    printf("FAIL - Given binary tree is not a heap\n");
}
