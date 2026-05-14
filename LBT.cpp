#include "LBT.h"

LBT::LBT() : root_(nullptr), n(0) {}

LBT::~LBT() {
    if (root_ != nullptr) {
        deleteSubtree(root_);
        root_ = nullptr;
        n = 0;
    }
}

void LBT::deleteSubtree(Node* v) {
    if (v == nullptr) return;
    if (v->left != nullptr) deleteSubtree(v->left);
    if (v->right != nullptr) deleteSubtree(v->right);
    delete v;
}

int LBT::size() const { return n; }

bool LBT::empty() const { return n == 0; }

LBT::Position LBT::root() const { return Position(root_); }

void LBT::addRoot() {
    if (root_ != nullptr) {
        deleteSubtree(root_);
    }
    root_ = new Node();
    root_->par = nullptr;
    root_->left = nullptr;
    root_->right = nullptr;
    n = 1;
}

void LBT::expandExternal(const Position& p) {
    Node* v = p.v;
    if (v == nullptr) return; 
    if (v->left == nullptr) {
        v->left = new Node();
        v->left->par = v;
    }
    if (v->right == nullptr) {
        v->right = new Node();
        v->right->par = v;
    }
    int added = 0;
    if (v->left != nullptr) ++added; 
    if (v->right != nullptr) ++added;
    
    n += 2;
}

LBT::Position LBT::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    if (w == nullptr) return Position(nullptr); 
    Node* v = w->par; 
    if (v == nullptr) return Position(nullptr); 

    Node* sibling = (w == v->left) ? v->right : v->left;

    if (v == root_) {
        root_ = sibling;
        if (sibling != nullptr) sibling->par = nullptr;
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
void LBT::preorderPrint(std::ostream& out) const {
    if (root_ == nullptr) return;
    preorderPrintNode(root_, out);
}

void LBT::inorderPrint(std::ostream& out) const {
    if (root_ == nullptr) return;
    inorderPrintNode(root_, out);
}

void LBT::postorderPrint(std::ostream& out) const {
    if (root_ == nullptr) return;
    postorderPrintNode(root_, out);
}

void LBT::preorderPrintNode(Node* v, std::ostream& out) const {
    if (v == nullptr) return;
    out << v->elt << ' ';
    if (v->left != nullptr) preorderPrintNode(v->left, out);
    if (v->right != nullptr) preorderPrintNode(v->right, out);
}

void LBT::inorderPrintNode(Node* v, std::ostream& out) const {
    if (v == nullptr) return;
    if (v->left != nullptr) inorderPrintNode(v->left, out);
    out << v->elt << ' ';
    if (v->right != nullptr) inorderPrintNode(v->right, out);
}

void LBT::postorderPrintNode(Node* v, std::ostream& out) const {
    if (v == nullptr) return;
    if (v->left != nullptr) postorderPrintNode(v->left, out);
    if (v->right != nullptr) postorderPrintNode(v->right, out);
    out << v->elt << ' ';
}
