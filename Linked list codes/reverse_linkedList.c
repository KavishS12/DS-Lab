#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *next;
};

void enqueue(struct node **list,int n){
    struct node *ptr;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->x = n;
    temp->next = NULL;

    ptr = *list;
    if(*list == NULL){
        *list = temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(struct node **list){
    if(*list == NULL){
        printf("List is empty\n");
        return ;
    }
    struct node *ptr;
    ptr = *list;
    while(ptr!= NULL){
        printf("%d  ",ptr->x);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse(struct node **list){
    struct node *prevNode,*currNode,*nextNode;
    prevNode = NULL;
    currNode = nextNode = *list;
    while(nextNode != NULL){
        nextNode = nextNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    *list = prevNode;
}

int main()
{
    struct node *list = NULL;
    int choice;
    printf("Enter 1.Enqueue 2.Exit\n");
    do{
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element :");
            int n;
            scanf("%d",&n);
            enqueue(&list,n);
        }
        else {
                choice = -1;
                printf("Exiting...\n");
        }
    }while(choice != -1);

    printf("List : ");
    display(&list);

    printf("Reverse list : ");
    reverse(&list);
    display(&list);


    return 0;
}


