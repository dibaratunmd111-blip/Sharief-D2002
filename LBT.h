
class LBT 
{
protected:

    struct Node {
        int elt;
        Node* par;
        Node* left;
        Node* right;
        Node() {
            elt = 0; par = nullptr; left = nullptr; right = nullptr;
        }
    };

public:
    class Position {
    private:
        Node* v;
    public:

        friend class LBT;
        Position() {
            v = nullptr;
        }

        Position(Node* vv) {
            v = vv;
        }

        int& operator*() {
            return v->elt;
        }
        const int& operator*() const {
            return v->elt;
        }

        Position left() const {
            if (v == nullptr) {
                return Position(nullptr);
            }
            return Position(v->left);
        }

        Position right() const {
            if (v == nullptr) {
                return Position(nullptr);
            }
            return Position(v->right);
        }

        Position parent() const {
            if (v == nullptr) {
                return Position(nullptr);
            }
            return Position(v->par);
        }

        bool isNull() const {
            return v == nullptr;
        }

        bool isRoot() const {
            return (v != nullptr && v->par == nullptr);
        }

        bool isExternal() const {
            return (v != nullptr && v->left == nullptr && v->right == nullptr);
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

    void preorderPrint() const;
    void inorderPrint() const;
    void postorderPrint() const;
    void printAscending() const;
    void printDescending() const;

    void preorderAscending() const;
    void preorderDescending() const;

    void inorderAscending() const;
    void inorderDescending() const;

    void postorderAscending() const;
    void postorderDescending() const;


protected:

    void preorderPrintNode(Node* v) const;
    void inorderPrintNode(Node* v) const;
    void postorderPrintNode(Node* v) const;

    void printAscendingNode(Node* v) const;
    void printDescendingNode(Node* v) const;

    void deleteSubtree(Node* v);

private:
    Node* root_;
    int n;
};

