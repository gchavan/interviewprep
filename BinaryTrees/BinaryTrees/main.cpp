#include "Headers.h"

int main()
{
    int arr[] = { 8, 4, 2, 3, 1, 6, 5, 7, 12, 9, 14, 11, 13, 15 };
    // int arr[] = { 32, 24, 41, 21, 28, 35, 47, 14, 25, 31, 38 };
    int size = sizeof(arr) / sizeof(arr[0]);

    node* root = nullptr;
    for (auto i: arr)
        insert(&root, i);

    cout << "Print tree level wise..." << endl;
    printByLevel(root);

    cout << endl << "**********************Tree traversals**********************" << endl;
    cout << "preorder  :";
    preorder(root);
    cout << endl << "inorder   :";
    inorder(root);
    cout << endl << "postorder :";
    postorder(root);
    cout << endl;

    cout << endl << "************************tree algos*************************" << endl;

    //cout << "Testing if tree is a bst..." << endl;
    //// Update node with 5 to 3 so that it fails the BST test
    //int data = 5;
    //node* found = find(root, data);
    //cout << endl << "searching for " << data << " : " << (found ? "Found" : "NOT Found") << endl;
    //found->data = 3;
    //cout << "is tree bst :" << (isBST(root, INT_MIN, INT_MAX) ? "true" : "false") << endl;

    int minRange = 4;
    int maxRange = 12;
    vector<node*> ranges;
    findRange(root, minRange, maxRange, ranges);
    cout << endl << "print nodes between (" << minRange << " & " << maxRange << ")" << endl;
    for (auto& temp : ranges)
        cout << temp->data << " ";
    cout << endl;

    cout << endl << "Print root to leaf paths..." << endl;
    vector<node*> nodes;
    printRootToLeafPaths(root, nodes);

    cout << endl << "Print min and max (binary search tree)..." << endl;
    node* min = minimum(root);
    node* max = maximum(root);
    cout << "Min: " << min->data << ". Max: " << max->data;
    cout << endl;

    // test node deletion
    // node* nodeToDelete = find(root, 8);
    // deleteNode(&root, nodeToDelete);
    // cout << "Print tree level wise..." << endl;
    // printByLevel(root);

    cout << endl << "Print node parents..." << endl;
    printNodeParents(root);
    cout << endl;

    cout << endl << "Print successors..." << endl;
    printSuccessors(root);
    cout << endl;

    cout << endl << "Print predecessors..." << endl;
    printPredecessors(root);
    cout << endl;

    cout << endl << "Print path to sum..." << endl;
    printPathToSum(root, 42);
    cout << endl;

    node* temp = nullptr;
    closestNode(root, 10, &temp);
    cout << "the closest node to 10 is: " << temp->data << endl;

    findTwoNodesWithSum(root, 66);
    findTwoNodesWithSum(root, 64);
    findTwoNodesWithSum(root, 57);
    findTwoNodesWithSum(root, 72);
    findTwoNodesWithSum(root, 70);
    findTwoNodesWithSum(root, 79);

    deleteTree(&root);

    cout << endl;
    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}