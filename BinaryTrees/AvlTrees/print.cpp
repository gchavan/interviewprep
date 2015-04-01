#include "Headers.h"

void printNodes(vector<node*> nodes)
{
    for (auto& temp : nodes)
        cout << temp->data << " ";

    cout << endl;
}

void preorder(node* root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void printByLevel(node* root)
{
    if (!root)
        return;

    queue<node*> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        int currLevel = nodes.size();
        while (currLevel--)
        {
            node* curr = nodes.front();
            nodes.pop();

            cout << curr->data << " ";

            if (curr->left)
                nodes.push(curr->left);

            if (curr->right)
                nodes.push(curr->right);
        }
        cout << endl;
    }
}

void printRootToLeafPaths(node* root, vector<node*> nodes)
{
    if (!root)
        return;

    nodes.push_back(root);

    printRootToLeafPaths(root->left, nodes);

    // Leaf node
    if (!root->left && !root->right)
    {
        printNodes(nodes);
    }

    printRootToLeafPaths(root->right, nodes);

    nodes.pop_back();
}

void printNodeParents(node* root)
{
    if (!root)
        return;

    printNodeParents(root->left);
    printNodeParents(root->right);
    cout << "{" << root->data << " :: " << ((root->parent) ? root->parent->data : -1) << "} ";
}

void printPathToSum(node* root, int sum)
{
    bool found = false;
    int currSum = 0;
    vector<node*> path;

    if (!printPathToSum(root, sum, 0, path))
    {
        cout << "No path could be found matching the sum.";
    }
    cout << endl;
}

bool printPathToSum(node* root, int sum, int currSum, vector<node*>& path)
{
    if (sum == currSum)
    {
        for (auto& temp : path)
        {
            cout << temp->data << " -> ";
        }
        return true;
    }

    if (!root)
        return false;

    bool found = false;
    if ((currSum + root->data) <= sum)
    {
        path.push_back(root);
        found = printPathToSum(root->left, sum, currSum + root->data, path);
        path.pop_back();

        if (!found)
        {
            path.push_back(root);
            found = printPathToSum(root->right, sum, currSum + root->data, path);
            path.pop_back();
        }
    }

    return found;
}