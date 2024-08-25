#include <stdio.h>

#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue(int);
void dequeue();
void display();

int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(9);

    dequeue();
    dequeue();

    enqueue(3);
    enqueue(1);

    display();
}

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        printf("OVERFLOW");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("underflow");
    }
    else if (front == rear)
    {
        // printf("%d ", queue[front]);
        front = rear = -1;
    }
    else
    {
        // printf("%d ", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("the queue is empty");
    }

    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
