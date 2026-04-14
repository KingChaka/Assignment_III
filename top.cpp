/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
************************************************* */

#include "expTree.h"                                            // iostream is already included here



void preOrd(const std::string& expr){
// https://chatgpt.com/s/t_69de33378bfc81918f9c39c85bde0f42
    std::stack<char> rands;
    std::stack<char> rators;
    for (int i=0; i < expr.size(); i++) {
        if (isspace(expr[i]) || expr[i] == '(') continue;
        if (isalnum(expr[i])) rands.push(expr[i]);
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') rators.push(expr[i]);
        else if (expr[i] == ')') {
            std::cout << expr[++i] << std::endl;
            
        }
    }
}

int main(void) {
    std::string expr = "((A+B)/(C-D))";                         // from instructions
    std::cout << "Input string: " << expr << std::endl;

    ExpTree<char> tree;
    tree.storeExpression(expr);

    std::cout << "Pre-order: ";
    tree.preorderPrint(tree.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postorderPrint(tree.treeRoot);
    std::cout << "\n" << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Expression take from HW#3 */
    std::string expr2 = "(((5+2)*(2-1))/(((2+9)+((7-2)-1))*8))";    // parenthese added after '/' because it wasn't fully parenthesize.
    std::cout << "Input string: " << expr2 << std::endl;

    ExpTree<char> tree2;
    tree2.storeExpression(expr2);

    std::cout << "Pre-order: ";
    tree2.preorderPrint(tree2.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree2.postorderPrint(tree2.treeRoot);
    std::cout << "\n" << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Somehting I just made up */
    std::string expr3 = "(((((((1+2)+3)+4)+5)+6)+7)+8)";
    std::cout << "Input string: " << expr3 << std::endl;

    ExpTree<char> tree3;
    tree3.storeExpression(expr3);

    std::cout << "Pre-order: ";
    tree3.preorderPrint(tree3.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree3.postorderPrint(tree3.treeRoot);
    std::cout << "\n" << std::endl;

    return 0;
}
