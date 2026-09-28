#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int CAPACITY = 20;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

bool insertEnd(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;
    list.data[list.size] = value;
    list.size++;
    return true;
}

bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;
    for (int i = list.size; i > 0; i--)
        list.data[i] = list.data[i - 1];
    list.data[0] = value;
    list.size++;
    return true;
}

bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)
        return false;
    for (int i = position; i < list.size - 1; i++)
        list.data[i] = list.data[i + 1];
    list.size--;
    return true;
}

void displayList(const ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
        cout << list.data[i] << " ";
    cout << endl;
}

int main()
{
    ArrayList list;
    int *ptr = list.data;
    int *minPtr = list.data;
    int *maxPtr = list.data;
    int *medianPtr = list.data;
    int *closestPtr = list.data;
    int sum = 0;
    int closestPosition;
    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    cout << fixed << setprecision(2);

    // Part A
    int vals[9] = {18, 7, 45, 11, 36, 40, 21, 13, 29};
    for (int i = 0; i < 9; i++)
        insertEnd(list, vals[i]);

    cout << "Initial ArrayList: ";
    displayList(list);

    // Part B
    while (ptr < list.data + list.size)
    {
        sum += *ptr;
        if (*ptr < *minPtr)
            minPtr = ptr;
        if (*ptr > *maxPtr)
            maxPtr = ptr;
        ptr++;
    }

    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;

    // Part C
    int temp[CAPACITY];
    for (int i = 0; i < list.size; i++)
        temp[i] = list.data[i];

    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    int medianValue = temp[list.size / 2];

    ptr = list.data;
    while (ptr < list.data + list.size)
    {
        if (*ptr == medianValue)
        {
            medianPtr = ptr;
            break;
        }
        ptr++;
    }

    cout << "Median Value: " << *medianPtr << endl;
    cout << "Sum: " << sum << endl;

    // Part D
    generalAverage = (double)sum / list.size;
    specialAverage = (*minPtr + *medianPtr + *maxPtr) / 3.0;

    ptr = list.data;
    closestPtr = list.data;
    double smallest = fabs(*ptr - specialAverage);

    while (ptr < list.data + list.size)
    {
        double dist = fabs(*ptr - specialAverage);
        if (dist < smallest)
        {
            smallest = dist;
            closestPtr = ptr;
        }
        ptr++;
    }

    closestPosition = closestPtr - list.data;

    cout << "General Average: " << generalAverage << endl;
    cout << "Special Average: " << specialAverage << endl;
    cout << "Closest Value: " << *closestPtr << endl;
    cout << "Position of Closest Value: " << closestPosition << endl;

    // Part E
    averageDifference = fabs(generalAverage - specialAverage);
    finalScore = fabs(*closestPtr - generalAverage) + fabs(*closestPtr - specialAverage) + averageDifference;

    cout << "Difference Between Averages: " << averageDifference << endl;
    cout << "Final Score: " << finalScore << endl;

    deleteAtPosition(list, closestPosition);
    cout << "ArrayList After Deletion: ";
    displayList(list);

    insertAtBeginning(list, (int)round(specialAverage));
    cout << "Final ArrayList After Insertion: ";
    displayList(list);

    return 0;
}
