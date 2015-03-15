#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    node(int data)
        :data(data), left(nullptr), right(nullptr), parent(nullptr)
    {
    }

    int data;
    node* left;
    node* right;
    node* parent;
};

// CRUD operations
node* find(node* root, int data);
void remove(node** root, int data);
void transplant(node** root, node* oldNode, node* newNode);
void insert(node** root, int data);
void deleteNode(node** root, node* nodeToDelete);
void deleteTree(node** root);

// printing
void printNodes(vector<node*> nodes);
void printByLevel(node* root);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
void printRootToLeafPaths(node* root, vector<node*> nodes);
void printNodeParents(node* root);
void printSuccessors(node* root);
void printPredecessors(node* root);
void printPathToSum(node* root, int sum);
bool printPathToSum(node* root, int sum, int currSum, vector<node*>& path);

// algos
void findRange(node* root, int min, int max, vector<node*>& ranges);
bool isBST(node* root, int min, int max);
node* minimum(node* root);
node* maximum(node* root);
node* successor(node* node);
node* predecessor(node* node);
void closestNode(node* root, int data, node** closest);
void pushLeftNodes(node* root, stack<node*>& left);
void pushRightNodes(node* root, stack<node*>& right);
void findTwoNodesWithSum(node* root, int sum);
