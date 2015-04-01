#include "Headers.h"

int height(node* node)
{
    if (!node)
        return 0;

    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(node* node)
{
    if (!node)
        return 0;

    return height(node->left) - height(node->right);
}

node* rightRotate(node** root, node* z)
{
    node* y = z->left;

    z->left = y->right;
    y->right = z;
    y->parent = z->parent;
    z->parent = y;

    if (!y->parent)
    {
        *root = y;
    }
    else
    {
        y->parent->left = y;
    }

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* leftRotate(node** root, node* z)
{
    node* y = z->right;

    z->right = y->left;
    y->left = z;
    y->parent = z->parent;
    z->parent = y;

    if (!y->parent)
    {
        *root = y;
    }
    else
    {
        y->parent->right = y;
    }

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

void insert(node** root, int data)
{
    node* temp = new node(data);
    if (!(*root))
    {
        *root = temp;
        return;
    }

    node* prev = nullptr;
    node* curr = *root;
    while (curr)
    {
        prev = curr;
        if (data <= curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data <= prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    temp->parent = prev;

    node* n = temp->parent;
    while (n)
    {
        n->height = max(height(n->left), height(n->right)) + 1;

        int balance = getBalance(n);

        // Left-Left Case
        if (balance == 2 && n->left && data < n->left->data)
        {
            rightRotate(root, n);
        }
        // Left-Right Case
        if (balance == 2 && n->left && data > n->left->data)
        {
            n->left = leftRotate(root, n->left);
            rightRotate(root, n);
        }
        // Right-Right Case
        else if (balance == -2 && n->right && data > n->right->data)
        {
            leftRotate(root, n);
        }
        // Right-Left Case
        if (balance == -2 && n->right && data < n->right->data)
        {
            n->right = rightRotate(root, n->right);
            leftRotate(root, n);
        }

        n = n->parent;
    }
}

node* insert(node** root, node* n, int data)
{
    if (!n)
    {
        n = new node(data);
        if (!(*root))
        {
            *root = n;
        }
        return n;
    }

    if (data <= n->data)
        n->left = insert(root, n->left, data);
    else
        n->right = insert(root, n->right, data);

    if (n->left && n->left->data == data)
    {
        n->left->parent = n;
    }
    else if (n->right && n->right->data == data)
    {
        n->right->parent = n;
    }

    n->height = max(height(n->left), height(n->right)) + 1;

    int balance = getBalance(n);

    // Left-Left Case
    if (balance == 2 && data < n->left->data)
    {
        return rightRotate(root, n);
    }
    // Left-Right Case
    if (balance == 2 && data > n->left->data)
    {
        n->left = leftRotate(root, n->left);
        return rightRotate(root, n);
    }
    // Right-Right Case
    else if (balance == -2 && data > n->right->data)
    {
        return leftRotate(root, n);
    }
    // Right-Left Case
    if (balance == -2 && data < n->right->data)
    {
        n->right = rightRotate(root, n->right);
        return leftRotate(root, n);
    }

    return n;
}

node* find(node* root, int data)
{
    if (!root)
        return nullptr;

    node* curr = root;

    while (curr && curr->data != data)
    {
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return curr;
}

void deleteTree(node** root)
{
    if (!*root)
        return;

    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);

    delete *root;
}