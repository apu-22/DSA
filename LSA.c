#include <stdio.h>
#include <stdlib.h>

struct node *createLS(int arr[], int size);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int a[] = {2, 3, 4, 1, 10};
    struct node *head;
    head = createLS(a, 5);

    struct node *current =head;

    while (current != NULL)
    {
        /* code */ printf("-> %d ", current->data);
        current = current->next;
    }
    return 0;
}

struct node *createLS(int arr[], int size)
{
    struct node *head = NULL, *temp = NULL, *current = NULL;

    for (int i = 0; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}