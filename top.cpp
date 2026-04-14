#include "expTree.h"

int main(void) {
    std::string expr = "((A+B)*(C-D))";

    ExpTree<char> tree;
    tree.storeExpression(expr);

    // Pass the pointer treeRoot, not the data tree.root()
    std::cout << "Pre-order: ";
    tree.preorderPrint(tree.treeRoot);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postorderPrint(tree.treeRoot);
    std::cout << std::endl;

    return 0;
}
