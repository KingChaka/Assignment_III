#include <iostream>
#include "tree.h"

int main(void) {
    Tree<int> tree;

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    tree.insert(tree.treeRoot, 5);

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    return 0;
}