#ifndef EXP_TREE_H
#define EXP_TREE_H

#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isalnum
#include "tree.h"

template <typename T>
class ExpTree : public Tree<T> {
public:
    std::stack<TreeNode<T>*> operands;
    std::stack<char> operators;

    ExpTree() { }

    // Helper to create a new node easily
    TreeNode<T>* createNode(T val) {
        TreeNode<T>* node = new TreeNode<T>;
        node->data = val;
        return node;
    }

    void storeExpression(const std::string& expr) {
        for (char ch : expr) {
            if (isspace(ch) || ch == '(') continue; 
            
            if (isalnum(ch)) {
                operands.push(createNode(ch));
            } 
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                operators.push(ch);
            } 
            else if (ch == ')') {
                if (operators.empty() || operands.size() < 2) continue;

                TreeNode<T>* pNode = createNode(operators.top());
                operators.pop();

                pNode->right = operands.top();
                operands.pop();

                pNode->left = operands.top();
                operands.pop();

                operands.push(pNode);
            }
        }
        // CRITICAL: Set the base class treeRoot to the final operand
        if (!operands.empty()) {
            this->treeRoot = operands.top();
        }
    }

    // Fixed recursion: call the same function name
    void preorderPrint(TreeNode<T>* node) {
        if (!node) return;
        std::cout << node->data << " ";
        preorderPrint(node->left);
        preorderPrint(node->right);
    }

    void postorderPrint(TreeNode<T>* node) {
        if (!node) return;
        postorderPrint(node->left);
        postorderPrint(node->right);
        std::cout << node->data << " ";
    }
};

#endif
