#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//node 
struct AVL_Node
{
    int element;
    AVL_Node *left;
    AVL_Node *right;
    int height;

    AVL_Node(const int &ele, AVL_Node *lt = nullptr, AVL_Node *rt = nullptr, int h = 0)
        : element{ele}, left{lt}, right{rt}, height{h} {}
};

//AVL_Tree from textbook
class AVL_Tree
{
private:
    AVL_Node *root;
    static const int ALLOWED_IMBALANCE = 1;

    AVL_Node *insert(const int &x, AVL_Node *&t)
    {

//loop
        if (t == nullptr)
        {
            t = new AVL_Node(x, nullptr, nullptr);
        }
        // adjusted to account for duplicates
        else if (x <= t->element)
        {
            t->left = insert(x, t->left);
        }
        else
        {
            t->right = insert(x, t->right);
        }
        return balance(t);
    }
//min node
    AVL_Node *findMin(AVL_Node *t) const
    {
        return t == nullptr ? nullptr : t->left == nullptr ? t
                                                           : findMin(t->left);
    }

    AVL_Node *remove(const int &x, AVL_Node *&t)
    {
        if (t == nullptr)
        {
            return nullptr;
        }

        if (x < t->element)
        {
            t->left = remove(x, t->left);
        }
        else if (x > t->element)
        {
            t->right = remove(x, t->right);
        }
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            t->right = remove(t->element, t->right);
        }
        else
        {
            AVL_Node *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
        return balance(t);
    }
//balance
    AVL_Node *balance(AVL_Node *&t)
    {
        if (t == nullptr)
            return t;

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
        {
            if (height(t->left->left) >= height(t->left->right))
            {
                t = rotateWithLeftChild(t);
            }
            else
            {
                t = doubleWithLeftChild(t);
            }
        }
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
        {
            if (height(t->right->right) >= height(t->right->left))
            {
                t = rotateWithRightChild(t);
            }
            else
            {
                t = doubleWithRightChild(t);
            }
        }
        t->height = std::max(height(t->left), height(t->right)) + 1;
        return t;
    }
//height node
    int height(AVL_Node *t) const
    {
        return t == nullptr ? -1 : t->height;
    }
//rotateWithLeftChild
    AVL_Node *rotateWithLeftChild(AVL_Node *&k2)
    {
        AVL_Node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->left), k2->height) + 1;
        return k1;
    }
//rotateWithRightChild
    AVL_Node *rotateWithRightChild(AVL_Node *&k1)
    {
        AVL_Node *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = std::max(height(k1->left), height(k1->right)) + 1;
        k2->height = std::max(k1->height, height(k2->right)) + 1;
        return k2;
    }
//doubleWithLeftChild
    AVL_Node *doubleWithLeftChild(AVL_Node *&k3)
    {
        k3->left = rotateWithRightChild(k3->left);
        return rotateWithLeftChild(k3);
    }
//doubleWithRightChild
    AVL_Node *doubleWithRightChild(AVL_Node *&k1)
    {
        k1->right = rotateWithLeftChild(k1->right);
        return rotateWithRightChild(k1);
    }

//getNodeCount Function
    int getNodeCount(AVL_Node *t) const
    {
        return t == nullptr ? 0 : 1 + getNodeCount(t->left) + getNodeCount(t->right);
    }
//isEmpty helper function
    bool isEmpty(AVL_Node *t) const
    {
        return t == nullptr;
    }
//printInOrder function
    void printInOrder(AVL_Node *t) const
    {
        if (t == nullptr)
        {
            return;
        }
        printInOrder(t->left);
        std::cout << t->element << " ";
        printInOrder(t->right);
    }
//public function defined
public:
    AVL_Tree() : root(nullptr) {}

    void insert(const int &x)
    {
        root = insert(x, root);
    }

    void remove(const int &x)
    {
        root = remove(x, root);
    }

    // Helper function for tree
    int getNodeCount() const
    {
        return getNodeCount(root);
    }

    bool isEmpty() const
    {
        return isEmpty(root);
    }

    // Helper function for max
    int getMaximum() const
    {
        AVL_Node *temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->element;
    }

    // Helper function for min
    int getMinimum() const
    {
        AVL_Node *temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->element;
    }


    void printInOrder() const
    {
        printInOrder(root);
        std::cout << "\n";
    }
};


//hpp
void treeMedian(const std::vector<int> *instructions);