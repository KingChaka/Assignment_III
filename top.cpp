/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #3 - Tree Traversal for Parenthesized Math Expressions
*  Purpose: To reinforce and demonstrate a sufficient understanding of
*           of the tree ADT.
************************************************* */

#include "expTree.h"                                            // iostream is already included here

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

    return 0;
}
