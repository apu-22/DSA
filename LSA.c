#include <stdio.h>
#include <stdlib.h>

struct node *createLS(int arr[], int size);
int searchItem(struct node *head, int item); // Function declaration
void revLS(struct node *head);
void printLS(struct node *head);
void insertBE(struct node *head, int newdata);
void insertED(struct node *head, int newdata);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int a[] = {2, 3, 4, 1, 10};
    struct node *head;
    head = createLS(a, 5); // function call for traverse

    printLS(head);

    printf("\n\nIndex : %d\n", searchItem(head, 1)); // function call for search item

     struct node *newHead=head;
    insertBE(head, 15);
    insertED(head,15);
    revLS(head);

    return 0;
}

void insertBE(struct node *head, int newdata)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    temp->data = newdata;
    temp->next = head;

    struct node *newHead = temp;
    struct node *current = newHead;
    newHead = temp;

    printLS(newHead);
}

void insertED(struct node *head, int newdata){
  struct node *current=head;
  while (current->next != NULL)
  {
    current=current->next;
  }
  
   struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = newdata;
    temp->next = NULL;

    current->next=temp;
    printLS(head);

}


void printLS(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        /* code */ printf("-> %d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

void revLS(struct node *head)
{
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next; // sotre the next node
        current->next = prev; // reverse the link
        prev = current;
        current = next;
    }
    head = prev;

    while (head != NULL)
    {
        /* code */ printf("-> %d ", head->data);
        head = head->next;
    }
}

int searchItem(struct node *head, int item)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == item)
        {
            return ++index;
        }
        else
        {
            head = head->next;
            index++;
        }
    }
    return -1;
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