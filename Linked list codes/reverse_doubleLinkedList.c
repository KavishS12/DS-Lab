#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *prev;
    struct node *next;
};

void insertEnd(struct node **list,int n){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(*list == NULL){
        temp->x = n;
        temp->next = NULL;
        temp->prev = NULL;
        *list = temp;
        return;
    }
    struct node *ptr = *list;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    temp->x = n;
    temp->prev  = ptr;
    temp->next = NULL;
    ptr->next = temp;
}

void display(struct node **list){
    struct node *ptr;
    ptr = *list;
    while(ptr!=NULL){
        printf("%d ",ptr->x);
        ptr  = ptr->next;
    }
    printf("\n");
}

void reverse(struct node **list){
    struct node *currNode,*prevNode,*nextNode;
    currNode = nextNode = *list;
    prevNode = NULL;
    while(nextNode != NULL){
        nextNode = nextNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    *list = prevNode;
}

int main()
{
    struct node *list = (struct node*)malloc(sizeof(struct node));
    list = NULL;
    printf("enter 1.Insert 2.exit\n");
    int choice = 0;
    while(choice != -1){
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter value:");
            int n;
            scanf("%d",&n);
            insertEnd(&list,n);
        }
        else{
            printf("Exiting...\n");
            choice = -1;
        }
    }
    printf("List is:");
    display(&list);
    reverse(&list);
    printf("Reversed List is:");
    display(&list);
}
