/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
************************************************* */

#include "expTree.h"                                            // iostream is already included here

int main(void) {
    std::string expr = "((A+B)*(C-D))";                         // from instructions
    std::cout << "Input string: " << expr << std::endl;

    ExpTree<char> tree;
    tree.storeExpression(expr);

    std::cout << "Pre-order: ";
    tree.preorderPrint(tree.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postorderPrint(tree.treeRoot);
    std::cout << std::endl;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    std::string expr2 = "(((5+2)*(2-1))/((2+9)+((7-2)-1))*8";   // taken from the homework
    ExpTree<char> tree2;
    tree2.storeExpression(expr2);

    std::cout << "Pre-order: ";
    tree2.preorderPrint(tree2.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree2.postorderPrint(tree2.treeRoot);
    std::cout << std::endl;

    return 0;
}
