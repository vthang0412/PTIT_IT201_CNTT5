#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node *insertAtTail(Node *head,int x) {
    Node *newNode = createNode(x);
    if (head == NULL) return newNode;

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
void printList(Node *head) {
    printf("\nNULL <-> ");
    while (head != NULL) {
        printf("%d <-> ",head->data);
        head= head->next;
    }
    printf("NULL\n");
}
void printNode(Node *head) {
    int index = 1;
    while (head != NULL) {
        printf("Node %d: %d\n", index, head->data);
        head = head->next;
        index++;
    }
}
int main() {
    Node *head = NULL;
    int n,value;
    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtTail(head, value);
    }
    printList(head);
    printNode(head);
}