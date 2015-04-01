#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

class RBTree
{
public:
    void Insert(int data);
    void Delete(int data);
    void Print();

private:
    enum Color
    {
        Black,
        Red
    };

    struct RBTreeNode
    {
        RBTreeNode(int data)
        {
            this->data = data;
            color = Color::Red;
            left = right = parent = nullptr;
        }

        int data;
        Color color;
        shared_ptr<RBTreeNode> parent;
        shared_ptr<RBTreeNode> left;
        shared_ptr<RBTreeNode> right;
    };

    void LeftRotate(shared_ptr<RBTreeNode> x);
    void RightRotate(shared_ptr<RBTreeNode> x);
    void InsertFixup(shared_ptr<RBTreeNode> z);

    shared_ptr<RBTreeNode> RBSearch(int data);

    shared_ptr<RBTreeNode> TreeMinimum(shared_ptr<RBTreeNode> node);
    void Transplant(shared_ptr<RBTreeNode> u, shared_ptr<RBTreeNode> v);
    void Delete(shared_ptr<RBTreeNode> z);
    void DeleteFixup(shared_ptr<RBTreeNode> z);

    shared_ptr<RBTreeNode> m_root;
};