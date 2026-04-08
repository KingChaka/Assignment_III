#include <iostream>
#include "tree.h"

int main(void) {
    Tree<int> tree;

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;
    std::cout << std::endl;

    tree.insert(tree.treeRoot, 5);
    tree.insert(tree.treeRoot, 3);
    tree.insert(tree.treeRoot, 4);

    std::cout << "5 is located at:  " << tree.search(tree.treeRoot,5) << endl;
    std::cout << "4 is located at:  " << tree.search(tree.treeRoot,4) << endl;
    std::cout << "3 is located at:  " << tree.search(tree.treeRoot,3) << endl;
    std::cout << std::endl;

    tree.remove(tree.treeRoot,3);


    std::cout << "5 is located at:  " << tree.search(tree.treeRoot,5) << endl;
    std::cout << "4 is located at:  " << tree.search(tree.treeRoot,4) << endl;
    std::cout << "3 is located at:  " << tree.search(tree.treeRoot,3) << endl;
    std::cout << std::endl;

    std::cout << "Tree empty?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  "  << tree.size() << std::endl;
    std::cout << "Tree root:  "  << tree.root() << std::endl;
    std::cout << std::endl;


    return 0;
}