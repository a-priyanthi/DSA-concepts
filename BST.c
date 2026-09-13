#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {

    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

void preorder(struct Node *root) {

    if (root != NULL) {

        printf("%d ", root->data);

        preorder(root->left);

        preorder(root->right);
    }
}

void postorder(struct Node *root) {

    if (root != NULL) {

        postorder(root->left);

        postorder(root->right);

        printf("%d ", root->data);
    }
}

struct Node* search(struct Node *root, int key) {

    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* findMin(struct Node *root) {

    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}


struct Node* findMax(struct Node *root) {

    while (root != NULL && root->right != NULL)
        root = root->right;

    return root;
}

struct Node* deleteNode(struct Node *root, int key) {

    struct Node *temp;

    if (root == NULL)
        return root;


    if (key < root->data) {

        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data) {

        root->right = deleteNode(root->right, key);
    }

    else {

        if (root->left == NULL && root->right == NULL) {

            free(root);
            return NULL;
        }

        else if (root->left == NULL) {

            temp = root->right;

            free(root);

            return temp;
        }
        else if (root->right == NULL) {

            temp = root->left;

            free(root);

            return temp;
        }

        else {

            temp = findMin(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int countNodes(struct Node *root) {

    if (root == NULL)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}

int countLeafNodes(struct Node *root) {

    if (root == NULL)
        return 0;

    if (root->left == NULL &&
        root->right == NULL)
        return 1;

    return countLeafNodes(root->left) +
           countLeafNodes(root->right);
}

int height(struct Node *root) {

    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}
int sumNodes(struct Node *root) {

    if (root == NULL)
        return 0;

    return root->data +
           sumNodes(root->left) +
           sumNodes(root->right);
}
void levelOrder(struct Node *root) {

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    if (root == NULL)
        return;

    queue[rear++] = root;

    while (front < rear) {

        struct Node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

void treeInformation(struct Node *root) {

    struct Node *minNode;
    struct Node *maxNode;

    if (root == NULL) {

        printf("Tree is empty!\n");
        return;
    }

    minNode = findMin(root);
    maxNode = findMax(root);

    printf("\n========== TREE INFORMATION ==========\n");

    printf("Total nodes     : %d\n",
           countNodes(root));

    printf("Leaf nodes      : %d\n",
           countLeafNodes(root));

    printf("Height          : %d\n",
           height(root));

    printf("Minimum value   : %d\n",
           minNode->data);

    printf("Maximum value   : %d\n",
           maxNode->data);

    printf("Sum of nodes    : %d\n",
           sumNodes(root));

    printf("======================================\n");
}

int main() {

    struct Node *root = NULL;

    int choice;
    int value;
    struct Node *result;

    do {

        printf("\n=====================================\n");
        printf("       BINARY TREE / BST\n");
        printf("=====================================\n");

        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Level Order Traversal\n");
        printf("6. Search\n");
        printf("7. Delete\n");
        printf("8. Find Minimum\n");
        printf("9. Find Maximum\n");
        printf("10. Tree Information\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Element inserted successfully.\n");

                break;


            case 2:

                printf("Inorder: ");

                inorder(root);

                printf("\n");

                break;


            case 3:

                printf("Preorder: ");

                preorder(root);

                printf("\n");

                break;


            case 4:

                printf("Postorder: ");

                postorder(root);

                printf("\n");

                break;


            case 5:

                printf("Level Order: ");

                levelOrder(root);

                printf("\n");

                break;


            case 6:

                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL)
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");

                break;


            case 7:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result == NULL) {

                    printf("Element not found!\n");

                }
                else {

                    root = deleteNode(root, value);

                    printf("Element deleted successfully.\n");
                }

                break;


            case 8:

                if (root == NULL) {

                    printf("Tree is empty!\n");

                }
                else {

                    result = findMin(root);

                    printf("Minimum value = %d\n",
                           result->data);
                }

                break;


            case 9:

                if (root == NULL) {

                    printf("Tree is empty!\n");

                }
                else {

                    result = findMax(root);

                    printf("Maximum value = %d\n",
                           result->data);
                }

                break;


            case 10:

                treeInformation(root);

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
