#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
Node *insertAtHead(Node *head, int x) {
    Node *newNode = createNode(x);
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    return newNode;
}
Node *deleteHead(Node *head) {
    if (head==NULL) return NULL;
    Node *temp =head;
    head = head->next;
    if (head!=NULL) head->prev=NULL;
    free(temp);
    return head;
}
void printList(Node *head) {
    while (head!=NULL) {
        printf("%d <-> ",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);

    printList(head);
    printf("\n");
    head = deleteHead(head);
    printList(head);
}