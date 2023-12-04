#include<stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node * createNode(int x) {
    node * new = (node *) malloc(sizeof(node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* createBinaryTree()
{
    node *p;
    int n;
    printf("Enter data(-1 for no data):");
    scanf("%d",&n);

    if(n == -1) return NULL;

    p = (node*)malloc(sizeof(node));
    p->data=n;

    printf("Enter left child of %d:\n",n);
    p->left=createBinaryTree();

    printf("Enter right child of %d:\n",n);
    p->right=createBinaryTree();
    return p;
}

void inOrder(node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ",tree->data);
        inOrder(tree->right);
    }
}

void postOrder(node *tree) {
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ",tree->data);
    }
}

void preOrder(node *tree) {
    if (tree != NULL) {
        printf("%d ",tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void levelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(node *t){
    if(t==NULL)
        return 0;
    int leftDepth=height(t->left);
    int rightDepth=height(t->right);
    return ((leftDepth>rightDepth)?(leftDepth+1):(rightDepth+1));
}

 int leafNodes(node *t){
    if(t == NULL)
        return 0;
    if(t->left==NULL && t->right==NULL)
        return 1;
    return leafNodes(t->left) + leafNodes(t->right);
 }

 node *findParent(node *t){
     int target;
     printf("enter the data of node whose parent is to be found \n");
     scanf("%d",&target);
     if (t==NULL || (t->right!=NULL && t->right->data==target) || (t->left!=NULL && t->left->data==target))
        return t;

     node *leftResult = findParent(t->left);
     node *rightResult = findParent(t->right);
     return (leftResult!=NULL)?leftResult:rightResult;
 }

 int findAncestors(node *t,int target){
     if(t==NULL)
        return 0;
     if(t->data==target)
        return 1;
     if(findAncestors(t->left,target) || findAncestors(t->right,target)){
         printf("%d\t",t->data);
         return 1;
     }
     printf("\n");
     return 0;
 }

 node * copyBT(node * t) {
    if (t == NULL)
        return NULL;
    node * new = createNode(t->data);
    new->left = copyBT(t->left);
    new->right = copyBT(t->right);

    return new;
}

int eqCheck(node * node1, node * node2) {
    if (node1 == NULL && node2 == NULL)
        return 1;
    if (node1 == NULL || node2 == NULL)
        return 0;
    if (node1->data != node2->data)
        return 0;
    return eqCheck(node1->left, node2->left) && eqCheck(node1->right, node2->right);
}

int main()
{
    node *root;
    root = createBinaryTree();

    printf("\nThe preorder traversal of tree is:\n");
    preOrder(root);

    printf("\nThe postorder traversal of tree is:\n");
    postOrder(root);

    printf("\nThe inorder traversal of tree is:\n");
    inOrder(root);

    printf("\nThe level order traversal of tree is:\n");
    levelOrder(root);

    int k=height(root);
    printf("\nHeight of tree is %d\n",k);

    int ln=leafNodes(root);
    printf("Number of leaf nodes are %d\n",ln);

    //temp=findParent(root);
    //printf("parent of given node is %d",temp->data);

    printf("Enter data of node whose ancestors are to be found:");
    int target;
    scanf("%d",&target);
    printf("Ancestors of the given nodes are :");
    findAncestors(root,target);

    return 0;
}
