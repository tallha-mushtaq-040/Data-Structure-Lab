#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

struct LinkedList
{
    Node *first = NULL;
    Node *last = NULL;
};

void insertEnd(LinkedList &list, int value)
{
    Node *p = new Node;
    p->data = value;
    if (list.first == NULL)
        list.first = list.last = p;
    else
    {
        list.last->next = p;
        list.last = p;
    }
}

void displayList(const LinkedList &list)
{
    Node *p = list.first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ============================================================
// LAB TASK 1 - START
// ============================================================
void displayReverseLoop(const LinkedList &list)
{
    int count = 0;
    Node *p = list.first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    for (int i = count; i >= 1; i--)
    {
        p = list.first;
        for (int j = 1; j < i; j++)
            p = p->next;
        cout << p->data << " ";
    }
    cout << endl;
}

void printReverse(Node *p)
{
    if (p == NULL)
        return;
    printReverse(p->next);
    cout << p->data << " ";
}

void displayReverseRecursive(const LinkedList &list)
{
    printReverse(list.first);
    cout << endl;
}
// ============================================================
// LAB TASK 1 - END
// ============================================================


// ============================================================
// LAB TASK 2 - START
// ============================================================
LinkedList mergeLists(const LinkedList &list1, const LinkedList &list2)
{
    LinkedList merged;
    Node *p = list1.first;
    while (p != NULL)
    {
        insertEnd(merged, p->data);
        p = p->next;
    }
    p = list2.first;
    while (p != NULL)
    {
        insertEnd(merged, p->data);
        p = p->next;
    }
    return merged;
}
// ============================================================
// LAB TASK 2 - END
// ============================================================


// ============================================================
// LAB TASK 3 - START
// ============================================================
int findOccurrences(const LinkedList &list, int key)
{
    int count = 0;
    int position = 1;
    Node *p = list.first;
    while (p != NULL)
    {
        if (p->data == key)
        {
            count++;
            cout << key << " found at position " << position << endl;
        }
        p = p->next;
        position++;
    }
    if (count == 0)
        cout << key << " not found in the list" << endl;
    else
        cout << key << " occurs " << count << " time(s)" << endl;
    return count;
}
// ============================================================
// LAB TASK 3 - END
// ============================================================


int main()
{
    LinkedList list1, list2;
    insertEnd(list1, 10);
    insertEnd(list1, 20);
    insertEnd(list1, 30);
    insertEnd(list2, 40);
    insertEnd(list2, 10);
    insertEnd(list2, 50);

    cout << "List 1: ";
    displayList(list1);

    // Task 1
    cout << "Reverse (loop): ";
    displayReverseLoop(list1);
    cout << "Reverse (recursion): ";
    displayReverseRecursive(list1);

    // Task 2
    LinkedList merged = mergeLists(list1, list2);
    cout << "Merged list: ";
    displayList(merged);

    // Task 3
    findOccurrences(merged, 10);

    return 0;
}
