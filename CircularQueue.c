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
    if ((rear + 1) == front)
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
        rear = (rear + 1) % SIZE;
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
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("the queue is empty");
    }

    else
    {
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d ", queue[rear]);
    }
}

