#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Element pushed successfully.\n");
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack:\n");

    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

struct Node {
    int data;
    struct Node *next;
};

struct Node *stackTop = NULL;

void linkedPush() {
    int value;

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = stackTop;

    stackTop = newNode;

    printf("Element pushed successfully.\n");
}

void linkedPop() {
    struct Node *temp;

    if (stackTop == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = stackTop;

    printf("Deleted element: %d\n", temp->data);

    stackTop = stackTop->next;

    free(temp);
}

void linkedPeek() {
    if (stackTop == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", stackTop->data);
}

void linkedDisplay() {
    struct Node *temp = stackTop;

    if (stackTop == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

char operatorStack[MAX];
int operatorTop = -1;

void pushOperator(char ch) {
    operatorStack[++operatorTop] = ch;
}

char popOperator() {
    return operatorStack[operatorTop--];
}

char peekOperator() {
    return operatorStack[operatorTop];
}

int precedence(char ch) {

    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix() {

    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    operatorTop = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        ch = infix[i];

        /* Operand */
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        /* Opening bracket */
        else if (ch == '(') {
            pushOperator(ch);
        }

        /* Closing bracket */
        else if (ch == ')') {

            while (operatorTop != -1 &&
                   peekOperator() != '(') {

                postfix[j++] = popOperator();
            }

            if (operatorTop != -1)
                popOperator();
        }

        /* Operator */
        else {

            while (operatorTop != -1 &&
                   precedence(peekOperator()) >= precedence(ch)) {

                postfix[j++] = popOperator();
            }

            pushOperator(ch);
        }
    }

    /* Pop remaining operators */
    while (operatorTop != -1)
        postfix[j++] = popOperator();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int valueStack[MAX];
int valueTop = -1;

void pushValue(int value) {
    valueStack[++valueTop] = value;
}

int popValue() {
    return valueStack[valueTop--];
}

void postfixEvaluation() {

    char postfix[MAX];
    int a, b, result;

    valueTop = -1;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {

        char ch = postfix[i];

        /* Operand */
        if (isdigit(ch)) {

            pushValue(ch - '0');
        }

        /* Operator */
        else {

            b = popValue();
            a = popValue();

            switch (ch) {

                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator!\n");
                    return;
            }

            pushValue(result);
        }
    }

    if (valueTop == 0)
        printf("Result = %d\n", popValue());
}

void checkParentheses() {

    char expression[MAX];
    char brackets[MAX];

    int bracketTop = -1;
    int valid = 1;

    printf("Enter expression: ");
    scanf("%s", expression);

    for (int i = 0; expression[i] != '\0'; i++) {

        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {

            brackets[++bracketTop] = ch;
        }

        else if (ch == ')' || ch == ']' || ch == '}') {

            if (bracketTop == -1) {
                valid = 0;
                break;
            }

            char open = brackets[bracketTop--];

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {

                valid = 0;
                break;
            }
        }
    }

    if (bracketTop != -1)
        valid = 0;

    if (valid)
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");
}

void arrayStackMenu() {

    int choice;

    do {

        printf("\n----- STACK USING ARRAY -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}


void linkedStackMenu() {

    int choice;

    do {

        printf("\n----- STACK USING LINKED LIST -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Back\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                linkedPush();
                break;

            case 2:
                linkedPop();
                break;

            case 3:
                linkedPeek();
                break;

            case 4:
                linkedDisplay();
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

        printf("\n====================================\n");
        printf("          STACK OPERATIONS\n");
        printf("====================================\n");

        printf("1. Stack using Array\n");
        printf("2. Stack using Linked List\n");
        printf("3. Infix to Postfix\n");
        printf("4. Postfix Evaluation\n");
        printf("5. Parentheses Matching\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                arrayStackMenu();
                break;

            case 2:
                linkedStackMenu();
                break;

            case 3:
                infixToPostfix();
                break;

            case 4:
                postfixEvaluation();
                break;

            case 5:
                checkParentheses();
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
