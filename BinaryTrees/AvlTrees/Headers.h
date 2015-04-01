#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    node(int data)
        : data(data),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          height(1)
    {
    }

    int data;
    node* left;
    node* right;
    node* parent;
    int height;
};

// CRUD operations
node* find(node* root, int data);
// void remove(node** root, int data);
void insert(node** root, int data);
node* insert(node** root, node* n, int data);
// void deleteNode(node** root, node* nodeToDelete);
void deleteTree(node** root);

// Utility Methods
int height(node* node);
int max(int a, int b);
int getBalance(node* node);
node* rightRotate(node** root, node* z);
node* leftRotate(node** root, node* z);

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