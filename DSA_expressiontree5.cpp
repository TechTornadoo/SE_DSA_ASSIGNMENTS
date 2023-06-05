//DSA_ASSIGNMENT5 
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

Node* createNode(char value) {
    Node* node = new Node();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* constructExpressionTree(string prefixExpression) {
    stack<Node*> st;

    // Read the prefix expression from right to left
    for (int i = prefixExpression.length() - 1; i >= 0; i--) {
        char token = prefixExpression[i];

        if (token == '+' || token == '-' || token == '*' || token == '/') {
            // Create a new node with the operator
            Node* node = createNode(token);

            // Pop two operands from the stack and assign them as children of the new node
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();

            // Push the new node onto the stack
            st.push(node);
        } else {
            // Create a new node with the operand
            Node* node = createNode(token);

            // Push the operand node onto the stack
            st.push(node);
        }
    }

    // The last remaining node in the stack is the root of the expression tree
    return st.top();
}

void postOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->value << " ";
}

void deleteTree(Node* node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    string prefixExpression;
    cout << "Enter the prefix expression: ";
    getline(cin, prefixExpression);

    Node* expressionTree = constructExpressionTree(prefixExpression);

    // Traverse the expression tree using post-order traversal
    cout << "Post-order traversal: ";
    postOrderTraversal(expressionTree);
    cout << endl;

    // Delete the expression tree
    deleteTree(expressionTree);

    return 0;
}
// Enter the prefix expression: +--a*bc/def
// Post-order traversal: a b c * - d e / - f +