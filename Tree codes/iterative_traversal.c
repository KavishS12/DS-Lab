 #include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} Node ;


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

typedef struct {
    Node ** nodesList;
    int front,rear;
} Queue;

void insertQ(Queue *q, Node * node) {
    if (q->front == -1)
        q->front = 0;
    q->nodesList[++(q->rear)] = node;
}

Node * deleteQ(Queue *q) {
    Node * item = (Node *) malloc(sizeof(Node));
    item = q->nodesList[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front++;
    return item;
}

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* createBinaryTree()
{
    Node *p;
    int n;
    printf("Enter data(-1 for no data):");
    scanf("%d",&n);

    if(n == -1) return NULL;

    p = (Node*)malloc(sizeof(Node));
    p->data=n;

    printf("Enter left child of %d:\n",n);
    p->left=createBinaryTree();

    printf("Enter right child of %d:\n",n);
    p->right=createBinaryTree();
    return p;
}

void iterPreOrder(Node ** tree) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Stack s;
    s.tos = -1;
    push(&s,*tree);
    while (s.tos != -1) {
        temp = pop(&s);
        printf("%d ",temp->data);
        if (temp->right != NULL)
            push(&s,temp->right);
        if (temp->left != NULL)
            push(&s,temp->left);
    }
}

void iterPostOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * temp2 = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        while (temp != NULL) {
            if (temp->right != NULL)
                push(&s,temp->right);
            push(&s,temp);
            temp = temp->left;
        }

        temp = pop(&s);
        if ((temp->right != NULL) && (s.nodes[s.tos] == (temp->right))) {
            temp2 = pop(&s);
            push(&s,temp);
            temp = temp2;
        }
        else {
            printf("%d ", temp->data);
            temp = NULL;
        }
    } while(s.tos != -1);
}

void iterInOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        if (temp != NULL) {
            push(&s,temp);
            temp = temp->left;
        }
        else {
            if (s.tos != -1) {
                temp = pop(&s);
                printf("%d ",temp->data);
                temp = temp->right;
            }
            else
                break;
        }
    } while(1);
}


void iterLevelOrder(Node **tree) {
    Queue q;
    q.nodesList = (Node **) malloc(20 * sizeof(Node *));
    q.front = -1;
    q.rear = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    while (temp != NULL) {
        printf("%d ",temp->data);
        if (temp->left != NULL)
            insertQ(&q,temp->left);
        if (temp->right != NULL)
            insertQ(&q,temp->right);
        if (q.front == -1)
            temp = NULL;
        else
            temp = deleteQ(&q);
    }
}

int main() {
    Node * tree ;
    tree = createBinaryTree();
    printf("Pre Order : ");
    iterPreOrder(&tree);
    printf("\nPost Order : ");
    iterPostOrder(&tree);
    printf("\nInOrder : ");
    iterInOrder(&tree);
    printf("\nLevel Order : ");
    iterLevelOrder(&tree);
}
