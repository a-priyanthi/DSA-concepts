#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    int value;

    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("Element inserted successfully.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void queuePeek() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void displayQueue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int circularQueue[MAX];
int cfront = -1;
int crear = -1;

void circularEnqueue() {
    int value;

    if ((crear + 1) % MAX == cfront) {
        printf("Circular Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (cfront == -1) {
        cfront = 0;
        crear = 0;
    }
    else {
        crear = (crear + 1) % MAX;
    }

    circularQueue[crear] = value;

    printf("Element inserted successfully.\n");
}

void circularDequeue() {
    if (cfront == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", circularQueue[cfront]);

    if (cfront == crear) {
        cfront = -1;
        crear = -1;
    }
    else {
        cfront = (cfront + 1) % MAX;
    }
}

void circularPeek() {
    if (cfront == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", circularQueue[cfront]);
}

void circularDisplay() {
    int i;

    if (cfront == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");

    i = cfront;

    while (1) {
        printf("%d ", circularQueue[i]);

        if (i == crear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int deque[MAX];
int dfront = -1;
int drear = -1;

void insertFront() {
    int value;

    if ((dfront == 0 && drear == MAX - 1) ||
        dfront == drear + 1) {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (dfront == -1) {
        dfront = 0;
        drear = 0;
    }
    else if (dfront == 0) {
        dfront = MAX - 1;
    }
    else {
        dfront--;
    }

    deque[dfront] = value;
}

void insertRear() {
    int value;

    if ((dfront == 0 && drear == MAX - 1) ||
        dfront == drear + 1) {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (dfront == -1) {
        dfront = 0;
        drear = 0;
    }
    else if (drear == MAX - 1) {
        drear = 0;
    }
    else {
        drear++;
    }

    deque[drear] = value;
}

void deleteFront() {
    if (dfront == -1) {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[dfront]);

    if (dfront == drear) {
        dfront = -1;
        drear = -1;
    }
    else if (dfront == MAX - 1) {
        dfront = 0;
    }
    else {
        dfront++;
    }
}

void deleteRear() {
    if (dfront == -1) {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[drear]);

    if (dfront == drear) {
        dfront = -1;
        drear = -1;
    }
    else if (drear == 0) {
        drear = MAX - 1;
    }
    else {
        drear--;
    }
}

void displayDeque() {
    int i;

    if (dfront == -1) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque: ");

    i = dfront;

    while (1) {
        printf("%d ", deque[i]);

        if (i == drear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

struct PriorityElement {
    int data;
    int priority;
};

struct PriorityElement pq[MAX];
int pqSize = 0;

void priorityEnqueue() {
    int value, priority;

    if (pqSize == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &priority);

    pq[pqSize].data = value;
    pq[pqSize].priority = priority;

    pqSize++;

    printf("Element inserted successfully.\n");
}

void priorityDequeue() {
    int highest;
    int i;

    if (pqSize == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    highest = 0;

    for (i = 1; i < pqSize; i++) {
        if (pq[i].priority > pq[highest].priority)
            highest = i;
    }

    printf("Deleted element: %d\n", pq[highest].data);

    for (i = highest; i < pqSize - 1; i++)
        pq[i] = pq[i + 1];

    pqSize--;
}

void priorityDisplay() {
    if (pqSize == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nValue\tPriority\n");

    for (int i = 0; i < pqSize; i++)
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
}

void simpleQueueMenu() {

    int choice;

    do {
        printf("\n----- SIMPLE QUEUE -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                queuePeek();
                break;

            case 4:
                displayQueue();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}


void circularQueueMenu() {

    int choice;

    do {
        printf("\n----- CIRCULAR QUEUE -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                circularEnqueue();
                break;

            case 2:
                circularDequeue();
                break;

            case 3:
                circularPeek();
                break;

            case 4:
                circularDisplay();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}


void dequeMenu() {

    int choice;

    do {
        printf("\n----- DEQUE -----\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                displayDeque();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}


void priorityQueueMenu() {

    int choice;

    do {
        printf("\n----- PRIORITY QUEUE -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                priorityEnqueue();
                break;

            case 2:
                priorityDequeue();
                break;

            case 3:
                priorityDisplay();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

int main() {

    int choice;

    do {

        printf("\n========================================\n");
        printf("             QUEUE OPERATIONS\n");
        printf("========================================\n");

        printf("1. Simple Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Deque\n");
        printf("4. Priority Queue\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                simpleQueueMenu();
                break;

            case 2:
                circularQueueMenu();
                break;

            case 3:
                dequeMenu();
                break;

            case 4:
                priorityQueueMenu();
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
