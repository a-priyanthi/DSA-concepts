#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(struct Node* root)
{
    if (root == NULL)
        return 0;

    return root->height;
}


/* =========================
   MAXIMUM
   ========================= */

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(struct Node* root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

struct Node* rightRotate(struct Node* y)
{
    struct Node* x;
    struct Node* temp;

    x = y->left;
    temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left),
                         height(y->right));

    x->height = 1 + max(height(x->left),
                         height(x->right));

    return x;
}

struct Node* leftRotate(struct Node* x)
{
    struct Node* y;
    struct Node* temp;

    y = x->right;
    temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left),
                         height(x->right));

    y->height = 1 + max(height(y->left),
                         height(y->right));

    return y;
}

struct Node* insert(struct Node* root, int data)
{
    int balance;

    /* Normal BST insertion */

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    else
    {
        printf("Duplicate values are not allowed.\n");
        return root;
    }

    root->height = 1 + max(height(root->left),
                            height(root->right));


    balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
    {
        printf("LL Rotation performed.\n");
        return rightRotate(root);
    }

    if (balance < -1 && data > root->right->data)
    {
        printf("RR Rotation performed.\n");
        return leftRotate(root);
    }

    if (balance > 1 && data > root->left->data)
    {
        printf("LR Rotation performed.\n");

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        printf("RL Rotation performed.\n");

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

struct Node* minValueNode(struct Node* root)
{
    struct Node* current;

    current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int data)
{
    int balance;

    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else
    {
        

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        

        else if (root->left == NULL)
        {
            struct Node* temp = root->right;

            free(root);

            return temp;
        }

        

        else if (root->right == NULL)
        {
            struct Node* temp = root->left;

            free(root);

            return temp;
        }

        

        else
        {
            struct Node* temp;

            temp = minValueNode(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }
    }


   

    root->height = 1 + max(height(root->left),
                            height(root->right));


    

    balance = getBalance(root);


    

    if (balance > 1 &&
        getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }


   

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);

        return rightRotate(root);
    }




    if (balance < -1 &&
        getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }


    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

struct Node* search(struct Node* root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void displayInfo(struct Node* root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Tree Height   : %d\n", height(root));
    printf("Root Balance  : %d\n", getBalance(root));
}

int main()
{
    struct Node* root = NULL;

    int choice;
    int value;

    while (1)
    {
        printf("\n========== AVL TREE ==========\n");

        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Height & Balance Factor\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                break;


            case 2:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) == NULL)
                {
                    printf("Value not found.\n");
                }
                else
                {
                    root = deleteNode(root, value);
                    printf("%d deleted successfully.\n", value);
                }

                break;


            case 3:

                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) != NULL)
                    printf("%d found in AVL Tree.\n", value);
                else
                    printf("%d not found.\n", value);

                break;


            case 4:

                printf("Inorder: ");
                inorder(root);
                printf("\n");

                break;


            case 5:

                printf("Preorder: ");
                preorder(root);
                printf("\n");

                break;


            case 6:

                printf("Postorder: ");
                postorder(root);
                printf("\n");

                break;


            case 7:

                displayInfo(root);

                break;


            case 8:

                printf("Program ended.\n");
                return 0;


            default:

                printf("Invalid choice!\n");
        }
    }

    return 0;
}
