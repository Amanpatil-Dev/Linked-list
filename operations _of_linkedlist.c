#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr -> next; 
    }
}

// Case 1
struct Node * Insertionatfirst(struct Node *head, int data)
{
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
  ptr->data = data;
  
  ptr->next = head;
  return ptr;
}

// Case 2
struct Node * Insertionatindex(struct Node *head, int data, int index)
{

  struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *  p = head;
  int i = 0;
  while(i != index - 1)
  {
     p = p-> next;
     i++;
  }
  
  ptr->data = data;
  ptr-> next = p->next;
  p->next = ptr;
  return head;
}

// Case 3
struct Node * Insertionatend(struct Node *head, int data)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node * p = head;
    
    while(p->next != NULL)
    {
        p = p-> next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * InsertionafteranyNode(struct Node *head, struct Node *prevNode, int data)
{
 struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
 ptr -> data = data;
 
 ptr ->next = prevNode -> next;
 prevNode->next = ptr;
 
 return head;
}
 
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 7;
    head->next = second;
    
    // link second and third nodes
    second->data = 11;
    second->next = third;
    
    // link third and fourth nodes
    third->data  = 41;
    third->next = fourth;
    
    //Terminate the list at the third nodes
    fourth->data = 66;
    fourth->next = NULL;
    
    printf("Linked list before insertion\n");
    linkedlistTraversal(head);
     head = Insertionatfirst(head, 01);
     head = Insertionatindex(head, 89, 1);
    head = Insertionatend(head, 5);
    head = InsertionafteranyNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedlistTraversal(head);

    
    return 0;
}
