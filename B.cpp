#include <iostream>
#include "LinkedBinaryTree.h"

int main() {
    LinkedBinaryTree tree;
tree.addRoot();
    LinkedBinaryTree::Position r = tree.root();
    *r = 50; 
    tree.expandExternal(r);

    LinkedBinaryTree::Position left = r.left();
    LinkedBinaryTree::Position right = r.right();
    *left = 45;
    *right = 60;

    tree.expandExternal(left);
    LinkedBinaryTree::Position left_l = left.left();
    LinkedBinaryTree::Position left_r = left.right();
    *left_l = 30;
    *left_r = 65;

    tree.expandExternal(right);
    LinkedBinaryTree::Position right_l = right.left();
    LinkedBinaryTree::Position right_r = right.right();
    *right_l = 20;
    *right_r = 70;
    
    std::cout << "Preorder: ";
    tree.preorderPrint();
    std::cout << std::endl;

    std::cout << "Inorder: ";
    tree.inorderPrint();
    std::cout << std::endl;

    std::cout << "Postorder: ";
    tree.postorderPrint();
    std::cout << std::endl;


    return EXIT_SUCCESS;
}
