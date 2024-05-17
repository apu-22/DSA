#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key, data;
    struct node *next;
};

struct node *head = NULL;

void createll(int key, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void printll()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("(%d,%d)\n", current->key, current->data);
        current = current->next;
    }
}

void delete_first()
{
    head = head->next;
}

void delete_last()
{
    if (head == NULL)
    {
        // List is empty
        return;
    }

    if (head->next == NULL)
    {
        // List has only one element
        head = head->next;
    }

    struct node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);  // Free the last node
    current->next = NULL; // Set the second to last node's next to NULL
}

void insertBE(int key, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertED(int key, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void insert_between_key(int key, int new_key, int new_data)
{
    struct node *current = head;

    while (current->key != key)
    {
        current = current->next;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = new_key;
    new_node->data = new_data;

    if (current == head)
    {
        new_node->next = head;
        head = new_node;
    }

    else
    {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_between_key(int key)
{
    // if (head == NULL || head->next == NULL)
    // {
    //     // List is empty or has only one node
    //     return;
    // }

    struct node *current = head;
    struct node *prev = NULL;

    if (head == NULL)
        return;

    // Traverse the list to find the node with the given key
    while (current->key != key)
    {
        if (current->next == NULL)
        {
            printf("Key did not find\n\n");
            return;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    if (current == head)
    {
        // head=head->next;
        free(head);
        return;
    }
    else
    {
        prev->next = current->next;
    }
}

void revll()
{
    struct node *current = head, *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort_by_data()
{
    if (head == NULL)
        return;

    struct node *current = head, *index = NULL;
    int temp_key, temp_data;

    while (current != NULL)
    {
        index = current->next;

        while (index != NULL)
        {
            if (current->data > index->data)
            {
                temp_data = current->data;
                temp_key = current->key;

                current->data = index->data;
                current->key = index->key;

                index->data = temp_data;
                index->key = temp_key;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void sort_by_key()
{
    if (head == NULL)
        return;

    struct node *current = head, *index = NULL;
    int temp_key, temp_data;

    while (current != NULL)
    {
        index = current->next;

        while (index != NULL)
        {
            if (current->key > index->key)
            {
                temp_data = current->data;
                temp_key = current->key;

                current->data = index->data;
                current->key = index->key;

                index->data = temp_data;
                index->key = temp_key;
            }
            index = index->next;
        }
        current = current->next;
    }
}

int main()
{
    createll(4, 45);
    createll(3, 35);
    createll(2, 85);
    createll(1, 67);
    createll(5, 40);

    printf("\nAfter creating linked list:\n");
    printll();

    delete_first();
    printf("\nAfter deleting first item list:\n");
    printll();

    delete_last();
    printf("\nAfter deleting last item list:\n");
    printll();

    insertBE(6, 50);
    printf("\nAfter inserting at the first position:\n");
    printll();

    insertED(7, 22);
    printf("\nAfter inserting at the last position:\n");
    printll();

    insert_between_key(2, 8, 25);
    printf("\nAfter inserting at the middle position:\n");
    printll();

    delete_between_key(2);
    printf("\nAfter deleting at the middle position:\n");
    printll();

    revll();
    printf("\nAfter reverse linked list:\n");
    printll();

    sort_by_data();
    printf("\nAfter sorting linked list by data:\n");
    printll();

    sort_by_key();
    printf("\nAfter sorting linked list by key:\n");
    printll();
}