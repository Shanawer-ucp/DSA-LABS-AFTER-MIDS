// Task 6 (Bonus) - Build Expression Tree from Postfix Expression
// DSA Lab Week 11
// Postfix Expression: 3 5 + 8 2 - *
// Reconstructs the same tree as Task 5 using a stack

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

struct ExprNode {
    string data;
    ExprNode* left;
    ExprNode* right;
};

ExprNode* createExprNode(string value) {
    ExprNode* newNode = new ExprNode();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Check if a token is an operator
bool isOperator(const string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Build expression tree from a postfix expression string
ExprNode* buildFromPostfix(const string& postfix) {
    stack<ExprNode*> s;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (!isOperator(token)) {
            // Operand: create a leaf node and push onto stack
            s.push(createExprNode(token));
        } else {
            // Operator: pop two nodes, make them children
            ExprNode* opNode = createExprNode(token);

            // First popped becomes right child, second becomes left child
            opNode->right = s.top(); s.pop();
            opNode->left  = s.top(); s.pop();

            s.push(opNode); // Push the new subtree back
        }
    }

    // The remaining element is the root of the expression tree
    return s.top();
}

// Infix traversal with brackets
void printInfix(ExprNode* root) {
    if (root == nullptr)
        return;

    bool isOp = isOperator(root->data);
    if (isOp) cout << "(";
    printInfix(root->left);
    cout << root->data;
    printInfix(root->right);
    if (isOp) cout << ")";
}

// Prefix traversal
void printPrefix(ExprNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Postfix traversal
void printPostfix(ExprNode* root) {
    if (root == nullptr) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// Evaluate the expression tree
int evaluate(ExprNode* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return stoi(root->data);

    int leftVal  = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->data == "+") return leftVal + rightVal;
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;
    if (root->data == "/") return leftVal / rightVal;

    return 0;
}

int main() {
    string postfix = "3 5 + 8 2 - *";

    cout << "Postfix Input: " << postfix << endl;

    // Build the expression tree from postfix
    ExprNode* root = buildFromPostfix(postfix);

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    cout << "Final Answer: " << evaluate(root) << endl;

    return 0;
}
