// Task 5 - Expression Tree Construction and Traversal
// DSA Lab Week 11
// Expression: (3 + 5) * (8 - 2)
// Tree Structure:
//           *
//          / \
//         +   -
//        / \ / \
//       3  5 8  2

#include <iostream>
#include <string>
using namespace std;

struct ExprNode {
    string data;
    ExprNode* left;
    ExprNode* right;
};

// Helper to create a new expression node
ExprNode* createExprNode(string value) {
    ExprNode* newNode = new ExprNode();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Infix traversal: Left -> Root -> Right (with brackets)
void printInfix(ExprNode* root) {
    if (root == nullptr)
        return;

    // If it's an operator node, add brackets around sub-expression
    bool isOperator = (root->data == "+" || root->data == "-" ||
                       root->data == "*" || root->data == "/");

    if (isOperator) cout << "(";
    printInfix(root->left);
    cout << root->data;
    printInfix(root->right);
    if (isOperator) cout << ")";
}

// Prefix traversal: Root -> Left -> Right
void printPrefix(ExprNode* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Postfix traversal: Left -> Right -> Root
void printPostfix(ExprNode* root) {
    if (root == nullptr)
        return;

    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// Evaluate the expression tree numerically
int evaluate(ExprNode* root) {
    if (root == nullptr)
        return 0;

    // Leaf node: it's an operand (number)
    if (root->left == nullptr && root->right == nullptr)
        return stoi(root->data);

    // Recursively evaluate left and right subtrees
    int leftVal  = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Print the intermediate step
    cout << leftVal << " " << root->data << " " << rightVal
         << " = ";

    if (root->data == "+") {
        cout << leftVal + rightVal << endl;
        return leftVal + rightVal;
    }
    if (root->data == "-") {
        cout << leftVal - rightVal << endl;
        return leftVal - rightVal;
    }
    if (root->data == "*") {
        cout << leftVal * rightVal << endl;
        return leftVal * rightVal;
    }
    if (root->data == "/") {
        cout << leftVal / rightVal << endl;
        return leftVal / rightVal;
    }

    return 0;
}

int main() {
    // Build the expression tree for (3 + 5) * (8 - 2)
    ExprNode* root    = createExprNode("*");
    ExprNode* plus    = createExprNode("+");
    ExprNode* minus   = createExprNode("-");
    ExprNode* three   = createExprNode("3");
    ExprNode* five    = createExprNode("5");
    ExprNode* eight   = createExprNode("8");
    ExprNode* two     = createExprNode("2");

    // Link nodes
    root->left  = plus;
    root->right = minus;
    plus->left  = three;
    plus->right = five;
    minus->left = eight;
    minus->right = two;

    // Print expressions
    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    // Evaluate the expression (prints intermediate steps)
    cout << "Evaluation:" << endl;
    int result = evaluate(root);
    cout << "Final Answer: " << result << endl;

    return 0;
}
