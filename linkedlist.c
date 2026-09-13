#include <stdio.h>
#include <stdlib.h>

/* ---------- SINGLY LINKED LIST ---------- */

struct SNode {
    int data;
    struct SNode *next;
};

struct SNode *head = NULL;

void singlyInsertBeginning() {
    int value;
    struct SNode *newNode;

    newNode = (struct SNode *)malloc(sizeof(struct SNode));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void singlyInsertEnd() {
    int value;
    struct SNode *newNode, *temp;

    newNode = (struct SNode *)malloc(sizeof(struct SNode));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void singlyInsertPosition() {
    int value, position, i;
    struct SNode *newNode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    newNode = (struct SNode *)malloc(sizeof(struct SNode));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void singlyDeleteBeginning() {
    struct SNode *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

void singlyDeleteEnd() {
    struct SNode *temp, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void singlyDeletePosition() {
    int position, i;
    struct SNode *temp, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void singlySearch() {
    int key, position = 1;
    struct SNode *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Element found at position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found!\n");
}

void singlyDisplay() {
    struct SNode *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Singly Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


/* ---------- DOUBLY LINKED LIST ---------- */

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode *dhead = NULL;

void doublyInsertEnd() {
    int value;
    struct DNode *newNode, *temp;

    newNode = (struct DNode *)malloc(sizeof(struct DNode));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (dhead == NULL) {
        dhead = newNode;
        return;
    }

    temp = dhead;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void doublyDeleteEnd() {
    struct DNode *temp;

    if (dhead == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = dhead;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        dhead = NULL;

    free(temp);
}

void doublyDisplayForward() {
    struct DNode *temp = dhead;

    if (dhead == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void doublyDisplayBackward() {
    struct DNode *temp = dhead;

    if (dhead == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}


/* ---------- CIRCULAR LINKED LIST ---------- */

struct CNode {
    int data;
    struct CNode *next;
};

struct CNode *chead = NULL;

void circularInsertEnd() {
    int value;
    struct CNode *newNode, *temp;

    newNode = (struct CNode *)malloc(sizeof(struct CNode));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (chead == NULL) {
        chead = newNode;
        newNode->next = chead;
        return;
    }

    temp = chead;

    while (temp->next != chead)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = chead;
}

void circularDeleteBeginning() {
    struct CNode *temp, *last;

    if (chead == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (chead->next == chead) {
        free(chead);
        chead = NULL;
        return;
    }

    last = chead;

    while (last->next != chead)
        last = last->next;

    temp = chead;
    chead = chead->next;
    last->next = chead;

    free(temp);
}

void circularDisplay() {
    struct CNode *temp;

    if (chead == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = chead;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != chead);

    printf("(back to head)\n");
}

int main() {

    int choice;

    do {

        printf("\n========== LINKED LIST ==========\n");
        printf("1. Singly Linked List\n");
        printf("2. Doubly Linked List\n");
        printf("3. Circular Linked List\n");
        printf("0. Exit\n");
        printf("=================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                int ch;

                do {
                    printf("\n----- SINGLY LINKED LIST -----\n");
                    printf("1. Insert at Beginning\n");
                    printf("2. Insert at End\n");
                    printf("3. Insert at Position\n");
                    printf("4. Delete from Beginning\n");
                    printf("5. Delete from End\n");
                    printf("6. Delete from Position\n");
                    printf("7. Search\n");
                    printf("8. Display\n");
                    printf("0. Back\n");

                    printf("Enter choice: ");
                    scanf("%d", &ch);

                    switch (ch) {

                        case 1:
                            singlyInsertBeginning();
                            break;

                        case 2:
                            singlyInsertEnd();
                            break;

                        case 3:
                            singlyInsertPosition();
                            break;

                        case 4:
                            singlyDeleteBeginning();
                            break;

                        case 5:
                            singlyDeleteEnd();
                            break;

                        case 6:
                            singlyDeletePosition();
                            break;

                        case 7:
                            singlySearch();
                            break;

                        case 8:
                            singlyDisplay();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (ch != 0);

                break;
            }

            case 2: {
                int ch;

                do {
                    printf("\n----- DOUBLY LINKED LIST -----\n");
                    printf("1. Insert at End\n");
                    printf("2. Delete from End\n");
                    printf("3. Display Forward\n");
                    printf("4. Display Backward\n");
                    printf("0. Back\n");

                    printf("Enter choice: ");
                    scanf("%d", &ch);

                    switch (ch) {

                        case 1:
                            doublyInsertEnd();
                            break;

                        case 2:
                            doublyDeleteEnd();
                            break;

                        case 3:
                            doublyDisplayForward();
                            break;

                        case 4:
                            doublyDisplayBackward();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (ch != 0);

                break;
            }

            case 3: {
                int ch;

                do {
                    printf("\n----- CIRCULAR LINKED LIST -----\n");
                    printf("1. Insert at End\n");
                    printf("2. Delete from Beginning\n");
                    printf("3. Display\n");
                    printf("0. Back\n");

                    printf("Enter choice: ");
                    scanf("%d", &ch);

                    switch (ch) {

                        case 1:
                            circularInsertEnd();
                            break;

                        case 2:
                            circularDeleteBeginning();
                            break;

                        case 3:
                            circularDisplay();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (ch != 0);

                break;
            }

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
```
