#include "lbt.h"
#include <iostream>

LinkedBinaryTree::LinkedBinaryTree() {
    root_ = nullptr;
    n = 0;
}

LinkedBinaryTree::~LinkedBinaryTree() {
    if (root_ != nullptr) {
        deleteSubtree(root_);
        root_ = nullptr;
        n = 0;
    }
}

void LinkedBinaryTree::deleteSubtree(Node* v) {
    if (v == nullptr) {
        return;
    }

    if (v->left != nullptr) {
        deleteSubtree(v->left);
    }

    if (v->right != nullptr) {
        deleteSubtree(v->right);
    }

    delete v;
}

int LinkedBinaryTree::size() const {
    return n;
}

bool LinkedBinaryTree::empty() const {
    return n == 0;
}

LinkedBinaryTree::Node* LinkedBinaryTree::root() const {
    return root_;
}

void LinkedBinaryTree::preorderPrint() const {
    if (root_ == nullptr) return;
    preorderPrintNode(root_);
}

void LinkedBinaryTree::inorderPrint() const {
    if (root_ == nullptr) return;
    inorderPrintNode(root_);
}

void LinkedBinaryTree::postorderPrint() const {
    if (root_ == nullptr) return;
    postorderPrintNode(root_);
}

void LinkedBinaryTree::preorderPrintNode(Node* v) const {
    if (v == nullptr) return;
    std::cout << v->elt << " ";
    preorderPrintNode(v->left);
    preorderPrintNode(v->right);
}

void LinkedBinaryTree::inorderPrintNode(Node* v) const {
    if (v == nullptr) return;
    inorderPrintNode(v->left);
    std::cout << v->elt << " ";
    inorderPrintNode(v->right);
}

void LinkedBinaryTree::postorderPrintNode(Node* v) const {
    if (v == nullptr) return;
    postorderPrintNode(v->left);
    postorderPrintNode(v->right);
    std::cout << v->elt << " ";
}

void LinkedBinaryTree::insert(const int& value) {
    // Case 1: empty tree
    if (root_ == nullptr) {
        root_ = new Node();
        root_->elt = value;
        n = 1;
        return;
    }
    // Case 2: non-empty tree
    insertRec(root_, value);
}

void LinkedBinaryTree::insertRec(Node* current, const int& value) {
    // Ignore duplicate values
    if (value == current->elt) {
        std::cout << "You  value (" << value << ") because it has duplicate value in the tree!" << std::endl;
        return;
    }
    // Go to left subtree
    if (value < current->elt) {
        if (current->left == nullptr) {
            Node* newNode = new Node();
            newNode->elt = value;
            newNode->par = current;
            current->left = newNode;
            n++;
        }                                                   
        else {
            insertRec(current->left, value);
        }
    }
    // Go to right subtree
    else {
        if (current->right == nullptr) {
            Node* newNode = new Node();
            newNode->elt = value;
            newNode->par = current;
            current->right = newNode;
            n++;
        }
        else {
            insertRec(current->right, value);
        }
    }
}

void LinkedBinaryTree::ascendingPrint() const {
    if (root_ == nullptr) return;
    ascendingPrintNode(root_);
}
    // left -> root -> right    

void LinkedBinaryTree::ascendingPrintNode(Node* v) const {
    if (v == nullptr) return;
    ascendingPrintNode(v->left);
    std::cout << v->elt << " ";
    ascendingPrintNode(v->right);
}

void LinkedBinaryTree::descendingPrint() const {
    if (root_ == nullptr) return;
    descendingPrintNode(root_);
}

void LinkedBinaryTree::descendingPrintNode(Node* v) const {
    if (v == nullptr) return;

    // Right -> Root -> Left
    descendingPrintNode(v->right);
    std::cout << v->elt << " ";
    descendingPrintNode(v->left);
}

