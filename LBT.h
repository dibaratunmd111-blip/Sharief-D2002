#include <iostream>

class LBT {
protected:
    struct Node {
        int elt;
        Node* par;
        Node* left;
        Node* right;

        Node() : elt(0), par(nullptr), left(nullptr), right(nullptr) {}
    };

public:
    class Position {
    private:
        Node* v; 
    public:
        friend class LBT;

        Position(Node* vv = nullptr) : v(vv) {}

        int& operator*() {
            return v->elt;
        }
        
        const int& operator*() const {
            return v->elt;
        }

    };

public:
    LBT();   
    ~LBT();  

    int size() const;
    bool empty() const;
    Position root() const;

    void addRoot();

    void expandExternal(const Position& p);

    Position removeAboveExternal(const Position& p);
    
    void preorderPrint(std::ostream& out) const;
    void inorderPrint(std::ostream& out) const;
    void postorderPrint(std::ostream& out) const;

protected:
    void preorderPrintNode(Node* v, std::ostream& out) const;
    void inorderPrintNode(Node* v, std::ostream& out) const;
    void postorderPrintNode(Node* v, std::ostream& out) const;

    void deleteSubtree(Node* v);

private:
    Node* root_; 
    int n;       
};

