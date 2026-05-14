#include <iostream>
#include "LBT.h"


int main() {
    LBT tree;
    tree.addRoot();
    LBT::Position r = tree.root();
    *r = 1;

    tree.expandExternal(r);

    LBT::Position left = r.left();
    LBT::Position right = r.right();
    *left = 2;
    *right = 3;

    tree.expandExternal(left);
    LBT::Position left_l = left.left();
    LBT::Position left_r = left.right();
    *left_l = 4;
    *left_r = 5;

    tree.expandExternal(right);
    LBT::Position right_l = right.left();
    LBT::Position right_r = right.right();
    *right_l = 6;

    std::cout << "Preorder: ";
    tree.preorderPrint(std::cout);
    std::cout << std::endl;

    std::cout << "Inorder: ";
    tree.inorderPrint(std::cout);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    tree.postorderPrint(std::cout);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
