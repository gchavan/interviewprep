#include "Headers.h"

void PrintList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty..." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->data << " => ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void PrintListReverse(Node* head, Node* currNode)
{
    if (currNode == nullptr)
    {
        return;
    }

    PrintListReverse(head, currNode->next);

    cout << currNode->data;

    if (currNode != head)
    {
        cout << " <= ";
    }
}

void InsertFront(Node** head, int data)
{
    Node* newNode = new Node(data);

    newNode->next = *head;

    *head = newNode;
}

void InsertBack(Node** head, int data)
{
    Node* curr = *head;
    Node* prev = nullptr;
    while (curr != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }

    Node* newNode = new Node(data);
    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        prev->next = newNode;
    }
}

void DeleteList(Node** head)
{
    Node* temp = *head;
    Node* next = nullptr;

    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }

    *head = nullptr;
}

void ReverseList(Node** head)
{
    if (!(*head))
        return;

    Node* prev = nullptr;
    Node* curr = *head;
    Node* next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

Node* MergeSortedLists(Node* head1, Node* head2)
{
    if (!head1)
    {
        return head2;
    }
    else if (!head2)
    {
        return head1;
    }

    Node* currNodeFirst = head1;
    Node* currNodeSecond = head2;
    Node* newHead = nullptr;
    Node* currNode = nullptr;

    if (currNodeFirst->data <= currNodeSecond->data)
    {
        newHead = currNodeFirst;
        currNodeFirst = currNodeFirst->next;
    }
    else
    {
        newHead = currNodeSecond;
        currNodeSecond = currNodeSecond->next;
    }

    currNode = newHead;

    while (currNodeFirst && currNodeSecond)
    {
        if (currNodeFirst->data <= currNodeSecond->data)
        {
            currNode->next = currNodeFirst;
            currNode = currNodeFirst;
            currNodeFirst = currNodeFirst->next;
        }
        else
        {
            currNode->next = currNodeSecond;
            currNode = currNodeSecond;
            currNodeSecond = currNodeSecond->next;
        }
    }

    while (currNodeFirst)
    {
        currNode->next = currNodeFirst;
        currNode = currNodeFirst;
        currNodeFirst = currNodeFirst->next;
    }

    while (currNodeSecond)
    {
        currNode->next = currNodeSecond;
        currNode = currNodeSecond;
        currNodeSecond = currNodeSecond->next;
    }

    return newHead;
}