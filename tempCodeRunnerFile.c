void revLS(struct node *head)
// {
//     struct node *prev = NULL, *current = head, *next = NULL;
//     while (current != NULL)
//     {
//         next = current->next; // sotre the next node
//         current->next = prev; // reverse the link
//         prev = current;
//         current = next;
//     }
//     head = prev;

//     while (head != NULL)
//     {
//         /* code */ printf("-> %d ", head->data);
//         head = head->next;
//     }
// }