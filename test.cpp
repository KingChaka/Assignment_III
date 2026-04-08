#include <iostream>
#include "tree.h"

int main(void) {
    Tree<int> tree;

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    tree.insert(tree.treeRoot, 5);
    tree.insert(tree.treeRoot, 3);
    tree.insert(tree.treeRoot, 4);
    tree.insert(tree.treeRoot, 6);

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    return 0;
}