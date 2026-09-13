#include <stdio.h>
#include <stdlib.h>
#define MAX_KEYS 3
#define MAX_CHILDREN 4
typedef struct Node {
    int keys[MAX_KEYS];
    struct Node *child[MAX_CHILDREN];
    int n;
    int leaf;
} Node;

Node *root = NULL;

Node *createNode(int leaf) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->n = 0;
    node->leaf = leaf;

    for (int i = 0; i < MAX_CHILDREN; i++)
        node->child[i] = NULL;

    return node;
}

void splitChild(Node *parent, int index) {
    Node *full = parent->child[index];
    Node *newNode = createNode(full->leaf);

    int middle = full->keys[1];

    newNode->n = 1;
    newNode->keys[0] = full->keys[2];

    if (!full->leaf) {
        newNode->child[0] = full->child[2];
        newNode->child[1] = full->child[3];
    }

    full->n = 1;

    for (int i = parent->n; i >= index + 1; i--)
        parent->child[i + 1] = parent->child[i];

    parent->child[index + 1] = newNode;

    for (int i = parent->n - 1; i >= index; i--)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = middle;
    parent->n++;
}

int insertRecursive(Node *node, int key, int *promoted, Node **newChild) {
    int i;

    if (node->leaf) {
        i = node->n - 1;

        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        if (i >= 0 && key == node->keys[i])
            return 0;

        node->keys[i + 1] = key;
        node->n++;
    } else {
        i = node->n - 1;

        while (i >= 0 && key < node->keys[i])
            i--;

        i++;

        if (i < node->n && key == node->keys[i])
            return 0;

        int promotedKey;
        Node *child;

        if (insertRecursive(node->child[i], key, &promotedKey, &child)) {
            for (int j = node->n; j > i; j--)
                node->keys[j] = node->keys[j - 1];

            for (int j = node->n + 1; j > i + 1; j--)
                node->child[j] = node->child[j - 1];

            node->keys[i] = promotedKey;
            node->child[i + 1] = child;
            node->n++;
        }
    }

    if (node->n <= MAX_KEYS)
        return 0;

    Node *right = createNode(node->leaf);

    *promoted = node->keys[1];

    right->n = 2;
    right->keys[0] = node->keys[2];

    if (!node->leaf) {
        right->child[0] = node->child[2];
        right->child[1] = node->child[3];
    }

    node->n = 1;

    *newChild = right;

    return 1;
}

void insert(int key) {
    int promoted;
    Node *newChild;

    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = key;
        root->n = 1;

        printf("%d inserted.\n", key);
        return;
    }

    if (searchValue(root, key)) {
        printf("Duplicate value not allowed.\n");
        return;
    }

    if (insertRecursive(root, key, &promoted, &newChild)) {
        Node *newRoot = createNode(0);

        newRoot->keys[0] = promoted;
        newRoot->n = 1;

        newRoot->child[0] = root;
        newRoot->child[1] = newChild;

        root = newRoot;
    }

    printf("%d inserted.\n", key);
}

int searchValue(Node *node, int key) {
    if (node == NULL)
        return 0;

    int i = 0;

    while (i < node->n && key > node->keys[i])
        i++;

    if (i < node->n && key == node->keys[i])
        return 1;

    if (node->leaf)
        return 0;

    return searchValue(node->child[i], key);
}

void search(Node *node, int key) {
    if (searchValue(node, key))
        printf("%d found.\n", key);
    else
        printf("%d not found.\n", key);
}

void inorder(Node *node) {
    if (node == NULL)
        return;

    for (int i = 0; i < node->n; i++) {
        if (!node->leaf)
            inorder(node->child[i]);

        printf("%d ", node->keys[i]);
    }

    if (!node->leaf)
        inorder(node->child[node->n]);
}

void display(Node *node, int level) {
    if (node == NULL)
        return;

    printf("Level %d: [", level);

    for (int i = 0; i < node->n; i++) {
        printf("%d", node->keys[i]);

        if (i < node->n - 1)
            printf(" ");
    }

    printf("]\n");

    if (!node->leaf) {
        for (int i = 0; i <= node->n; i++)
            display(node->child[i], level + 1);
    }
}

int countKeys(Node *node) {
    if (node == NULL)
        return 0;

    int count = node->n;

    if (!node->leaf) {
        for (int i = 0; i <= node->n; i++)
            count += countKeys(node->child[i]);
    }

    return count;
}

int height(Node *node) {
    if (node == NULL)
        return 0;

    if (node->leaf)
        return 1;

    return 1 + height(node->child[0]);
}

void freeTree(Node *node) {
    if (node == NULL)
        return;

    if (!node->leaf) {
        for (int i = 0; i <= node->n; i++)
            freeTree(node->child[i]);
    }

    free(node);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n========== BOTTOM-UP TREE ==========\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Display Tree\n");
        printf("5. Count Keys\n");
        printf("6. Height\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    display(root, 0);
                break;

            case 5:
                printf("Total keys: %d\n", countKeys(root));
                break;

            case 6:
                printf("Height: %d\n", height(root));
                break;

            case 7:
                freeTree(root);
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
