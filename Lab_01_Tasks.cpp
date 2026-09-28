#include <iostream>
using namespace std;

const int CAPACITY = 50;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

// ============================================================
// LAB TASK 1 - START
// ============================================================
void sumOfSquares()
{
    int start, stop;
    cout << "Enter starting value: ";
    cin >> start;
    cout << "Enter stopping value: ";
    cin >> stop;

    long long sum = 0;
    int x = start;
    while (x <= stop)
    {
        sum += (long long)x * x;
        x++;
    }
    cout << "Sum of X^2 from " << start << " to " << stop << " = " << sum << endl;
}

// ============================================================
// LAB TASK 1 - END
// ============================================================


// ============================================================
// LAB TASK 2 - START
// ============================================================
int linearSearch(const ArrayList &list, int key);

bool insertEnd(ArrayList &list, int value)
{
    if (list.size == CAPACITY)
        return false;
    list.data[list.size] = value;
    list.size++;
    return true;
}

bool insertStart(ArrayList &list, int value)
{
    if (list.size == CAPACITY)
        return false;
    for (int i = list.size; i > 0; i--)
        list.data[i] = list.data[i - 1];
    list.data[0] = value;
    list.size++;
    return true;
}

bool insertAfterValue(ArrayList &list, int target, int value)
{
    if (list.size == CAPACITY)
        return false;
    int pos = linearSearch(list, target);
    if (pos == -1)
        return false;
    for (int i = list.size; i > pos + 1; i--)
        list.data[i] = list.data[i - 1];
    list.data[pos + 1] = value;
    list.size++;
    return true;
}

bool insertBeforeValue(ArrayList &list, int target, int value)
{
    if (list.size == CAPACITY)
        return false;
    int pos = linearSearch(list, target);
    if (pos == -1)
        return false;
    for (int i = list.size; i > pos; i--)
        list.data[i] = list.data[i - 1];
    list.data[pos] = value;
    list.size++;
    return true;
}

void displayList(const ArrayList &list)
{
    if (list.size == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    for (int i = 0; i < list.size; i++)
        cout << list.data[i] << " ";
    cout << endl;
}

bool deleteEnd(ArrayList &list)
{
    if (list.size == 0)
        return false;
    list.size--;
    return true;
}

bool deleteStart(ArrayList &list)
{
    if (list.size == 0)
        return false;
    for (int i = 0; i < list.size - 1; i++)
        list.data[i] = list.data[i + 1];
    list.size--;
    return true;
}

bool deleteValue(ArrayList &list, int value)
{
    int pos = linearSearch(list, value);
    if (pos == -1)
        return false;
    for (int i = pos; i < list.size - 1; i++)
        list.data[i] = list.data[i + 1];
    list.size--;
    return true;
}

// ============================================================
// LAB TASK 2 - END
// ============================================================


// ============================================================
// LAB TASK 3 - START
// ============================================================
int linearSearch(const ArrayList &list, int key)
{
    int i = 0;
    while (i < list.size)
    {
        if (list.data[i] == key)
            return i;
        i++;
    }
    return -1;
}
// ============================================================
// LAB TASK 3 - END
// ============================================================


int main()
{
    ArrayList list;
    int choice, value, target;

    do
    {
        cout << "\n1. Sum of X^2 (Lab Task 1)" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at start" << endl;
        cout << "4. Insert after specific value" << endl;
        cout << "5. Insert before specific value" << endl;
        cout << "6. Display list" << endl;
        cout << "7. Delete from end" << endl;
        cout << "8. Delete from start" << endl;
        cout << "9. Delete specific value" << endl;
        cout << "10. Linear search (Lab Task 3)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sumOfSquares();
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            if (insertEnd(list, value))
                cout << "Inserted" << endl;
            else
                cout << "List is full" << endl;
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            if (insertStart(list, value))
                cout << "Inserted" << endl;
            else
                cout << "List is full" << endl;
            break;
        case 4:
            cout << "Enter the existing value: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            if (insertAfterValue(list, target, value))
                cout << "Inserted" << endl;
            else
                cout << "Could not insert (value not found or list full)" << endl;
            break;
        case 5:
            cout << "Enter the existing value: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            if (insertBeforeValue(list, target, value))
                cout << "Inserted" << endl;
            else
                cout << "Could not insert (value not found or list full)" << endl;
            break;
        case 6:
            displayList(list);
            break;
        case 7:
            if (deleteEnd(list))
                cout << "Deleted" << endl;
            else
                cout << "List is empty" << endl;
            break;
        case 8:
            if (deleteStart(list))
                cout << "Deleted" << endl;
            else
                cout << "List is empty" << endl;
            break;
        case 9:
            cout << "Enter value to delete: ";
            cin >> value;
            if (deleteValue(list, value))
                cout << "Deleted" << endl;
            else
                cout << "Value not found" << endl;
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            target = linearSearch(list, value);
            if (target == -1)
                cout << "Value not found" << endl;
            else
                cout << "Value found at index " << target << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
