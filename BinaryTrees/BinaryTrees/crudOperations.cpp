#include "Headers.h"

void insert(node** root, int data)
{
    node* temp = new node(data);

    if (!(*root))
    {
        *root = temp;
    }
    else
    {
        node* parent = nullptr;
        node* curr = *root;
        while (curr)
        {
            parent = curr;
            if (data <= curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (data < parent->data)
            parent->left = temp;
        else
            parent->right = temp;

        temp->parent = parent;
    }
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

void transplant(node** root, node* oldNode, node* newNode)
{
    if (!oldNode->parent)
    {
        *root = newNode;
    }
    else if (oldNode == oldNode->parent->left)
    {
        oldNode->parent->left = newNode;
    }
    else
    {
        oldNode->parent->right = newNode;
    }

    if (newNode)
        newNode->parent = oldNode->parent;
}

void deleteNode(node** root, node* nodeToDelete)
{
    if (!nodeToDelete->left)
    {
        transplant(root, nodeToDelete, nodeToDelete->right);
    }
    else if (!nodeToDelete->right)
    {
        transplant(root, nodeToDelete, nodeToDelete->left);
    }
    else
    {
        node* min = minimum(nodeToDelete->right);
        if (min->parent != nodeToDelete)
        {
            transplant(root, min, min->right);
            min->right = nodeToDelete->right;
            min->right->parent = min;
        }
        transplant(root, nodeToDelete, min);
        min->left = nodeToDelete->left;
        min->left->parent = min;
    }
}

void deleteTree(node** root)
{
    if (!*root)
        return;

    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);

    delete *root;
}