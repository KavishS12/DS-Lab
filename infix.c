#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char *read_string()
{
    char buffer[MAX_SIZE];

    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';

    return strdup(buffer);
}

typedef struct{
    int array[MAX_SIZE];
    int top;
} stack;

int is_empty(stack *s)
{
    return s->top == -1;
}

int is_full(stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int push(stack *s, int e)
{
    if (is_full(s))
        return 0;
    else
        s->array[++(s->top)] = e;

    return 1;
}

int pop(stack *s)
{
    if (is_empty(s))
        return -999;
    else
        return s->array[(s->top)--];
}

void display(stack *s)
{
    printf("[");

    for (int i = 0; i <= s->top - 1; i++)
        printf("%d, ", s->array[i]);

    if (!is_empty(s))
        printf("%d", s->array[s->top]);

    printf("]\n");
}

int peek(stack *s)
{
    return s->array[s->top];
}

char *infix_to_prefix(char*);
char *infix_to_postfix(char*);
int is_operator(char);
int precedence(char);
char *strrev(char*);

char *infix_to_prefix(char *exp)
{
    char *reversed = strrev(exp);

    for (int i = 0; i < strlen(reversed); i++) {
        if (reversed[i] == '(')
            reversed[i] = ')';
        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    return strrev(infix_to_postfix(reversed));
}

char *infix_to_postfix(char *exp)
{
    stack operators;
    stack output;
    operators.top = -1;
    output.top = -1;

    for (int i = 0; i < strlen(exp); i++) {
        char token = exp[i];

        if (is_operator(token)) {
            while (!is_empty(&operators) && precedence(peek(&operators)) >= precedence(token))
                push(&output, pop(&operators));
            push(&operators, token);
        } else if (token == '(') {
            push(&operators, token);
        } else if (token == ')') {
            while (peek(&operators) != '(')
                push(&output, pop(&operators));
            pop(&operators);
        } else {
            push(&output, token);
        }
    }

    while (!is_empty(&operators))
            push(&output, pop(&operators));

    int n = (output.top + 1);

    char *result = malloc((n + 1) * sizeof(char));
    result[n] = '\0';

    for (int i = n - 1; i >= 0; i--)
        result[i] = pop(&output);

    return result;
}

int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

char *strrev(char *str)
{
    int n = strlen(str);

    char *reversed = malloc((n + 1) * sizeof(char));
    reversed[n] = '\0';

    for (int i = 0; i < n; i++)
        reversed[i] = str[n - i - 1];

    return reversed;
}


int main()
{
    printf("Infix: ");
    char *exp = read_string();

    char *result = infix_to_prefix(exp);
    printf("Prefix: %s\n", result);

    char *result2 = infix_to_postfix(exp);
    printf("Postfix: %s\n", result2);
}

