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

int find(struct node **list,int n){
    struct node *ptr;
    ptr = *list;
    while(ptr != NULL){
        if((ptr->x) == n)return 1;
        ptr = ptr->next;
    }
    return 0;
}

struct node* Union(struct node **l1,struct node **l2){
    struct node *un = (struct node*)malloc(sizeof(struct node));
    un-> x = (*l1)->x;
    un->next = NULL;
    struct node *ptr1,*ptr3;
    ptr1 = (*l1)->next;
    ptr3 = un;
    while(ptr1 != NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->x = ptr1->x;
        temp->next = NULL;
        ptr3->next = temp;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }
    ptr1 = *l2;
    while(ptr1 != NULL){
        if(!find(&un,ptr1->x)){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->x = ptr1->x;
            temp->next = NULL;
            ptr3->next = temp;
            ptr3 = ptr3->next;
        }
        ptr1 = ptr1->next;
    }
    return un;
}

struct node* intersection(struct node **l1,struct node** l2){
    struct node *inter = (struct node*)malloc(sizeof(struct node));
    inter = NULL;
    struct node *ptr1,*ptr3;
    ptr1 = *l1;
    while(ptr1 != NULL){
        if(find(l2,ptr1->x)){
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->x = ptr1->x;
            temp->next = NULL;
            if(inter == NULL){
                inter = temp;
                ptr3 = inter;
            }
            else {
                ptr3->next = temp;
                ptr3= ptr3->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return inter;
}

int main()
{
    struct node *l1 = NULL;
    struct node *l2 = NULL;
    int choice;
    printf("Enter 1.Enqueue1 2.Enqueue2 3.Exit\n");
    do{
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element :");
            int n;
            scanf("%d",&n);
            enqueue(&l1,n);
        }
        else if(choice == 2){
            printf("Enter element :");
            int n;
            scanf("%d",&n);
            enqueue(&l2,n);
        }
        else {
                choice = -1;
                printf("Exiting...\n");
        }
    }while(choice != -1);

    printf("list 1 : ");
    display(&l1);
    printf("list 2 : ");
    display(&l2);
    printf("Union :");
    struct node *un = Union(&l1,&l2);
    display(&un);
    printf("Intersection :");
    struct node *in = intersection(&l1,&l2);
    display(&in);
    return 0;
}

