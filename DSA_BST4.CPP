//DSA_ASSIGNMENT4
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    if (newNode) {
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
        return root;
    }
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int findHeight(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int findMinimum(Node* root) {
    if (root == nullptr) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    if (root->left == nullptr)
        return root->data;
    return findMinimum(root->left);
}
Node* swapTree(Node* root) {
    if (root == nullptr)
        return nullptr;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapTree(root->left);
    swapTree(root->right);
    return root;
}
bool searchValue(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return searchValue(root->left, value);
    else
        return searchValue(root->right, value);
}
int main() {
    Node* root = nullptr;
    // Insert nodes in the given order
    int values[] = { 10, 6, 15, 3, 8, 12, 18 };
    int numNodes = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < numNodes; i++)
        root = insertNode(root, values[i]);
    cout << "Binary Search Tree (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;
    cout << "Number of nodes in the longest path: " << findHeight(root) << endl;
    int minimum = findMinimum(root);
    if (minimum != -1)
        cout << "Minimum value in the tree: " << minimum << endl;
    root = swapTree(root);
    cout << "Binary Search Tree after swapping left and right pointers:\n";
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    int searchVal;
    cout << "Enter a value to search in the tree: ";
    cin >> searchVal;
    if (searchValue(root, searchVal))
        cout << "Value found in the tree\n";
    else
        cout << "Value not found in the tree\n";
    return 0;
}