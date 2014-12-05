#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Node
{
    Node(int x)
        :data(x),
        next(nullptr)
    {}

    int data;
    Node* next;
};

// #define DEBUG 0

void PrintList(Node* head);
void PrintListReverse(Node* head, Node* currNode);
void DeleteList(Node** head);
void InsertFront(Node** head, int data);
void InsertBack(Node** head, int data);

Node* MergeSortedLists(Node* head1, Node* head2);
Node* Add(Node* head1, Node* head2);
Node* AddReverse(Node* head1, Node* head2);
Node* Subtract(Node* head1, Node* head2);