#include <iostream>
#include <stack>
#include <string>
#include "tree.h"



#ifndef EXP_TREE_H
#define EXP_TREE_H

template <typename T>
class ExpTree : public Tree<T> {

    public:
        // CONSTRUCTORS and DESTRUCTOR ----------------------------------------
        ExpTree() { }
        ~ExpTree() { }

        // Members
        std::stack<TreeNode<char>*> operands;
        std::stack<char> operators;
        Tree eTree;

        // MUTATOR ------------------------------------------------------------
        void storeExpression(const string& expr) {

            for (char ch : expr) {
                if (ch == ' ') continue;            // skip spaces
                if (ch == '(')  continue;           // skip opening
                else if (isalnum(ch)) operands.push(createNode(ch));
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') operators.push(ch);
                // operators are stored

                else if (ch == ')') {
                    TreeNode<T> * pNode = new TreeNode<T>;
                    pNode->data = operators.top();
                    operators.pop();                            // removes the character from stack

                    pNode->right = operands.top();
                    operands.pop();

                    pNode->left  = operands.top();
                    operands.pop();

                    operands.push(pNode);
                }
            }
            return;
        }

        // ACESSORS ----s> t-------------------------------------------------------
        
        void preorderPrint(TreeNode<T>* root) {
            if (!root) return;

            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

        void postorderPrint(TreeNode<T>* root) {
            if (!root) return;

            postorder(root->left);
            postorder(root->right);
            std::cout << root->data << " ";
        }


};

#endif // EXP_TREE_H