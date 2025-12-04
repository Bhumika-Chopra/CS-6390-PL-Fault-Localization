#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = nullptr;
  return node;
}

bool search(Node *root, int key, int verbose) {
  Node *current;
  current = root;

  while (current != nullptr) {
    if (current->data = key)
      return true;
    if (key < current->data)
      current = current->left;
    else
      current = current->right;
  }

  return false;
}

int main() {
  Node *root = newNode(50);
  root->left = newNode(30);
  root->right = newNode(70);
  int key;
  cin >> key;
  cout << (search(root, key, 0) ? "Found" : "Not found") << endl;
  delete root->right;
  delete root->left;
  delete root;
  return 0;
}
