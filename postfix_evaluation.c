#include<stdio.h>
#include<string.h>

# define MAX 10
# define true 1
# define false 0

typedef struct
{
    int arr[MAX];
    int top;
}stack;

int IsEmpty(stack *s)
{
    if (s->top==-1) return(true);
    else return(false);
}

int IsFull(stack *s)
{
    if (s->top==MAX-1) return(true);
    else return(false);
}

void push(stack *s,int x)
{
    if (IsFull(s))
    {
        printf("Stack overflow.");
    }
    else{
        s->top++;
        s->arr[s->top]=x;
    }
}

int pop(stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack underflow.");
    }
    else{
        return s->arr[s->top--];
    }
}

void display(stack *s)
{
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->arr[i]);
    }
    printf("\n");
}

int main()
{
    char exp[10];
    printf("Enter the expression:");
    scanf("%s",exp);

    stack s;
    s.top=-1;
    int len=strlen(exp);

    for(int i=0;i<len;i++){
        if(exp[i]>='0' && exp[i]<='9'){
            push(&s,exp[i]-48);
        }
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            int a1 = pop(&s);
            int a2 = pop(&s);

            if(exp[i] == '+'){
                push(&s,a2+a1);
            }
            else if(exp[i] == '-'){
                push(&s,a2-a1);
            }
            else if(exp[i] == '*'){
                push(&s,a2*a1);
            }
            else if(exp[i] == '/'){
                push(&s,a2/a1);
            }
        }
        display(&s);
    }
    printf("Result : %d",s.arr[s.top]);
    return 0;
}
