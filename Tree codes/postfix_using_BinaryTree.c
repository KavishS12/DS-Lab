#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

typedef struct {
    Node * nodes[100];
    int tos;
} Stack;

void push(Stack * s, Node * x) {
    s->nodes[++(s->tos)] = x;
}

Node * pop(Stack * s) {
    return (s->nodes[(s->tos)--]);
}

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

double eval(char op,double x,double y) {
    if (op == '+')  return x+y;
    if (op == '-')  return x-y;
    if (op == '*')  return x*y;
    if (op == '/')  return x/y;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

double evaluate(Node * node) {
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return (double) (node->val -'0');

    double x = evaluate(node->left);
    double y = evaluate(node->right);

    return eval(node->val,x,y);
}

int main() {
    Stack nodeStack;
    nodeStack.tos = -1;
    char postfix[100];
    printf("Enter postfix expression : ");
    scanf("%s",postfix);
    int len = strlen(postfix);
    int i;
    for (i=0;i<len;i++) {
        if (!isOperator(postfix[i]))
            push(&nodeStack,createNode(postfix[i]));
        else {
            Node * root = createNode(postfix[i]);
            root->right = pop(&nodeStack);
            root->left = pop(&nodeStack);
            push(&nodeStack,root);
        }
    }
    //for prefix
    /*
    for (int i = len - 1; i >= 0; i--) {
        if (!isOperator(prefix[i])) {
            push(&nodeStack, createNode(prefix[i]));
        }
        else {
            Node *root = createNode(prefix[i]);
            root->left = pop(&nodeStack);
            root->right = pop(&nodeStack);
            push(&nodeStack, root);
        }
    }
    */

    Node * root = pop(&nodeStack);
    printf("Ans :  %lf",evaluate(root));
}
