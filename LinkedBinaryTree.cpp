#include "LinkedBinaryTree.h"
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

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
    return Position(root_);
}


void LinkedBinaryTree::addRoot() {
    if (root_ != nullptr) {
        deleteSubtree(root_);
    }
    root_ = new Node();
    root_->par = nullptr;
    root_->left = nullptr;
    root_->right = nullptr;
    n = 1;
}

void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;
    if (v == nullptr) {
        return;
    }
    if (v->left == nullptr) {
        v->left = new Node();
        v->left->par = v;
    }
    if (v->right == nullptr) {
        v->right = new Node();
        v->right->par = v;
    }

    int added = 0;
    if (v->left != nullptr) {
        ++added;
    }
    if (v->right != nullptr) {
        ++added;
    }
    n += 2;
}

LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    if (w == nullptr) {
        return Position(nullptr);
    } 
    Node* v = w->par; 
    if (v == nullptr) {
        return Position(nullptr);
    } 
    Node* sibling;
    if (w == v->left) {
        v->right;
        sibling = v->right;
    }
    else {
        v->left;
        sibling = v->left;
    }

    if (v == root_) {
        
        root_ = sibling;
        if (sibling != nullptr) {
            sibling->par = nullptr;
        }
    }
    else {
        Node* gpar = v->par;
        if (gpar->left == v) gpar->left = sibling;
        else gpar->right = sibling;
        if (sibling != nullptr) sibling->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sibling);
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
