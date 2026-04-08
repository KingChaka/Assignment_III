#include <iostream>
#include "tree.h"

int main(void){
    Tree<int> tree;

    std::cout << "Tree exist?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    tree.insert(tree.root(), 5);
    tree.insert(tree.root(), 7);

    std::cout << "Tree exist?  " << tree.empty() << std::endl;
    std::cout << "Tree size:  " << tree.size() << std::endl;
    std::cout << "Tree root:  " << tree.root() << std::endl;

    return 0;
}