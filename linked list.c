#include<stdio.h>
#include <stdlib.h> 

typedef struct node
{
   int data;
   struct node *next;
}Node;


void addnum(Node *head, int num)
{
    Node *temp = head;
    Node *foot = head->next;
    while(foot->next != NULL)
    {
        foot = foot->next;
    }
    while(temp->next != foot)
    {
        temp = temp->next;
    }
    if (num + foot->data < 9)
    {
        foot->data = num + foot->data;
        foot = temp;
        temp = head;
    }
    else
    {
        foot->data = (num + foot->data) % 10;
        int carry = (num + foot->data) / 10;
        temp->data += (num + foot->data);
        temp = head;
    }
}
