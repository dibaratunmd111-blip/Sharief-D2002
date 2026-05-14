#include <iostream>
#include "LBT.h"

int main() {
    LBT tree;
    tree.addRoot();
    LBT::Position r = tree.root();
    *r = 50;
    tree.expandExternal(r);

    LBT::Position left = r.left();
    LBT::Position right = r.right();
    *left = 45;
    *right = 60;

    tree.expandExternal(left);
    LBT::Position left_l = left.left();
    LBT::Position left_r = left.right();
    *left_l = 30;
    *left_r = 8;

    tree.expandExternal(right);
    LBT::Position right_l = right.left();
    LBT::Position right_r = right.right();
    *right_l = 20;
    *right_r = 6;

    std::cout << "Preorder: ";
    tree.preorderPrint();
    std::cout << std::endl;

    std::cout << "Inorder: ";
    tree.inorderPrint();
    std::cout << std::endl;

    std::cout << "Postorder: ";
    tree.postorderPrint();
    std::cout << std::endl;
    
    std::cout << "\n";

    std::cout << "Ascending order: ";
    tree.printAscending();
    std::cout << std::endl;

    std::cout << "Descending order: ";
    tree.printDescending();
    std::cout << std::endl;


    return EXIT_SUCCESS;
}
