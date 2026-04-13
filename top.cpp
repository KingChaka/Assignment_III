#include <string>
#include "expTree.h"


int main(void) {
    std::string expr = "((A+B)*(C-D))";

    ExpTree<char> tree;
    tree.storeExpression(expr);

    std::cout << "Pre-order: ";
    tree.preorderPrint(tree.root());
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postorderPrint(tree.root());
    std::cout << std::endl;

    return 0;
}
