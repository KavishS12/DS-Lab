#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isOperator(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')return 1;
    else return 0;
}

char* preToPost(char* pre_exp) {
    int length = strlen(pre_exp);
    char** stack = (char**)malloc(length * sizeof(char*));
    int top = -1;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char* op1 = stack[top--];
            char* op2 = stack[top--];

            int temp_size = strlen(op1) + strlen(op2) + 2;
            char* temp = (char*)malloc(temp_size * sizeof(char));
            sprintf(temp, "%s%s%c", op1, op2, pre_exp[i]);

            stack[++top] = temp;
        }
        else {
            char* temp = (char*)malloc(2 * sizeof(char));
            temp[0] = pre_exp[i];
            temp[1] = '\0';

            stack[++top] = temp;
        }
    }

    return stack[0];
}

int main() {
    char pre_exp[20];
    printf("Enter a prefix expression:");
    scanf("%s",pre_exp);
    char* post_exp = preToPost(pre_exp);

    printf("Postfix : %s", post_exp);

    free(post_exp);

    return 0;
}


