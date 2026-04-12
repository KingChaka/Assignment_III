#include <iostream>
#include <stack>
#include <string>
#include "tree.h"

using namespace std;

TreeNode<char>* storeExpression(const string& expr) {

    stack<TreeNode<char>*> operands;
    stack<char> operators;

    for (char ch : expr) {
        if (ch == ' ') continue;            // skip spaces
        if (ch == '(')  continue;           // skip opening
        else if (isalnum(ch)) operands.push(createNode(ch));
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') operators.push(ch);

        else if (ch == ')') {
            char op = operators.top();
            operators.pop();

            TreeNode<char>* right = operands.top();
            operands.pop();

            TreeNode<char>* left  = operands.top();
            operands.pop();

            TreeNode<char>* node = createNode(op);
            node->left = left;
            node->right = right;

            operands.push(node);
        }
    }
    return operands.top();
}



// ---------------- MAIN ----------------
int main() {
    string expr = "((A+B)*(C-D))";

    TreeNode<char>* root = buildExpressionTree(expr);

    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}