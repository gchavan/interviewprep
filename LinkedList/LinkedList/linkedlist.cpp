#include "Headers.h"

void DoBasicOperations();
void MergeSortedLists();

int main()
{
    DoBasicOperations();

    // MergeSortedLists();

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void DoBasicOperations()
{
    Node* head = nullptr;

    PrintList(head);

    InsertBack(&head, 4);
    InsertBack(&head, 5);
    InsertBack(&head, 6);
    PrintList(head);

    InsertFront(&head, 3);
    InsertFront(&head, 2);
    InsertFront(&head, 1);
    PrintList(head);

    cout << endl << "Print list in reverse order..." << endl;
    PrintListReverse(head, head);
    cout << endl;

    cout << endl << "Reversing list..." << endl;
    ReverseList(&head);

    cout << endl << "Print list after reversing..." << endl;
    PrintList(head);

    cout << endl << "Deleting list..." << endl;
    DeleteList(&head);

    PrintList(head);
}

void MergeSortedLists()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    InsertBack(&head1, 1);
    InsertBack(&head1, 3);
    InsertBack(&head1, 5);

    InsertBack(&head2, 2);
    InsertBack(&head2, 4);
    InsertBack(&head2, 6);

    auto mergedList = MergeSortedLists(head1, head2);

    PrintList(mergedList);

    DeleteList(&mergedList);
}
