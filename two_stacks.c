#include <stdio.h>
#define MAX_SIZE 10

struct TwoStacks {
    int top1;
    int top2;
    int arr[MAX_SIZE];
};

void initialize(struct TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}

void push1(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

void push2(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

int pop2(struct TwoStacks* ts) {
    if (ts->top2 < MAX_SIZE) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}

void display1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        printf("Stack 1: ");
        for (int i = 0; i <= ts->top1; ++i) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    } else {
        printf("Stack 1 is empty\n");
    }
}

void display2(struct TwoStacks* ts) {
    if (ts->top2 < MAX_SIZE) {
        printf("Stack 2: ");
        for (int i = MAX_SIZE - 1; i >= ts->top2; --i) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    } else {
        printf("Stack 2 is empty\n");
    }
}

int main() {
    struct TwoStacks ts;
    initialize(&ts);
    int choice, x;

    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push to Stack 1: ");
                scanf("%d", &x);
                push1(&ts, x);
                break;
            case 2:
                printf("Enter element to push to Stack 2: ");
                scanf("%d", &x);
                push2(&ts, x);
                break;
            case 3:
                x = pop1(&ts);
                if (x != -1) {
                    printf("Popped element from Stack 1: %d\n", x);
                }
                break;
            case 4:
                x = pop2(&ts);
                if (x != -1) {
                    printf("Popped element from Stack 2: %d\n", x);
                }
                break;
            case 5:
                display1(&ts);
                break;
            case 6:
                display2(&ts);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 0);

    return 0;
}

