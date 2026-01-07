
class LinkedBinaryTree 
{
protected:

    struct Node {
        int elt;
        Node* par;
        Node* left;
        Node* right;
        Node() {
            elt = 0;par = nullptr;left = nullptr;right = nullptr;
        }
    };

public:
    LinkedBinaryTree();  
    ~LinkedBinaryTree(); 

    int size() const;
    bool empty() const;
    Node* root() const;

    void preorderPrint() const;
    void inorderPrint() const;
    void postorderPrint() const;
    void insert(const int& value);
    void ascendingPrint()const;
    void descendingPrint() const;
    void  printSide(Node* v, int level) const;

protected:
    
    void printTreeSideways() const;
    void preorderPrintNode(Node* v) const;
    void inorderPrintNode(Node* v) const;
    void postorderPrintNode(Node* v) const;
    void deleteSubtree(Node* v);
    void insertRec(Node* current, const int& value);
    void ascendingPrintNode(Node* v)const;
    void descendingPrintNode(Node* v) const;

private:
    Node* root_;
    int n;       
};
