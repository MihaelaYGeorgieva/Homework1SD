#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i) //n is size of arr, i is index of root
{
    int largest = i; // Initialize largest index as root
    int leftChild = 2*i + 1; /* If the parent node is stored at index I,
                        the left child can be calculated by 2 * I + 1 and
                        right child by 2 * I + 2 (assuming the indexing starts at 0). */
    int rightChild = 2*i + 2;

    // if left child is larger than root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // if right child is larger than largest
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build heap
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    // one by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



int partition (int arr[], int first, int last)
{
    int pivot = arr[last];    // pivot is last elem
    int i = (first - 1);  // index of smaller element

    for (int j = first; j <= last- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return (i + 1);
}


void quickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        // pi is partitioning index
        int pi = partition(arr, first, last);

        //  sorts elements before
        // partition and after partition
        quickSort(arr, first, pi - 1);
        quickSort(arr, pi + 1, last);
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[] = {121, 10, 17, 57, 36, 17};
    int arr2[] = {10, 867, 0, 36, 1};
    int arr3[] = {105, 867, 0, 36, 1, 2, 35};

    int n = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    heapSort(arr, n);
     cout << "Sorted array : \n";
     printArray(arr, n);

       heapSort(arr2, n2);
     cout << "Sorted array2 : \n";
     printArray(arr2, n2);

       heapSort(arr3, n3);
     cout << "Sorted array3 : \n";
     printArray(arr3, n3);

   quickSort(arr, 0, n-1);
    cout << "Sorted array : \n";
     printArray(arr, n);

      quickSort(arr2, 0, n2-1);
    cout << "Sorted array : \n";
     printArray(arr2, n2);

      quickSort(arr3, 0, n3-1);
    cout << "Sorted array : \n";
     printArray(arr3, n3);
    return 0;
}
