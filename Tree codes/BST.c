#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node *createBST(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insertBST(struct node *root, int value) {
    if (root == NULL) {
        return createBST(value);
    }
     if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }

    return root;
}
struct node *searchBST(struct node *root,int key){
   if(root==NULL || root->data==key){
       return root;
   }
   if(key<root->data)
        return searchBST(root->left,key);
   else
        return searchBST(root->right,key);
}
int depthBST(struct node *root){
    if(root==NULL)
        return 0;
    int leftD=depthBST(root->left);
    int rightD=depthBST(root->right);
    return (leftD>rightD?(leftD+1):(rightD+1));
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int choice, value,key,hei;
     printf("1. create BST\n");
        printf("2. insertBST\n");
        printf("3. inorder display\n");
        printf("4.search BST\n");
         printf("5.height of tree\n");
        printf("0. exit\n");
    do {


        printf("choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                root = createBST(value);
                break;
            case 2:
                printf("enter value: ");
                scanf("%d", &value);
                root = insertBST(root, value);
                break;
            case 3:
                printf("Inorder Display: ");
                inorder(root);
                printf("\n");
                break;
                case 4:printf("enter value to be searched\n");
                scanf("%d",&key);
                if(searchBST(root,key)!=NULL){
                    printf("entered value present in tree\n");
                }
                else{
                    printf("value not found\n");
                }
                break;
                case 5: hei=depthBST(root);
                printf("height of BST is %d\n",hei);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
