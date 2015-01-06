#include "Headers.h"

void findRange(node* root, int min, int max, vector<node*>& ranges)
{
    if (!root || root->data < min || root->data > max)
        return;

    findRange(root->left, min, max, ranges);
    ranges.push_back(root);
    findRange(root->right, min, max, ranges);
}

bool isBST(node* root, int min, int max)
{
    if (!root)
        return true;

    if (root->data < min || root->data > max)
        return false;

    bool isLeftBst = isBST(root->left, min, root->data);
    bool isRightBst = isBST(root->right, root->data, max);

    return isLeftBst && isRightBst;
}

node* minimum(node* root)
{
    if (!root)
        return nullptr;

    node* temp = root;
    while (temp->left)
        temp = temp->left;

    return temp;
}

node* maximum(node* root)
{
    if (!root)
        return nullptr;

    node* temp = root;
    while (temp->right)
        temp = temp->right;

    return temp;
}

node* successor(node* root)
{
    if (!root)
        return nullptr;

    if (root->right)
    {
        return minimum(root->right);
    }

    node* parent = root->parent;
    while (parent && parent->right == root)
    {
        root = parent;
        parent = parent->parent;
    }

    return parent;
}

node* predecessor(node* root)
{
    if (!root)
        return nullptr;

    if (root->left)
    {
        return maximum(root->left);
    }

    node* parent = root->parent;
    while (parent && parent->left == root)
    {
        root = parent;
        parent = parent->parent;
    }

    return parent;
}

void closestNode(node* root, int data, node** closest)
{
    if (!root)
        return;

    int diff = abs(root->data - data);

    if (!*closest || (*closest && diff < (abs(data-(*closest)->data))))
    {
        *closest = root;
    }

    if (root->data > data)
    {
        closestNode(root->left, data, closest);
    }
    else if (root->data < data)
    {
        closestNode(root->right, data, closest);
    }
}

void findTwoNodesWithSum(node* root, int sum)
{
    if (!root)
        return;

    stack<node*> left;
    stack<node*> right;
    
    pushLeftNodes(root, left);
    pushRightNodes(root, right);
    bool sumFound = false;
    while (!left.empty() && !right.empty())
    {
        node* min = left.top();
        node* max = right.top();
        int currSum = min->data + max->data;

        if (currSum == sum && min != max)
        {
            cout << "Sum found!! " << min->data << " + " << max->data << " = " << sum << endl;
            sumFound = true;
            break;
        }
        else if (currSum < sum)
        {
            left.pop();
            if (min->right)
            {
                pushLeftNodes(min->right, left);
            }
        }
        else // if(currSum > sum)
        {
            right.pop();
            if (max->left)
            {
                pushRightNodes(max->left, right);
            }
        }
    }

    if (!sumFound)
    {
        cout << "No two nodes found with sum " << sum << endl;
    }
}

void pushLeftNodes(node* root, stack<node*>& left)
{
    if (!root)
        return;

    node* temp = root;
    while (temp)
    {
        left.push(temp);
        temp = temp->left;
    }
}

void pushRightNodes(node* root, stack<node*>& right)
{
    if (!root)
        return;

    node* temp = root;
    while (temp)
    {
        right.push(temp);
        temp = temp->right;
    }
}
