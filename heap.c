#include <stdio.h>
#define MAX 100

int minHeap[MAX];
int minSize = 0;

void minHeapifyUp(int index)
{
    int parent, temp;

    while (index > 0)
    {
        parent = (index - 1) / 2;

        if (minHeap[parent] <= minHeap[index])
            break;

        temp = minHeap[parent];
        minHeap[parent] = minHeap[index];
        minHeap[index] = temp;

        index = parent;
    }
}

void minHeapifyDown(int index)
{
    int left, right, smallest, temp;

    while (1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if (right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        temp = minHeap[index];
        minHeap[index] = minHeap[smallest];
        minHeap[smallest] = temp;

        index = smallest;
    }
}

void minInsert(int value)
{
    if (minSize == MAX)
    {
        printf("Min Heap is full!\n");
        return;
    }

    minHeap[minSize] = value;
    minSize++;

    minHeapifyUp(minSize - 1);

    printf("%d inserted into Min Heap.\n", value);
}

void minDelete()
{
    int deleted;

    if (minSize == 0)
    {
        printf("Min Heap is empty!\n");
        return;
    }

    deleted = minHeap[0];

    minHeap[0] = minHeap[minSize - 1];
    minSize--;

    minHeapifyDown(0);

    printf("%d deleted from Min Heap.\n", deleted);
}

void displayMinHeap()
{
    int i;

    if (minSize == 0)
    {
        printf("Min Heap is empty!\n");
        return;
    }

    printf("Min Heap: ");

    for (i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);

    printf("\n");
}
int maxHeap[MAX];
int maxSize = 0;

void maxHeapifyUp(int index)
{
    int parent, temp;

    while (index > 0)
    {
        parent = (index - 1) / 2;

        if (maxHeap[parent] >= maxHeap[index])
            break;

        temp = maxHeap[parent];
        maxHeap[parent] = maxHeap[index];
        maxHeap[index] = temp;

        index = parent;
    }
}

void maxHeapifyDown(int index)
{
    int left, right, largest, temp;

    while (1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;

        if (left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == index)
            break;

        temp = maxHeap[index];
        maxHeap[index] = maxHeap[largest];
        maxHeap[largest] = temp;

        index = largest;
    }
}

void maxInsert(int value)
{
    if (maxSize == MAX)
    {
        printf("Max Heap is full!\n");
        return;
    }

    maxHeap[maxSize] = value;
    maxSize++;

    maxHeapifyUp(maxSize - 1);

    printf("%d inserted into Max Heap.\n", value);
}

void maxDelete()
{
    int deleted;

    if (maxSize == 0)
    {
        printf("Max Heap is empty!\n");
        return;
    }

    deleted = maxHeap[0];

    maxHeap[0] = maxHeap[maxSize - 1];
    maxSize--;

    maxHeapifyDown(0);

    printf("%d deleted from Max Heap.\n", deleted);
}

void displayMaxHeap()
{
    int i;

    if (maxSize == 0)
    {
        printf("Max Heap is empty!\n");
        return;
    }

    printf("Max Heap: ");

    for (i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);

    printf("\n");
}

void heapify(int arr[], int n, int i)
{
    int largest;
    int left;
    int right;
    int temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort()
{
    int arr[MAX];
    int n;
    int i;
    int temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size!\n");
        return;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Heap Sort */

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    printf("Sorted Array: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void buildMinHeap()
{
    int n, i, value;

    minSize = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size!\n");
        return;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        minInsert(value);
    }

    printf("Min Heap created successfully.\n");
}

void buildMaxHeap()
{
    int n, i, value;

    maxSize = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size!\n");
        return;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        maxInsert(value);
    }

    printf("Max Heap created successfully.\n");
}

int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n========== HEAP OPERATIONS ==========\n");
        printf("1. Build Min Heap\n");
        printf("2. Insert into Min Heap\n");
        printf("3. Delete Minimum\n");
        printf("4. Display Min Heap\n");
        printf("\n");
        printf("5. Build Max Heap\n");
        printf("6. Insert into Max Heap\n");
        printf("7. Delete Maximum\n");
        printf("8. Display Max Heap\n");
        printf("\n");
        printf("9. Heap Sort\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                buildMinHeap();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                minInsert(value);
                break;

            case 3:
                minDelete();
                break;

            case 4:
                displayMinHeap();
                break;

            case 5:
                buildMaxHeap();
                break;

            case 6:
                printf("Enter value: ");
                scanf("%d", &value);
                maxInsert(value);
                break;

            case 7:
                maxDelete();
                break;

            case 8:
                displayMaxHeap();
                break;

            case 9:
                heapSort();
                break;

            case 10:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
