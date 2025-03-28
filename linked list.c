#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addnum(Node *head, int num) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    temp->data += num;

    while (temp->data > 9) {
        temp->data -= 10;
        if (prev == NULL) {
            Node* newNode = createNode(1);
            newNode->next = head;
            head = newNode;
        } else {
            prev->data += 1;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    addnum(head, 7);

    printf("List after adding 7: ");
    printList(head);

    return 0;
}
