#include<stdio.h>
#include <stdlib.h> 

typedef struct node
{
   int data;
   struct node *next;
}Node;
Node addnum(Node *head, int num)
{
    Node *temp = head;
    Node *foot = head;

    while(foot != NULL){
        foot = foot->next;
        }
    if (temp->data + num > 9)
    {
        while(temp != foot)
        {
            temp = temp->next;
        }
        addnum(Node *temp, 1);
        temp = head;
    }
    else{
        foot->data += num;
        while(temp != foot)
        {
            temp = temp->next;
        }
        foot = temp;
    }
    return head;
}
