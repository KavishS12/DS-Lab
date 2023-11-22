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

void dequeue(struct node **list){
    struct node *ptr;
    if(*list == NULL){
        printf("List is empty\n");
        return;
    }
    else{
        ptr = *list;
        int a = ptr->x;
        *list = ptr->next;
        free(ptr);
        printf("Deleted : %d\n",a);
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

int main()
{
    struct node *queue = NULL;
    int choice;
    printf("Enter 1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
    do{
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element :");
            int n;
            scanf("%d",&n);
            enqueue(&queue,n);
        }
        else if(choice == 2){
            dequeue(&queue);
        }
        else if(choice==3){
            display(&queue);
        }
        else {
                choice = -1;
                printf("Exiting...\n");
        }
    }while(choice != -1);

    return 0;
}
