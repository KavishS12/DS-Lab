#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node * createTree(int pre[100], int post[100], int n, int * preIndex) {
    if (n <= 0)
        return NULL;
    Node * tree = createNode(pre[(*preIndex)++]);
    if (n == 1)
        return tree;
    int i;
    for (i = 0; i < n; i++)
        if (pre[*preIndex] == post[i])
            break;
    if (i < n) {
        tree->left = createTree(pre, post, i + 1, preIndex);
        tree->right = createTree(pre, post + i + 1, n - i - 1, preIndex);
    }
    return tree;
}

void inOrder(Node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ",tree->val);
        inOrder(tree->right);
    }
}

int main() {
    int i, n, preInd = 0, pre[100], post[100];

    printf("Enter number of nodes ");
    scanf("%d",&n);

    printf("Enter preorder traversal: ");
    for(i = 0;i < n; i++)
        scanf("%d",&pre[i]);

    printf("Enter postorder traversal: ");
    for(i = 0;i < n;i++)
        scanf("%d",&post[i]);

    Node * tree = createTree(pre, post, n, &preInd);

    printf("Inorder traversal: ");
    inOrder(tree);
}
