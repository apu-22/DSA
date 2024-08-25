#include <stdio.h>

#define SIZE 5
int stack[SIZE], top = -1;

void push(int);
void pop();
void display();

int main()
{
    push(5);
    push(3);
    push(2);
    push(8);

    pop();

    display();

    push(10);

    display();
}

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("OVERFLOW");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW");
    }
    else
    {
        // printf("%d ", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("the stack is empty");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}