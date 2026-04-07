#include <iostream>
#include "tree.h"

int main(void){
    Tree<int> tree;

    std::cout << tree.exist() << std::endl;
    std::cout << tree.size() << std::endl;
    std::cout << tree.root() << std::endl;

    return 0;
}