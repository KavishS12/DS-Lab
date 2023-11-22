#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *next;
};

//create a circular linked list of n people having values from 1 to n
struct node* createCircular(int n){
    struct node *start = (struct node*)malloc(sizeof(struct node));
    start->x = 1;
    start->next = start;
    int i = 2;
    struct node *ptr = start;
    while(i<=n){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->x = i;
        temp->next = start;
        ptr->next = temp;
        ptr = ptr->next;
        i++;
    }
    return start;
};

void display(struct node **start){
    if(*start == NULL){
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = *start;
    while(ptr->next != *start){
        printf("%d  ",ptr->x);
        ptr = ptr->next;
    }
    printf("%d",ptr->x);
    printf("\n");
}

int JC(struct node *start,int n,int m){
    if(n==1){
        return start->x;
    }
    struct node *ptr;
    ptr = start;
    int i = 1;
    while(i<m-1){
        ptr = ptr->next;
        i++;
    }
    ptr->next  = (ptr->next)->next;
    JC(ptr->next,n-1,m);
}

int main()
{
    int n,m;
    printf("Enter the number of persons:");
    scanf("%d",&n);

    struct node *start = createCircular(n);
    display(&start);

    printf("Enter the value of m:");
    scanf("%d",&m);

    printf("Result:");
    printf("%d",JC(start,n,m));
}
