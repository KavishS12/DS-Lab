#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isOperator(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')return 1;
    else return 0;
}

char* PostToPre(char* post_exp){
    int len = strlen(post_exp);
    char** stack = (char**)malloc(len * sizeof(char*));
    int top =-1;

    for(int i=0;i<len;i++){
        if(isOperator(post_exp[i])){
            char* op1 = stack[top--];
            char* op2 = stack[top--];


            int temp_size = strlen(op1) + strlen(op2) + 2;
            char* temp = (char*)malloc(temp_size * sizeof(char));

            sprintf(temp,"%c%s%s",post_exp[i],op2,op1);
            stack[++top] = temp;
        }
        else{
            char* temp = (char*)malloc(2 * sizeof(char));
            temp[0] = post_exp[i];
            temp[1] = '\0';
            stack[++top]=temp;
        }
    }
    return stack[0];
}

void main()
{
    char post_exp[20];

    printf("Enter a postfix expression :");
    scanf("%s",post_exp);

    char* pre_exp = PostToPre(post_exp);
    printf("Postfix : %s", pre_exp);

    free(pre_exp);
    return 0;
}
