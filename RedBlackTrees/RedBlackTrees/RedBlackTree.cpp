#include "Headers.h"

void RBTree::Delete(int data)
{
    auto z = RBSearch(data);

    if (z)
    {
        cout << "Couldn't find " << data << " in the Red-Black Tree." << endl;
    }

    // RBDelete(z);
}

shared_ptr<RBTree::RBTreeNode> RBTree::RBSearch(int data)
{
    auto root = m_root;

    while (root && root->data != data)
    {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

void RBTree::Insert(int data)
{
    auto z = make_shared<RBTreeNode>(data);
    shared_ptr<RBTreeNode> y = nullptr;
    auto x = m_root;

    while (x)
    {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;

    if (!y)
        m_root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    InsertFixup(z);

    // Print();
    // cout << "------------------------------------------------------------------" << endl;
}

void RBTree::InsertFixup(shared_ptr<RBTreeNode> z)
{
   while (z && z->parent && z->parent->color == Color::Red)
    {
        if (z->parent->parent && z->parent == z->parent->parent->left)
        {
            auto uncle = z->parent->parent->right;
            if (uncle && uncle->color == Color::Red)
            {
                z->parent->color = Color::Black;
                uncle->color = Color::Black;
                z->parent->parent->color = Color::Red;
                z = z->parent->parent;
            }
            else if (z == z->parent->right)
            {
                z = z->parent;
                LeftRotate(z);
            }

            if (z && z->parent && z->parent->parent)
            {
                z->parent->color = Color::Black;
                z->parent->parent->color = Color::Red;
                RightRotate(z->parent->parent);
            }
        }
        else if (z->parent->parent && z->parent == z->parent->parent->right)
        {
            auto uncle = z->parent->parent->left;
            if (uncle && uncle->color == Color::Red)
            {
                z->parent->color = Color::Black;
                uncle->color = Color::Black;
                z->parent->parent->color = Color::Red;
                z = z->parent->parent;
            }
            else if (z == z->parent->left)
            {
                z = z->parent;
                RightRotate(z);
            }

            if (z && z->parent && z->parent->parent)
            {
                z->parent->color = Color::Black;
                z->parent->parent->color = Color::Red;
                LeftRotate(z->parent->parent);
            }
        }
    }
    m_root->color = Color::Black;
}

void RBTree::LeftRotate(shared_ptr<RBTreeNode> x)
{
    auto y = x->right;
    x->right = y->left;

    if (y->left)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    // If x's parent is null, 'x' was the root and we are updating the new root to 'y'
    if (!x->parent)
    {
        m_root = y;
    }
    // If 'x' is a left child, update 'x' parent's new left to be 'y'
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    // If 'x' is a right child, update 'x' parent's new right to be 'y'
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBTree::RightRotate(shared_ptr<RBTreeNode> x)
{
    auto y = x->left;
    x->left = y->right;

    if (y->right)
    {
        y->right->parent = x;
    }

    y->parent = x->parent;

    // If x's parent is null, 'x' was the root and we are updating the new root to 'y'
    if (!x->parent)
    {
        m_root = y;
    }
    // If 'x' is a left child, update 'x' parent's new left to be 'y'
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    // If 'x' is a right child, update 'x' parent's new right to be 'y'
    else
    {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

shared_ptr<RBTree::RBTreeNode> RBTree::TreeMinimum(shared_ptr<RBTreeNode> node)
{
    auto curr = node;
    if (curr)
    {
        while (curr->left)
        {
            curr = curr->left;
        }
    }

    return curr;
}

void RBTree::Transplant(shared_ptr<RBTreeNode> u, shared_ptr<RBTreeNode> v)
{
    if (u->parent == nullptr)
        m_root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

void RBTree::Delete(shared_ptr<RBTreeNode> z)
{
    auto x = z;
    auto y = z;
    auto yColor = y->color;

    if (z->left == nullptr)
    {
        x = z->right;
        Transplant(z, z->right);
    }
    else if (z->right == nullptr)
    {
        x = z->left;
        Transplant(z, z->left);
    }
    else
    {
        y = TreeMinimum(z->right);
        yColor = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (yColor == Color::Black)
    {
        DeleteFixup(x);
    }
}

void RBTree::DeleteFixup(shared_ptr<RBTreeNode> x)
{
}

void RBTree::Print()
{
    if (!m_root)
    {
        cout << "Red Black Tree is empty!!" << endl;
        return;
    }

    queue<shared_ptr<RBTreeNode>> nodes;
    nodes.push(m_root);

    while (!nodes.empty())
    {
        int currLevel = nodes.size();
        while (currLevel--)
        {
            auto curr = nodes.front();
            nodes.pop();

            cout << curr->data << "["
                << (curr->color == Color::Black ? 'b' : 'r')
                << (curr->parent ? "," : "");

            if (curr->parent)
                cout << curr->parent->data;

            cout << "] ";

            if (curr->left)
                nodes.push(curr->left);

            if (curr->right)
                nodes.push(curr->right);
        }
        cout << endl;
    }
}
