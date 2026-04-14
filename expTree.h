/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
*
************************************************* */
#include <iostream>
#include <stack>
#include <string>
#include <cctype>                                           // for isalnum()
#include "tree.h"


#ifndef EXP_TREE_H
#define EXP_TREE_H

template <typename T>
class ExpTree : public Tree<T> {
public:
    std::stack<TreeNode<T>*> operands;
    std::stack<char> operators;

    ExpTree() { }

    TreeNode<T>* createNode(T val) {
        /* Function to create new nodes*/                   // Easier b/c unlike BSTs, expression
        TreeNode<T>* node = new TreeNode<T>;                // trees require alot manipulation (IMHO)
        node->data = val;
        return node;
    }

    void storeExpression(const std::string& expr) {
        /* Takes the expression string and puts into tree form*/
        for (char ch : expr) {
            if (isspace(ch) || ch == '(') continue;

            if (isalnum(ch)) {								// disregards punctionation et al.
                operands.push(createNode(ch));
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                operators.push(ch);							// strictly for operators
            }
            else if (ch == ')') {
				// sub-expressions are built here; with parent operators.
                if (operators.empty() || operands.size() < 2) continue;

                TreeNode<T>* pNode = createNode(operators.top());	//
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
            this->treeRoot = operands.top();			// the root is set.
        }
    }

    void preorderPrint(TreeNode<T>* node) {
        /* prints tree in preorder format */
        if (!node) return;
        std::cout << node->data << " ";
        preorderPrint(node->left);
        preorderPrint(node->right);
    }

    void postorderPrint(TreeNode<T>* node) {
        /* prints tree in postorder format */
        if (!node) return;
        postorderPrint(node->left);
        postorderPrint(node->right);
        std::cout << node->data << " ";
    }
};

#endif
