/*
4. Write a C program to convert a given simple mathematical expression into prefix notation. You can assume some simple conditions for input like only 3 to 4 components are there in the expression.

Example = If the input string is E=(X*Y)-(Z+X) then the output must be E=  - * X Y + Z X.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 1000
#define nl printf("\n")
#define outs(s) printf("%s", s)
#define outi(i) printf("%d", i)
int t = -1;
char stack[MAX];

int is_full();
int is_empty();

void push(char item)
{
    if (is_full())
        return;
    t++;
    stack[t] = item;
}

int pop()
{
    if (is_empty())
        return INT_MIN;

    return stack[t--];
}

int is_full()
{
    return t == MAX - 1;
}

int is_empty()
{
    return t == -1;
}

int top_of_stack()
{
    if (is_empty())
        return INT_MIN;
    return stack[t];
}

int check_if_operand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;

    else
        return 0;
}

int precedence_char(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int getPostfix_exp(char *exp)
{
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i)
    {

        if (check_if_operand(exp[i])) // if operand
            exp[++j] = exp[i];

        else if (exp[i] == '(') // if open bracket
            push(exp[i]);

        else if (exp[i] == ')') // if closed bracket
        {
            while (!is_empty(stack) && top_of_stack(stack) != '(')
                exp[++j] = pop(stack);
            if (!is_empty(stack) && top_of_stack(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else // if opertor
        {
            while (!is_empty(stack) && precedence_char(exp[i]) <= precedence_char(top_of_stack(stack)))
                exp[++j] = pop(stack);
            push(exp[i]);
        }
    }
    while (!is_empty(stack))
        exp[++j] = pop(stack);

    exp[++j] = '\0';
}

void reverse(char *e)
{
    int size = strlen(e);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (e[i] != '\0')
    {
        temp[j] = e[i];
        j--;
        i++;
    }
    strcpy(e, temp);
}
void reverse_brackets(char *e)
{
    int i = 0;
    while (e[i] != '\0')
    {
        if (e[i] == ')')
            e[i] = '(';
        else if (e[i] == '(')
            e[i] = ')';
        i++;
    }
}
void Infix_to_prefix(char *e)
{

    int size = strlen(e);
    reverse(e);
    reverse_brackets(e);
    getPostfix_exp(e);
    reverse(e);
}

int main()
{
    char exp[] = "(X*Y)-(Z+X)";
    outs("The given string is: ");
    outs(exp);
    nl;
    Infix_to_prefix(exp);

    outs("The prefix expression is: ");
    outs(exp);
    nl;

    return 0;
}