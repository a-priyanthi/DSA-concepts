#include <stdio.h>

#define MAX 100

void display(int arr[], int n);
void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void linearSearch(int arr[], int n);
void binarySearch(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void reverse(int arr[], int n);
void findMaxMin(int arr[], int n);
void findSumAverage(int arr[], int n);

int main() {
    int arr[MAX], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n========== ARRAY OPERATIONS ==========\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Bubble Sort\n");
        printf("7. Selection Sort\n");
        printf("8. Insertion Sort\n");
        printf("9. Reverse Array\n");
        printf("10. Find Maximum and Minimum\n");
        printf("11. Find Sum and Average\n");
        printf("0. Exit\n");
        printf("======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                display(arr, n);
                break;

            case 2:
                insert(arr, &n);
                break;

            case 3:
                deleteElement(arr, &n);
                break;

            case 4:
                linearSearch(arr, n);
                break;

            case 5:
                binarySearch(arr, n);
                break;

            case 6:
                bubbleSort(arr, n);
                printf("Array sorted using Bubble Sort.\n");
                display(arr, n);
                break;

            case 7:
                selectionSort(arr, n);
                printf("Array sorted using Selection Sort.\n");
                display(arr, n);
                break;

            case 8:
                insertionSort(arr, n);
                printf("Array sorted using Insertion Sort.\n");
                display(arr, n);
                break;

            case 9:
                reverse(arr, n);
                printf("Array reversed successfully.\n");
                display(arr, n);
                break;

            case 10:
                findMaxMin(arr, n);
                break;

            case 11:
                findSumAverage(arr, n);
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}


/* Display Array */
void display(int arr[], int n) {

    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


/* Insert Element */
void insert(int arr[], int *n) {

    int position, value;

    if (*n >= MAX) {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position to insert: ");
    scanf("%d", &position);

    printf("Enter value: ");
    scanf("%d", &value);

    if (position < 1 || position > *n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i >= position; i--)
        arr[i] = arr[i - 1];

    arr[position - 1] = value;

    (*n)++;

    printf("Element inserted successfully.\n");
}


/* Delete Element */
void deleteElement(int arr[], int *n) {

    int position;

    if (*n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    printf("Element deleted successfully.\n");
}


/* Linear Search */
void linearSearch(int arr[], int n) {

    int key, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {

        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found.\n");
}


/* Binary Search */
void binarySearch(int arr[], int n) {

    int key;
    int low = 0;
    int high = n - 1;
    int found = 0;

    printf("Binary Search requires a SORTED array.\n");

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found)
        printf("Element not found.\n");
}


/* Bubble Sort */
void bubbleSort(int arr[], int n) {

    int temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


/* Selection Sort */
void selectionSort(int arr[], int n) {

    int min, temp;

    for (int i = 0; i < n - 1; i++) {

        min = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


/* Insertion Sort */
void insertionSort(int arr[], int n) {

    int key, j;

    for (int i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


/* Reverse Array */
void reverse(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    int temp;

    while (start < end) {

        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}


/* Maximum and Minimum */
void findMaxMin(int arr[], int n) {

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
}


/* Sum and Average */
void findSumAverage(int arr[], int n) {

    int sum = 0;
    float average;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
}
